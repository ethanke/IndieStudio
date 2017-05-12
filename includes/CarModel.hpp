//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_github/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 01:10:00 2017 Sousa Victor
// Last update Fri May 12 03:03:36 2017 Sousa Victor
//

#ifndef CARMODEL_HPP_
#define CARMODEL_HPP_

#include "APhysicObject.hpp"

namespace indie {

    class CarModel: public APhysicObject {

    public:
        CarModel(irr::scene::ISceneManager *sceneManager, std::string const &path, std::shared_ptr<irrBulletWorld> world,
            irr::scene::ISceneNode *parent = 0, irr::s32 id = -1, irr::f32 mass = 10,
            const irr::core::vector3df &position = irr::core::vector3df(0,0,0),
            const irr::core::vector3df &rotation = irr::core::vector3df(0,0,0),
            const irr::core::vector3df &scale = irr::core::vector3df(1.0f, 1.0f, 1.0f));
        ~CarModel();

        void OnFrame();

        IRigidBody *getBody() const {
            return this->_body;
        }

    };

}

#endif /*CARMODEL_HPP_*/
