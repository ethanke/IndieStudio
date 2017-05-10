//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Thu May 11 01:46:46 2017 Sousa Victor
//

#include "IndieGame.hpp"

using namespace indie;

IndieGame::IndieGame(int width, int height) : AGame(width, height) {
}

IndieGame::~IndieGame() {

}

void IndieGame::addGameObject() {
    this->_device->getFileSystem()->addFileArchive((std::string(SOURCES_PATH) + std::string("/Assets/")).c_str());
    this->_device->getCursorControl()->setVisible(false);

    irr::scene::ISceneNode* skydome = this->_smgr->addSkyDomeSceneNode(this->_driver->getTexture("skybox/Skydome1.png"),16,8,0.95f,2.0f);
    this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

    #ifdef DEBUG
        std::string array[8] = {
            "BigCity/CityEngineMaterial_2_part1.obj",
            "BigCity/CityEngineMaterial_2_part2.obj",
            "BigCity/CityEngineMaterial_2_part3.obj",
            "BigCity/CityEngineMaterial_6.obj",
            "BigCity/CityEngineMaterial.obj",
            "BigCity/CityEngineMaterial_9.obj",
            "BigCity/CityEngineMaterial_12.obj",
            "BigCity/CityEngineMaterial_10.obj"
        };
        for (auto const &str: array) {
            irr::scene::IMesh* mesh = this->_smgr->getMesh(str.c_str());
            irr::scene::ISceneNode *node = this->_smgr->addOctreeSceneNode(mesh, 0, -1, 1024);
            node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
            ICollisionShape *shape = new IBvhTriangleMeshShape(node, mesh, 0);
            auto building = this->_world->addRigidBody(shape);
            building->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
        }
    #else
        FolderLoader loader(this->_smgr, this->_world, "obj", std::string(SOURCES_PATH) + std::string("/Assets/BigCity"));
        loader.execute();
    #endif

    Car *car = new Car(this->_smgr, "Lambo/MURCIELAGO640.obj", this->_world,
                       NULL, -1, 1, irr::core::vector3df(5, 10, 0), irr::core::vector3df(0, -90, 0), irr::core::vector3df(0.40, 0.40, 0.40));
    this->_objectList.push_back(car);

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
    GameCameraFPS *cameraFps1 = new GameCameraFPS(this->_smgr, irr::core::rect<irr::s32>(0, 0, this->_windowSize.Width, this->_windowSize.Height), 0, 75.0f, 0.001f, -1, keyMap1, 5, true, 0.1, false, true);
    cameraFps1->setAspectRatio(1.f * cameraFps1->getViewPort().getWidth() / cameraFps1->getViewPort().getHeight());
    cameraFps1->setFOV(cameraFps1->getFOV() * cameraFps1->getViewPort().getHeight() / this->_windowSize.Height);
    this->_cameraList.push_back(cameraFps1);
}
