//
// Client.cpp for Client in /Users/leandr_g/Documents/Shared folder/IndieStudio/sources/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:50:28 2017 Gaëtan Léandre
// Last update Sun Jun 11 17:28:17 2017 Sousa Victor
//

#include                "Client.hpp"

using namespace indie;

Client Client::_instance = Client();

Client::Client(std::string const &ip, int port)
{
    this->_ip = ip;
    this->_port = port;
    this->_id = -1;
}

Client::~Client()
{

}

Client::Client(const Client &obj)
{
    //this->_client = obj._client;
}

Client &Client::operator=(const Client &obj)
{
    //this->_client = obj._client;
    return (*this);
}

Client &Client::Instance() {
    return _instance;
}

void Client::init(NetworkEventBridge *bridge) {
    this->_client.connect("http://" + this->_ip + ":" + std::to_string(this->_port));
    this->SetupCallback();
}

void Client::SetupCallback() {
    this->_client.socket()->on("welcome", sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp)
    {
        std::cout  << "server said: " << data->get_map()["message"]->get_string() << std::endl;
    }));

    this->_client.socket()->on("time", sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp)
    {
        std::cout << "server sent his timestamp: " << data->get_map()["time"]->get_string() << std::endl;
    }));
}

void Client::stop() {
    //TODO stop _client;
}

void Client::requestId() {
    // int id = -1;
    // std::ifstream infile((std::string(SOURCES_PATH) + std::string("/Data/id.txt")).c_str());
    //
    // if (infile >> id) {
    //     if (id != -1) {
    //         this->_id = id;
    //         this->giveId();
    //         return;
    //     }
    // }
    // Message data("getid");
    // this->_socket.write(data.getJSON());

}

void Client::giveId() {
    // Message data("setid");
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
}

void Client::addMoney(int nb) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("addmoney");
    // data("id") = std::to_string(this->_id);
    // data("value") = std::to_string(nb);
    // this->_socket.write(data.getJSON());
}

void Client::requestMoney() {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("getmoney");
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
}

void Client::joinId(const wchar_t *dest_id) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("join");
    // data("id") = std::to_string(this->_id);
    // std::wstring ws(dest_id);
    // std::string dest(ws.begin(), ws.end());
    // data("value") = dest;
    // this->_socket.write(data.getJSON());
}

void Client::move(irr::core::vector3df const &pos, irr::core::vector3df const &rot) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("move");
    // Message position("position");
    // data["position"] = position;
    // data["position"]("Z") = std::to_string(pos.Z);
    // data["position"]("Y") = std::to_string(pos.Y);
    // data["position"]("X") = std::to_string(pos.X);
    // Message rotation("rotation");
    // data["rotation"] = rotation;
    // data["rotation"]("Z") = std::to_string(rot.Z);
    // data["rotation"]("Y") = std::to_string(rot.Y);
    // data["rotation"]("X") = std::to_string(rot.X);
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
}

void Client::sendEngine(irr::core::vector3df const &vel, irr::core::vector3df const &ang, float engine, float breaking, float steering) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("cardata");
    // data("steering") = std::to_string(steering);
    // data("breaking") = std::to_string(breaking);
    // data("engine") = std::to_string(engine);
    // Message velocity("velocity");
    // data["velocity"] = velocity;
    // data["velocity"]("Z") = std::to_string(vel.Z);
    // data["velocity"]("Y") = std::to_string(vel.Y);
    // data["velocity"]("X") = std::to_string(vel.X);
    // Message angular("angular");
    // data["angular"] = angular;
    // data["angular"]("Z") = std::to_string(ang.Z);
    // data["angular"]("Y") = std::to_string(ang.Y);
    // data["angular"]("X") = std::to_string(ang.X);
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
}

void Client::creatingCourseLobby(irr::s32 const &id) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("creatinglobby");
    // data("id") = std::to_string(this->_id);
    // data("course") = std::to_string(id);
    // this->_socket.write(data.getJSON());
}

void Client::leavingCourseLobby() {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("leavinglobby");
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
}

void Client::debug(std::string const &debug)
{
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    // Message data("debug");
    // data("msg") = debug;
    // this->_socket.write(data.getJSON());
}




ClientSocket Client::getSocket() {
    return ClientSocket();
}

void Client::setId(int id) {
    // std::ofstream infile((std::string(SOURCES_PATH) + std::string("/Data/id.txt")).c_str());
    //
    // infile << id;
    // this->_id = id;
}

int Client::getId() const {
    // return this->_id;
    return (0);
}

void Client::setCarNo(int no) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    // Message data("setcarno");
    // data("id") = std::to_string(this->_id);
    // data("value") = std::to_string(no);
    // this->_socket.write(data.getJSON());
}
