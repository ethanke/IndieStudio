//
// ClientSocket.hpp for clientSocket in /Users/leandr_g/Documents/Shared folder/IndieStudio/includes/Client/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:56:35 2017 Gaëtan Léandre
// Last update Wed Jun  7 00:59:58 2017 Gaëtan Léandre
//

#ifndef CLIENTSOCKET_HPP__
#define CLIENTSOCKET_HPP__

#include                <future>
#include                "Socket.hpp"

class ClientSocket : public Socket {
private:
    std::future<void> _async;
    void _launchLoop();

public:
    ClientSocket ();
    virtual ~ClientSocket ();
    ClientSocket(const ClientSocket &obj);
    ClientSocket &operator=(const ClientSocket &obj);
    bool init(std::string const &ip, int port);
    void stop();
    void launchLoop();
    void reciveCommand(std::string const &json);
};

#endif /* !CLIENTSOCKET_HPP__ */
