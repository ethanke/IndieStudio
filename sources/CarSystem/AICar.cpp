//
// AICar.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 24 20:31:35 2017 Sousa Victor
// Last update Mon Jun  5 01:05:37 2017 Sousa Victor
//

#include "AICar.hpp"

using namespace indie;

bool learn = false;

AICar::AICar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, Circuit const &circuit, int car_no):
    Car(sceneManager, guiManager, eventReceiver, bulletPhysicsSystem, circuit, car_no, irr::core::vector3df(2, 36.5, 0), false),
    _neuralSystem(std::vector<unsigned> {2, 15, 3}), _carWatcher(this, circuit.getCheckpoints(), this, sceneManager) {

    this->_cCheck = 0;
    this->_n1Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n2Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n3Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;

    if (learn == false) {
        Neural::NetworkTrainer trainer("/Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/build/car_example.txt");
        //for (int i = 0; i < 50; i++)
            this->_neuralSystem.train(trainer);
    } else {
        file.open("/Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/build/car_example.txt");
        file << "topology: 2 15 3 " << std::endl;
    }
}

AICar::~AICar() {
    if (learn)
        file.close();
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

        if (c2 != NULL) {
            irr::core::vector3df camDir2 = checkDir;
            irr::core::vector2df camDir2d2 = checkDir2d;
            irr::core::vector3df checkDir2 = (c2->getChPosition() - c1->getChPosition()).normalize();
            irr::core::vector2df checkDir2d2(checkDir2.X, checkDir2.Z);
            float angle2 = atan2(camDir2d2.X * checkDir2d2.Y - camDir2d2.Y * checkDir2d2.X, camDir2d2.X * checkDir2d2.X + camDir2d2.Y * checkDir2d2.Y);
            outputData.push_back(angle2);
        } else {
            outputData.push_back(angle);
        }
    } else {
        outputData.push_back(0.0);
        outputData.push_back(0.0);
    }
    //outputData.push_back(getVel() / getMaxSpeed());

    if (learn == false)
        this->_neuralSystem.feedForward(outputData);
    else {
        file << "in: ";
        for (auto f: outputData) {
            file << f << " ";
        }
        file << std::endl;
    }

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
    if (learn) {
        Car::KeyboardEvent();
        float force = 0.0;
        float steer = 0.0;
        float brake = 0.0;

        if(_eventReceiver->IsKeyDown(irr::KEY_UP)) {
    		if(!reverse)
    			force = 1.0;
    		else
    			force = -1.0;
    	}

        if(_eventReceiver->IsKeyDown(irr::KEY_LEFT) && !_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) {
            steer = -1.0;
    	} else if(!_eventReceiver->IsKeyDown(irr::KEY_LEFT) && _eventReceiver->IsKeyDown(irr::KEY_RIGHT)) {
            steer = 1.0;
    	}

    	if(_eventReceiver->IsKeyDown(irr::KEY_SPACE)) {
    		brake = 1.0;
    	}

        file << "out: ";
        file << force << " " << steer << " " << brake << " " << std::endl;
    } else {
        std::vector<double> result = this->_neuralSystem.getResults();
        std::cout << result[0] << " " << result[1] << " " << result[2] << std::endl;
        this->_car->move(result[0]);
        this->_car->steer(result[1]);
        this->_car->brake(result[2]);
    }
}
