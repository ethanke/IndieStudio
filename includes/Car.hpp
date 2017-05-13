//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:14:16 2017 Sousa Victor
// Last update Fri May 12 13:16:00 2017 Sousa Victor
//

#ifndef CAR_HPP_
#define CAR_HPP_

#include "BasicCamera.hpp"
#include "CarModel.hpp"
#include "EventReceiver.hpp"
#include "SteeringWheel.hpp"

#include "GameCube.hpp"

namespace indie {

    class Car : public IGameObject {

    public:
        Car();
        Car(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world, EventReceiver *eventReceiver);
        ~Car();

        void OnFrame();

        AGameCamera *getCamera() const;

    protected:
        CarModel _carModel;
        BasicCamera *_camera;
        EventReceiver *_eventReceiver;

    };

}

#endif /*CAR_HPP_*/
