//
// CarWheel.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Mon May 15 14:11:11 2017 Sousa Victor
// Last update Mon May 15 17:59:09 2017 Sousa Victor
//

#include "CarWheel.hpp"

using namespace indie;

GroundMaterial::GroundMaterial() {
    this->_grip = 1.0f;
    this->_drag = 0.1f;
    this->_surfaceType = SurfaceType::Hard;
}

GroundMaterial::~GroundMaterial() {

}


float GroundMaterial::getGrip() const {
    return this->_grip;
}

void GroundMaterial::setGrip(float grip) {
    this->_grip = grip;
}


float GroundMaterial::getDrag() const {
    return this->_drag;
}

void GroundMaterial::setDrag(float drag) {
    this->_drag = drag;
}



Wheel() {
    this->_steer = false;
    this->_drive = false;
    this->_brake = true;
    this->_handbrake = false;
}
~Wheel() {

}

WheelCollider const &Wheel::getWheelCollider() const {
    return this->_wheelCollider;
}
void Wheel::WheelCollider(WheelCollider const &wheelCollider) {
    this->_wheelCollider = wheelCollider;
}

Transform const &Wheel::getWheelTransform() const {
    return this->_wheelTransform;
}
void Wheel::WheelTransform(Transform const &wheelTransform) {
    this->_wheelTransform = wheelTransform;
}

Transform const &Wheel::getCaliperTransform() const {
    return this->_caliperTransform;
}
void Wheel::CaliperTransform(Transform const &caliperTransform) {
    this->_caliperTransform = caliperTransform;
}

bool Wheel::getSteer() const {
    return this->_steer;
}
void Wheel::Steer(bool steer) {
    this->_steer = steer;
}

bool Wheel::getDrive() const {
    return this->_drive;
}
void Wheel::Drive(bool drive) {
    this->_drive = drive;
}

bool Wheel::getBrake() const {
    return this->_brake;
}
void Wheel::Brake(bool brake) {
    this->_brake = brake;
}

bool Wheel::getHandBrake() const {
    return this->_handbrake;
}
void Wheel::HandBrake(bool handbrake) {
    this->_handbrake = handbrake;
}


WheelHit::WheelHit() {

}

WheelHit::~WheelHit() {

}

const Collider WheelHit::getCollider() const {
    return this->_collider;
}

void WheelHit::setCollider(const Collider &collider) {
    this->_collider = collider;
}


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


