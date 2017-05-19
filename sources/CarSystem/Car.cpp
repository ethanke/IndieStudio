//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Fri May 19 21:22:14 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver):
    AGameObject(sceneManager) {

    this->_eventReceiver = eventReceiver;
    this->_camera = new BasicCamera(this->_smgr, 0, -1, irr::core::vector3df(10, 37.5, 4), irr::core::vector3df(2, 36, 0));

    this->_carNode = this->_smgr->addMeshSceneNode(this->_smgr->getMesh("/Users/vicostudio/Documents/Shared/TEK2/CPP/UniversityRacer/models/car.3ds"));
    this->_carNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_carNode->setPosition(irr::core::vector3df(2, 38, 4));

}

Car::~Car() {

}

void Car::OnFrame() {
    int valueX = ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 0 :
                 ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) && !this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 1 :
                 (!this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? -1 : 0;
    int valueY = ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 0 :
                 ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) && !this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? -1 :
                 (!this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 1 : 0;

    if (this->_eventReceiver->IsKeyDown(irr::KEY_UP)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0.15, 0, 0));
    } else if (this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(-0.15, 0, 0));
    } else {

    }
    if (this->_eventReceiver->IsKeyDown(irr::KEY_LEFT)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0, 0, 0.15));
    }
    if (this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0, 0, -0.15));
    }
}

irr::core::vector3d<float>	Car::getPosition() const {
    return _carNode->getPosition();
}


AGameCamera *Car::getCamera() const {
    return this->_camera;
}
