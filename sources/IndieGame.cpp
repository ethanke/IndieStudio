//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Wed May 10 20:41:50 2017 Sousa Victor
//

#include "IndieGame.hpp"

using namespace indie;

IndieGame::IndieGame(int width, int height) : AGame(width, height) {
}

IndieGame::~IndieGame() {

}

void IndieGame::addGameObject() {
    this->_device->getFileSystem()->addFileArchive((std::string(SOURCES_PATH) + std::string("/Assets/")).c_str());

    GameCube *cube = new GameCube(this->_smgr, this->_world, 10.0f, 1, 0, -1, irr::core::vector3df(0.0f, 0.0f, 30.0f));
    this->_objectList.push_back(cube);

    irr::scene::ISceneNode* skybox = this->_smgr->addSkyBoxSceneNode(
        this->_driver->getTexture("skybox/irrlicht2_up.jpg"),
        this->_driver->getTexture("skybox/irrlicht2_dn.jpg"),
        this->_driver->getTexture("skybox/irrlicht2_lf.jpg"),
        this->_driver->getTexture("skybox/irrlicht2_rt.jpg"),
        this->_driver->getTexture("skybox/irrlicht2_ft.jpg"),
        this->_driver->getTexture("skybox/irrlicht2_bk.jpg"));
    irr::scene::ISceneNode* skydome = this->_smgr->addSkyDomeSceneNode(this->_driver->getTexture("skybox/skydome.jpg"),16,8,0.95f,2.0f);
    this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

    FolderLoader loader(this->_smgr, this->_world, "obj", std::string(SOURCES_PATH) + std::string("/Assets/BigCity"));
    loader.execute(irr::core::vector3df(2, 2, 2), irr::core::vector3df(0, -75, 0));
}

void IndieGame::addCameraObject() {
    irr::SKeyMap keyMap1[5];                    // re-assigne les commandes
    keyMap1[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
    keyMap1[0].KeyCode = irr::KEY_KEY_W;        // w
    keyMap1[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
    keyMap1[1].KeyCode = irr::KEY_KEY_S;        // s
    keyMap1[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
    keyMap1[2].KeyCode = irr::KEY_KEY_A;        // a
    keyMap1[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
    keyMap1[3].KeyCode = irr::KEY_KEY_D;        // d
    keyMap1[4].Action = irr::EKA_JUMP_UP;       // saut
    keyMap1[4].KeyCode = irr::KEY_SPACE;        // barre espace
    GameCameraFPS *cameraFps1 = new GameCameraFPS(this->_smgr, irr::core::rect<irr::s32>(0, 0, this->_windowSize.Width, this->_windowSize.Height), 0, 100.0f, 0.1f, -1, keyMap1, 5, true, 0.1, false, true);
    cameraFps1->setAspectRatio(1.f * cameraFps1->getViewPort().getWidth() / cameraFps1->getViewPort().getHeight());
    cameraFps1->setFOV(cameraFps1->getFOV() * cameraFps1->getViewPort().getHeight() / this->_windowSize.Height);
    this->_cameraList.push_back(cameraFps1);
}
