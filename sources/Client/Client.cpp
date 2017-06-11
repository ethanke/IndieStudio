//
// Client.cpp for Client in /Users/leandr_g/Documents/Shared folder/IndieStudio/sources/
//
// Made by Gaëtan Léandre
// Login   <gaetan.leandre@epitech.eu>
//
// Started on  Tue Jun  6 21:50:28 2017 Gaëtan Léandre
// Last update Sun Jun 11 18:15:01 2017 Sousa Victor
//

#include                "Client.hpp"

using namespace indie;

Client Client::_instance = Client();

Client::Client(std::string const &ip, int port)
{
    this->_ip = ip;
    this->_port = port;
    this->_id = "-1";
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
    this->_bridge = bridge;
    this->_client.connect("http://" + this->_ip + ":" + std::to_string(this->_port));
    this->parseID();
    this->SetupCallback();
}

void Client::SetupCallback() {
    this->_client.socket()->on("give your id", sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp)
    {
        this->_client.socket()->emit("id client is", "{\"id\": \"" + this->_id + "\"}");
    }));

    this->_client.socket()->on("change id", sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp)
    {
        this->setId(data->get_map()["new_id"]->get_string());
        this->_shortId = data->get_map()["short_id"]->get_string();
    }));

    this->_client.socket()->on("connected_to", sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list &ack_resp)
    {
        this->_bridge->addEvent(name, data);
    }));
}

void Client::stop() {
    //TODO stop _client;
}

void Client::parseID() {
    std::string id = "-1";
    std::ifstream infile((std::string(SOURCES_PATH) + std::string("/Data/id.txt")).c_str());

    if (infile >> id) {
        if (id != "-1") {
            this->_id = id;
        }
    }
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
}

void Client::giveId() {
    // Message data("setid");
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
}

// void Client::addMoney(int nb) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("addmoney");
    // data("id") = std::to_string(this->_id);
    // data("value") = std::to_string(nb);
    // this->_socket.write(data.getJSON());
// }

// void Client::requestMoney() {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("getmoney");
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
// }

void Client::joinId(const wchar_t *dest_id) {
    rapidjson::Document d;
    d.SetObject();
    rapidjson::Value v(rapidjson::kObjectType);

    v.SetString(this->_id.c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("id", v, d.GetAllocator());

    std::wstring ws(dest_id);
    std::string dest(ws.begin(), ws.end());
    v.SetString(dest.c_str(), static_cast<rapidjson::SizeType>(dest.length()), d.GetAllocator());
    d.AddMember("dest", v, d.GetAllocator());

    this->_client.socket()->emit("joining someone", this->getString(d));
}

void Client::sendPosAndRota(irr::core::vector3df const &pos, irr::core::vector3df const &rot) {
    rapidjson::Document d;
    d.SetObject();
    rapidjson::Value v(rapidjson::kObjectType);

    v.SetString(this->_id.c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("id", v, d.GetAllocator());

    v.SetString(std::to_string(pos.X).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("posX", v, d.GetAllocator());
    v.SetString(std::to_string(pos.Y).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("posY", v, d.GetAllocator());
    v.SetString(std::to_string(pos.Z).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("posZ", v, d.GetAllocator());

    v.SetString(std::to_string(rot.X).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("rotX", v, d.GetAllocator());
    v.SetString(std::to_string(rot.Y).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("rotY", v, d.GetAllocator());
    v.SetString(std::to_string(rot.Z).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("rotZ", v, d.GetAllocator());

    this->_client.socket()->emit("send pos", this->getString(d));
}

void Client::sendEngineData(irr::core::vector3df const &vel, irr::core::vector3df const &ang, float engine, float breaking, float steering) {
    rapidjson::Document d;
    d.SetObject();
    rapidjson::Value v(rapidjson::kObjectType);

    v.SetString(this->_id.c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("id", v, d.GetAllocator());

    v.SetString(std::to_string(engine).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("engine", v, d.GetAllocator());

    v.SetString(std::to_string(breaking).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("breaking", v, d.GetAllocator());

    v.SetString(std::to_string(steering).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("steering", v, d.GetAllocator());

    v.SetString(std::to_string(vel.X).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("LinearX", v, d.GetAllocator());

    v.SetString(std::to_string(vel.Y).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("LinearY", v, d.GetAllocator());

    v.SetString(std::to_string(vel.Z).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("LinearZ", v, d.GetAllocator());

    v.SetString(std::to_string(ang.X).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("AngularX", v, d.GetAllocator());

    v.SetString(std::to_string(ang.Y).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("AngularY", v, d.GetAllocator());

    v.SetString(std::to_string(ang.Z).c_str(), static_cast<rapidjson::SizeType>(this->_id.length()), d.GetAllocator());
    d.AddMember("AngularZ", v, d.GetAllocator());

    this->_client.socket()->emit("sent engine", this->getString(d));
}

// void Client::creatingCourseLobby(irr::s32 const &id) {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("creatinglobby");
    // data("id") = std::to_string(this->_id);
    // data("course") = std::to_string(id);
    // this->_socket.write(data.getJSON());
// }

// void Client::leavingCourseLobby() {
    // if (this->_id == -1) {
    //     this->requestId();
    //     return;
    // }
    //
    // Message data("leavinglobby");
    // data("id") = std::to_string(this->_id);
    // this->_socket.write(data.getJSON());
// }

void Client::setId(std::string const & id) {
    std::ofstream infile((std::string(SOURCES_PATH) + std::string("/Data/id.txt")).c_str());

    infile << id;
    this->_id = id;
}

std::string const & Client::getId() const {
    return this->_id;
}

std::string const & Client::getShortId() const {
    return this->_shortId;
}

void Client::setCarNo(int no) {
    this->_client.socket()->emit("carNum changed", "{\"id\": \"" + this->_id + "\", \"nbr\": \"" + std::to_string(no) + "\"}");
}

std::string const Client::getString(rapidjson::Document const &d) {
    rapidjson::StringBuffer buffer;
    buffer.Clear();
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);
    std::string json = buffer.GetString();
    return json;
}