WheelData::WheelData() {
    this->_steerAngle = 0.0f;
	this->_grounded = false;
	this->_groundMaterial = null;
	this->_suspensionCompression = 0.0f;
	this->_downforce = 0.0f;
	this->_velocity = Vector3.zero;
	this->_localVelocity = Vector2.zero;
	this->_localRigForce = Vector2.zero;
	this->_isBraking = false;
	this->_finalInput = 0.0f;
	this->_tireSlip = Vector2.zero;
	this->_tireForce = Vector2.zero;
	this->_dragForce = Vector2.zero;
	this->_angularVelocity = 0.0f;
	this->_angularPosition = 0.0f;
	this->_lastPhysicMaterial = new PhysicMaterial();
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
void WheelData::setWheel(const Wheel &wheel) const {
    this->_wheel = wheel;
}

const WheelCollider &WheelData::getCollider() const {
    return this->_collider;
}
void WheelData::setCollider(const WheelCollider &collider) const {
    this->_collider = collider;
}

const Transform &WheelData::getTransform() const {
    return this->_transform;
}
void WheelData::setTransform(const Transform &transform) const {
    this->_transform = transform;
}

const Vector3 &WheelData::getOrigin() const {
    return this->_origin;
}
void WheelData::setOrigin(const Vector3 &origin) const {
    this->_origin = origin;
}

float WheelData::getForceDistance() const {
    return this->_forceDistance;
}
void WheelData::setForceDistance(float forceDistance) const {
    this->_forceDistance = forceDistance;
}

float WheelData::getSteerAngle() const {
    return this->_steerAngle:
}
void WheelData::setSteerAngle(float steerAngle) const {
    this->_steerAngle = steerAngle;
}

bool WheelData::getGrounded() const {
    return this->_grounded;
}
void WheelData::setGrounded(bool grounded) const {
    this->_grounded = grounded;
}

const WheelHit &WheelData::getHit() const {
    return this->_hit;
}
void WheelData::setHit(const WheelHit &hit) const {
    this->_hit = hit;
}

const GroundMaterial &WheelData::getGroundMaterial() const {
    return this->_groundMaterial;
}
void WheelData::setGroundMaterial(const GroundMaterial &groundMaterial) const {
    this->_groundMaterial = groundMaterial;
}

float WheelData::getSuspensionCompression() const {
    return this->_suspensionCompression;
}
void WheelData::setSuspensionCompression(float suspensionCompression) const {
    this->_suspensionCompression = suspensionCompression;
}

float WheelData::getDownforce() const {
    return this->_downforce;
}
void WheelData::setSownforce(float downforce) const {
    this->_downforce = downforce;
}

const Vector3 &WheelData::getVelocity() const {
    return this->_velocity;
}
void WheelData::setVelocity(const Vector3 &velocity) const {
    this->_velocity = velocity;
}

const Vector2 &WheelData::getLocalVelocity() const {
    return this->_localVelocity;
}
void WheelData::setLocalVelocity(const Vector2 &localVelocity) const {
    this->_localVelocity = localVelocity;
}

const Vector2 &WheelData::getLocalRigForce() const {
    return this->_localRigForce;
}
void WheelData::setLocalRigForce(const Vector2 &localRigForce) const {
    this->_localRigForce = localRigForce;
}

bool WheelData::getIsBraking() const {
    return this->_isBraking;
}
void WheelData::setIsBraking(bool isBraking) const {
    this->_isBraking = isBraking;
}

float WheelData::getFinalInput() const {
    return this->_finalInput;
}
void WheelData::setFinalInput(float finalInput) const {
    this->_finalInput = finalInput;
}

const Vector2 &WheelData::getTireSlip() const {
    return this->_tireSlip;
}
void WheelData::setTireSlip(const Vector2 &tireSlip) const {
    this->_tireSlip = tireSlip;
}

const Vector2 &WheelData::getTireForce() const {
    return this->_tireForce;
}
void WheelData::setTireForce(const Vector2 &tireForce) const {
    this->_tireForce = tireForce;
}

const Vector2 &WheelData::getDragForce() const {
    return this->_dragForce;
}
void WheelData::setDragForce(const Vector2 &dragForce) const {
    this->_dragForce = dragForce;
}

float WheelData::getAngularVelocity() const {
    return this->_angularVelocity;
}
void WheelData::setAngularVelocity(float angularVelocity) const {
    this->_angularVelocity = angularVelocity;
}

float WheelData::getAngularPosition() const {
    return this->_angularPosition;
}
void WheelData::setAngularPosition(float angularPosition) const {
    this->_angularPosition = angularPosition;
}

const PhysicMaterial &WheelData::getLastPhysicMaterial() const {
    return this->_lastPhysicMaterial;
}
void WheelData::setLastPhysicMaterial(const PhysicMaterial &lastPhysicMaterial) const {
    this->_lastPhysicMaterial = lastPhysicMaterial;
}

const RaycastHit &WheelData::getRayHit() const {
    return this->_rayHit;
}
void WheelData::setRayHit(const RaycastHit &rayHit) const {
    this->_rayHit = rayHit;
}

float WheelData::getPositionRatio() const {
    return this->_positionRatio;
}
void WheelData::setPositionRatio(float positionRatio) const {
    this->_positionRatio = positionRatio;
}

bool WheelData::getIsWheelChildOfCaliper() const {
    return this->_isWheelChildOfCaliper;
}
void WheelData::setIsWheelChildOfCaliper(bool isWheelChildOfCaliper) const {
    this->_isWheelChildOfCaliper = isWheelChildOfCaliper;
}

float WheelData::getCombinedTireSlip() const {
    return this->_combinedTireSlip=
}
void WheelData::setCombinedTireSlip(float combinedTireSlip) const {
    this->_combinedTireSlip = combinedTireSlip;
}

float WheelData::getDownforceRatio() const {
    return this->_downforceRatio;
}
void WheelData::setDownforceRatio(float downforceRatio) const {
    this->_downforceRatio = downforceRatio;
}
