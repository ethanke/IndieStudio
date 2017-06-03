//
// Circuit.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat Jun  3 20:12:02 2017 Sousa Victor
// Last update Sat Jun  3 21:09:34 2017 Sousa Victor
//

#include "Circuit.hpp"

using namespace indie;

Circuit::Circuit() {

}

Circuit::Circuit(const Circuit& obj) {
    this->_checkpoints = obj._checkpoints;
}

Circuit::~Circuit() {

}

Circuit &Circuit::operator=(const Circuit& obj) {
    this->_checkpoints = obj._checkpoints;
    return *this;
}

void Circuit::OnFrame() {
    for (auto check : this->_checkpoints) {
        check.OnFrame();
    }
}

Circuit &Circuit::operator <<(GameCheckpoint const &point) {
    this->_checkpoints.push_back(GameCheckpoint(point));
    return *this;
}


std::vector<GameCheckpoint> const &Circuit::getNextCheckpoints(unsigned index) const {
    return this->_checkpoints;
}

std::vector<GameCheckpoint> const &Circuit::getCheckpoints() const {
    return this->_checkpoints;
}
