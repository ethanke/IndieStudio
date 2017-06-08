//
// Client.hpp for client in /Users/leandr_g/Documents/Shared folder/IndieStudio/includes/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:51:52 2017 Gaëtan Léandre
// Last update Thu Jun  8 16:43:33 2017 Sousa Victor
//

#ifndef             CLIENT_HPP
#define             CLIENT_HPP

#include <fstream>
#include "ClientSocket.hpp"
#include "EventReceiver.hpp"
#include "Message.hpp"
#include "IndieStudioConfig.h"


namespace indie {

    class Client {
    private:
        static Client _instance;
        ClientSocket _socket;
        std::string _ip;
        int _port;
        int _id;

    public:
        //93.9.51.53
        //10.16.252.77
        explicit Client (std::string const &ip = "127.0.0.1", int port = 1234);
        virtual ~Client ();
        Client(const Client &obj);
        Client &operator=(const Client &obj);
        static Client &Instance();
        void init(NetworkEventBridge *bridge);
        void stop();

        ClientSocket getSocket();
        void setId(int id);
        int getId() const;

        void requestId();
        void giveId();
        void addMoney(int nb);
        void requestMoney();
        void joinId(std::string const &dest_id);
        void move(std::string const &vel, std::string const &x, std::string const &y, std::string const &z);
        void creatingCourseLobby(irr::s32 const &id);
        void leavingCourseLobby();


    };

}

#else

#endif /* !CLIENT_HPP */
