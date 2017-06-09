//
// Server.cpp for server in /Users/leandr_g/Documents/Shared folder/IndieStudio/server/src/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Fri May 26 03:32:38 2017 Gaëtan Léandre
// Last update Fri May 26 04:14:18 2017 Gaëtan Léandre
//

#include            "Server.hh"

Server::Server ()
{
}

Server::~Server ()
{

}

Server::Server(const Server &obj)
{
    this->_clients = obj._clients;
}

Server    &Server::operator=(const Server &obj)
{
    this->_clients = obj._clients;
    return (*this);
}

void Server::startRace(Message const &message)
{
    //TODO Create race
}

void Server::endRace(int id)
{
    //TODO Delete race
}

bool Server::deleteClientFromRaceById(int id)
{
    for (auto &x: this->_races)
    {
        if (x.deleteClientById(id) == true)
            return (true);
    }
    return (false);
}

bool Server::deleteClientFromRaceByFd(int fd)
{
    for (auto &x: this->_races)
    {
        if (x.deleteClientByFd(fd) == true)
            return (true);
    }
    return (false);
}

bool Server::deleteClientById(int id)
{
    for (auto &x: this->_clients)
    {
        if (x.second->getId() == id)
        {
            deleteClientFromRaceByFd(x.second->getSocket().getFd());
            this->_clients.erase(x.second->getSocket().getFd());
            return (true);
        }
    }
    return (false);
}

bool Server::deleteClientByFd(int fd)
{
    if (this->_clients.count(fd) > 0)
    {
        deleteClientFromRaceByFd(fd);
        this->_clients.erase(fd);
        return (true);
    }
    return (false);
}

void Server::shutdown() {
    Message data("disconnect");
    writeAll(data.getJSON());
}
