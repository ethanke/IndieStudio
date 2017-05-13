//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Fri May 12 18:15:59 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car() {
    
}

Car::Car(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world, EventReceiver *eventReceiver)
    : _carModel(sceneManager, "car/car1/Smallcar.obj", world, NULL, -1, 100, irr::core::vector3df(2, 36, 0), irr::core::vector3df(180, 82.5, 175), irr::core::vector3df(1, 1, 1)) {

    this->_eventReceiver = eventReceiver;
    this->_camera = new BasicCamera(sceneManager, 0, -1, irr::core::vector3df(-10, 42.5, 0), irr::core::vector3df(2, 36, 0));

    //SteeringWheel *steeringwheel = new SteeringWheel(sceneManager, std::string("car/steeringwheel.obj"), world, this->_camera->getCamera(), -1, 0, irr::core::vector3df(2, 40, 0), irr::core::vector3df(0, 0, 0), irr::core::vector3df(1, 1, 1));
}

Car::~Car() {

}

void Car::OnFrame() {
    std::cout << this->_carModel.getPosition().X << " " << this->_carModel.getPosition().Y << " " << this->_carModel.getPosition().Z << std::endl;

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

AGameCamera *Car::getCamera() const {
    return this->_camera;
}
