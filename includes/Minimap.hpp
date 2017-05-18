//
// Minimap.hpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 20:33:23 2017 Ethan Kerdelhue
// Last update Thu May 18 19:28:21 2017 Sousa Victor
//

#ifndef MINIMAP_HPP
  #define MINIMAP_HPP

#include <iostream>
#include <IVideoDriver.h>
#include <IGeometryCreator.h>
#include "AGameObject.hpp"
#include "Car.hpp"

namespace indie {

  class Minimap : public AGameObject {

  public:
    Minimap (irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car, irr::video::IVideoDriver* driver, irr::IrrlichtDevice *device,
          const irr::core::vector3df& position = irr::core::vector3df(0,0,0),
          const irr::core::vector3df& rotation = irr::core::vector3df(0,0,0),
          const irr::core::vector3df& scale = irr::core::vector3df(1.0f,1.0f,1.0f));

    virtual ~Minimap ();
    virtual void OnFrame();

    virtual void setViewport(irr::core::rect<irr::s32> viewport) {
        this->_viewport = viewport;
    }
    virtual irr::core::rect<irr::s32> getViewport() const {
        return this->_viewport;
    }

    protected:
        irr::core::rect<irr::s32>     _viewport;
        Car                           *_car;
        irr::scene::ICameraSceneNode  *_camera;
        irr::scene::IMesh     *_plane;
        irr::scene::IMeshSceneNode *_plane_node;

  };
}

#endif
