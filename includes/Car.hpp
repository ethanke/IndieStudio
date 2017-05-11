//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:14:16 2017 Sousa Victor
// Last update Fri May 12 00:27:30 2017 Sousa Victor
//

#ifndef CAR_HPP_
#define CAR_HPP_

#include "BasicCamera.hpp"
#include "CarModel.hpp"
#include "EventDelegate.hpp"

namespace indie {

    class Car : public IGameObject, public EventDelegate {

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
