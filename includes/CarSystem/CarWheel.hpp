//
// CarWheel.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May 14 21:22:35 2017 Sousa Victor
// Last update Mon May 15 17:58:21 2017 Sousa Victor
//

#ifndef CARWHEEL_HPP_
#define CARWHEEL_HPP_

#include "IGameObject.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"

namespace indie {

    class GroundMaterial {

    public: enum SurfaceType {
            Hard,
            Soft
        };

    public:
        GroundMaterial();
        ~GroundMaterial();

        float getGrip() const;
        void setGrip(float grip);

        float getDrag() const;
        void setDrag(float drag);

    private:
        //PhysicMaterial physicMaterial;
        float _grip;
        float _drag;
        SurfaceType _surfaceType;

        // TireMarksRenderer marksRenderer;
        // TireParticleEmitter particleEmitter;
	};


    class Wheel {

    public:
        Wheel();
        ~Wheel();

        WheelCollider const &getWheelCollider() const;
        void setWheelCollider(WheelCollider const &wheelCollider);

        Transform const &getWheelTransform() const;
        void setWheelTransform(Transform const &wheelTransform);

        Transform const &getCaliperTransform() const;
        void setCaliperTransform(Transform const &caliperTransform);

        bool getSteer() const;
        void setSteer(bool steer);

        bool getDrive() const;
        void setDrive(bool drive);

        bool getBrake() const;
        void setBrake(bool brake);

        bool getHandBrake() const;
        void setHandBrake(bool handbrake);


    private:
        WheelCollider _wheelCollider;
        Transform _wheelTransform;
        Transform _caliperTransform;
        bool _steer;
        bool _drive;
        bool _brake;
        bool _handbrake;

    };


    class WheelHit {

    public:
        WheelHit();
        ~WheelHit();

        const Collider &getCollider() const;
        void setCollider(const Collider &collider);

        float getForce() const;
        void setForce(float force);

        const Vector3 &getForwardDir() const;
        void setForwardDir(const Vector3 &forwardDir);

        float getForwardSlip() const;
        void setForwardSlip(float forwardSlip);

        const Vector3 &getNormal() const;
        void setNormal(const Vector3 &normal);

        const Vector3 &getPoint() const;
        void setPoint(const Vector3 &point);

        const Vector3 &getSidewaysDir() const;
        void setSidewaysDir(const Vector3 &sidewaysDir);

        float getSidewaysSlip() const;
        void setSidewaysSlip(float sidewaysSlip);


    private:
        Collider _collider;
        float _force;
		Vector3 _forwardDir;
		float _forwardSlip;
		Vector3 _normal;
		Vector3 _point;
		Vector3 _sidewaysDir;
		float _sidewaysSlip;
	};


    class WheelData {

    public:
        WheelData();
        ~WheelData();

        const Wheel &getWheel() const;
        void setWheel(const Wheel &wheel) const;

        const WheelCollider &getCollider() const;
        void setCollider(const WheelCollider &collider) const;

        const Transform &getTransform() const;
        void setTransform(const Transform &transform) const;

        const Vector3 &getOrigin() const;
        void setOrigin(const Vector3 &origin) const;

        float getForceDistance() const;
        void setForceDistance(float forceDistance) const;

        float getSteerAngle() const;
        void setSteerAngle(float steerAngle) const;

        bool getGrounded() const;
        void setGrounded(bool grounded) const;

        const WheelHit &getHit() const;
        void setHit(const WheelHit &hit) const;

        const GroundMaterial &getGroundMaterial() const;
        void setGroundMaterial(const GroundMaterial &groundMaterial) const;

        float getSuspensionCompression() const;
        void setSuspensionCompression(float suspensionCompression) const;

        float getDownforce() const;
        void setDownforce(float downforce) const;

        const Vector3 &getVelocity() const;
        void setVelocity(const Vector3 &velocity) const;

        const Vector2 &getLocalVelocity() const;
        void setLocalVelocity(const Vector2 &localVelocity) const;

        const Vector2 &getLocalRigForce() const;
        void setLocalRigForce(const Vector2 &localRigForce) const;

        bool getIsBraking() const;
        void setIsBraking(bool isBraking) const;

        float getFinalInput() const;
        void setFinalInput(float finalInput) const;

        const Vector2 &getTireSlip() const;
        void setTireSlip(const Vector2 &tireSlip) const;

        const Vector2 &getTireForce() const;
        void setTireForce(const Vector2 &tireForce) const;

        const Vector2 &getDragForce() const;
        void setDragForce(const Vector2 &dragForce) const;

        float getAngularVelocity() const;
        void setAngularVelocity(float angularVelocity) const;

        float getAngularPosition() const;
        void setAngularPosition(float angularPosition) const;

        const PhysicMaterial &getLastPhysicMaterial() const;
        void setLastPhysicMaterial(const PhysicMaterial &lastPhysicMaterial) const;

        const RaycastHit &getRayHit() const;
        void setRayHit(const RaycastHit &rayHit) const;

        float getPositionRatio() const;
        void setPositionRatio(float positionRatio) const;

        bool getIsWheelChildOfCaliper() const;
        void setIsWheelChildOfCaliper(bool isWheelChildOfCaliper) const;

        float getCombinedTireSlip() const;
        void setCombinedTireSlip(float combinedTireSlip) const;

        float getDownforceRatio() const;
        void setDownforceRatio(float downforceRatio) const;

    private:
    	Wheel _wheel;
    	WheelCollider _collider;
    	Transform _transform;
    	Vector3 _origin;
    	float _forceDistance;
    	float _steerAngle;
    	bool _grounded;
    	WheelHit _hit;
    	GroundMaterial _groundMaterial;
    	float _suspensionCompression;
    	float _downforce;
    	Vector3 _velocity;
    	Vector2 _localVelocity;
    	Vector2 _localRigForce;
    	bool _isBraking;
    	float _finalInput;
    	Vector2 _tireSlip;
    	Vector2 _tireForce;
    	Vector2 _dragForce;
    	float _angularVelocity;
    	float _angularPosition;
    	PhysicMaterial _lastPhysicMaterial;
    	RaycastHit _rayHit;
    	float _positionRatio;
    	bool _isWheelChildOfCaliper;
    	float _combinedTireSlip;
    	float _downforceRatio;

    };

}

#endif /*CARWHEEL_HPP_*/
