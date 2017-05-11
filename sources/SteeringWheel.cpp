//
// SteeringWheel.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Wed May 10 23:26:18 2017 Ethan Kerdelhue
// Last update Thu May 11 02:13:04 2017 Ethan Kerdelhue
//

#include "SteeringWheel.hpp"

using namespace indie;

SteeringWheel::SteeringWheel(irr::scene::ISceneManager *sceneManager, std::string const &path, irr::scene::ISceneNode *parent , irr::s32 id,
    const irr::core::vector3df &position,
    const irr::core::vector3df &rotation,
    const irr::core::vector3df &scale) : AModelObject(sceneManager, path, parent, id, position, rotation, scale) {


}

SteeringWheel::~SteeringWheel() {

}


void SteeringWheel::OnFrame() {

}
