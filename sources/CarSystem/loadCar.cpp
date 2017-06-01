#include "loadCar.h"


//default constructor
CLoadCar::CLoadCar()
{

}

//default destructor
CLoadCar::~CLoadCar()
{
    carNode->remove();
    tire1->remove();
    tire2->remove();
    tire3->remove();
    tire4->remove();
}

void CLoadCar::Init(irr::scene::ISceneManager *smgr, physics::CBulletPhysics* BPS, s32 val)
{
	sm = smgr;
	bulletPhysSys = BPS;

    if (val < 0) {
        val = 0;
    } else if (val > 0) {
        val = 0;
    }
	switch (val) {
		case 0: {
			drive = FWD;
			max_speed = 150.0f;
			carNode = loadMeshFromFile("car/SV/SV.obj");
            tire1 = loadMeshFromFile("car/SV/SV_tire_front_left.obj");      //front left
            tire2 = loadMeshFromFile("car/Car/SV_tire_front_right.obj");     //front right
            tire3 = loadMeshFromFile("car/Car/SV_tire_back_left.obj");      //back left
            tire4 = loadMeshFromFile("car/Car/SV_tire_back_right.obj");   //back right
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
                tire1,
                tire2,
                tire3,
                tire4
			);

            carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = -0.45f;	//-0.55f
			carParams.FrontAxeOffset = 1.32f;	//1.37f
			carParams.FrontAxeHalfWidth = 0.8f;	//0.8f
			carParams.RearAxeOffset = -1.383f;	//1.37f
			carParams.RearAxeHalfWidth = 0.85f;	//0.8f
			carParams.Mass = 1600.0f;
			carParams.MaxEngineForce = 2500.0f;
			carParams.MaxBreakingForce = 100.0f;	//100.0f
			carParams.SteeringIncrement = 0.025f;	//0.04f
			carParams.SteeringClamp = 0.4f;
			carParams.WheelRadius = 0.35f;	//0.35f
			carParams.WheelWidth = 0.1f;	//0.2f
			carParams.WheelFriction = 6.f;	//10.0f

			carParams.SuspensionStiffness = 100.0f;	//50.0f
			carParams.SuspensionDamping = 0.4f * 4.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionCompression = 0.3f * 4.0f * btSqrt(carParams.SuspensionStiffness);
			carParams.SuspensionRestLength = 0.1f;

			carParams.RollInfluence = 0.05;	//0.25f

			car->init(&carParams);

		}break;
	}

	car->setPosition(car_pos);
    core::vector3df rot(0, 90, 0);
	car->setRotation(rot, 90); //90

}

void CLoadCar::Update(s32 drivetype)
{
	car->update(drivetype, max_speed);
}

void CLoadCar::resetCar(s32 newangle)
{
	core::vector3df pos = car->getPosition();
	car->reset();
    core::vector3df position(pos.X, pos.Y+2, pos.Z);
	car->setPosition(position);
    core::vector3df rotation(0, 90, 0);
	car->setRotation(rotation, newangle);
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
    //node->addShadowVolumeSceneNode(NULL, -1, true);

	return node;
}

void CLoadCar::Clear()
{
	if(carNode)	carNode->remove();
}
