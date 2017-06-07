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
        explicit Client (std::string const &ip = "127.0.0.1", int port = 1234);
        virtual ~Client ();
        Client(const Client &obj);
        Client &operator=(const Client &obj);
        static Client &Instance();
        void init();

        ClientSocket getSocket();
        void setId(int id);
        int getId() const;

        std::string read();

        void requestId();
        void addMoney(int nb);
        void move(irr::core::vector3df const &pos, irr::core::vector3df const &rot);
        void creatingCourseLobby(irr::s32 const &id);
        void leavingCourseLobby();


    };

}

#else

#endif /* !CLIENT_HPP */
