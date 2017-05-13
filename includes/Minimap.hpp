//
// Minimap.hpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 20:33:23 2017 Ethan Kerdelhue
// Last update Sun May 14 01:53:04 2017 Sousa Victor
//

#ifndef MINIMAP_HPP
  #define MINIMAP_HPP

#include "AGameCamera.hpp"
#include "Car.hpp"

namespace indie {

  class Minimap : public AGameCamera {

  public:
    Minimap (irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id, Car *car,
          irr::video::IVideoDriver* driver,
          const irr::core::vector3df& position = irr::core::vector3df(0,0,0),
          const irr::core::vector3df& rotation = irr::core::vector3df(0,0,0),
          const irr::core::vector3df& scale = irr::core::vector3df(1.0f,1.0f,1.0f));

    virtual ~Minimap ();
    virtual void OnFrame();
    virtual void setCamera(irr::scene::ICameraSceneNode* camera);
    virtual void Init();
    virtual void createMap();
    virtual void displayMap();

    virtual void setViewport(irr::core::rect<irr::s32> viewport) {
        this->_viewport = viewport;
    }
    virtual irr::core::rect<irr::s32> getViewport() const {
        return this->_viewport;
    }

    protected:
        irr::core::rect<irr::s32>     _viewport;
        Car                           *_car;
        irr::video::IVideoDriver* _driver;
        irr::video::ITexture          *_tMap;
        irr::scene::ICameraSceneNode  *_camera1;
        irr::scene::ICameraSceneNode  *_camera2;

  };
}


#endif
