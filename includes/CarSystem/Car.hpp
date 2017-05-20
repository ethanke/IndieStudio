//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:14:16 2017 Sousa Victor
// Last update Sat May 20 21:59:51 2017 Sousa Victor
//

#ifndef CAR_HPP_
#define CAR_HPP_

#include "BasicCamera.hpp"
#include "EventReceiver.hpp"
#include "loadCar.h"

namespace indie {

    class Car : public AGameObject {

    public:
        Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no = 0);
        ~Car();

        void OnFrame();

        AGameCamera *getCamera() const;
        irr::core::vector3d<float> getPosition() const;

    protected:
        int m_car_no;
        CLoadCar loadCar;
        irr::s32 drive_tipe;
        physics::PhysicsCar* m_car;
        physics::CBulletPhysics* m_bulletPhysicsSystem;

        bool reverse;
        bool drive;
        bool park;

        BasicCamera *_camera;
        core::vector3df m_cameraPosition;
        float m_cameraHeight;
        float m_minCameraDistance;
        float m_maxCameraDistance;

        void KeyboardEvent();

        EventReceiver *_eventReceiver;

        void updateCamera();

    };

}

#endif /*CAR_HPP_*/
