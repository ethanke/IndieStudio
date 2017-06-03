//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Sat Jun  3 21:49:04 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, Circuit const &circuit, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, circuit, car_no, irr::core::vector3df(2, 36, 0), true),
    _neuralSystem(std::vector<unsigned> {9, 15, 3}), _carWatcher(this, circuit.getCheckpoints(), this, sceneManager) {

    this->_carWatcher.setNeedRemove(true);

}

AICar::~AICar() {

}

core::vector3df rotateByAngle(const core::vector3df &vec, const core::vector3df &up, float angle) {
    core::quaternion rotation;
    rotation.fromAngleAxis(angle, up);
    return rotation * vec;
}

void AICar::OnFrame() {
    this->_carWatcher.OnFrame();

    std::unordered_map<std::string, btCollisionWorld::ClosestRayResultCallback*> hitMap;

    std::vector<double> outputData;
    outputData.push_back(getVel());

    //this->_neuralSystem.feedForward(outputData);

    Car::OnFrame();
}

void AICar::OnEnterInCourseChPt(GameCheckpoint const &ch) {

}

void AICar::KeyboardEvent() {
    // std::vector<double> result = this->_neuralSystem.getResults();
    // this->_car->move(result[0]);
    // this->_car->steer(result[1]);
    // this->_car->brake(result[2]);
}
