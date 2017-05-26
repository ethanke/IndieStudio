//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Fri May 26 21:44:27 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, car_no) {

    this->_rayInfo = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(400, 20, 2000, 1200));
    this->_rayInfo->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);

}

AICar::~AICar() {

}

core::vector3df rotateByAngle(const core::vector3df &vec, const core::vector3df &up, float angle) {
    core::quaternion rotation;
    rotation.fromAngleAxis(angle, up);
    return rotation * vec;
}

void AICar::OnFrame() {
    this->_outputData.str(std::string());;
    std::string str("         \n");

    std::unordered_map<std::string, btCollisionWorld::ClosestRayResultCallback*> hitMap;

    core::vector3df rot = this->_car->getRotation();
    core::vector3df dir = rot.rotationToDirection().normalize();
    core::vector3df right  = dir.crossProduct(core::vector3df(0, 1, 0));
    core::vector3df up = right.crossProduct(dir);

    this->_outputData << "in: " << up.X << " " << up.Y << " " << up.Z << " ";
    this->_outputData << getVel() << " ";

    hitMap[" " + std::to_string(0.0)] = processHit(dir);
    hitMap[""  + std::to_string(-0.0)] = processHit((dir = -dir));
    hitMap[" " + std::to_string(112.5)] = processHit(rotateByAngle(dir, up, 112.5));
    hitMap[""  + std::to_string(-112.5)] = processHit(rotateByAngle(dir, up, -112.5));
    hitMap[" " + std::to_string(90.0)] = processHit(rotateByAngle(dir, up, 90));
    hitMap[""  + std::to_string(-90.0)] = processHit(rotateByAngle(dir, up, -90));
    hitMap[" " + std::to_string(78.75)] = processHit(rotateByAngle(dir, up, 78.75));
    hitMap[""  + std::to_string(-78.75)] = processHit(rotateByAngle(dir, up, -78.75));
    hitMap[" " + std::to_string(67.5)] = processHit(rotateByAngle(dir, up, 67.5));
    hitMap[""  + std::to_string(-67.5)] = processHit(rotateByAngle(dir, up, -67.5));
    hitMap[" " + std::to_string(56.25)] = processHit(rotateByAngle(dir, up, 56.25));
    hitMap[""  + std::to_string(-56.25)] = processHit(rotateByAngle(dir, up, -56.25));
    hitMap[" " + std::to_string(45.0)] = processHit(rotateByAngle(dir, up, 45));
    hitMap[""  + std::to_string(-45.0)] = processHit(rotateByAngle(dir, up, -45));
    hitMap[" " + std::to_string(33.75)] = processHit(rotateByAngle(dir, up, 33.75));
    hitMap[""  + std::to_string(-33.75)] = processHit(rotateByAngle(dir, up, -33.75));
    hitMap[" " + std::to_string(22.5)] = processHit(rotateByAngle(dir, up, 22.5));
    hitMap[""  + std::to_string(-22.5)] = processHit(rotateByAngle(dir, up, -22.5));

    for (auto &hit : hitMap) {
        str += "Ray " + hit.first + ":        ";
        if(hit.second->hasHit()){
            core::vector3df vec(hit.second->m_hitPointWorld.getX(), hit.second->m_hitPointWorld.getY(), hit.second->m_hitPointWorld.getZ());
            str += "Collision at : " + std::to_string(vec.getLength() / 1000) + " m\n";
        } else {
            str += "no hit\n";
        }
    }

    for (auto &hit : hitMap) {
        if(hit.second->hasHit()){
            core::vector3df vec(hit.second->m_hitPointWorld.getX(), hit.second->m_hitPointWorld.getY(), hit.second->m_hitPointWorld.getZ());
            if (vec.getLength() / 1000 > 1) {
                this->_outputData << "0.0 ";
            } else {
                this->_outputData << vec.getLength() / 1000 << " ";
            }
        } else {
            this->_outputData << "0.0 ";
        }
    }

    if(!reverse) {
        this->_outputData << "0.0 ";
    } else {
        this->_outputData << "1.0 ";
    }

    system(std::string("echo " + this->_outputData.str() + " >> sample_input").c_str());

    this->_rayInfo->setText(Utils::StrToWstr(str));
    Car::OnFrame();
}

void AICar::KeyboardEvent() {
    this->_outputData.str(std::string());
    this->_outputData << "out: ";
    //steering
	if(_eventReceiver->IsKeyDown(irr::KEY_UP)) {
		this->_outputData << "0.0 ";
	} else {
        this->_outputData << "1.1 ";
    }

    if(_eventReceiver->IsKeyDown(irr::KEY_DOWN)) {
        this->_outputData << "0.0 ";
    } else {
        this->_outputData << "1.1 ";
    }

	if(_eventReceiver->IsKeyDown(irr::KEY_LEFT)) {
        this->_outputData << "0.0 ";
    } else {
        this->_outputData << "1.1 ";
    }

	if(_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) {
        this->_outputData << "0.0 ";
    } else {
        this->_outputData << "1.1 ";
    }

	if(_eventReceiver->IsKeyDown(irr::KEY_SPACE)) {
        this->_outputData << "0.0 ";
    } else {
        this->_outputData << "1.1 ";
    }
    system(std::string("echo " + this->_outputData.str() + " >> sample_input").c_str());
	Car::KeyboardEvent();
}

btCollisionWorld::ClosestRayResultCallback *AICar::processHit(const core::vector3df &dir) {
    core::vector3df pos = this->_car->getPosition();
    core::vector3df lkt = pos + dir * 250;

    btVector3 btFrom(pos.X, pos.Y, pos.Z);
    btVector3 btTo(lkt.X, lkt.Y, lkt.Z);
    btCollisionWorld::ClosestRayResultCallback *res = new btCollisionWorld::ClosestRayResultCallback(btFrom, btTo);
    this->_bulletPhysicsSystem->getDynamicsWorld()->rayTest(btFrom, btTo, *res);
    return res;
}
