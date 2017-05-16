//
// WheelHit.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Tue May 16 12:26:38 2017 Sousa Victor
// Last update Tue May 16 12:26:47 2017 Sousa Victor
//

#include "WheelHit.hpp"

using namespace indie;

WheelHit::WheelHit() {

}

WheelHit::~WheelHit() {

}

// const Collider WheelHit::getCollider() const {
//     return this->_collider;
// }
//
// void WheelHit::setCollider(const Collider &collider) {
//     this->_collider = collider;
// }


float WheelHit::getForce() const {
    return this->_force;
}

void WheelHit::setForce(float force) {
    this->_force = force;
}


const Vector3 &WheelHit::getForwardDir() const {
    return this->_forwardDir;
}

void WheelHit::setForwardDir(const Vector3 &forwardDir) {
    this->_forwardDir = forwardDir;
}


float WheelHit::getForwardSlip() const {
    return this->_forwardSlip;
}

void WheelHit::setForwardSlip(float forwardSlip) {
    this->_forwardSlip = forwardSlip;
}


const Vector3 &WheelHit::getNormal() const {
    return this->_normal;
}

void WheelHit::setNormal(const Vector3 &normal) {
    this->_normal = normal;
}


const Vector3 &WheelHit::getPoint() const {
    return this->_point;
}

void WheelHit::setPoint(const Vector3 &point) {
    this->_point = point;
}


const Vector3 &WheelHit::getSidewaysDir() const {
    return this->_sidewaysDir;
}

void WheelHit::setSidewaysDir(const Vector3 &sidewaysDir) {
    this->_sidewaysDir = sidewaysDir;
}


float WheelHit::getSidewaysSlip() const {
    return this->_sidewaysSlip;
}

void WheelHit::setSidewaysSlip(float sidewaysSlip) {
    this->_sidewaysSlip = sidewaysSlip;
}
