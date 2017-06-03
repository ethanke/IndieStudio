//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Thu Jun  1 22:38:35 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no,
         irr::core::vector3df position, bool isAI):
    AGameObject(sceneManager) {

    this->_gui = guiManager;
    this->_eventReceiver = eventReceiver;
    this->_bulletPhysicsSystem = bulletPhysicsSystem;

    this->_cameraPosition = core::vector3df(30, 30, 30);
	this->_cameraHeight = 5.5f;
	this->_baseCameraDistance = 6.0f;

    this->_isAI = isAI;
    if (!this->_isAI) {
        this->_camera = new BasicCamera(this->_smgr, 0, -1, irr::core::vector3df(-4, 38, 0), irr::core::vector3df(2, 36, 0));
        this->_camera->setFarValue(500);
    }

    reverse = false;

    this->_car_no = car_no;
    this->_carLoader.setCarPos(position);
	this->_carLoader.Init(this->_smgr, this->_bulletPhysicsSystem, this->_car_no);

	this->_car = this->_carLoader.getCar();
    drive_tipe = this->_carLoader.returnDrive();

    // myfile.open ("car.txt");
    // myfile << "topology: 12 15 10 3 " << std::endl;

}

Car::~Car() {
    delete this->_car;
    if (!this->_isAI) {
        delete this->_camera;
    }
    //myfile.close();
}
//
// core::vector3df rotateByAngle3(const core::vector3df &vec, const core::vector3df &up, float angle) {
//     core::quaternion rotation;
//     rotation.fromAngleAxis(angle, up);
//     return rotation * vec;
// }
//
// btCollisionWorld::ClosestRayResultCallback *Car::processHit(const core::vector3df &dir) {
//     core::vector3df pos = this->_car->getPosition();
//     core::vector3df lkt = pos + dir * 250;
//
//     btVector3 btFrom(pos.X, pos.Y, pos.Z);
//     btVector3 btTo(lkt.X, lkt.Y, lkt.Z);
//     btCollisionWorld::ClosestRayResultCallback *res = new btCollisionWorld::ClosestRayResultCallback(btFrom, btTo);
//     this->_bulletPhysicsSystem->getDynamicsWorld()->rayTest(btFrom, btTo, *res);
//     return res;
// }

void Car::OnFrame() {
    // std::unordered_map<std::string, btCollisionWorld::ClosestRayResultCallback*> hitMap;
    // core::vector3df rot = this->_car->getRotation();
    // core::vector3df dir = rot.rotationToDirection().normalize();
    // core::vector3df right  = dir.crossProduct(core::vector3df(0, 1, 0));
    // core::vector3df up = right.crossProduct(dir);
    // core::vector3df checkPointDir = (core::vector3df(100, 0, 0) - this->_car->getPosition()).normalize();
    // std::vector<double> outputData;
    // outputData.push_back(up.X);
    // outputData.push_back(up.Y);
    // outputData.push_back(up.Z);
    // outputData.push_back(getVel());
    // hitMap[std::to_string(0.0)] = processHit(dir);
    // hitMap[std::to_string(-0.0)] = processHit((dir = -dir));
    // hitMap[std::to_string(112.5)] = processHit(rotateByAngle3(dir, up, 112.5));
    // hitMap[std::to_string(-112.5)] = processHit(rotateByAngle3(dir, up, -112.5));
    // hitMap[std::to_string(90.0)] = processHit(rotateByAngle3(dir, up, 90));
    // hitMap[std::to_string(-90.0)] = processHit(rotateByAngle3(dir, up, -90));
    // hitMap[std::to_string(22.5)] = processHit(rotateByAngle3(dir, up, 22.5));
    // hitMap[std::to_string(-22.5)] = processHit(rotateByAngle3(dir, up, -22.5));
    // for (auto &hit : hitMap) {
    //     if(hit.second->hasHit()){
    //         core::vector3df vec(hit.second->m_hitPointWorld.getX(), hit.second->m_hitPointWorld.getY(), hit.second->m_hitPointWorld.getZ());
    //         if (vec.getLength() / 1000 > 1) {
    //             outputData.push_back(0.0);
    //         } else {
    //             outputData.push_back(vec.getLength() / 1000);
    //         }
    //     } else {
    //         outputData.push_back(0.0);
    //     }
    // }
    // myfile << "in: ";
    // for (auto f : outputData) {
    //     myfile << f << " ";
    // }
    // myfile << std::endl;
    //

    KeyboardEvent();
    if (!this->_isAI) {
        updateCamera();
    }
	this->_carLoader.Update(drive_tipe);
}

void Car::updateCamera() {
	// look at the vehicle
	core::vector3df targetPos = this->_car->getPosition();
    core::vector3df targetRot = this->_car->getRotation();
    core::vector3df targetdir = targetRot.rotationToDirection().normalize();

    this->_cameraPosition = irr::core::vector3df(targetPos.X, targetPos.Y + this->_cameraHeight + this->_car->getlinVel() / 70, targetPos.Z) + -targetdir * (this->_baseCameraDistance + this->_car->getlinVel() / 35);
    //this->_cameraPosition = targetPos + -targetdir * 0.01;

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
	if(_eventReceiver->IsKeyDown(irr::KEY_BACK))
	{
		this->_carLoader.resetCar(0); // 90
	}

    // myfile << "out: ";
    // if(_eventReceiver->IsKeyDown(irr::KEY_UP)) {
	// 	if(!reverse)
	// 		myfile << "1.0 ";
	// 	else
	// 		myfile << "-1.0 ";
	// } else {
    //     myfile << "0.0 ";
    // }
    // if (_eventReceiver->IsKeyDown(irr::KEY_RIGHT)  && !_eventReceiver->IsKeyDown(irr::KEY_RIGHT))
    //     myfile << "1.0 ";
    // else if (!_eventReceiver->IsKeyDown(irr::KEY_RIGHT)  && _eventReceiver->IsKeyDown(irr::KEY_RIGHT))
    //     myfile << "-1.0 ";
    // else
    //     myfile << "0.0 ";
    // if(_eventReceiver->IsKeyDown(irr::KEY_SPACE)) {
	// 	myfile << "1.0 ";
	// } else {
    //     myfile << "0.0 ";
    // }
    // myfile << std::endl;

}

irr::core::vector3d<float>	Car::getPosition() const {
    return this->_car->getPosition();
}

irr::core::vector3d<float>	Car::getRotation() const {
    return this->_car->getRotation();
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
