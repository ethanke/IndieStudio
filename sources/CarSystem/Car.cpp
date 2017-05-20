//
// Car.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May 11 23:18:00 2017 Sousa Victor
// Last update Sat May 20 22:01:10 2017 Sousa Victor
//

#include "Car.hpp"

using namespace indie;

Car::Car(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no):
    AGameObject(sceneManager) {

    this->_eventReceiver = eventReceiver;
    m_bulletPhysicsSystem = bulletPhysicsSystem;

    m_cameraPosition = core::vector3df(30, 30, 30);
	m_cameraHeight = 5.0f;
	m_minCameraDistance = 2.0f; //1.0f;
	m_maxCameraDistance = 5.0f;
    this->_camera = new BasicCamera(this->_smgr, 0, -1, irr::core::vector3df(-4, 38, 0), irr::core::vector3df(2, 36, 0));

    reverse = false;
	drive = true;
	park = false;

    m_car_no = car_no;
    loadCar.setCarPos(irr::core::vector3df(2, 38, 0));
	//loadCar.setCarStRot(irr::core::vector3df(180, 82.5, 175));
	loadCar.Init(this->_smgr, m_bulletPhysicsSystem, m_car_no);

	//lighting && shininess 0 1 3 5
	if( m_car_no == 0 || m_car_no == 1 || m_car_no == 3 || m_car_no == 5 ) {
		loadCar.getCarNode()->setMaterialFlag(video::EMF_LIGHTING, true);
		loadCar.getCarNode()->getMaterial(loadCar.getCarNode()->getMaterialCount()).Shininess = 50.0f;
		loadCar.getCarNode()->getMaterial(loadCar.getCarNode()->getMaterialCount()).SpecularColor.set(255,128,128,0);
	}

	m_car = loadCar.getCar();
    drive_tipe = loadCar.returnDrive();

}

Car::~Car() {

}

void Car::OnFrame() {
    int valueX = ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 0 :
                 ( this->_eventReceiver->IsKeyDown(irr::KEY_UP) && !this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? 1 :
                 (!this->_eventReceiver->IsKeyDown(irr::KEY_UP) &&  this->_eventReceiver->IsKeyDown(irr::KEY_DOWN)) ? -1 : 0;
    int valueY = ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 0 :
                 ( this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) && !this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? -1 :
                 (!this->_eventReceiver->IsKeyDown(irr::KEY_LEFT) &&  this->_eventReceiver->IsKeyDown(irr::KEY_RIGHT)) ? 1 : 0;

    KeyboardEvent();
	loadCar.Update(drive_tipe);
    updateCamera();
}

void Car::updateCamera() {
	// look at the vehicle
	core::vector3df cameraTargetPosition = m_car->getPosition();

	// interpolate the camera height
	m_cameraPosition.Y = (15.0f * m_cameraPosition.Y + cameraTargetPosition.Y + m_cameraHeight) / 16.0f;

	core::vector3df camToObject = cameraTargetPosition - m_cameraPosition;

	//keep distance between min and max distance
	float cameraDistance = camToObject.getLength();
	float correctionFactor = 0.0f;

	if (cameraDistance < m_minCameraDistance)
	{
		correctionFactor = 0.15 * (m_minCameraDistance - cameraDistance) / cameraDistance;
	}
	else if (cameraDistance > m_maxCameraDistance)
	{
		correctionFactor = 0.15 * (m_maxCameraDistance - cameraDistance) / cameraDistance;
	}

	m_cameraPosition -= correctionFactor * camToObject;

	this->_camera->setPosition(m_cameraPosition);
	this->_camera->setTarget(cameraTargetPosition);
}

void Car::KeyboardEvent() {
	//steering
	if(_eventReceiver->IsKeyDown(irr::KEY_UP))
	//if(_eventReceiver->IsKeyDown(irr::KEY_KEY_I))
	{
		if(!reverse)
			m_car->goForward();
		else
			m_car->goBackwards();
		park = false;
	} else m_car->slowdown();
	if(_eventReceiver->IsKeyDown(irr::KEY_DOWN))
	//if(_eventReceiver->IsKeyDown(irr::KEY_KEY_K))
	{
		m_car->stop();
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_LEFT))
	//if(_eventReceiver->IsKeyDown(irr::KEY_KEY_J))
	{
		m_car->steerLeft();
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_RIGHT))
	//if(_eventReceiver->IsKeyDown(irr::KEY_KEY_L))
	{
		m_car->steerRight();
	}
	else if(!_eventReceiver->IsKeyDown(irr::KEY_LEFT) && !_eventReceiver->IsKeyDown(irr::KEY_RIGHT))
		m_car->resetSteering();
	if(_eventReceiver->IsKeyDown(irr::KEY_SPACE))
	{
		m_car->handbrake();
		park = true;
		//reverse = false;
		//drive = false;
	}
/*	if(_eventReceiver->IsKeyDown(irr::KEY_KEY_V))
	{
		aiDebug = !aiDebug;
		if ( aimgr )
			aimgr->setDebugVisible(aiDebug);
	}*/
	if(_eventReceiver->IsKeyDown(irr::KEY_KEY_N))
	{
		//stopCount = true;
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_KEY_R))
	{
		reverse = true;
		drive = false;
		park = false;
	}
	//change with D in release version
	if(_eventReceiver->IsKeyDown(irr::KEY_KEY_D))
	{
		reverse = false;
		park = false;
		drive = true;
	}
	if(_eventReceiver->IsKeyDown(irr::KEY_BACK))
	{
		loadCar.resetCar( m_car->getAngle() ); // 90
	}

}

irr::core::vector3d<float>	Car::getPosition() const {
    return irr::core::vector3df(0, 0, 0);
}


AGameCamera *Car::getCamera() const {
    return this->_camera;
}
