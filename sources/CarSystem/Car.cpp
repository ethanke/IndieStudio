//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Sun Jun 11 00:09:31 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, Circuit const &circuit, int car_no,
         irr::core::vector3df position, bool isAI):
    AGameObject(sceneManager), _circuit(circuit) {

    this->_gui = guiManager;
    this->_eventReceiver = eventReceiver;
    this->_bulletPhysicsSystem = bulletPhysicsSystem;

    for (auto check : this->_circuit.getCheckpoints()) {
        check.setChVisible(true);
    }

    this->_cameraPosition = core::vector3df(30, 30, 30);
	this->_cameraHeight = 3.5f;
	this->_baseCameraDistance = 6.0f;
    this->_elapsedTime = 0;

    this->_isAI = isAI;
    if (!this->_isAI) {
        this->_camera = new BasicCamera(this->_smgr, 0, -1, irr::core::vector3df(-4, 38, 0), irr::core::vector3df(2, 36, 0));
        this->_camera->setFarValue(500);
    }

    this->reverse = false;
    this->_lookback = false;
    this->_mustSendData = false;

    this->_car_no = car_no;
    if (this->_isAI == false)
        Client::Instance().setCarNo(car_no);
    this->_carLoader.setCarPos(position);
	this->_carLoader.Init(this->_smgr, this->_bulletPhysicsSystem, this->_car_no);

	this->_car = this->_carLoader.getCar();
    drive_tipe = this->_carLoader.returnDrive();

}

Car::~Car() {
    delete this->_car;
    if (!this->_isAI) {
        delete this->_camera;
    }
}

void Car::OnFrame() {
    KeyboardEvent();
    if (!this->_isAI) {
        updateCamera();
        if (this->_elapsedTime >= 1) {
            if (this->_mustSendData == true)
                Client::Instance().sendPosAndRota(this->getPosition(), this->getRotation());
            this->_elapsedTime = 0;
        } else {
            this->_elapsedTime += DeltaTimer::DeltaTime;
        }
    }
    if (!this->_isAI && this->_mustSendData == true && this->_elapsedTime >= 0.01) {
        Client::Instance().sendEngineData(getLinearVelocity(), getAngularVelocity(), this->_car->getEngineForce(), this->_car->getBreakingForce(), this->_car->getSteeringValue());
        this->_elapsedTime1 = 0;
    } else if (this->_elapsedTime1 < 0.01)
        this->_elapsedTime1 += DeltaTimer::DeltaTime;

	this->_carLoader.Update(drive_tipe);
}

void Car::updateCamera() {
	core::vector3df targetPos = this->_car->getPosition();
    core::vector3df targetRot = this->_car->getRotation();
    core::vector3df targetdir = targetRot.rotationToDirection().normalize();

    if (this->_lookback == false)
        this->_cameraPosition = irr::core::vector3df(targetPos.X, targetPos.Y + this->_cameraHeight + this->_car->getlinVel() / 70, targetPos.Z) + -targetdir * (this->_baseCameraDistance + this->_car->getlinVel() / 35);
    else
        this->_cameraPosition = irr::core::vector3df(targetPos.X, targetPos.Y + this->_cameraHeight + this->_car->getlinVel() / 70, targetPos.Z) + targetdir * (this->_baseCameraDistance + this->_car->getlinVel() / 35);

	this->_camera->setPosition(this->_cameraPosition);
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
    if(_eventReceiver->IsKeyDown(irr::KEY_KEY_C)) {
		this->_lookback = true;
	} else {
        this->_lookback = false;
    }
	if(_eventReceiver->IsKeyDown(irr::KEY_BACK))
	{
		this->_carLoader.resetCar(0); // 90
	}

}

irr::core::vector3d<float>	Car::getPosition() const {
    return this->_car->getPosition();
}

void Car::setPosition(irr::core::vector3df &pos) {
    this->_car->setPosition(pos);
}

irr::core::vector3d<float>	Car::getRotation() const {
    return this->_car->getRotation(false);
}

void Car::setRotation(irr::core::vector3df &rot) {
    this->_car->setRotation(rot);
}

AGameCamera *Car::getCamera() const {
    return this->_camera;
}

irr::f32 Car::getVel() const {
    return this->_car->getlinVel();
}

irr::f32 Car::getMaxSpeed() const {
    return this->_carLoader.getMaxSpeed();
}

void Car::mustSendData(bool value) {
    this->_mustSendData = value;
}

irr::core::vector3df const Car::getAngularVelocity() const {
    return this->_car->getAngularVelocity();
}
irr::core::vector3df const Car::getLinearVelocity() const {
    return this->_car->getLinearVelocity();
}
void Car::setAngularVelocity(irr::core::vector3df const &vec) {
    this->_car->setAngularVelocity(vec);
}
void Car::setLinearVelocity(irr::core::vector3df const &vec) {
    this->_car->setLinearVelocity(vec);
}
float Car::getEngineForce(void) const {
    return this->_car->getEngineForce();
}
void Car::setEngineForce(float newForce) {
    this->_car->setEngineForce(newForce);
}
float Car::getBreakingForce(void) const {
    return this->_car->getBreakingForce();
}
void Car::setBreakingForce(float newForce) {
    this->_car->setBreakingForce(newForce);
}
float Car::getSteeringValue(void) const {
    return this->_car->getSteeringValue();
}
void Car::setSteeringValue(float newForce) {
    this->_car->setSteeringValue(newForce);
}
int Car::getCarNo() const {
    return this->_car_no;
}
