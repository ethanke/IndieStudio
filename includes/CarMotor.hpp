//
// CarMotor.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat May 13 22:28:43 2017 Sousa Victor
// Last update Mon May 15 11:31:56 2017 Sousa Victor
//

#ifndef CARMOTOR_HPP_
#define CARMOTOR_HPP_

//#include "CarWheel.hpp"
#include "Utils.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [RequireComponent(typeof(Rigidbody))] public class VehicleController : MonoBehaviour
// class VehicleController : public MonoBehaviour
// {
// public:
// 	enum class CenterOfMassMode
// 	{
// 		Transform,
// 		Parametric
// 	};
//
// public:
// 	enum class BrakeMode
// 	{
// 		Slip,
// 		Ratio
// 	};
// public:
// 	enum class UpdateRate
// 	{
// 		OnUpdate,
// 		OnFixedUpdate,
// 		Disabled
// 	};
// public:
// 	enum class PositionMode
// 	{
// 		Accurate,
// 		Fast
// 	};
//
// private:
// 	class VehicleFrame
// 	{
// 	public:
// 		float frontPosition; // Average forwards position of all "front" wheels
// 		float rearPosition; // Average forwards position of all "rear" wheels
// 		float baseHeight; // Average vertical position of all wheels (center.y)
// 		float frontWidth; // Average semi-axle distance for all "front" wheels
// 		float rearWidth; // Average semi-axle distance for all "rear" wheels
//
// 		float middlePoint; // Forwards position that separates "front" and "rear" wheels
// 	};
//
// public:
// //C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
// //ORIGINAL LINE: public Wheel[] wheels = new Wheel[0];
// 	Wheel *wheels;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Center of Mass")] public CenterOfMassMode centerOfMassMode = CenterOfMassMode.Parametric;
// 	CenterOfMassMode centerOfMassMode;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0.1f, 0.9f)] public float centerOfMassPosition = 0.5f;
// 	float centerOfMassPosition;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(-1.0f, 1.0f)] public float centerOfMassHeightOffset = 0.0f;
// 	float centerOfMassHeightOffset;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [FormerlySerializedAs("centerOfMass")] public Transform centerOfMassTransform;
// 	Transform *centerOfMassTransform;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Vehicle Setup")][FormerlySerializedAs("maxSpeed")] public float maxSpeedForward = 27.78f;
// 	float maxSpeedForward;
// 	float maxSpeedReverse;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,3)] public float tireFriction = 1.0f;
// 	float tireFriction;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float rollingResistance = 0.05f;
// 	float rollingResistance;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float antiRoll = 0.2f;
// 	float antiRoll;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,89)] public float maxSteerAngle = 35.0f;
// 	float maxSteerAngle;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,4)] public float aeroDrag = 0.0f;
// 	float aeroDrag;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,2)] public float aeroDownforce = 1.0f;
// 	float aeroDownforce;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Vehicle Balance")][Range(0, 1)] public float driveBalance = 0.5f;
// 	float driveBalance;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0, 1)] public float brakeBalance = 0.5f;
// 	float brakeBalance;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0.3f, 0.7f)] public float tireFrictionBalance = 0.5f;
// 	float tireFrictionBalance;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float aeroBalance = 0.5f;
// 	float aeroBalance;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float handlingBias = 0.5f;
// 	float handlingBias;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Motor")] public float maxDriveForce = 2000.0f;
// 	float maxDriveForce;
// 	// [Space(5)]
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0.0001f, 0.9999f)] public float forceCurveShape = 0.5f;
// 	float forceCurveShape;
// 	float maxDriveSlip;
// 	float driveForceToMaxSlip;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Brakes")] public float maxBrakeForce = 3000.0f;
// 	float maxBrakeForce;
// 	float brakeForceToMaxSlip;
//
// 	BrakeMode brakeMode;
// 	float maxBrakeSlip;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float maxBrakeRatio = 0.5f;
// 	float maxBrakeRatio;
//
// 	BrakeMode handbrakeMode;
// 	float maxHandbrakeSlip;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float maxHandbrakeRatio = 1.0f;
// 	float maxHandbrakeRatio;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Driving Aids")][FormerlySerializedAs("tcEnabled")] public bool tractionControl = false;
// 	bool tractionControl;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)][FormerlySerializedAs("tcRatio")] public float tractionControlRatio = 1.0f;
// 	float tractionControlRatio;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [FormerlySerializedAs("absEnabled")] public bool brakeAssist = false;
// 	bool brakeAssist;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)][FormerlySerializedAs("absRatio")] public float brakeAssistRatio = 1.0f;
// 	float brakeAssistRatio;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [FormerlySerializedAs("espEnabled")] public bool steeringLimit = false;
// 	bool steeringLimit;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)][FormerlySerializedAs("espRatio")] public float steeringLimitRatio = 0.5f;
// 	float steeringLimitRatio;
//
// 	bool steeringAssist;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float steeringAssistRatio = 0.5f;
// 	float steeringAssistRatio;
//
// 	// Vehicle controls
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(-1,1)] public float steerInput = 0.0f;
// 	float steerInput;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(-1,1)] public float throttleInput = 0.0f;
// 	float throttleInput;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float brakeInput = 0.0f;
// 	float brakeInput;
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Range(0,1)] public float handbrakeInput = 0.0f;
// 	float handbrakeInput;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Visual Wheels")] public UpdateRate spinUpdateRate = UpdateRate.OnUpdate;
// 	UpdateRate spinUpdateRate;
// 	PositionMode wheelPositionMode;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Wheel Contact")][Range(0,0.5f)] public float sleepVelocity = 0.2f;
// 	float sleepVelocity;
//
// 	// Ground physic properties applied when no proper ground material is available.
// 	float defaultGroundGrip;
// 	float defaultGroundDrag;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [Header("Optimization & Debug")] public bool disallowRuntimeChanges = false;
// 	bool disallowRuntimeChanges;
// 	// Runtime updates can be disabled when the mass, the center of mass and the suspension
// 	// are not expected to change in runtime. They may still change, but the vehicle should
// 	// be disabled / enabled for the new values to have effect.
//
// 	// WheelHit correction fixes the wheel contact point, which gets shifted with speed.
// 	// Uses an additional RayCast per wheel per physics frame. Can be safely disabled on
// 	// non-player vehicles (i.e. traffic)
//
// 	bool disableWheelHitCorrection;
//
// 	// In PhysX wheels are considered to point in the same direction as the vehicle's body.
// 	// The steer angle correction allows the wheels to point in any direction as defined
// 	// by their transform hierarchy.
//
// 	bool disableSteerAngleCorrection;
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [FormerlySerializedAs("showContactGizmos")] public bool showCollisionGizmos = false;
// 	bool showCollisionGizmos;
//
// 	// Public non-exposed properties. To be configured from scripting if necessary.
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [NonSerialized] public bool processContacts = false;
// 	bool processContacts; // This is set to True by the components that use contacts (Audio, Damage)
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [NonSerialized] public float impactThreeshold = 0.6f;
// 	float impactThreeshold; // 0.0 - 1.0. The DotNormal of the impact is calculated. Less than this value means drag, more means impact.
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [NonSerialized] public float impactInterval = 0.2f;
// 	float impactInterval; // Time interval between processing impacts for visual or sound effects.
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [NonSerialized] public float impactIntervalRandom = 0.4f;
// 	float impactIntervalRandom; // Random percentaje for the impact interval, avoiding regularities.
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [NonSerialized] public float impactMinSpeed = 2.0f;
// 	float impactMinSpeed; // Minimum relative velocity at which conctacts may be consideered impacts.
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [NonSerialized] public bool computeExtendedTireData = false;
// 	bool computeExtendedTireData; // Components using extended tire data (tire marks, smoke, particles, audio) set this to True
//
//
// 	// Add-on components subscribe to this delegate to get notified on impacts.
// 	// Use VehicleController.current to access the values of the controller that sent the event.
//
// 	typedef void (*OnImpact)();
// 	OnImpact onImpact;
//
// 	static VehicleController *current;
//
//
// 	// Impact properties. Use from an OnImpact event only.
// 	// Private values get masaged properly just before invoking the event.
//
// 	Vector3 *getlocalImpactPosition() const;
// 	Vector3 *getlocalImpactVelocity() const;
// 	const bool &getisHardImpact() const;
//
// 	// Body drag properties. Can be queued continuously.
//
// 	Vector3 *getlocalDragPosition() const;
// 	Vector3 *getlocalDragVelocity() const;
// 	const bool &getisHardDrag() const;
//
//
// 	// Utility, also available for add-on components
//
// 	static float RpmToW;
// 	static float WToRpm;
//
// 	WheelData *getwheelData() const;
//
// 	const float &getspeed() const;
// 	const float &getspeedAngle() const;
// 	const float &getsteerAngle() const;
//
//
// 	// Cached and internal data, some accesible from scripting
//
// private:
// 	Transform *m_transform;
// 	Rigidbody *m_rigidbody;
// 	GroundMaterialManager *m_groundMaterialManager;
//
// public:
// 	Transform *getcachedTransform() const;
// 	Rigidbody *getcachedRigidbody() const;
//
// private:
// 	Rigidbody *m_referenceBody;
// 	Rigidbody *m_referenceCandidate;
// 	int m_referenceCandidateCount;
//
// 	// Debug
//
// public:
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [NonSerialized] public string debugText = "";
// 	std::wstring debugText;
//
//
// 	// Internal data
//
// private:
// //C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
// //ORIGINAL LINE: WheelData[] m_wheelData = new WheelData[0];
// 	WheelData *m_wheelData;
// 	float m_speed;
// 	float m_speedAngle;
// 	float m_steerAngle;
// 	bool m_usesHandbrake;
//
// 	CommonTools::BiasLerpContext *m_forceBiasCtx;
//
// 	VehicleFrame m_vehicleFrame;
//
//
// 	void OnValidate();
//
//
// 	void OnEnable();
//
//
// 	void Update();
//
//
// 	void FixedUpdate();
//
//
// 	//----------------------------------------------------------------------------------------------
//
//
// 	void ComputeSteerAngle();
//
//
// 	void UpdateSteering(WheelData *wd);
//
//
// 	float FixSteerAngle(WheelData *wd, float inputSteerAngle);
//
//
// 	 void UpdateSuspension(WheelData *wd);
//
//
// 	void UpdateLocalFrame(WheelData *wd);
//
//
// 	void UpdateGroundMaterial(WheelData *wd);
//
//
// 	void ComputeTireForces(WheelData *wd);
//
//
// 	void ApplyTireForces(WheelData *wd);
//
// 	// Methods for calculating tire data
//
//
// 	// Application point for the sideways force
//
// public:
// 	Vector3 *GetSidewaysForceAppPoint(WheelData *wd, Vector3 *contactPoint);
//
//
// 	// Slip angle based on velocity
//
// private:
// 	static float ComputeSlipAngle(Vector2 *localVelocity);
//
//
// 	// Combined slip value. It's the magnitude of tireSlip, but the x component being weighted with
// 	// the velocity-based slip angle. The implementation is equivalent to:
// 	//
// 	// float combinedSlip = new Vector2(tireSlip.x * Mathf.Sin(GetSlipAngle()), tireSlip.y).magnitude
//
// 	static float ComputeCombinedSlip(Vector2 *localVelocity, Vector2 *tireSlip);
//
//
// 	void ComputeExtendedTireData(WheelData *wd, float referenceDownforce);
//
//
// 	// Calculate current maximum force according to speed
//
//
// 	float ComputeDriveForce(float demandedForce, float maxForce, bool grounded);
//
//
// 	// Calculate brake ratio and slip based on the current brake method
//
//
// 	void ComputeBrakeValues(WheelData *wd, BrakeMode mode, float maxSlip, float maxRatio, float &brakeSlip, float &brakeRatio);
//
//
// 	// Set the visual transform for the wheel
//
//
// 	void UpdateTransform(WheelData *wd);
//
//
// 	// Updates a ground material reference based on the physics material assigned to a collider
// 	// using a cached reference for the physics material. This way the ground material manager
// 	// is queried only when the physic material changes.
//
// 	void UpdateGroundMaterialCached(PhysicMaterial *colliderMaterial, PhysicMaterial *&cachedMaterial, GroundMaterial *&groundMaterial);
//
//
// 	//----------------------------------------------------------------------------------------------
//
//
// public:
// 	void ResetVehicle();
//
//
// 	//----------------------------------------------------------------------------------------------
//
// 	// Private methods for dealing with colliders
//
//
// private:
// //C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
// //ORIGINAL LINE: Collider[] m_colliders = new Collider[0];
// 	Collider *m_colliders;
// //C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
// //ORIGINAL LINE: int[] m_colLayers = new int[0];
// 	int *m_colLayers;
//
//
// 	void FindColliders();
//
//
// 	void DisableCollidersRaycast();
//
//
// 	void EnableCollidersRaycast();
//
//
// 	float GetWheelForceDistance(WheelCollider *col);
//
//
// 	void UpdateWheelCollider(WheelCollider *col);
//
//
// 	WheelFrictionCurve *m_colliderFriction;
//
// 	void SetupWheelCollider(WheelCollider *col);
//
//
// 	void UpdateWheelSleep(WheelData *wd);
//
//
// 	//----------------------------------------------------------------------------------------------
//
// 	// Vehicle balancing
//
//
//
// 	VehicleFrame ComputeVehicleFrame();
//
//
// 	void ConfigureCenterOfMass();
//
//
// 	// Balanced value (linear cross-faded):
// 	//
// 	//		bias	rear	front
// 	//		0.0		0.0		2.0
// 	//		0.5		1.0		1.0
// 	//		1.0		2.0		0.0
//
// public:
// 	static float GetBalancedValue(float value, float bias, float positionRatio);
//
//
// 	// Ramp balanced value:
// 	//
// 	//		bias	rear	front
// 	//		0.0		0.0		1.0
// 	//		0.5		1.0		1.0
// 	//		1.0		1.0		0.0
//
// 	static float GetRampBalancedValue(float value, float bias, float positionRatio);
//
//
// 	//----------------------------------------------------------------------------------------------
//
// 	// Contact processing
//
//
// 	// Private data for internal use
//
// private:
// 	int m_sumImpactCount;
// 	Vector3 *m_sumImpactPosition;
// 	Vector3 *m_sumImpactVelocity;
// 	int m_sumImpactHardness;
// 	float m_lastImpactTime;
//
// 	Vector3 *m_localDragPosition;
// 	Vector3 *m_localDragVelocity;
// 	int m_localDragHardness;
//
// 	float m_lastStrongImpactTime;
// 	PhysicMaterial *m_lastImpactedMaterial;
// 	GroundMaterial *m_impactedGroundMaterial;
//
//
// 	void OnCollisionEnter(Collision *collision);
//
//
// 	void OnCollisionStay(Collision *collision);
//
//
// 	void ProcessContacts(Collision *col, bool forceImpact);
//
//
// 	// Impact processing
//
// 	void HandleImpacts();
//
//
// 	// Drag processing
// 	// The values come from OnCollisionEnter/Stay so the actual drag value is updated accordingly.
// 	//
// 	// This function is invoked from both OnCollision (increase the drag value) and Update
// 	// (smoothly decrease the value to zero).
//
// 	void UpdateDragState(Vector3 *dragPosition, Vector3 *dragVelocity, int dragHardness);
//
//
// 	//----------------------------------------------------------------------------------------------
//
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [ContextMenu("Adjust WheelColliders to their meshes")] void AdjustWheelColliders()
// 	void AdjustWheelColliders();
//
//
// 	static void AdjustColliderToWheelMesh(WheelCollider *wheelCollider, Transform *wheelTransform);
//
//
// 	static Bounds *GetScaledBounds(MeshFilter *meshFilter);
//
//
// //C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
// //ORIGINAL LINE: [ContextMenu("Convert Center of Mass from Transform to Parametric")] void FromTransformToParametricCoM()
// 	void FromTransformToParametricCoM();
//
//
// 	//----------------------------------------------------------------------------------------------
//
//
// 	#if defined(UNITY_EDITOR)
//
//
// public:
// 	void OnDrawGizmos();
//
//
// private:
// 	static Color *AlphaColor(Color *col, float alpha = 1.0f);
//
//
// 	static void DrawCrossMarkHandle(Vector3 *pos, Vector3 *forward, Vector3 *right, Vector3 *up, float length = 0.1f);
//
// 	#endif
//
// 	private:
// 		void InitializeInstanceFields();
//
// public:
// 		VehicleController()
// 		{
// 			InitializeInstanceFields();
// 		}
// };
// }
//

namespace indie {

    class CarMotor {

    public:
        CarMotor(irr::gui::IGUIEnvironment* guiManager, bool debugMode = false);
        ~CarMotor();

        void OnFrame(int inputX, int inputY);

    private:
        bool _debug;
        irr::gui::IGUIEnvironment* _gui;

        irr::gui::IGUIStaticText *_inputGui;

    };

}

#else

namespace indie {

    class CarMotor;

}

#endif /*CARMOTOR_HPP_*/
