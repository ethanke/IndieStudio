//
// CarModel.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_github/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 01:12:02 2017 Sousa Victor
// Last update Thu May 18 19:21:50 2017 Sousa Victor
//

#include "CarModel.hpp"

using namespace indie;

CarModel::CarModel() {

}

CarModel::CarModel(irr::scene::ISceneManager *sceneManager, std::string const &path,
    irr::scene::ISceneNode *parent, irr::s32 id, irr::f32 mass, const irr::core::vector3df &position,
    const irr::core::vector3df &rotation, const irr::core::vector3df &scale)
    : APhysicObject(sceneManager, path, parent, id, mass, position, rotation, scale) {

}

CarModel::~CarModel() {

}


void CarModel::OnFrame() {

}
