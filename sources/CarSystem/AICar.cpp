//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Thu May 25 02:05:26 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, car_no) {

    this->_rayInfo = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(400, 20, 800, 400));
    this->_rayInfo->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);

}

void AICar::OnFrame() {
    std::string str("      \nray Front: 0");
    this->_rayInfo->setText(Utils::StrToWstr(str));

    Car::OnFrame();
}

AICar::~AICar() {

}
