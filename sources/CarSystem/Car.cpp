//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Tue May 23 02:36:46 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    AGameObject(sceneManager) {

    this->_eventReceiver = eventReceiver;
    this->_bulletPhysicsSystem = bulletPhysicsSystem;

    m_cameraPosition = core::vector3df(30, 30, 30);
	m_cameraHeight = 1.5f;
	m_baseCameraDistance = 6.0f;

	this->_camera = new BasicCamera(this->_smgr, 0, -1, irr::core::vector3df(-4, 38, 0), irr::core::vector3df(2, 36, 0));
    this->_camera->setFarValue(500);

    reverse = false;
	drive = true;
	park = false;

    m_car_no = car_no;
    this->_carLoader.setCarPos(irr::core::vector3df(2, 38, 0));
	this->_carLoader.Init(this->_smgr, this->_bulletPhysicsSystem, m_car_no);

	this->_car = this->_carLoader.getCar();
    drive_tipe = this->_carLoader.returnDrive();

}

Car::~Car() {

}

void Car::OnFrame() {
    KeyboardEvent();
    updateCamera();
	this->_carLoader.Update(drive_tipe);
}

void Car::updateCamera() {
	// look at the vehicle
	core::vector3df targetPos = this->_car->getPosition();
    core::vector3df targetRot = this->_car->getRotation();
    core::vector3df targetdir = targetRot.rotationToDirection().normalize();

    m_cameraPosition = irr::core::vector3df(targetPos.X, targetPos.Y + m_cameraHeight + this->_car->getlinVel() / 110, targetPos.Z) + -targetdir * (m_baseCameraDistance + this->_car->getlinVel() / 50);
    //m_cameraPosition = targetPos + -targetdir * 0.01;

	this->_camera->setPosition(m_cameraPosition);
	this->_camera->setTarget(targetPos);
}

void Car::KeyboardEvent() {
	//steering
	if(_eventReceiver->IsKeyDown(irr::KEY_UP)) {
		if(!reverse)
			this->_car->goForward();
		else
			this->_car->goBackwards();
	} else {
        this->_car->slowdown();
    }

    if(_eventReceiver->IsKeyDown(irr::KEY_DOWN)) {
		this->_car->stop();
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_LEFT)) {
		this->_car->steerLeft();
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) {
		this->_car->steerRight();
	}
	else if(!_eventReceiver->IsKeyDown(irr::KEY_LEFT) && !_eventReceiver->IsKeyDown(irr::KEY_RIGHT))
		this->_car->resetSteering();

	if(_eventReceiver->IsKeyDown(irr::KEY_SPACE)) {
		this->_car->handbrake();
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_KEY_R)) {
		reverse = true;
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_KEY_D)) {
		reverse = false;
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_BACK))
	{
		this->_carLoader.resetCar(0); // 90
	}

}

irr::core::vector3d<float>	Car::getPosition() const {
    return this->_car->getPosition();
}


AGameCamera *Car::getCamera() const {
    return this->_camera;
}

irr::f32 Car::getVel() const {
    return this->_car->getlinVel();
}
