//
// Client.cpp for Client in /Users/leandr_g/Documents/Shared folder/IndieStudio/sources/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:50:28 2017 Gaëtan Léandre
// Last update Tue Jun  6 22:12:54 2017 Gaëtan Léandre
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
    this->_socket = obj._socket;
}

Client &Client::operator=(const Client &obj)
{
    this->_socket = obj._socket;
    return (*this);
}

Client &Client::Instance() {
    return _instance;
}

void Client::init() {
    this->_socket.init(this->_ip, this->_port);
    this->_socket.launchLoop();
}

void Client::stop() {
    this->_socket.stop();
}

std::string Client::read() {
    return std::string("lol");
}




void Client::requestId() {
    int id = -1;
    std::ifstream infile((std::string(SOURCES_PATH) + std::string("/Data/id.txt")).c_str());

    if (infile >> id) {
        Client::Instance().setId(id);
        return;
    }

    Message data("getid");
    std::cout << data.getJSON() << std::endl;
    Client::Instance().getSocket().write(data.getJSON());

}

void Client::addMoney(int nb) {
    if (this->_id == -1) {
        Client::Instance().requestId();
        return;
    }

    Message data("addmoney");
    data("id") = std::to_string(this->_id);
    data("value") = std::to_string(nb);
    std::cout << data.getJSON() << std::endl;
    this->_socket.write(data.getJSON());
}

void Client::move(irr::core::vector3df const &pos, irr::core::vector3df const &rot) {
    if (this->_id == -1) {
        Client::Instance().requestId();
        return;
    }

    Message data("move");
    Message position("position");
    data["position"] = position;
    data["position"]("Z") = std::to_string(pos.Z);
    data["position"]("Y") = std::to_string(pos.Y);
    data["position"]("X") = std::to_string(pos.X);
    Message rotation("rotation");
    data["rotation"] = rotation;
    data["rotation"]("Z") = std::to_string(rot.Z);
    data["rotation"]("Y") = std::to_string(rot.Y);
    data["rotation"]("X") = std::to_string(rot.X);
    data("id") = std::to_string(this->_id);
    std::cout << data.getJSON() << std::endl;
    this->_socket.write(data.getJSON());
}

void Client::creatingCourseLobby(irr::s32 const &id) {
    if (this->_id == -1) {
        Client::Instance().requestId();
        return;
    }

    Message data("creatinglobby");
    data("id") = std::to_string(this->_id);
    data("course") = std::to_string(id);
    std::cout << data.getJSON() << std::endl;
    this->_socket.write(data.getJSON());
}

void Client::leavingCourseLobby() {
    if (this->_id == -1) {
        Client::Instance().requestId();
        return;
    }

    Message data("leavinglobby");
    data("id") = std::to_string(this->_id);
    std::cout << data.getJSON() << std::endl;
    this->_socket.write(data.getJSON());
}





ClientSocket Client::getSocket() {
    return this->_socket;
}

void Client::setId(int id) {
    this->_id = id;
}

int Client::getId() const {
    return this->_id;
}
