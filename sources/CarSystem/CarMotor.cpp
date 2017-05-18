//
// CarMotor.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat May 13 22:34:06 2017 Sousa Victor
// Last update Thu May 18 19:22:44 2017 Sousa Victor
//

#include "CarMotor.hpp"

using namespace indie;

CarMotor::CarMotor(irr::gui::IGUIEnvironment* guiManager, bool debugMode) {
    this->_gui = guiManager;
    this->_debug = debugMode;

    setupCar();
    startCar();
}

CarMotor::~CarMotor() {

}
void CarMotor::setupCar() {

}

void CarMotor::startCar() {

}

void CarMotor::OnFrame(float throttle, float brake, float handbrake, int inputY) {

}
