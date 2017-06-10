//
// NetworkCar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat Jun 10 16:38:11 2017 Sousa Victor
// Last update Sat Jun 10 16:41:03 2017 Sousa Victor
//

#include "NetworkCar.hpp"

using namespace indie;

NetworkCar::NetworkCar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, Circuit const &circuit, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, circuit, car_no, irr::core::vector3df(2, 36.5, 0), true) {

}

NetworkCar::~NetworkCar() {

}

void NetworkCar::OnFrame() {
    this->_carLoader.Update(drive_tipe);
}
