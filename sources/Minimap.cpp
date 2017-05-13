//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Sun May 14 01:55:43 2017 Sousa Victor
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car,
      irr::video::IVideoDriver *driver, const irr::core::vector3df& position, const irr::core::vector3df& rotation,
      const irr::core::vector3df& scale) : AGameCamera(sceneManager, parent, id, position, rotation, scale) {

    _driver = driver;
}

Minimap::~Minimap()
{

}

void Minimap::OnFrame() {

}

void Minimap::Init() {
    std::cout << "start init\n";
    _camera1 = this->_smgr->getActiveCamera();
    if (_driver->queryFeature(irr::video::EVDF_RENDER_TO_TARGET))
    {
        _tMap = _driver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>(_viewport.getWidth(), _viewport.getHeight()), "RTT1");
       _camera2 = this->_smgr->addCameraSceneNode(0, irr::core::vector3df(10,10,-80), irr::core::vector3df(-10,10,-100));
   } else {
       std::cout << "can't render minimap on your pc" << std::endl;
   }
   std::cout << "end init\n";
}

void Minimap::setCamera(irr::scene::ICameraSceneNode* camera)
{
   _camera2 = camera;
}
void Minimap::createMap()
{
    _driver->setRenderTarget(_tMap);

    this->_smgr->setActiveCamera(_camera2);
    this->_driver->setViewPort(this->_viewport);
    this->_smgr->drawAll();
    _driver->setRenderTarget(0, true, true, 0);
    this->_smgr->setActiveCamera(_camera1);
}

void Minimap::displayMap()
{
    _driver->draw2DImage(_tMap, irr::core::position2d<irr::s32>(_viewport.UpperLeftCorner.X, _viewport.UpperLeftCorner.Y), //position to draw the minimap on screen
    irr::core::rect<irr::s32>(0,0,_viewport.getWidth(), _viewport.getHeight()), 0,
    irr::video::SColor(255,255,255,255), true);
}
