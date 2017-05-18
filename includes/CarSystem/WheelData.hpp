//
// CarWheel.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May 14 21:22:35 2017 Sousa Victor
// Last update Wed May 17 01:12:26 2017 Sousa Victor
//

#ifndef WHEELDATA_HPP_
#define WHEELDATA_HPP_

#include "IGameObject.hpp"
#include "GroundMaterial.hpp"
#include "Wheel.hpp"
#include "WheelHit.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"

namespace indie {

    class WheelData {

    public:
        WheelData();
        ~WheelData();

        const Wheel &getWheel() const;
        void setWheel(const Wheel &wheel);

        // const WheelCollider &getCollider() const;
        // void setCollider(const WheelCollider &collider);
        //
        // const Transform &getTransform() const;
        // void setTransform(const Transform &transform);

        const Vector3 &getOrigin() const;
        void setOrigin(const Vector3 &origin);

        float getForceDistance() const;
        void setForceDistance(float forceDistance);

        float getSteerAngle() const;
        void setSteerAngle(float steerAngle);

        bool getGrounded() const;
        void setGrounded(bool grounded);

        const WheelHit &getHit() const;
        void setHit(const WheelHit &hit);

        const GroundMaterial &getGroundMaterial() const;
        void setGroundMaterial(const GroundMaterial &groundMaterial);

        float getSuspensionCompression() const;
        void setSuspensionCompression(float suspensionCompression);

        float getDownforce() const;
        void setDownforce(float downforce);

        const Vector3 &getVelocity() const;
        void setVelocity(const Vector3 &velocity);

        const Vector2 &getLocalVelocity() const;
        void setLocalVelocity(const Vector2 &localVelocity);

        const Vector2 &getLocalRigForce() const;
        void setLocalRigForce(const Vector2 &localRigForce);

        bool getIsBraking() const;
        void setIsBraking(bool isBraking);

        float getFinalInput() const;
        void setFinalInput(float finalInput);

        const Vector2 &getTireSlip() const;
        void setTireSlip(const Vector2 &tireSlip);

        const Vector2 &getTireForce() const;
        void setTireForce(const Vector2 &tireForce);

        const Vector2 &getDragForce() const;
        void setDragForce(const Vector2 &dragForce);

        float getAngularVelocity() const;
        void setAngularVelocity(float angularVelocity);

        float getAngularPosition() const;
        void setAngularPosition(float angularPosition);

        // const PhysicMaterial &getLastPhysicMaterial() const;
        // void setLastPhysicMaterial(const PhysicMaterial &lastPhysicMaterial);
        //
        // const RaycastHit &getRayHit() const;
        // void setRayHit(const RaycastHit &rayHit);

        float getPositionRatio() const;
        void setPositionRatio(float positionRatio);

        bool getIsWheelChildOfCaliper() const;
        void setIsWheelChildOfCaliper(bool isWheelChildOfCaliper);

        float getCombinedTireSlip() const;
        void setCombinedTireSlip(float combinedTireSlip);

        float getDownforceRatio() const;
        void setDownforceRatio(float downforceRatio);

    private:
    	Wheel _wheel;
    	//WheelCollider _collider;
    	//Transform _transform;
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
    	//PhysicMaterial _lastPhysicMaterial;
    	//RaycastHit _rayHit;
    	float _positionRatio;
    	bool _isWheelChildOfCaliper;
    	float _combinedTireSlip;
    	float _downforceRatio;

    };

}

#endif /*WHEELDATA_HPP_*/
