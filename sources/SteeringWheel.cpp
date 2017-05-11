//
// SteeringWheel.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Wed May 10 23:26:18 2017 Ethan Kerdelhue
// Last update Fri May 12 01:21:09 2017 Ethan Kerdelhue
//

#include "SteeringWheel.hpp"

using namespace indie;

SteeringWheel::SteeringWheel(irr::scene::ISceneManager *sceneManager, std::string const &path, std::shared_ptr<irrBulletWorld> world, irr::scene::ISceneNode *parent, irr::s32 id, irr::f32 mass,
    const irr::core::vector3df &position,
    const irr::core::vector3df &rotation,
    const irr::core::vector3df &scale) : APhysicObject(sceneManager, path, world, parent, id, mass, position, rotation, scale) {

      // this->_body->proceedToTransform(btVector3(90, 0, 0));
      // this->_body->setPosition(irr::core::vector3df(1, 50, 10));

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

    // irr::core::quaternion test;
    // test.set(irr::core::vector3df(this->_body->getRotation().rotationToDirection().X, this->_body->getRotation().rotationToDirection().Y, this->_body->getRotation().rotationToDirection().Z));
    // test.fromAngleAxis(i, irr::core::vector3df(this->_body->getRotation().rotationToDirection().X, this->_body->getRotation().rotationToDirection().Y, this->_body->getRotation().rotationToDirection().Z));
    // test.normalize();
    // irr::core::vector3df rot;
    // test.toEuler(rot);
    // std::cout << "rot rotation : Z : " << rot.Z * irr::core::RADTODEG << std::endl;
    // this->_body->setRotation(irr::core::vector3df((rot.X * irr::core::RADTODEG) , (rot.Y * irr::core::RADTODEG), (rot.Z * irr::core::RADTODEG)));

}
