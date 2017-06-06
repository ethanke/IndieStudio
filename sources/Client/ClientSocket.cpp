//
// ClientSocket.cpp for clientSocket in /Users/leandr_g/Documents/Shared folder/IndieStudio/sources/Client/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:59:27 2017 Gaëtan Léandre
// Last update Tue Jun  6 22:18:41 2017 Gaëtan Léandre
//

#include                "ClientSocket.hpp"

ClientSocket::ClientSocket()
{
}

ClientSocket::~ClientSocket()
{
}

ClientSocket::ClientSocket(const ClientSocket &obj)
{
    this->_fd = obj._fd;
    this->_ip = obj._ip;
    this->_started = obj._started;
    this->_detach = false;
    (const_cast<ClientSocket &>(obj))._detach = true;
}

ClientSocket &ClientSocket::operator=(const ClientSocket &obj)
{
    this->_fd = obj._fd;
    this->_ip = obj._ip;
    this->_started = obj._started;
    this->_detach = false;
    (const_cast<ClientSocket &>(obj))._detach = true;
    return (*this);
}

bool ClientSocket::init(std::string const &ip)
{

    return (true);
}
