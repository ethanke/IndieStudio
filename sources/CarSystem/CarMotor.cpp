//
// CarMotor.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat May 13 22:34:06 2017 Sousa Victor
// Last update Thu May 18 17:25:43 2017 Sousa Victor
//

#include "CarMotor.hpp"

using namespace indie;

CarMotor::CarMotor(irr::gui::IGUIEnvironment* guiManager, IRigidBody *rigidbody, bool debugMode) {
    this->_gui = guiManager;
    this->_debug = debugMode;
    this->m_rigidbody = rigidbody;

    this->_inputGui = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(50, 50, 300, 65), true, true, 0, -1, true);
    this->_steerInputGui = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(50, 65, 300, 80), true, true, 0, -1, true);
    this->_steerAngleGui = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(50, 80, 300, 140), true, true, 0, -1, true);

    setupCar();
    startCar();
}

CarMotor::~CarMotor() {

}
void CarMotor::setupCar() {
    for (int i = 0; i < 2; i++) {
        this->wheels.push_back(Wheel());
        this->wheels[i].setSteer(true);
        this->wheels[i].setDrive(true);
        this->wheels[i].setBrake(true);
        this->wheels[i].setHandBrake(false);
    }
    for (int i = 2; i < 4; i++) {
        this->wheels.push_back(Wheel());
        this->wheels[i].setSteer(false);
        this->wheels[i].setDrive(true);
        this->wheels[i].setBrake(true);
        this->wheels[i].setHandBrake(true);
    }
    this->centerOfMassPosition = 0.5f; //[Range(0.1f, 0.9f)]
    this->centerOfMassHeightOffset = 0.0f; //[Range(-1.0f, 1.0f)]
    this->centerOfMassTransform = this->m_rigidbody->getPointer()->getCenterOfMassTransform();
    this->maxSpeedForward = 27.78f;
    this->maxSpeedReverse = 12.0f;
    this->tireFriction = 1.0f; //[Range(0,3)]
    this->rollingResistance = 0.05f; //[Range(0,1)]
    this->antiRoll = 0.2f; //[Range(0,1)]
    this->maxSteerAngle = 35.0f; //[Range(0,89)]
    this->aeroDrag = 0.0f; //[Range(0,4)]
    this->aeroDownforce = 1.0f; //[Range(0,2)]
    this->driveBalance = 0.5f; //[Range(0, 1)]
    this->brakeBalance = 0.5f; //[Range(0, 1)]
    this->tireFrictionBalance = 0.5f; //[Range(0.3f, 0.7f)]
    this->aeroBalance = 0.5f; //[Range(0,1)]
    this->handlingBias = 0.5f; //[Range(0,1)]
    this->maxDriveForce = 2000.0f; // [Space(5)]
    this->forceCurveShape = 0.5f; //[Range(0.0001f, 0.9999f)]
    this->maxDriveSlip = 4.0f;
    this->driveForceToMaxSlip = 1000.0f;
    this->maxBrakeForce = 3000.0f;
    this->brakeForceToMaxSlip = 1000.0f;
    this->brakeMode = BrakeMode::Slip;
    this->maxBrakeSlip = 2.0f;
    this->maxBrakeRatio = 0.5f; //[Range(0,1)]
    this->handbrakeMode = BrakeMode::Slip;
    this->maxHandbrakeSlip = 10.0f;
    this->maxHandbrakeRatio = 1.0f; //[Range(0,1)]
    this->tractionControl = false; //[FormerlySerializedAs("tcEnabled")]
    this->tractionControlRatio = 1.0f; //[Range(0,1)]
    this->brakeAssist = false; //[FormerlySerializedAs("absEnabled")]
    this->brakeAssistRatio = 1.0f; //[Range(0,1)]
    this->steeringLimit = false; //[FormerlySerializedAs("espEnabled")]
    this->steeringLimitRatio = 0.5f; //[Range(0,1)]
    this->steeringAssist = true;
    this->steeringAssistRatio = 0.5f; //[Range(0,1)]
    this->steerInput = 0.0f; //[Range(-1,1)] = 0.5f; //[Range(0.1f, 0.9f)]
    this->throttleInput = 0.0f; //[Range(-1,1)]
    this->brakeInput = 0.0f; //[Range(0,1)]
    this->handbrakeInput = 0.0f; //[Range(0,1)]
    this->sleepVelocity = 0.2f;//[Range(0,0.5f)]
    this->defaultGroundGrip = 1.0f;
    this->defaultGroundDrag = 0.0f;
    this->processContacts = false;		// This is set to True by the components that use contacts (Audio, Damage)
    this->impactThreeshold = 0.6f;		// 0.0 - 1.0. The DotNormal of the impact is calculated. Less than this value means drag, more means impact.
    this->impactInterval = 0.2f;			// Time interval between processing impacts for visual or sound effects.
    this->impactIntervalRandom = 0.4f;	// Random percentaje for the impact interval, avoiding regularities.
    this->impactMinSpeed = 2.0f;			// Minimum relative velocity at which conctacts may be consideered impacts.
    this->computeExtendedTireData = false;// Components using extended tire data (tire marks, smoke, particles, audio) set this to True
    // Transform m_transform;
    // GroundMaterialManager m_groundMaterialManager;
    // Transform cachedTransform { get { return m_transform; } }
    // Rigidbody cachedRigidbody { get { return m_rigidbody; } }
    // Rigidbody m_referenceBody = null;
    // Rigidbody m_referenceCandidate = null;
    // int m_referenceCandidateCount = 0;
    //this->:vector<WheelData> m_wheelData; // TO FILL
    this->m_speed = 0.0f;
    this->m_speedAngle = 0.0f;
    this->m_steerAngle = 0.0f;
    this->m_usesHandbrake = false;
}

