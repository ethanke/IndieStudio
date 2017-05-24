//
// AICar.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/includes/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:30:32 2017 Sousa Victor
// Last update Wed May 24 20:33:21 2017 Sousa Victor
//

#ifndef AICAR_HPP_
#define AICAR_HPP_

#include "Car.hpp"

namespace indie {

    class AICar : public Car {

    public:
        AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no = 0);
        ~AICar();

    };

}

#endif /*AICAR_HPP_*/
