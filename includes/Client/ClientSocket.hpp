//
// ClientSocket.hpp for clientSocket in /Users/leandr_g/Documents/Shared folder/IndieStudio/includes/Client/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:56:35 2017 Gaëtan Léandre
// Last update Thu Jun  8 16:49:40 2017 Sousa Victor
//

#ifndef CLIENTSOCKET_HPP__
#define CLIENTSOCKET_HPP__

#include <future>
#include <vector>
#include "Socket.hpp"
#include "NetworkEventBridge.hpp"

 namespace indie {

    class ClientSocket : public Socket {
    private:
        std::future<void> _async;
        void _launchLoop();
        NetworkEventBridge *_bridge;

    public:
        ClientSocket ();
        virtual ~ClientSocket ();
        ClientSocket(const ClientSocket &obj);
        ClientSocket &operator=(const ClientSocket &obj);
        bool init(std::string const &ip, int port, indie::NetworkEventBridge *bridge);
        void stop();
        void launchLoop();
        void reciveCommand(std::string const &json);
    };


}

#endif /* !CLIENTSOCKET_HPP__ */
