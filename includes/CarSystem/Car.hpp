//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:14:16 2017 Sousa Victor
// Last update Sat Jun 10 20:17:30 2017 Sousa Victor
//

#ifndef CAR_HPP_
#define CAR_HPP_

#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "BasicCamera.hpp"
#include "EventReceiver.hpp"
#include "Circuit.hpp"
#include "Client.hpp"
#include "loadCar.h"

namespace indie {

    class Car : public AGameObject {

    public:
        Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, Circuit const &circuit, int car_no = 0,
            irr::core::vector3df position = irr::core::vector3df(-9, 40, 0), bool isAI = false);
        ~Car();

        virtual void OnFrame();

        virtual AGameCamera *getCamera() const;
        virtual irr::core::vector3d<float> getPosition() const;
        void setPosition(irr::core::vector3df &pos);
        virtual irr::core::vector3d<float> getRotation() const;
        void setRotation(irr::core::vector3df &rot);
        virtual irr::f32 getVel() const;
        virtual irr::f32 getMaxSpeed() const;
        void mustSendData(bool value);

        virtual irr::core::vector3df const getAngularVelocity() const;
        void setAngularVelocity(irr::core::vector3df const &vec);
        virtual irr::core::vector3df const getLinearVelocity() const;
        void setLinearVelocity(irr::core::vector3df const &vec);
        float getEngineForce(void) const;
        void setEngineForce(float newForce);
        float getBreakingForce(void) const;
        void setBreakingForce(float newForce);
        float getSteeringValue(void) const;
        void setSteeringValue(float newForce);


    protected:
        physics::CBulletPhysics* _bulletPhysicsSystem;
        EventReceiver *_eventReceiver;
        irr::gui::IGUIEnvironment* _gui;

        Circuit const _circuit;

        int _car_no;
        bool _isAI;
        CLoadCar _carLoader;
        physics::PhysicsCar* _car;
        irr::s32 drive_tipe;

        bool reverse;
        bool _lookback;
        bool _mustSendData;
        irr::f32 _elapsedTime;

        BasicCamera *_camera;
        core::vector3df _cameraPosition;
        float _cameraHeight;
        float _baseCameraDistance;

        virtual void KeyboardEvent();
        virtual void updateCamera();

    };

}

#endif /*CAR_HPP_*/
