//
// Minimap.cpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 22:28:14 2017 Ethan Kerdelhue
// Last update Sun May 14 02:19:50 2017 Sousa Victor
//

#include "Minimap.hpp"

using namespace indie;

Minimap::Minimap(irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car,
      irr::video::IVideoDriver *driver, const irr::core::vector3df& position, const irr::core::vector3df& rotation,
      const irr::core::vector3df& scale) : AGameCamera(sceneManager, parent, id, position, rotation, scale) {

    _driver = driver;
    _camera1 = this->_smgr->getActiveCamera();
    _camera = this->_smgr->addCameraSceneNode(0, position,  irr::core::vector3df(2, 36, 0));
    _camera->setPosition(irr::core::vector3df(-200, 125, 0));
    //_camera->setRotation(irr::core::vector3df(2, 36, 0));
    this->_smgr->setActiveCamera(_camera1);
}

Minimap::~Minimap()
{

}

void Minimap::OnFrame() {

}

void Minimap::Init() {
    if (_driver->queryFeature(irr::video::EVDF_RENDER_TO_TARGET))
    {
        _tMap = _driver->addRenderTargetTexture(irr::core::dimension2d<irr::u32>(_viewport.getWidth(), _viewport.getHeight()), "RTT1");
   } else {
       std::cout << "can't render minimap on your pc" << std::endl;
   }
}

void Minimap::setCamera(irr::scene::ICameraSceneNode* camera)
{
   _camera = camera;
}
void Minimap::createMap()
{
    _driver->setRenderTarget(_tMap);

    this->_smgr->setActiveCamera(_camera);
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
