//
// main.cpp for  in /Users/vicostudio/Documents/Shared Folder/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May  4 17:46:24 2017 Sousa Victor
// Last update Sun Jun 11 05:05:30 2017 Sousa Victor
//

#include "IndieGame.hpp"

#include "sio_socket.h"
#include "sio_client.h"

int main(int argc, char* argv[]) {
    sio::client h;
    h.connect("http://127.0.0.1:3000");

    h.socket()->on("welcome", sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp)
    {
        std::cout  << "server said: " << data->get_map()["message"]->get_string() << std::endl;
    }));

    h.socket()->on("time", sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp)
    {
        std::cout << "server sent his timestamp: " << data->get_map()["time"]->get_string() << std::endl;
    }));

    indie::IndieGame game(1400, 800);

    game.Setup();
    game.Start();
    game.Clean();

    return 1;
}
