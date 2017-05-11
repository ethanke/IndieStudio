//
// SteeringWheel.hpp for  in /Users/ethankerdelhue/Documents/shared/IndieStudio/includes/
//
// Made by Ethan Kerdelhue
// Login   <ethan.kerdelhue@epitech.eu@epitech.eu>
//
// Started on  Wed May 10 23:22:20 2017 Ethan Kerdelhue
// Last update Thu May 11 19:16:41 2017 Ethan Kerdelhue
//

#ifndef STEERINGWHELL_HPP
#define STEERINGWHELL_HPP

#include "AModelObject.hpp"

namespace indie {

    class SteeringWheel: public AModelObject {
    private:

    public:
      SteeringWheel(irr::scene::ISceneManager *sceneManager, std::string const &path = "", irr::scene::ISceneNode *parent = 0, irr::s32 id = -1,
          const irr::core::vector3df &position = irr::core::vector3df(0,0,0),
          const irr::core::vector3df &rotation = irr::core::vector3df(0,0,0),
          const irr::core::vector3df &scale = irr::core::vector3df(1.0f, 1.0f, 1.0f));
      ~SteeringWheel();

      void OnFrame();
    };
}

#endif /* !STEERINGWHELL_HPP */
