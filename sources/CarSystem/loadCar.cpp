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

    if (val < 0) {
        val = 0;
    } else if (val > 0) {
        val = 0;
    }
	switch (val) {
		case 0: {
			drive = AWD;
			max_speed = 180.0f;
			carNode = loadMeshFromFile("car/Car/old_F1.obj");
			carNode->setPosition(core::vector3df(0.f, 0.f, 0.f));
            carNode->setMaterialFlag(irr::video::EMF_LIGHTING, true);
			carNode->getMaterial(0).Shininess = 20.f;
			car = new physics::PhysicsCar(
				bulletPhysSys,
				carNode,
                loadMeshFromFile("car/Car/old_F1_tire_right.obj"),
                loadMeshFromFile("car/Car/old_F1_tire_left.obj"),
                loadMeshFromFile("car/Car/old_F1_tire_right.obj"),
                loadMeshFromFile("car/Car/old_F1_tire_left.obj")
			);

            carParams.CenterOfMassOffset = core::vector3df(0, -0.09, 0);
			carParams.CarBodyOffset = 0.05f;	//-0.55f
			carParams.FrontAxeOffset = 1.8f;	//1.37f
			carParams.FrontAxeHalfWidth = 0.95f;	//0.8f
			carParams.RearAxeOffset = -1.35f;	//1.37f
			carParams.RearAxeHalfWidth = 0.85f;	//0.8f
			carParams.Mass = 1600.0f;
			carParams.MaxEngineForce = 2500.0f;
			carParams.MaxBreakingForce = 50.0f;	//100.0f
			carParams.SteeringIncrement = 0.04f;	//0.04f
			carParams.SteeringClamp = 0.2f;
			carParams.WheelRadius = 0.5f;	//0.35f
			carParams.WheelWidth = 0.2f;	//0.2f
			carParams.WheelFriction = 10.f;	//10.0f

			carParams.SuspensionStiffness = 70.0f;	//50.0f
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
    //node->addShadowVolumeSceneNode(NULL, -1, true);

	return node;
}

void CLoadCar::Clear()
{
	if(carNode)	carNode->remove();
}