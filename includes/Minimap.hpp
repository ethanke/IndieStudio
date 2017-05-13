//
// Minimap.hpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/sources/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Sat May 13 20:33:23 2017 Ethan Kerdelhue
// Last update Sat May 13 22:58:04 2017 Ethan Kerdelhue
//

#ifndef MINIMAP_HPP
  #define MINIMAP_HPP

#include "AGameCamera.hpp"

namespace indie {

  class Minimap : public AGameCamera {
  private:

  public:
    Minimap (irr::scene::ISceneManager *sceneManager, irr::scene::ISceneNode* parent, irr::s32 id,
          const irr::core::vector3df& position = irr::core::vector3df(0,0,0),
          const irr::core::vector3df& rotation = irr::core::vector3df(0,0,0),
                const irr::core::vector3df& scale = irr::core::vector3df(1.0f,1.0f,1.0f));
    virtual ~Minimap ();


    virtual void OnFrame();

  };
}


#endif
