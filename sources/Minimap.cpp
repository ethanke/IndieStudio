//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Sat May 13 23:01:06 2017 Ethan Kerdelhue
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id,
      const irr::core::vector3df& position,
      const irr::core::vector3df& rotation,
      const irr::core::vector3df& scale) : AGameCamera(sceneManager, parent, id, position, rotation, scale)
{

}

Minimap::~Minimap()
{

}

void Minimap::OnFrame() {
  std::cout << " OnFrame::Minimap " << std::endl;
}
