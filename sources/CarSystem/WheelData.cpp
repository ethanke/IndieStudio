//
// CarWheel.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Mon May 15 14:11:11 2017 Sousa Victor
// Last update Tue May 16 12:30:47 2017 Sousa Victor
//

#include "WheelData.hpp"

using namespace indie;

WheelData::WheelData() {
    this->_steerAngle = 0.0f;
	this->_grounded = false;
	//this->_groundMaterial = null;
	this->_suspensionCompression = 0.0f;
	this->_downforce = 0.0f;
	this->_velocity = Vector3::getzero();
	this->_localVelocity = Vector2::getzero();
	this->_localRigForce = Vector2::getzero();
	this->_isBraking = false;
	this->_finalInput = 0.0f;
	this->_tireSlip = Vector2::getzero();
	this->_tireForce = Vector2::getzero();
	this->_dragForce = Vector2::getzero();
	this->_angularVelocity = 0.0f;
	this->_angularPosition = 0.0f;
	//this->_lastPhysicMaterial = new PhysicMaterial();
	this->_positionRatio = 0.0f;
	this->_isWheelChildOfCaliper = false;
    this->_combinedTireSlip = 0.0f;
	this->_downforceRatio = 0.0f;
}
WheelData::~WheelData() {

}

const Wheel &WheelData::getWheel() const {
    return this->_wheel;
}
void WheelData::setWheel(const Wheel &wheel) {
    this->_wheel = wheel;
}

// const WheelCollider &WheelData::getCollider() const {
//     return this->_collider;
// }
// void WheelData::setCollider(const WheelCollider &collider) const {
//     this->_collider = collider;
// }
//
// const Transform &WheelData::getTransform() const {
//     return this->_transform;
// }
// void WheelData::setTransform(const Transform &transform) const {
//     this->_transform = transform;
// }

const Vector3 &WheelData::getOrigin() const {
    return this->_origin;
}
void WheelData::setOrigin(const Vector3 &origin) {
    this->_origin = origin;
}

float WheelData::getForceDistance() const {
    return this->_forceDistance;
}
void WheelData::setForceDistance(float forceDistance) {
    this->_forceDistance = forceDistance;
}

float WheelData::getSteerAngle() const {
    return this->_steerAngle;
}
void WheelData::setSteerAngle(float steerAngle) {
    this->_steerAngle = steerAngle;
}

bool WheelData::getGrounded() const {
    return this->_grounded;
}
void WheelData::setGrounded(bool grounded) {
    this->_grounded = grounded;
}

const WheelHit &WheelData::getHit() const {
    return this->_hit;
}
void WheelData::setHit(const WheelHit &hit) {
    this->_hit = hit;
}

const GroundMaterial &WheelData::getGroundMaterial() const {
    return this->_groundMaterial;
}
void WheelData::setGroundMaterial(const GroundMaterial &groundMaterial) {
    this->_groundMaterial = groundMaterial;
}

float WheelData::getSuspensionCompression() const {
    return this->_suspensionCompression;
}
void WheelData::setSuspensionCompression(float suspensionCompression) {
    this->_suspensionCompression = suspensionCompression;
}

float WheelData::getDownforce() const {
    return this->_downforce;
}
void WheelData::setDownforce(float downforce) {
    this->_downforce = downforce;
}

const Vector3 &WheelData::getVelocity() const {
    return this->_velocity;
}
void WheelData::setVelocity(const Vector3 &velocity) {
    this->_velocity = velocity;
}

const Vector2 &WheelData::getLocalVelocity() const {
    return this->_localVelocity;
}
void WheelData::setLocalVelocity(const Vector2 &localVelocity) {
    this->_localVelocity = localVelocity;
}

const Vector2 &WheelData::getLocalRigForce() const {
    return this->_localRigForce;
}
void WheelData::setLocalRigForce(const Vector2 &localRigForce) {
    this->_localRigForce = localRigForce;
}

bool WheelData::getIsBraking() const {
    return this->_isBraking;
}
void WheelData::setIsBraking(bool isBraking) {
    this->_isBraking = isBraking;
}

float WheelData::getFinalInput() const {
    return this->_finalInput;
}
void WheelData::setFinalInput(float finalInput) {
    this->_finalInput = finalInput;
}

const Vector2 &WheelData::getTireSlip() const {
    return this->_tireSlip;
}
void WheelData::setTireSlip(const Vector2 &tireSlip) {
    this->_tireSlip = tireSlip;
}

const Vector2 &WheelData::getTireForce() const {
    return this->_tireForce;
}
void WheelData::setTireForce(const Vector2 &tireForce) {
    this->_tireForce = tireForce;
}

const Vector2 &WheelData::getDragForce() const {
    return this->_dragForce;
}
void WheelData::setDragForce(const Vector2 &dragForce) {
    this->_dragForce = dragForce;
}

float WheelData::getAngularVelocity() const {
    return this->_angularVelocity;
}
void WheelData::setAngularVelocity(float angularVelocity) {
    this->_angularVelocity = angularVelocity;
}

float WheelData::getAngularPosition() const {
    return this->_angularPosition;
}
void WheelData::setAngularPosition(float angularPosition) {
    this->_angularPosition = angularPosition;
}

// const PhysicMaterial &WheelData::getLastPhysicMaterial() const {
//     return this->_lastPhysicMaterial;
// }
// void WheelData::setLastPhysicMaterial(const PhysicMaterial &lastPhysicMaterial) {
//     this->_lastPhysicMaterial = lastPhysicMaterial;
// }
//
// const RaycastHit &WheelData::getRayHit() const {
//     return this->_rayHit;
// }
// void WheelData::setRayHit(const RaycastHit &rayHit) {
//     this->_rayHit = rayHit;
// }

float WheelData::getPositionRatio() const {
    return this->_positionRatio;
}
void WheelData::setPositionRatio(float positionRatio) {
    this->_positionRatio = positionRatio;
}

bool WheelData::getIsWheelChildOfCaliper() const {
    return this->_isWheelChildOfCaliper;
}
void WheelData::setIsWheelChildOfCaliper(bool isWheelChildOfCaliper) {
    this->_isWheelChildOfCaliper = isWheelChildOfCaliper;
}

float WheelData::getCombinedTireSlip() const {
    return this->_combinedTireSlip;
}
void WheelData::setCombinedTireSlip(float combinedTireSlip) {
    this->_combinedTireSlip = combinedTireSlip;
}

float WheelData::getDownforceRatio() const {
    return this->_downforceRatio;
}
void WheelData::setDownforceRatio(float downforceRatio) {
    this->_downforceRatio = downforceRatio;
}
