//
// GeneticTrainer.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/NeuralNetwork/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu Jun  1 04:22:47 2017 Sousa Victor
// Last update Thu Jun  1 04:46:56 2017 Sousa Victor
//

#include "GeneticTrainer.hpp"

using namespace indie;

GeneticTrainer::GeneticTrainer(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem) {
    this->_smgr = sceneManager;
    this->_gui = guiManager;
    this->_eventReceiver = eventReceiver;
    this->_bulletPhysicsSystem = bulletPhysicsSystem;

    this->_aiCar = NULL;
    this->_aiCar = new AICar(this->_smgr, this->_gui, this->_eventReceiver, this->_bulletPhysicsSystem, 0);
}

GeneticTrainer::~GeneticTrainer() {

}


void GeneticTrainer::OnFrame() {
    this->_aiCar->OnFrame();
}

Car *GeneticTrainer::getCar() const {
    return this->_aiCar;
}
