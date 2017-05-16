//
// Wheel.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Tue May 16 12:30:29 2017 Sousa Victor
// Last update Tue May 16 12:30:53 2017 Sousa Victor
//

#include "Wheel.hpp"

using namespace indie;

Wheel::Wheel() {
    this->_steer = false;
    this->_drive = false;
    this->_brake = true;
    this->_handbrake = false;
}

Wheel::Wheel(const Wheel &rhs) {
    this->_steer = rhs._steer;
    this->_drive = rhs._drive;
    this->_brake = rhs._brake;
    this->_handbrake = rhs._handbrake;
}

Wheel::~Wheel() {

}

Wheel &Wheel::operator =(const Wheel &rhs) {
    this->_steer = rhs._steer;
    this->_drive = rhs._drive;
    this->_brake = rhs._brake;
    this->_handbrake = rhs._handbrake;
    return *this;
}

// WheelCollider const &Wheel::getWheelCollider() const {
//     return this->_wheelCollider;
// }
// void Wheel::WheelCollider(WheelCollider const &wheelCollider) {
//     this->_wheelCollider = wheelCollider;
// }
//
// Transform const &Wheel::getWheelTransform() const {
//     return this->_wheelTransform;
// }
// void Wheel::WheelTransform(Transform const &wheelTransform) {
//     this->_wheelTransform = wheelTransform;
// }
//
// Transform const &Wheel::getCaliperTransform() const {
//     return this->_caliperTransform;
// }
// void Wheel::CaliperTransform(Transform const &caliperTransform) {
//     this->_caliperTransform = caliperTransform;
// }

bool Wheel::getSteer() const {
    return this->_steer;
}
void Wheel::setSteer(bool steer) {
    this->_steer = steer;
}

bool Wheel::getDrive() const {
    return this->_drive;
}
void Wheel::setDrive(bool drive) {
    this->_drive = drive;
}

bool Wheel::getBrake() const {
    return this->_brake;
}
void Wheel::setBrake(bool brake) {
    this->_brake = brake;
}

bool Wheel::getHandBrake() const {
    return this->_handbrake;
}
void Wheel::setHandBrake(bool handbrake) {
    this->_handbrake = handbrake;
}
