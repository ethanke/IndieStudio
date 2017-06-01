//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Thu Jun  1 03:51:15 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, car_no, irr::core::vector3df(2, 38, 10), true), _neuralSystem(std::vector<unsigned> {20, 35, 20, 3}) {

    // Neural::Genome gen = _neuralSystem.toGenome();
    // _neuralSystem.fromGenome(gen);

    //this->_neuralSystem.loadFrom(std::string(SOURCES_PATH) + "/NetworkData/samples_save/car.txt");
}

AICar::~AICar() {

}

core::vector3df rotateByAngle(const core::vector3df &vec, const core::vector3df &up, float angle) {
    core::quaternion rotation;
    rotation.fromAngleAxis(angle, up);
    return rotation * vec;
}

void AICar::OnFrame() {
    std::unordered_map<std::string, btCollisionWorld::ClosestRayResultCallback*> hitMap;

    core::vector3df rot = this->_car->getRotation();
    core::vector3df dir = rot.rotationToDirection().normalize();
    core::vector3df right  = dir.crossProduct(core::vector3df(0, 1, 0));
    core::vector3df up = right.crossProduct(dir);

    std::vector<double> outputData;
    outputData.push_back(up.X);
    outputData.push_back(up.Y);
    outputData.push_back(up.Z);
    outputData.push_back(getVel());

    hitMap[std::to_string(0.0)] = processHit(dir);
    hitMap[std::to_string(-0.0)] = processHit((dir = -dir));
    hitMap[std::to_string(112.5)] = processHit(rotateByAngle(dir, up, 112.5));
    hitMap[std::to_string(-112.5)] = processHit(rotateByAngle(dir, up, -112.5));
    hitMap[std::to_string(90.0)] = processHit(rotateByAngle(dir, up, 90));
    hitMap[std::to_string(-90.0)] = processHit(rotateByAngle(dir, up, -90));
    hitMap[std::to_string(78.75)] = processHit(rotateByAngle(dir, up, 78.75));
    hitMap[std::to_string(-78.75)] = processHit(rotateByAngle(dir, up, -78.75));
    hitMap[std::to_string(67.5)] = processHit(rotateByAngle(dir, up, 67.5));
    hitMap[std::to_string(-67.5)] = processHit(rotateByAngle(dir, up, -67.5));
    hitMap[std::to_string(45.0)] = processHit(rotateByAngle(dir, up, 45));
    hitMap[std::to_string(-45.0)] = processHit(rotateByAngle(dir, up, -45));
    hitMap[std::to_string(33.75)] = processHit(rotateByAngle(dir, up, 33.75));
    hitMap[std::to_string(-33.75)] = processHit(rotateByAngle(dir, up, -33.75));
    hitMap[std::to_string(22.5)] = processHit(rotateByAngle(dir, up, 22.5));
    hitMap[std::to_string(-22.5)] = processHit(rotateByAngle(dir, up, -22.5));

    for (auto &hit : hitMap) {
        if(hit.second->hasHit()){
            core::vector3df vec(hit.second->m_hitPointWorld.getX(), hit.second->m_hitPointWorld.getY(), hit.second->m_hitPointWorld.getZ());
            if (vec.getLength() / 1000 > 1) {
                outputData.push_back(0.0);
            } else {
                outputData.push_back(vec.getLength() / 1000);
            }
        } else {
            outputData.push_back(0.0);
        }
    }

    this->_neuralSystem.feedForward(outputData);

    Car::OnFrame();
}

void AICar::KeyboardEvent() {
    std::vector<double> result = this->_neuralSystem.getResults();
    this->_car->move(result[0]);
    this->_car->steer(result[1]);
    this->_car->brake(result[2]);
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
