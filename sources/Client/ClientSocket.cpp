//
// ClientSocket.cpp for clientSocket in /Users/leandr_g/Documents/Shared folder/IndieStudio/sources/Client/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:59:27 2017 Gaëtan Léandre
// Last update Tue Jun  6 22:28:36 2017 Gaëtan Léandre
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

void ClientSocket::stop()
{
    if (this->_started == true && this->_detach == false)
    {
        ::close(this->_fd);
        this->_started = false;
    }
}

bool ClientSocket::init(std::string const &ip, int port)
{
    SOCKADDR_IN             s_in;

    stop();
    #if defined (WIN32)
        WSADATA WSAData;
        WSAStartup(MAKEWORD(2,2), &WSAData);
    #endif
    s_in.sin_addr.s_addr = inet_addr(ip.c_str());
    s_in.sin_port = htons(port);
    s_in.sin_family = AF_INET;
    if ((this->_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return (false);
    else if (connect(this->_fd, (SOCKADDR*)&s_in, sizeof(s_in)) == -1)
    {
        ::close(this->_fd);
        return (false);
    }
    return (true);
}
