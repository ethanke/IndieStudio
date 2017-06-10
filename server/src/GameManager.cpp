//
// GameManager.cpp for gameMananger in /Users/leandr_g/Documents/Shared folder/IndieStudio/server/src/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Fri May 26 00:03:45 2017 Gaëtan Léandre
// Last update Wed Jun  7 13:57:06 2017 Gaëtan Léandre
//

#include            "GameManager.hh"

GameManager::GameManager()
{
    Client tmp;

    tmp.setId(-1);
    this->_clients[-1] = tmp;
    int i = 0;
    this->_operation["getid"] = i++;
    this->_operation["setid"] = i++;
    this->_operation["move"] = i++;
    this->_operation["addmoney"] = i++;
    this->_operation["getmoney"] = i++;
    this->_operation["join"] = i++;
    this->_operation["debug"] = i++;
    this->_operation["velocity"] = i++;
}

GameManager::~GameManager ()
{
}

GameManager::GameManager(const GameManager &obj)
{
    this->_clients = obj._clients;
    this->_servers = obj._servers;
    this->_operation = obj._operation;
}

GameManager    &GameManager::operator=(const GameManager &obj)
{
    this->_clients = obj._clients;
    this->_servers = obj._servers;
    this->_operation = obj._operation;
    return (*this);
}

void GameManager::addClient(int sock)
{
    Client tmp;

    if (tmp.accept(sock) != false)
    {
        this->_clients[tmp.getSocket().getFd()] = tmp;
        std::cout << "New Client : " << tmp.getSocket().getIp() << std::endl;
    }
}

void GameManager::deleteClient(int fd)
{
    if (this->_clients.count(fd) > 0)
    {
        std::cout << "Disconnection : " << this->getClientByFd(fd).getSocket().getIp() << std::endl;
        for (auto &server : this->_servers) {
            if (server.foundClientByFd(fd)) {
                server.deleteClientByFd(fd);
                if (server.getClientNumber() == 1) {
                    server.shutdown();
                    this->_servers.pop_back();
                }
                break;
            }
        }
        this->_clients.erase(fd);
    }
}

Client &GameManager::getClientByFd(SOCKET fd)
{
    if (this->_clients.count(fd) > 0)
        return (this->_clients[fd]);
    return (this->_clients[-1]);
}

Client &GameManager::getClientById(int id)
{
    for (auto &x: this->_clients)
    {
        if (x.second.getId() == id)
            return (x.second);
    }
    return (this->_clients[-1]);
}

int GameManager::getClientsSize() const
{
    return (this->_clients.size());
}

void GameManager::foundCommand(Message &command, SOCKET fd) {
    switch (this->_operation[command.getTitle()])
    {
        case 0:
            getId(fd);
            break;
        case 1:
            setId(fd, std::atoi(command("id").c_str()));
            break;
        case 2:
            move(command);
            break;
        case 3:
            addMoney(fd, std::atoi(command("id").c_str()), std::atoi(command("value").c_str()));
            break;
        case 4:
            getMoney(fd, std::atoi(command("id").c_str()));
            break;
        case 5:
            joinServer(fd, std::atoi(command("id").c_str()), std::atoi(command("value").c_str()));
            break;
        case 6:
            debugMessage(command("msg"));
            break;
        case 7:
            move(command);
            break;
        default:
            std::cerr << "Command not found" << std::endl;
            break;
    }
}

void GameManager::launchCommand(std::string const &json, SOCKET fd)
{
    Message command("nothing");
    std::string delimiter("|");

    size_t pos = 0;
    std::string token;
    while ((pos = json.find(delimiter)) != std::string::npos) {
        token = json.substr(0, pos);
        command.parseJSON(token);
        std::cout << command.getTitle() << " " << token << std::endl;
        this->foundCommand(command, fd);
        const_cast<std::string&>(json).erase(0, pos + delimiter.length());
    }
    this->foundCommand(command, fd);
}

void GameManager::readClientByFdSet(fd_set *fdset)
{
    std::string tmp;

    for (auto & x: this->_clients)
    {
        if (FD_ISSET(x.second.getSocket().getFd(), fdset))
        {
            tmp = x.second.read();
            if (tmp == "-")
                deleteClient(x.second.getSocket().getFd());
            else
            {
                //TODO LAUNCH COMMAND BY COMMAND
                launchCommand(tmp, x.second.getSocket().getFd());
            }
            return;
        }
    }
}

void GameManager::readClientByFd(int fd)
{
    //TODO LAUNCH COMMAND BY COMMAND
    if (this->_clients.count(fd) > 0)
        launchCommand(this->_clients[fd].read(), this->_clients[fd].getSocket().getFd());
}

void GameManager::writeClientByFd(SOCKET fd, std::string const &str)
{
    if (this->_clients.count(fd) > 0)
        this->_clients[fd].write(str);
}

void GameManager::readClientById(int id)
{
    for (auto & x: this->_clients)
    {
        if (x.second.getId() == id)
        {
            //TODO LAUNCH COMMAND BY COMMAND
            launchCommand(x.second.read(), x.second.getSocket().getFd());
            return;
        }
    }
}

void GameManager::writeClientById(int id, std::string const &str)
{
    for (auto & x: this->_clients)
    {
        if (x.second.getId() == id)
        {
            x.second.write(str);
            return;
        }
    }
}

void GameManager::stop()
{
    this->_clients.clear();
    this->_servers.clear();
}

void GameManager::setListener(fd_set *fdset, int &max)
{
    for (auto & x: this->_clients)
    {
        x.second.getSocket().setListener(fdset, max);
    }
}

void GameManager::getId(int fd)
{
    Message setid("setid");
    //TODO USE DATABASE TO FOUND AN ID
    setid("id") = std::to_string(_idMax);
    this->_clients[fd].write(setid.getJSON());
    this->_clients[fd].setId(_idMax);
    _idMax++;

}

void GameManager::setId(int fd, int id)
{
    this->_clients[fd].setId(id);
}

void GameManager::addMoney(int fd, int id, int value) {
    this->_clients[fd].setMoney(this->_clients[fd].getMoney() + value);
}

void GameManager::getMoney(int fd, int id) {
    Message data("getmoney");
    data("value") = std::to_string(this->_clients[fd].getMoney());
    this->_clients[fd].write(data.getJSON());
}

void GameManager::move(Message &data) {
    for (auto &server : this->_servers) {
        if (server.foundClientById(std::atoi(data("id").c_str()))) {
            server.writeAllExeptById(data.getJSON(), std::atoi(data("id").c_str()));
            break;
        }
    }
}

void GameManager::joinServer(int fd, int id, int value) {
    if (value == id)
        return;
    for (auto &server : this->_servers) {
        if (server.foundClientById(id)) {
            std::cout << id << " already connected" << std::endl;
            return;
        }
    }
    Message data("connected");
    data("value") = std::to_string(value);
    for (auto &server : this->_servers) {
        if (server.foundClientById(value)) {
            server.addClient(&this->_clients[fd]);
            server.writeAll(data.getJSON());
            std::cout << "client " << id << " joined " << value << std::endl;
            return;
        }
    }
    Server serv;
    serv.addClient(&getClientById(value));
    serv.addClient(&getClientById(id));
    std::cout << "server created for " << value << " and client " << id << " joined" << std::endl;
    this->_servers.push_back(serv);
    serv.writeAll(data.getJSON());
}

void GameManager::debugMessage(std::string const &msg) {
    std::cout << "Debug message: " << msg << std::endl;
}
