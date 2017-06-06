//
// ClientSocket.hpp for clientSocket in /Users/leandr_g/Documents/Shared folder/IndieStudio/includes/Client/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:56:35 2017 Gaëtan Léandre
// Last update Tue Jun  6 22:14:34 2017 Gaëtan Léandre
//

#ifndef CLIENTSOCKET_HPP__
#define CLIENTSOCKET_HPP__

#include                "Socket.hpp"

class ClientSocket : public Socket {
public:
    ClientSocket ();
    virtual ~ClientSocket ();
    ClientSocket(const ClientSocket &obj);
    ClientSocket &operator=(const ClientSocket &obj);
    bool init(std::string const &ip);
};

#endif /* !CLIENTSOCKET_HPP__ */
