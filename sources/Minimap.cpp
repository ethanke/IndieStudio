//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Sun May 14 01:33:43 2017 Ethan Kerdelhue
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car,
      irr::IrrlichtDevice *device,
      const irr::core::vector3df& position,
      const irr::core::vector3df& rotation,
      const irr::core::vector3df& scale) : AGameCamera(sceneManager, parent, id, position, rotation, scale) {
    _camera1 = _device->getSceneManager()->getActiveCamera();
    if (_device->getVideoDriver()->queryFeature(irr::video::EVDF_RENDER_TO_TARGET))
    {
        _tMap = _device->getVideoDriver()->addRenderTargetTexture(irr::core::dimension2d<irr::u32>(200,200), "RTT1");
       _camera2 = _device->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(10,10,-80),
            irr::core::vector3df(-10,10,-100));
    }
}

Minimap::~Minimap()
{

}

void Minimap::OnFrame() {

}

void Minimap::setCamera(irr::scene::ICameraSceneNode* camera)
{
   _camera2 = camera;
}
void Minimap::createMap()
{
    // draw scene into render target

    // set render target texture
    _device->getVideoDriver()->setRenderTarget(_tMap);

    _device->getSceneManager()->setActiveCamera(_camera2);

    // draw whole scene into render buffer
    _device->getSceneManager()->drawAll();

    // set back old render target
    // The buffer might have been distorted, so clear it
    _device->getVideoDriver()->setRenderTarget(0, true, true, 0);

    _device->getSceneManager()->setActiveCamera(_camera1);
}

void Minimap::displayMap()
{
    _device->getVideoDriver()->draw2DImage(_tMap, irr::core::position2d<irr::s32>(50,50), //position to draw the minimap on screen
    irr::core::rect<irr::s32>(0,0,200,200), 0,
    irr::video::SColor(255,255,255,255), true);
}
