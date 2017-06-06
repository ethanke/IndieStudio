//
// Client.hpp for client in /Users/leandr_g/Documents/Shared folder/IndieStudio/includes/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:51:52 2017 Gaëtan Léandre
// Last update Tue Jun  6 22:08:37 2017 Gaëtan Léandre
//

#ifndef             CLIENT_HPP
#define             CLIENT_HPP

#include            "ClientSocket.hpp"

class Client {
private:
    static Client &_instance;
    ClientSocket _socket;

public:
    explicit Client (std::string const &ip, int port);
    virtual ~Client ();
    Client(const Client &obj);
    Client &operator=(const Client &obj);
    static Client &Instance();

};

#endif /* !CLIENT_HPP */
