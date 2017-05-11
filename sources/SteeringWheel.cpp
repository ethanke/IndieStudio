//
// SteeringWheel.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Wed May 10 23:26:18 2017 Ethan Kerdelhue
// Last update Thu May 11 21:22:24 2017 Ethan Kerdelhue
//

#include "SteeringWheel.hpp"

using namespace indie;

SteeringWheel::SteeringWheel(irr::scene::ISceneManager *sceneManager, std::string const &path, irr::scene::ISceneNode *parent , irr::s32 id,
    const irr::core::vector3df &position,
    const irr::core::vector3df &rotation,
    const irr::core::vector3df &scale) : AModelObject(sceneManager, path, parent, id, position, rotation, scale) {

      this->_node->setRotation(irr::core::vector3df(90, 0, 0));

}

SteeringWheel::~SteeringWheel() {

}


void SteeringWheel::OnFrame() {
  static bool dir = false;
    static irr::f32 i = 0.0f;

    if (dir) {
      i += 0.01f;
    } else {
      i -= 0.01f;
    }
    if (i > 1 || i < -1) {
      dir = !dir;
    }
    irr::core::vector3df steeringRotation = this->_node->getRotation();
    irr::core::vector3df steeringPosition = this->_node->getPosition();
    irr::core::vector3df steeringForward = this->_node->getRotation().rotationToDirection();
    std::cout << "Ma vie est chouette : " << steeringForward.X << " " << steeringForward.Y << " " << steeringForward.Z << std::endl;
    irr::core::quaternion test;
    test.fromAngleAxis(i, irr::core::vector3df(steeringForward.X, steeringForward.Y, steeringForward.Z));
    test.normalize();
    irr::core::vector3df rot;
    rot.X = rot.X + steeringForward.X;
    rot.Z = rot.Z + steeringForward.Z;
    rot.Z = rot.Z + steeringForward.Z;
    test.toEuler(rot);
    this->_node->setRotation(rot * irr::core::RADTODEG);
    std::cout << "Ma vie est nul : " << rot.X << " " << rot.Y << " " << rot.Z << std::endl;
}
