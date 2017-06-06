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
    this->_socket.init(ip, port);
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

bool Client::OnEvent(const irr::SEvent &event) {
    (void)event;
    lel();
    return true;
}

void Client::lel() {
    exit(1);
}
