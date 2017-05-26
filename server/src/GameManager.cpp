//
// GameManager.cpp for gameMananger in /Users/leandr_g/Documents/Shared folder/IndieStudio/server/src/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Fri May 26 00:03:45 2017 Gaëtan Léandre
// Last update Fri May 26 04:16:54 2017 Gaëtan Léandre
//

#include            "GameManager.hh"

GameManager::GameManager()
{
    Client tmp;

    tmp.setId(-1);
    this->_clients[-1] = tmp;
}

GameManager::~GameManager ()
{
}

GameManager::GameManager(const GameManager &obj)
{
    this->_clients = obj._clients;
}

GameManager    &GameManager::operator=(const GameManager &obj)
{
    this->_clients = obj._clients;
    return (*this);
}

void GameManager::addClient(int sock)
{
    Client tmp;

    if (tmp.accept(sock) != false)
        this->_clients[tmp.getSocket().getFd()] = tmp;
}

void GameManager::deleteClient(int fd)
{
    if (this->_clients.count(fd) > 0)
        this->_clients.erase(fd);
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

void GameManager::launchCommand(std::string json)
{
    //TODO LAUNCH COMMAND
}

void GameManager::readClientByFdSet(fd_set *fdset)
{
    for (auto & x: this->_clients)
    {
        if (FD_ISSET(x.second.getSocket().getFd(), fdset))
        {
            launchCommand(x.second.read());
            return;
        }
    }
}

void GameManager::readClientByFd(int fd)
{
    if (this->_clients.count(fd) > 0)
        launchCommand(this->_clients[fd].read());
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
            launchCommand(x.second.read());
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
