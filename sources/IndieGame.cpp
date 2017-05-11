//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Thu May 11 21:26:11 2017 Ethan Kerdelhue
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

    SteeringWheel *steeringwheel = new SteeringWheel(this->_smgr, std::string("car/steeringwheel.obj"), 0, -1, irr::core::vector3df(2, 8, 0), irr::core::vector3df(0, 90, 0), irr::core::vector3df(0.01, 0.01, 0.01));
    this->_objectList.push_back(steeringwheel);

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

    Car *car = new Car(this->_smgr, "car/Lambo/MURCIELAGO640.obj", this->_world,
                       NULL, -1, 1, irr::core::vector3df(2, 7, 0), irr::core::vector3df(0, -90, 0), irr::core::vector3df(0.40, 0.40, 0.40));
    this->_objectList.push_back(car);

}

void IndieGame::addCameraObject() {
    irr::scene::ILightSceneNode *sun_node;
    irr::video::SLight sun_data;
    sun_node = this->_smgr->addLightSceneNode();
    sun_data.Direction = irr::core::vector3df(0,0,0);
    sun_data.Type = irr::video::ELT_DIRECTIONAL;
    sun_data.AmbientColor = irr::video::SColorf(0.1f,0.1f,0.1f,1);
    sun_data.SpecularColor = irr::video::SColorf(0.4f,0.4f,0.4f,1);
    sun_data.DiffuseColor = irr::video::SColorf(1.0f,1.0f,1.0f,1);
    sun_data.CastShadows = false;
    sun_node->setLightData(sun_data);
    sun_node->setPosition(irr::core::vector3df(0,0,0));
    sun_node->setRotation(irr::core::vector3df(0,0,0));

    this->_smgr->setAmbientLight(irr::video::SColorf(0.25,0.25,0.25,1));

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
    GameCameraFPS *cameraFps1 = new GameCameraFPS(this->_smgr, irr::core::rect<irr::s32>(0, 0, this->_windowSize.Width, this->_windowSize.Height), 0, 100.0f, 0.01f, -1, keyMap1, 5, true, 0.1, false, true);
    cameraFps1->setAspectRatio(1.f * cameraFps1->getViewPort().getWidth() / cameraFps1->getViewPort().getHeight());
    cameraFps1->setFOV(cameraFps1->getFOV() * cameraFps1->getViewPort().getHeight() / this->_windowSize.Height);
    cameraFps1->setNearValue(0.1);
    this->_cameraList.push_back(cameraFps1);
}
