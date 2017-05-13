//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Sat May 13 23:57:45 2017 Sousa Victor
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id,
      const irr::core::vector3df& position,
      const irr::core::vector3df& rotation,
      const irr::core::vector3df& scale) : AGameCamera(sceneManager, parent, id, position, rotation, scale) {

    this->_camera = this->_smgr->addCameraSceneNode (parent, position);
    this->_viewport = irr::core::rect<irr::s32>(0, 0, 150, 150);

}

Minimap::~Minimap()
{

}

void Minimap::OnFrame() {
  std::cout << " OnFrame::Minimap " << std::endl;
}
