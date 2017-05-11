//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:14:16 2017 Sousa Victor
// Last update Thu May 11 23:47:47 2017 Sousa Victor
//

#ifndef CAR_HPP_
#define CAR_HPP_

#include "BasicCamera.hpp"
#include "CarModel.hpp"

namespace indie {

    class Car : public IGameObject {

    public:
        Car(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world);
        ~Car();

        void OnFrame();

        AGameCamera *getCamera() const;

    protected:
        CarModel _carModel;
        BasicCamera *_camera;

    };

}

#endif /*CAR_HPP_*/
