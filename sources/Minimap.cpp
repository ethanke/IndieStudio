//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Tue May 16 18:50:58 2017 Ethan Kerdelhue
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car,
      const irr::core::vector3df& position, const irr::core::vector3df& rotation, const irr::core::vector3df& scale)
      : AGameCamera(sceneManager, parent, id, position, rotation, scale) {

      //   irr::scene::IAnimatedMesh *terrain_model = sceneManager->addHillPlaneMesh("groundPlane", // Name of the scenenode
      //                         irr::core::dimension2d<irr::f32>(50.0f, 50.0f), // Tile size
      //                         irr::core::dimension2d<irr::u32>(80, 80), // Tile count
      //                         0, // Material
      //                         0.0f, // Hill height
      //                         irr::core::dimension2d<irr::f32>(0.0f, 0.0f), // countHills
      //                         irr::core::dimension2d<irr::f32>(80.0f, 80.0f)); // textureRepeatCount
      //
      // irr::scene::IAnimatedMeshSceneNode * terrain_node = sceneManager->addAnimatedMeshSceneNode(terrain_model);
      // terrain_node->setPosition(irr::core::vector3df(0,0,0));
}

Minimap::~Minimap()
{

}

void Minimap::OnFrame() {

}
