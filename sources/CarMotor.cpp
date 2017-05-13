//
// CarMotor.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat May 13 22:34:06 2017 Sousa Victor
// Last update Sun May 14 00:45:59 2017 Sousa Victor
//

#include "CarMotor.hpp"

using namespace indie;

CarMotor::CarMotor(irr::gui::IGUIEnvironment* guiManager, bool debugMode) {
    this->_gui = guiManager;
    this->_debug = debugMode;

     this->_inputGui = this->_gui->addStaticText(L"intput,  X: 0,  Y: 0", irr::core::rect<irr::s32>(0, 0, 500, 100));
}

CarMotor::~CarMotor() {

}

void CarMotor::OnFrame(int inputX, int inputY) {
    if (this->_debug && this->_gui != NULL) {

    }
}
