//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Sun May 14 02:52:57 2017 Ethan Kerdelhue
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car,
      const irr::core::vector3df& position, const irr::core::vector3df& rotation, const irr::core::vector3df& scale)
      : AGameCamera(sceneManager, parent, id, position, rotation, scale) {

    irr::scene::ICameraSceneNode  *camera1 = this->_smgr->getActiveCamera();
    this->_camera = this->_smgr->addCameraSceneNode(0, position,  irr::core::vector3df(2, 36, 0));
    _camera->setPosition(irr::core::vector3df(-200, 125, 0));
    this->_smgr->setActiveCamera(camera1);
}

Minimap::~Minimap()
{

}

void Minimap::OnFrame() {

}
