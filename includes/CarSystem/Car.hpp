//
// Car.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:14:16 2017 Sousa Victor
// Last update Fri May 19 06:15:26 2017 Sousa Victor
//

#ifndef CAR_HPP_
#define CAR_HPP_

#include "BasicCamera.hpp"
#include "CarModel.hpp"
#include "EventReceiver.hpp"

namespace indie {

    class Car : public AGameObject {

    public:
        Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, std::shared_ptr<irrBulletWorld> world, EventReceiver *eventReceiver);
        ~Car();

        void OnFrame();

        AGameCamera *getCamera() const;
        irr::core::vector3d<float> getPosition() const;

    protected:
        irr::scene::IAnimatedMeshSceneNode *_carNode;
        IGImpactMeshShape *_carShape;
        IRigidBody *_carRigidBody;
        IRaycastVehicle *_vehicle;

        BasicCamera *_camera;
        EventReceiver *_eventReceiver;

    };

}

#endif /*CAR_HPP_*/
