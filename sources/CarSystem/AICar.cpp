//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Sat Jun  3 20:08:27 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, car_no, irr::core::vector3df(2, 36, 0), true), _neuralSystem(std::vector<unsigned> {9, 15, 3}) {

    //this->_neuralSystem.loadFrom("/Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/build/save_car.txt");

    // Neural::NetworkTrainer trainer("/Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/build/car.txt");
    // for (int i = 0; i < 1000; i++) {
    //     this->_neuralSystem.train(trainer);
    // }
    // this->_neuralSystem.saveTo("./save_car.txt");

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

    std::vector<double> outputData;
    outputData.push_back(getVel());

    this->_neuralSystem.feedForward(outputData);

    Car::OnFrame();
}

void AICar::KeyboardEvent() {
    std::vector<double> result = this->_neuralSystem.getResults();
    std::cout << result[0] << " " << result[1] << " " << result[2] << std::endl;
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
