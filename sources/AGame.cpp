//
// AGame.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Mon May  8 22:22:15 2017 Sousa Victor
// Last update Sun May 14 00:03:29 2017 Sousa Victor
//

#include "AGame.hpp"

using namespace indie;

irr::f32 IGame::DeltaTime;
AGame::AGame(int width, int height) {
    this->_windowSize = irr::core::dimension2du(width, height);
}

AGame::~AGame() {

}


void AGame::Setup() {
    this->_device = irr::createDevice(irr::video::EDT_OPENGL, this->_windowSize, 32, false, false, false, this);
    if (this->_device == 0)
        throw std::exception();

    this->_driver = this->_device->getVideoDriver();
    this->_smgr = this->_device->getSceneManager();
    this->_gui = this->_device->getGUIEnvironment();

    this->_world.reset(createIrrBulletWorld(this->_device, true));
    this->_world->setGravity(irr::core::vector3df(0,-10,0));

    addGameObject();
    addEventReceiver();
}

void AGame::Start() {
    this->_isRunning = true;
    this->loop();
    this->_isRunning = false;
}

void AGame::Clean() {
    this->_device->drop();
}

void AGame::loop() {
    int lastFPS = -1;
    this->_oldTime = this->_device->getTimer()->getTime();
    while(this->_device->run()) {
        processDeltaTime();
        if (this->_device->isWindowActive()) {

            this->_world->stepSimulation(IGame::DeltaTime);
            objectOnFrame();

            irr::scene::ICameraSceneNode *mainCam = this->_smgr->getActiveCamera();
            this->_driver->setViewPort(irr::core::rect<irr::s32>(0, 0, this->_windowSize.Width, this->_windowSize.Height));
            this->_driver->beginScene(true, true, irr::video::SColor(255,20,20,40));
            this->_smgr->drawAll();
            this->_gui->drawAll();

            if (this->_minimapCamera != NULL) {
                this->_smgr->setActiveCamera(this->_minimapCamera);
                this->_driver->setViewPort(dynamic_cast<Minimap *>(this->_minimapCamera)->getViewport());
                this->_smgr->drawAll();
            }
            this->_smgr->setActiveCamera(mainCam);
            this->_driver->endScene();

            int fps = this->_driver->getFPS();
            irr::core::stringw str = L"Q3 [";
            str += this->_driver->getName();
            str += "] FPS:";
            str += fps;
            this->_device->setWindowCaption(str.c_str());
            lastFPS = fps;
        }
    }
}

void AGame::objectOnFrame() {
    for (auto &obj: this->_objectList)
        obj->OnFrame();
    if (this->_minimapCamera)
        this->_minimapCamera->OnFrame();
}

irr::core::dimension2du const &AGame::getWindowSize() const {
    return this->_windowSize;
}

bool AGame::isRunning() const {
    return this->_isRunning;
}

bool AGame::OnEvent(const irr::SEvent& event) {
    for (auto &receiver: this->_eventReceiverList) {
        (void)receiver;
    }
    return EventReceiver::OnEvent(event);
}

void AGame::processDeltaTime() {
    const irr::u32 now = this->_device->getTimer()->getTime();
    IGame::DeltaTime = (irr::f32)(now - this->_oldTime) / 1000.f;
    this->_oldTime = now;
}