//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Thu May 18 19:29:45 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver)
    : _carModel(sceneManager, "car/Car1/SV.obj", NULL, -1, 100, irr::core::vector3df(2, 36, 0), irr::core::vector3df(180, 82.5, 175), irr::core::vector3df(1, 1, 1)) {

    this->_motor = new CarMotor(guiManager, true);
    this->_eventReceiver = eventReceiver;
    this->_camera = new BasicCamera(sceneManager, 0, -1, irr::core::vector3df(-10, 42.5, 0), irr::core::vector3df(2, 36, 0));

}

Car::~Car() {

}

void Car::OnFrame() {
    int throttle = ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 0 :
                   ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) && !this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 1 :
                   (!this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? -1 : 0;
    int brake = this->_eventReceiver->IsKeyDown(irr::KEY_KEY_N);
    int handbrake = this->_eventReceiver->IsKeyDown(irr::KEY_SPACE);
    int valueY = ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 0 :
                 ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) && !this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? -1 :
                 (!this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 1 : 0;
    this->_motor->OnFrame(throttle, brake, handbrake, valueY);
    if (this->_eventReceiver->IsKeyDown(irr::KEY_UP)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0.5, 0, 0));
    } else if (this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(-0.5, 0, 0));
    } else {

    }
    if (this->_eventReceiver->IsKeyDown(irr::KEY_LEFT)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0, 0, 0.5));
    }
    if (this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0, 0, -0.5));
    }
}

irr::core::vector3d<float>	Car::getPosition() const {
    return _carModel.getPosition();
}


AGameCamera *Car::getCamera() const {
    return this->_camera;
}
