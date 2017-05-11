//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Fri May 12 00:13:03 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world)
    : _carModel(sceneManager, "car/LamboRouge/LamboRouge.obj", world, NULL, -1, 1, irr::core::vector3df(2, 36, 0), irr::core::vector3df(194, 90, 190), irr::core::vector3df(1, 1, 1)) {

    this->_camera = new BasicCamera(sceneManager, 0, -1, irr::core::vector3df(-10, 42.5, 0), irr::core::vector3df(2, 36, 0));

}

Car::~Car() {

}

void Car::OnFrame() {

}

AGameCamera *Car::getCamera() const {
    return this->_camera;
}
