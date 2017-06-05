//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Mon Jun  5 15:47:15 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

//bool manualMode = false;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, Circuit const &circuit, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, circuit, car_no, irr::core::vector3df(2, 36.5, 0), false),
    _steerBrain(std::vector<unsigned> {2, 15, 1}), _carWatcher(this, circuit.getCheckpoints(), this, sceneManager) {

    this->_cCheck = 0;
    this->_n1Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n2Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n3Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;

    Neural::NetworkTrainer trainer(std::string(SOURCES_PATH) + "/NetworkData/samples_input/car_steering.txt");
    this->_steerBrain.train(trainer);

    // if (manualMode == false) {
    //     this->_steerBrain.train(trainer);
    // } else {
    //     file.open(std::string(SOURCES_PATH) + "/build/car_example.txt");
    //     file << "topology: 2 5 1 " << std::endl;
    // }
}

AICar::~AICar() {
    // if (manualMode)
    //     file.close();
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
        irr::core::vector3df camDir = (this->getRotation().rotationToDirection()).normalize();
        irr::core::vector2df camDir2d(camDir.X, camDir.Z);
        irr::core::vector3df checkDir = (c1->getChPosition() - this->getPosition()).normalize();
        irr::core::vector2df checkDir2d(checkDir.X, checkDir.Z);
        float angle = atan2(camDir2d.X * checkDir2d.Y - camDir2d.Y * checkDir2d.X, camDir2d.X * checkDir2d.X + camDir2d.Y * checkDir2d.Y);
        outputData.push_back(angle);

        float dist = (c1->getPosition() - this->getPosition()).getLength();
        outputData.push_back(dist / 1000.0);
    } else {
        outputData.push_back(0.0);
        outputData.push_back(0.0);
    }
    this->_steerBrain.feedForward(outputData);

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
    // if (manualMode) {
    //     Car::KeyboardEvent();
    //     float force = 0.0;
    //     float brake = 0.0;
    //
    //     if(_eventReceiver->IsKeyDown(irr::KEY_UP)) {
    // 		if(!reverse)
    // 			force = 1.0;
    // 		else
    // 			force = -1.0;
    // 	}
	//     if(_eventReceiver->IsKeyDown(irr::KEY_SPACE)) {
    // 		brake = 1.0;
    // 	}
    //
    //     file << "out: " << std::fixed << std::setprecision(5) << steer << " " << std::endl;
    // } else {
    std::vector<double> steerResult = this->_steerBrain.getResults();
    this->_car->move(0.5);
    this->_car->steer(steerResult[0]);
    this->_car->brake(0);
}
