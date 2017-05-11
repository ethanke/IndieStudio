//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_github/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 01:12:02 2017 Sousa Victor
// Last update Thu May 11 01:53:02 2017 Ethan Kerdelhue
//

#include "CarModel.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, std::string const &path, std::shared_ptr<irrBulletWorld> world,
    irr::scene::ISceneNode *parent, irr::s32 id, irr::f32 mass, const irr::core::vector3df &position,
    const irr::core::vector3df &rotation, const irr::core::vector3df &scale)
    : APhysicObject(sceneManager, path, world, parent, id, mass, position, rotation, scale) {

}

Car::~Car() {

}


void Car::OnFrame() {

}
