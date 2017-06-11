//
// NetworkEventBridge.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu Jun  8 16:35:57 2017 Sousa Victor
// Last update Thu Jun  8 16:48:19 2017 Sousa Victor
//

#include "NetworkEventBridge.hpp"

using namespace indie;

NetworkEventBridge::NetworkEventBridge() {

}

NetworkEventBridge::~NetworkEventBridge() {

}

void NetworkEventBridge::addEvent(sio::message::ptr const &msg) {
    this->_cmdBuffer.push_back(msg);
}

void NetworkEventBridge::lockEventBuffer() {
    while (this->_mutex.try_lock() == false);
}

void NetworkEventBridge::unlockEventBuffer() {
    this->_mutex.unlock();
}
