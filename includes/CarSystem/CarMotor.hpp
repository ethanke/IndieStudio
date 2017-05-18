//
// CarMotor.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat May 13 22:28:43 2017 Sousa Victor
// Last update Thu May 18 03:11:29 2017 Sousa Victor
//

#ifndef CARMOTOR_HPP_
#define CARMOTOR_HPP_

#include "WheelData.hpp"
#include "Utils.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"

namespace indie {

    class CarMotor {

    public:
        CarMotor(irr::gui::IGUIEnvironment* guiManager, IRigidBody *rigidbody, bool debugMode = false);
        ~CarMotor();

        void OnFrame(int inputX, int inputY);

    private:
        virtual void setupCar();
        void startCar();
        bool _debug;
        irr::gui::IGUIEnvironment* _gui;
        irr::gui::IGUIStaticText *_inputGui;

        std::vector<Wheel> wheels;

        float centerOfMassPosition;
        float centerOfMassHeightOffset;
        btTransform centerOfMassTransform;

        //[Header("Vehicle Setup")]
            //[FormerlySerializedAs("maxSpeed")]
            float maxSpeedForward;
            float maxSpeedReverse;
            float tireFriction;
            float rollingResistance;
            float antiRoll;
            float maxSteerAngle;
            float aeroDrag;
            float aeroDownforce;

        //[Header("Vehicle Balance")]
            float driveBalance;
            float brakeBalance;
            float tireFrictionBalance;
            float aeroBalance;
            float handlingBias;

        //[Header("Motor")]
            float maxDriveForce;
            float forceCurveShape;
            float maxDriveSlip;
            float driveForceToMaxSlip;

        //[Header("Brakes")]
            float maxBrakeForce;
            float brakeForceToMaxSlip;
            enum BrakeMode {
                Slip,
                Ratio
            };
            BrakeMode brakeMode;
            float maxBrakeSlip;
            float maxBrakeRatio;
            BrakeMode handbrakeMode;
            float maxHandbrakeSlip;
            float maxHandbrakeRatio;

        //[Header("Driving Aids")]
            bool tractionControl;
            float tractionControlRatio;
            bool brakeAssist;
            float brakeAssistRatio;

            bool steeringLimit;
            float steeringLimitRatio;

            bool steeringAssist;
            float steeringAssistRatio;

        // Vehicle controls
            float steerInput;
            float throttleInput;
            float brakeInput;
            float handbrakeInput;

        float sleepVelocity;
        float defaultGroundGrip;
        float defaultGroundDrag;

        bool processContacts;
        float impactThreeshold;
        float impactInterval;
        float impactIntervalRandom;
        float impactMinSpeed;

        bool computeExtendedTireData;


        // Utility, also available for add-on components
        static float constexpr RpmToW = (2.0f * M_PI) / 60.0f;
        static float constexpr WToRpm = 60.0f / (2.0f * M_PI);

        // Cached and internal data, some accesible from scripting
        // Transform m_transform;
        IRigidBody *m_rigidbody;
        // GroundMaterialManager m_groundMaterialManager;
        //
        // Transform cachedTransform { get { return m_transform; } }
        // Rigidbody cachedRigidbody { get { return m_rigidbody; } }
        //
        // Rigidbody m_referenceBody;
        // Rigidbody m_referenceCandidate;
        // int m_referenceCandidateCount;
        //
        // // Debug
        //
        // [NonSerialized] string debugText;

        std::vector<WheelData> m_wheelData;
        float m_speed;
        float m_speedAngle;
        float m_steerAngle;
        bool m_usesHandbrake;

        //VehicleFrame m_vehicleFrame;

    private:
        void ConfigureCenterOfMass();
        void ComputeSteerAngle();

    private:
        static float InverseLerp(float a, float b, float value);

    };

}

#else

namespace indie {

    class CarMotor;

}

#endif /*CARMOTOR_HPP_*/
