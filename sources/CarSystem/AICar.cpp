//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Sun Jun  4 16:44:02 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, Circuit const &circuit, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, circuit, car_no, irr::core::vector3df(2, 36, 0), true),
    _neuralSystem(std::vector<unsigned> {10, 15, 3}), _carWatcher(this, circuit.getCheckpoints(), this, sceneManager) {

    this->_cCheck = 0;
    this->_n1Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n2Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n3Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
}

AICar::~AICar() {

}

void AICar::OnFrame() {
    this->_carWatcher.OnFrame();

    std::vector<double> outputData;

    GameCheckpoint const *c1 = NULL;
    GameCheckpoint const *c2 = NULL;
    GameCheckpoint const *c3 = NULL;

    int i = 0;
    for (auto check : this->_circuit.getCheckpoints()) {
        if (check.getID() == this->_n1Check) {
            c1 = &this->_circuit.getCheckpoints()[i];
            check.setChVisible(true);
        } else if (check.getID() == this->_n2Check) {
            c2 = &this->_circuit.getCheckpoints()[i];
            check.setChVisible(true);
        } else if (check.getID() == this->_n3Check) {
            c3 = &this->_circuit.getCheckpoints()[i];
            check.setChVisible(true);
        } else {
            check.setChVisible(false);
        }
        i++;
    }

    if (c1 != NULL) {
        core::vector3df dir = (c1->getPosition() - this->getPosition()).normalize();
        outputData.push_back(dir.X);
        outputData.push_back(dir.Y);
        outputData.push_back(dir.Z);
    } else {
        outputData.push_back(0.0);
        outputData.push_back(0.0);
        outputData.push_back(0.0);
    }

    if (c2 != NULL) {
        core::vector3df dir = (c2->getPosition() - this->getPosition()).normalize();
        outputData.push_back(dir.X);
        outputData.push_back(dir.Y);
        outputData.push_back(dir.Z);
    } else {
        outputData.push_back(0.0);
        outputData.push_back(0.0);
        outputData.push_back(0.0);
    }

    if (c3 != NULL) {
        core::vector3df dir = (c3->getPosition() - this->getPosition()).normalize();
        outputData.push_back(dir.X);
        outputData.push_back(dir.Y);
        outputData.push_back(dir.Z);
    } else {
        outputData.push_back(0.0);
        outputData.push_back(0.0);
        outputData.push_back(0.0);
    }

    outputData.push_back(getVel());
    this->_neuralSystem.feedForward(outputData);

    Car::OnFrame();
}

void AICar::OnEnterInCourseChPt(GameCheckpoint const &ch) {
    if (ch.getID() == this->_n1Check) {
        this->_n1Check = this->_n2Check;
        this->_n2Check = this->_n3Check;
        this->_n3Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
        for (auto check : this->_circuit.getCheckpoints()) {
            if (check.getID() == ch.getID()) {
                check.setChVisible(false);
            }
        }
    }
}

void AICar::KeyboardEvent() {
    std::vector<double> result = this->_neuralSystem.getResults();
    this->_car->move(result[0]);
    this->_car->steer(result[1]);
    this->_car->brake(result[2]);
}