void CarMotor::startCar() {
    m_usesHandbrake = false;
    for (int i = 0; i < 4; i++) {
        Wheel w = wheels[i];
        this->m_wheelData.push_back(WheelData());
        WheelData wd = this->m_wheelData[i];
        // wd.collider = w.wheelCollider;
        // wd.transform = w.wheelCollider.transform;
        if (w.getHandBrake())
            m_usesHandbrake = true;
        wd.setForceDistance(1.5);
        wd.setPositionRatio(i >= 2 ? 1.0f : 0.0f);
        wd.setWheel(w);
    }
}

void CarMotor::OnFrame(int inputX, int inputY) {
    this->steerInput = inputY;

    ComputeSteerAngle();

    for (auto wd : m_wheelData) {
        UpdateSteering(wd);
        //UpdateTransform(wd);
    }
    //
    // if (needDisableColliders)
    //     EnableCollidersRaycast();
    //
    // if (processContacts)
    // {
    //     UpdateDragState(Vector3.zero, Vector3.zero, m_localDragHardness);
    //     // debugText = string.Format("Drag Pos: {0}  Drag Velocity: {1,5:0.00}  Drag Friction: {2,4:0.00}", localDragPosition, localDragVelocity.magnitude, localDragFriction);
    // }

    if (this->_debug) {
        std::stringstream ss;
        ss << "intput,  X: " << inputX << ",  Y: " << inputY << std::endl;
        this->_inputGui->setText(Utils::StrToWstr(ss.str()));

        std::stringstream ss1;
        ss1 << "steer value: " << m_steerAngle << std::endl;
        this->_steerInputGui->setText(Utils::StrToWstr(ss1.str()));

        std::stringstream ss2;
        ss2 << "Wheel 1: " << m_wheelData[0].getSteerAngle() << std::endl;
        ss2 << "Wheel 2: " << m_wheelData[1].getSteerAngle() << std::endl;
        ss2 << "Wheel 3: " << m_wheelData[2].getSteerAngle() << std::endl;
        ss2 << "Wheel 4: " << m_wheelData[3].getSteerAngle();
        this->_steerAngleGui->setText(Utils::StrToWstr(ss2.str()));
    }
}


void CarMotor::ComputeSteerAngle ()
{
    float inputSteerAngle = maxSteerAngle * steerInput;

    float speedFactor = CarMotor::InverseLerp(0.1f, 3.0f, m_speed);

    if (steeringLimit)
    {
        float forwardSpeed = m_speed * steeringLimitRatio * speedFactor;
        float res = 3.0f / forwardSpeed;
        float maxEspAngle = std::sin(res < 0 ? 0 : res > 1 ? 1 : res) * 57.2958;
        float steerAngleLimit = std::min(maxSteerAngle, std::max(maxEspAngle, std::fabs(m_speedAngle)));
        inputSteerAngle = inputSteerAngle < -steerAngleLimit ? -steerAngleLimit : inputSteerAngle > +steerAngleLimit ? +steerAngleLimit : inputSteerAngle;
    }

    float assistedSteerAngle = 0.0f;
    if (steeringAssist)
        assistedSteerAngle = m_speedAngle * steeringAssistRatio * speedFactor * CarMotor::InverseLerp(2.0f, 3.0f, std::fabs(m_speedAngle));

    m_steerAngle = inputSteerAngle + assistedSteerAngle < -maxSteerAngle ? -maxSteerAngle : inputSteerAngle + assistedSteerAngle > +maxSteerAngle ? +maxSteerAngle : inputSteerAngle + assistedSteerAngle;
}

void CarMotor::UpdateSteering (WheelData wd){
    if (wd.getWheel().getSteer())
        wd.setSteerAngle(m_steerAngle);
	else
		wd.setSteerAngle(0.0f);
	//wd.collider.steerAngle = wd.getSteerAngle();
}

float CarMotor::InverseLerp(float a, float b, float value)
{
	float result;
	if (a != b) {
        float tmp = (value - a) / (b - a);
		result = tmp < 0 ? 0 : tmp > 1 ? 1 : tmp;
	} else {
		result = 0;
	}
	return result;
}
