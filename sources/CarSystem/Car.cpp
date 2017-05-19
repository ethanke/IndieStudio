//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Fri May 19 06:15:44 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, std::shared_ptr<irrBulletWorld> world, EventReceiver *eventReceiver):
    AGameObject(sceneManager) {

    this->_eventReceiver = eventReceiver;
    this->_camera = new BasicCamera(this->_smgr, 0, -1, irr::core::vector3df(-10, 42.5, 0), irr::core::vector3df(2, 36, 0));

    this->_carNode = this->_smgr->addAnimatedMeshSceneNode(this->_smgr->getMesh("car/Car/SV.obj"));
    this->_carNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    this->_carNode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    this->_carNode->addShadowVolumeSceneNode();
    this->_carNode->setPosition(irr::core::vector3df(2, 36, 0));
    this->_carNode->setRotation(irr::core::vector3df(180, 82.5, 175));

    this->_carShape = new IGImpactMeshShape(this->_carNode, this->_carNode->getMesh(), 800.0); // Tweak with mass a bit
    this->_carRigidBody = world->addRigidBody(this->_carShape);
    this->_carRigidBody->includeNodeOnRemoval(false);

    this->_carRigidBody->setDamping(0.45, 0.45);
    this->_carRigidBody->setFriction(7.0f);

    this->_vehicle = world->addRaycastVehicle(this->_carRigidBody);

    // Create wheel info
    SWheelInfoConstructionInfo wheel;
    wheel.wheelDirectionCS = irr::core::vector3df(0.0, -1.0, 0.0);
    wheel.wheelAxleCS = irr::core::vector3df(-0.5, 0.0, 0.0);
    wheel.suspensionRestLength = 0.30;
    wheel.wheelRadius = 0.230;
    wheel.wheelDirectionCS = irr::core::vector3df(0.0, -1.0, 0.0);

    // Left wheels
    wheel.chassisConnectionPointCS = irr::core::vector3df(-1, 0, 1);//this->_carNode->getJointNode("Tire_FL_joint")->getPosition();
    wheel.isFrontWheel = true;
    this->_vehicle->addWheel(wheel); // Add left front wheel

    wheel.isFrontWheel = false;
    wheel.chassisConnectionPointCS = irr::core::vector3df(-1, 0, -1);//this->_carNode->getJointNode("Tire_BL_joint")->getPosition();
    this->_vehicle->addWheel(wheel); // Add left back wheel

    // Right wheels
    wheel.wheelAxleCS.X = -wheel.wheelAxleCS.X; // Invert the wheel direction for right side

    wheel.chassisConnectionPointCS = irr::core::vector3df(1, 0, 1);//this->_carNode->getJointNode("Tire_FR_joint")->getPosition();
    wheel.isFrontWheel = true;
    this->_vehicle->addWheel(wheel); // Add left front wheel

    wheel.isFrontWheel = false;
    wheel.chassisConnectionPointCS = irr::core::vector3df(1, 0, -1);//this->_carNode->getJointNode("Tire_BR_joint")->getPosition();
    this->_vehicle->addWheel(wheel); // Add left back wheel

    wheel.isFrontWheel = false;
    irr::f32 wheelAxleCSX = -wheel.wheelAxleCS.X;

    // Tweak wheel info a bit, tweak here more
    for (irr::u32 i = 0; i < this->_vehicle->getNumWheels(); i++) {
            SWheelInfo& info = this->_vehicle->getWheelInfo(i);
            info.suspensionStiffness = 0.15f;
            info.wheelDampingRelaxation = 2.3f;
            info.wheelDampingCompression = 4.4f;
            info.frictionSlip = 1000;
            info.rollInfluence = 0.1f;
            this->_vehicle->updateWheelInfo(i);
    }
    this->_carRigidBody->setVehicleReference(this->_vehicle);

}

Car::~Car() {

}

void Car::OnFrame() {
    int valueX = ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 0 :
                 ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) && !this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 1 :
                 (!this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? -1 : 0;
    int valueY = ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 0 :
                 ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) && !this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? -1 :
                 (!this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 1 : 0;

    for(irr::u32 i=0; i < _vehicle->getNumWheels(); i++)
    {
        std::cout << "tire " << i << std::endl;
        if(_vehicle->getWheelInfo(i).raycastInfo.isInContact) {
            std::cout << "tire " << i << "TOUCH" << std::endl;
            _vehicle->applyEngineForce(3000, i);
        }
    }

    if (this->_eventReceiver->IsKeyDown(irr::KEY_UP)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0.5, 0, 0));
    } else if (this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(-0.5, 0, 0));
    } else {

    }
    if (this->_eventReceiver->IsKeyDown(irr::KEY_LEFT)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0, 0, 0.5));
    }
    if (this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) {
        this->_camera->getCamera()->setPosition(this->_camera->getCamera()->getPosition() + irr::core::vector3df(0, 0, -0.5));
    }
}

irr::core::vector3d<float>	Car::getPosition() const {
    return _carNode->getPosition();
}


AGameCamera *Car::getCamera() const {
    return this->_camera;
}
