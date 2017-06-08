//
// ClientSocket.cpp for clientSocket in /Users/leandr_g/Documents/Shared folder/IndieStudio/sources/Client/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:59:27 2017 Gaëtan Léandre
// Last update Thu Jun  8 16:49:34 2017 Sousa Victor
//

#include                "ClientSocket.hpp"

using namespace indie;


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

bool ClientSocket::init(std::string const &ip, int port, indie::NetworkEventBridge *bridge)
{
    SOCKADDR_IN             s_in;
    this->_bridge = bridge;

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
    this->_started = true;
    this->_detach = false;
    return (true);
}

void ClientSocket::_launchLoop()
{
    fd_set		fdset;
    std::string text;
    struct timeval tv = {5, 0};

    while (this->_started == true)
    {
        FD_ZERO(&fdset);
        FD_SET(this->_fd, &fdset);
        if (select(this->_fd + 1, &fdset, NULL, NULL, &tv) == -1)
            return;
        if (FD_ISSET(this->_fd, &fdset))
        {
            text = read();
            if (text == "-")
                return;
            reciveCommand(text);
        }
    }
}

void ClientSocket::launchLoop()
{
    if (this->_started == 1)
        this->_async = std::async(std::launch::async, &ClientSocket::_launchLoop, this);
}

void ClientSocket::reciveCommand(std::string const &json)
{
    this->_bridge->lockEventBuffer();
    this->_bridge->addEvent(json);
    this->_bridge->unlockEventBuffer();
}
