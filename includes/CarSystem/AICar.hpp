//
// AICar.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/includes/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:30:32 2017 Sousa Victor
// Last update Thu May 25 18:39:53 2017 Sousa Victor
//

#ifndef AICAR_HPP_
#define AICAR_HPP_

#include <unordered_map>
#include <sstream>
#include <iostream>
#include "Car.hpp"
#include "Utils.hpp"

namespace indie {

    class AICar : public Car {

    public:
        AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no = 0);
        ~AICar();

        virtual void OnFrame();

    private:
        btCollisionWorld::ClosestRayResultCallback *processHit(const core::vector3df &dir);

    };

}

#endif /*AICAR_HPP_*/
