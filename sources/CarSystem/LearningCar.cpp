//
// LearningCar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/NeuralNetwork/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu Jun  1 03:38:07 2017 Sousa Victor
// Last update Thu Jun  1 03:40:27 2017 Sousa Victor
//

#include "LearningCar.hpp"

using namespace indie;

LearningCar::LearningCar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    AICar(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, car_no) {

    this->_fitness = 0;
}

LearningCar::~LearningCar() {

}

void LearningCar::OnFrame() {

}
