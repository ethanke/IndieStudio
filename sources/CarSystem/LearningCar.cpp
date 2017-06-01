//
// LearningCar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/NeuralNetwork/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu Jun  1 03:38:07 2017 Sousa Victor
// Last update Thu Jun  1 04:09:14 2017 Sousa Victor
//

#include "LearningCar.hpp"

using namespace indie;

LearningCar::LearningCar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    AICar(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, car_no) {

    this->_fitness = 0;
    this->_hasFailed = false;
}

LearningCar::~LearningCar() {

}

void LearningCar::OnFrame() {
    if (getVel() < 1) {
        this->_indic++;
    } else {
        this->_indic = 0;
    }
    this->_hasFailed = this->_indic > 90;
    this->_fitness += getVel() * DeltaTimer::DeltaTime;
}

void LearningCar::SaveNetwork() const {
    this->_neuralSystem.saveTo("./car_" + std::to_string(this->_generationID) + "_" + std::to_string(this->_genomeID) + ".txt");
}

int LearningCar::getGenomeID() const {
    return this->_genomeID;
}

void LearningCar::setGenomeID(int genomeID) {
    this->_genomeID = genomeID;
}

int LearningCar::getGenerationID() const {
    return this->_generationID;
}

void LearningCar::setGenerationID(int generationID) {
    this->_generationID = generationID;
}

float LearningCar::getFitness() const {
    return this->_fitness;
}

void LearningCar::setFitness(float fitness) {
    this->_fitness = fitness;
}


bool LearningCar::getFailed() const {
    return this->_hasFailed;
}

void LearningCar::setFailed(bool failed) {
    this->_hasFailed = failed;
}
