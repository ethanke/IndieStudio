//
// Client.hpp for client in /Users/leandr_g/Documents/Shared folder/IndieStudio/includes/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:51:52 2017 Gaëtan Léandre
// Last update Sun Jun 11 17:39:31 2017 Sousa Victor
//

#ifndef             CLIENT_HPP
#define             CLIENT_HPP

#include <fstream>
#include "sio_socket.h"
#include "sio_client.h"

#include "NetworkEventBridge.hpp"
#include "EventReceiver.hpp"
#include "Message.hpp"
#include "ClientSocket.hpp"
#include "IndieStudioConfig.h"


namespace indie {

    class Client {
    private:
        static Client _instance;
        sio::client _client;
        std::string _ip;
        int _port;
        int _id;

        void SetupCallback();

    public:
        explicit Client (std::string const &ip = "37.187.8.132", int port = 3000);
        virtual ~Client ();
        Client(const Client &obj);
        Client &operator=(const Client &obj);
        static Client &Instance();
        void init(NetworkEventBridge *bridge);
        void stop();

        ClientSocket getSocket();
        void setId(int id);
        int getId() const;

        void debug(std::string const &debug);
        void requestId();
        void giveId();
        void addMoney(int nb);
        void requestMoney();
        void joinId(const wchar_t *dest_id);
        void move(irr::core::vector3df const &pos, irr::core::vector3df const &rot);
        void sendEngine(irr::core::vector3df const &vel, irr::core::vector3df const &ang, float engine, float breaking, float steering);
        void creatingCourseLobby(irr::s32 const &id);
        void leavingCourseLobby();
        void setCarNo(int no);


    };

}

#else

#endif /* !CLIENT_HPP */
