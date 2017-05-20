#include "loadCar.h"


//default constructor
CLoadCar::CLoadCar()
{

}

//default destructor
CLoadCar::~CLoadCar()
{

}

void CLoadCar::Init(irr::scene::ISceneManager *smgr, physics::CBulletPhysics* BPS, s32 val)
{
	sm = smgr;
	bulletPhysSys = BPS;

	switch (val) {

		case 0: {
			//Amaya GT
			drive = AWD;
			max_speed = 260.0f;
			carNode = loadMeshFromFile("cars/Amaya GT/coupe.3DS");
			//carNode = loadMeshFromFile("data/Vehicles/Subaru/imprezaZX.3ds");
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
			/*	carNode->setMaterialFlag(video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;*/
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
				loadMeshFromFile("cars/Amaya GT/wheel_right_front.3DS"),//front right wheel
				loadMeshFromFile("cars/Amaya GT/wheel_left_front.3DS"),//front left wheel
				loadMeshFromFile("cars/Amaya GT/wheel_right_back.3DS"),//back right wheel
				loadMeshFromFile("cars/Amaya GT/wheel_left_back.3DS")//back left wheel
				/*
				//in case the new models generate strange results
				loadMeshFromFile("data/Vehicles/Subaru/swheel_left.3ds"),//front right wheel
				loadMeshFromFile("data/Vehicles/Subaru/swheel.3ds"),//front left wheel
				loadMeshFromFile("data/Vehicles/Subaru/swheel_left.3ds"),//back right wheel
				loadMeshFromFile("data/Vehicles/Subaru/swheel.3ds")//back left wheel
				*/
			);

			carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.55f;	//-0.5f
			carParams.FrontAxeOffset = 1.6f;	//1.37f
			carParams.FrontAxeHalfWidth = 1.05f;	//0.8f
			carParams.RearAxeOffset = -1.2f;	//1.37f
			carParams.RearAxeHalfWidth = 1.05f;	//0.8f
			carParams.Mass = 1400.0f;
			carParams.MaxEngineForce = 3400.0f;
			carParams.MaxBreakingForce = 30.0f;	//100.0f
			carParams.SteeringIncrement = 0.5f;	//0.04f
			carParams.SteeringClamp = 0.3f;
			carParams.WheelRadius = 0.40f;	//0.35f
			carParams.WheelWidth = 0.6f;	//0.2f
			carParams.WheelFriction = 2.0f;	//10.0f 0.8f

			carParams.SuspensionStiffness = 70.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.15f;

			carParams.RollInfluence = 0.25f;	//0.25f

			car->init(&carParams);

		}break;

		case 1: {
			//Argent 200 berline
			drive = FWD;
			max_speed = 195.0f;
			carNode = loadMeshFromFile("cars/Argent 200 berline/fr_sedan.3DS");
			//carNode = loadMeshFromFile("data/Vehicles/Subaru/imprezaZX.3ds");
            core::vector3df pos(0.f, 0.f, 0.f);
			carNode->setPosition(pos);
			/*	carNode->setMaterialFlag(video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;*/
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
				loadMeshFromFile("cars/Argent 200 berline/wheel_right.3DS"),//right wheel
				loadMeshFromFile("cars/Argent 200 berline/wheel_left.3DS"),//left wheel
				loadMeshFromFile("cars/Argent 200 berline/wheel_right.3DS"),//right wheel
				loadMeshFromFile("cars/Argent 200 berline/wheel_left.3DS")//left wheel

			);

			carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.6f;	//-0.5f
			carParams.FrontAxeOffset = 2.1f;	//1.37f
			carParams.FrontAxeHalfWidth = 1.f;	//0.8f
			carParams.RearAxeOffset = -1.55f;	//1.37f
			carParams.RearAxeHalfWidth = 1.f;	//0.8f
			carParams.Mass = 1580.0f;
			carParams.MaxEngineForce = 1800.0f;
			carParams.MaxBreakingForce = 15.0f;	//100.0f
			carParams.SteeringIncrement = 0.5f;	//0.04f
			carParams.SteeringClamp = 0.3f;
			carParams.WheelRadius = 0.40f;	//0.35f
			carParams.WheelWidth = 0.6f;	//0.2f
			carParams.WheelFriction = 0.8f;	//10.0f

			carParams.SuspensionStiffness = 50.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.15f;

			carParams.RollInfluence = 0.25f;	//0.25f

			car->init(&carParams);

		}break;

		case 2: {
			//Eagle V8 muscle car
			drive = RWD;
			max_speed = 220.0f;
			carNode = loadMeshFromFile("cars/Eagle V8/us_mcar.3DS");
			//carNode = loadMeshFromFile("data/Vehicles/Subaru/imprezaZX.3ds");
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
			/*	carNode->setMaterialFlag(video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;*/
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
				loadMeshFromFile("cars/Eagle V8/wheel_front_right.3DS"),//right front wheel
				loadMeshFromFile("cars/Eagle V8/wheel_front_left.3DS"),//left front wheel
				loadMeshFromFile("cars/Eagle V8/wheel_back_right.3DS"),//right back wheel
				loadMeshFromFile("cars/Eagle V8/wheel_back_left.3DS")//left back wheel

			);

			carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.55f;	//-0.55f
			carParams.FrontAxeOffset = 1.8f;	//1.37f
			carParams.FrontAxeHalfWidth = 1.15f;	//0.8f
			carParams.RearAxeOffset = -1.72f;	//1.37f
			carParams.RearAxeHalfWidth = 1.f;	//0.8f
			carParams.Mass = 1700.0f;
			carParams.MaxEngineForce = 3000.0f;
			carParams.MaxBreakingForce = 15.0f;	//100.0f
			carParams.SteeringIncrement = 0.5f;	//0.04f
			carParams.SteeringClamp = 0.3f;
			carParams.WheelRadius = 0.4f;	//0.35f
			carParams.WheelWidth = 0.3f;	//0.2f
			carParams.WheelFriction = 0.8f;	//10.0f

			carParams.SuspensionStiffness = 65.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.15f;

			carParams.RollInfluence = 0.25f;	//0.25f

			car->init(&carParams);

		}break;

		case 3: {
			//Endurance Racer ER-12 car
			drive = AWD;
			max_speed = 395.0f;
			carNode = loadMeshFromFile("cars/ER-12/lms_car.3DS");
			//carNode = loadMeshFromFile("data/Vehicles/Subaru/imprezaZX.3ds");
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
			/*	carNode->setMaterialFlag(video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;*/
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
				loadMeshFromFile("cars/ER-12/wheel_fr_right.3DS"),//right front wheel
				loadMeshFromFile("cars/ER-12/wheel_fr_left.3DS"),//left front wheel
				loadMeshFromFile("cars/ER-12/wheel_bk_right.3DS"),//right back wheel
				loadMeshFromFile("cars/ER-12/wheel_bk_left.3DS")//left back wheel

			);

			carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.35f;	//-0.35f
			carParams.FrontAxeOffset = 1.62f;	//1.37f
			carParams.FrontAxeHalfWidth = 1.1f;	//0.8f
			carParams.RearAxeOffset = -1.8f;	//1.37f
			carParams.RearAxeHalfWidth = 1.f;	//0.8f
			carParams.Mass = 1150.0f;
			carParams.MaxEngineForce = 5000.0f;
			carParams.MaxBreakingForce = 40.0f;	//100.0f
			carParams.SteeringIncrement = 0.5f;	//0.04f
			carParams.SteeringClamp = 0.3f;
			carParams.WheelRadius = 0.5f;	//0.35f
			carParams.WheelWidth = 0.6f;	//0.2f
			carParams.WheelFriction = 2.5f;	//10.0f

			carParams.SuspensionStiffness = 110.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.15f;

			carParams.RollInfluence = 0.25f;	//0.25f

			car->init(&carParams);

		}break;

		case 4: {
			//Ghepardo GR supercar
			drive = RWD;
			max_speed = 330.0f;
			carNode = loadMeshFromFile("cars/Ghepardo GR/super_car.3DS");
			//carNode = loadMeshFromFile("data/Vehicles/Subaru/imprezaZX.3ds");
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
			/*	carNode->setMaterialFlag(video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;*/
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
				loadMeshFromFile("cars/Ghepardo GR/wheel_fr_right.3DS"),//right front wheel
				loadMeshFromFile("cars/Ghepardo GR/wheel_fr_left.3DS"),//left front wheel
				loadMeshFromFile("cars/Ghepardo GR/wheel_bk_right.3DS"),//right back wheel
				loadMeshFromFile("cars/Ghepardo GR/wheel_bk_left.3DS")//left back wheel

			);

			carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.45f;	//-0.55f
			carParams.FrontAxeOffset = 1.65f;	//1.37f
			carParams.FrontAxeHalfWidth = 1.f;	//0.8f
			carParams.RearAxeOffset = -1.65f;	//1.37f
			carParams.RearAxeHalfWidth = 0.9f;	//0.8f
			carParams.Mass = 1300.0f;
			carParams.MaxEngineForce = 3700.0f;
			carParams.MaxBreakingForce = 35.0f;	//100.0f
			carParams.SteeringIncrement = 0.5f;	//0.04f
			carParams.SteeringClamp = 0.3f;
			carParams.WheelRadius = 0.40f;	//0.35f
			carParams.WheelWidth = 0.6f;	//0.2f
			carParams.WheelFriction = 2.0f;	//10.0f

			carParams.SuspensionStiffness = 90.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.15f;

			carParams.RollInfluence = 0.25f;	//0.25f

			car->init(&carParams);


		}break;

		case 5: {
			//International Formula IF-12 car
			drive = RWD;
			max_speed = 370.0f;
			carNode = loadMeshFromFile("cars/IF-12/sg_seat.3DS");
			//carNode = loadMeshFromFile("data/Vehicles/Subaru/imprezaZX.3ds");
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
			/*	carNode->setMaterialFlag(video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;*/
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
				loadMeshFromFile("cars/IF-12/wheel_fr_right.3DS"),//right front wheel
				loadMeshFromFile("cars/IF-12/wheel_fr_left.3DS"),//left front wheel
				loadMeshFromFile("cars/IF-12/wheel_bk_right.3DS"),//right back wheel
				loadMeshFromFile("cars/IF-12/wheel_bk_left.3DS")//left back wheel

			);

			carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.18f;	//-0.55f
			carParams.FrontAxeOffset = 1.7f;	//1.37f
			carParams.FrontAxeHalfWidth = 1.3f;	//0.8f
			carParams.RearAxeOffset = -2.4f;	//1.37f
			carParams.RearAxeHalfWidth = 1.4f;	//0.8f
			carParams.Mass = 670.0f;
			carParams.MaxEngineForce = 5000.0f;
			carParams.MaxBreakingForce = 50.0f;	//100.0f
			carParams.SteeringIncrement = 0.5f;	//0.04f
			carParams.SteeringClamp = 0.3f;
			carParams.WheelRadius = 0.6f;	//0.35f
			carParams.WheelWidth = 0.6f;	//0.2f
			carParams.WheelFriction = 10.f;	//10.0f

			carParams.SuspensionStiffness = 150.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.15f;

			carParams.RollInfluence = 0.14f;	//0.25f

			car->init(&carParams);

		}break;

		case 6: {
			//'40 Vulture V8 Hot Rod
			drive = RWD;
			max_speed = 187.0f;
			carNode = loadMeshFromFile("cars/Vulture V8/hot_rod.3DS");
			//carNode = loadMeshFromFile("data/Vehicles/Subaru/imprezaZX.3ds");
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
			/*	carNode->setMaterialFlag(video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;*/
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
				loadMeshFromFile("cars/Vulture V8/wheel_front_right.3DS"),//right front wheel
				loadMeshFromFile("cars/Vulture V8/wheel_front_left.3DS"),//left front wheel
				loadMeshFromFile("cars/Vulture V8/wheel_back_right.3DS"),//right back wheel
				loadMeshFromFile("cars/Vulture V8/wheel_back_left.3DS")//left back wheel

			);

			carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.7f;	//-0.55f
			carParams.FrontAxeOffset = 2.5f;	//1.37f
			carParams.FrontAxeHalfWidth = 1.f;	//0.8f
			carParams.RearAxeOffset = -1.9f;	//1.37f
			carParams.RearAxeHalfWidth = 0.9f;	//0.8f
			carParams.Mass = 1600.0f;
			carParams.MaxEngineForce = 3300.0f;
			carParams.MaxBreakingForce = 10.0f;	//100.0f
			carParams.SteeringIncrement = 0.5f;	//0.04f
			carParams.SteeringClamp = 0.3f;
			carParams.WheelRadius = 0.40f;	//0.35f
			carParams.WheelWidth = 0.6f;	//0.2f
			carParams.WheelFriction = 0.8f;	//10.0f

			carParams.SuspensionStiffness = 50.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 2.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.15f;

			carParams.RollInfluence = 0.25f;	//0.25f

			car->init(&carParams);

		}break;

	}

	car->setPosition(car_pos);
    core::vector3df rot(0, 90, 0);
	car->setRotation(rot, angle); //90

	stopPos = 0;

}

