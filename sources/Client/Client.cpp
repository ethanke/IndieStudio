//
// Client.cpp for Client in /Users/leandr_g/Documents/Shared folder/IndieStudio/sources/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:50:28 2017 Gaëtan Léandre
// Last update Tue Jun  6 22:12:54 2017 Gaëtan Léandre
//

#include                "Client.hpp"

using namespace indie;

Client Client::_instance = Client();

Client::Client(std::string const &ip, int port)
{
    this->_ip = ip;
    this->_port = port;
    this->_id = -1;
}

Client::~Client()
{
}

Client::Client(const Client &obj)
{
    this->_socket = obj._socket;
}

Client &Client::operator=(const Client &obj)
{
    this->_socket = obj._socket;
    return (*this);
}

Client &Client::Instance() {
    return _instance;
}

void Client::init() {
    this->_socket.init(this->_ip, this->_port);
    this->_socket.launchLoop();
}

std::string read() {
    return std::string("lol");
}




void requestId() {
    int id = -1;
    std::ifstream infile((std::string(SOURCES_PATH) + std::string("/Data/id.txt")).c_str());
    Message data("getid");

    while (infile >> id) {
        Client::Instance().setId(id);
        return;
    }
    std::cout << data.getJSON() << std::endl;
    Client::Instance().getSocket().write(data.getJSON());

}

void Client::addMoney(int nb) {
    if (this->_id == -1) {
        Client::Instance().getId();
        return;
    }

    Message data("addmoney");
    data("id") = this->_id;
    data("value") = std::to_string(nb);
    this->_socket.write(data.getJSON());
}




ClientSocket Client::getSocket() {
    return this->_socket;
}

void Client::setId(int id) {
    this->_id = id;
}

int Client::getId() const {
    return this->_id;
}
