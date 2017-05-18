//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:14:16 2017 Sousa Victor
// Last update Thu May 18 19:23:57 2017 Sousa Victor
//

#ifndef CAR_HPP_
#define CAR_HPP_

#include "BasicCamera.hpp"
#include "CarModel.hpp"
#include "CarMotor.hpp"
#include "EventReceiver.hpp"

namespace indie {

    class Car : public IGameObject {

    public:
        Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver);
        ~Car();

        void OnFrame();

        AGameCamera *getCamera() const;
        irr::core::vector3d<float> getPosition() const;

    protected:
        CarModel _carModel;
        CarMotor *_motor;
        BasicCamera *_camera;
        EventReceiver *_eventReceiver;

    };

}

#endif /*CAR_HPP_*/