void CLoadCar::Update(s32 drivetype)
{
	car->update(drivetype, max_speed);
}

void CLoadCar::resetCar(s32 newangle)
{
	core::vector3df pos = car->getPosition();
	if(pos.Y < stopPos) {
		car->reset();
        core::vector3df position(pos.X, pos.Y+5, pos.Z);
		car->setPosition(position);
        core::vector3df rotation(0, 90, 0);
		car->setRotation(rotation, newangle);
	}
	//printf("car pos: y = %f\n", pos.Y);
}

irr::scene::IAnimatedMeshSceneNode* CLoadCar::loadMeshFromFile(const char* filename)
{

	irr::scene::IAnimatedMesh* mesh = sm->getMesh(filename);
	if (mesh == NULL) return NULL;

	irr::scene::IAnimatedMeshSceneNode* node = sm->addAnimatedMeshSceneNode(mesh);
	if (node == NULL)
	{
		//mesh->drop();
		return NULL;
	}

	node->setMaterialFlag(video::EMF_LIGHTING, false);	// no lighting

	//shadows....uncomment if shit isn't working
	//shadowNode = node->addShadowVolumeSceneNode(NULL, -1, true);

	return node;
}

void CLoadCar::Clear()
{
	if(carNode)	carNode->remove();
}
