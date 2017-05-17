//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Wed May 17 03:32:55 2017 Ethan Kerdelhue
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car, irr::video::IVideoDriver* driver, irr::IrrlichtDevice *device,
      const irr::core::vector3df& position, const irr::core::vector3df& rotation, const irr::core::vector3df& scale)
      : AGameObject(sceneManager) {
        this->_camera = sceneManager->getActiveCamera();
        this->_plane =  sceneManager->getGeometryCreator()->createPlaneMesh(irr::core::dimension2d<irr::f32>(0.00625f, 0.00625f), // Tile size
                              irr::core::dimension2d<irr::u32>(80,80), // Tile count
                              0, // Material
                              irr::core::dimension2d<irr::f32>(1.0f, 1.0f)); // textureRepeatCount

      this->_plane_node = sceneManager->addMeshSceneNode(this->_plane);
      this->_plane_node->setMaterialTexture(0, device->getVideoDriver()->getTexture("minimap.png"));
      this->_plane_node->setPosition(irr::core::vector3df(0,10,0));
      this->_plane_node->setRotation(irr::core::vector3df(0, 0, -90));
      // video::ITexture* images = driver->getTexture("../Assets/BigCity/minimap.png");
      // driver->draw2DImage(images, core::position2d<s32>(50,50),
      //           core::rect<s32>(0,0,342,224), 0,
      //           video::SColor(255,255,255,255), true);
}

Minimap::~Minimap()
{

}

// cameraRight = camera.direction cross (0, 1, 0)
// 0 -1 0
// camera getRotation to direction cross 0, -1 0

void Minimap::OnFrame() {
  this->_camera = this->_smgr->getActiveCamera();
  this->_plane_node->setPosition(this->_camera->getPosition() + this->_camera->getRotation().rotationToDirection() * irr::core::vector3df(1, 1, 1));
  this->_plane_node->setRotation(irr::core::vector3df(90, this->_camera->getRotation().Y + 180, this->_camera->getRotation().Z));

  irr::core::vector3df down = this->_camera->getRotation().rotationToDirection().crossProduct(this->_camera->getRotation().rotationToDirection().crossProduct(irr::core::vector3df(0, 1, 0)));
  this->_plane_node->setPosition(this->_plane_node->getPosition() + irr::core::vector3df(1, 1, 1) * this->_camera->getRotation().rotationToDirection().crossProduct(irr::core::vector3df(0, 1, 0)));
  this->_plane_node->setPosition(this->_plane_node->getPosition() + irr::core::vector3df(0.43, 0.43, 0.43) * down);
  std::cout << this->_camera->getPosition().X <<  " " << this->_camera->getPosition().Y << " " << this->_camera->getPosition().Z << std::endl;
  std::cout << this->_plane_node->getPosition().X <<  " " << this->_plane_node->getPosition().Y << " " << this->_plane_node->getPosition().Z << std::endl << std::endl;

}
