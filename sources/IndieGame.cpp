//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Thu May 11 22:08:06 2017 Ethan Kerdelhue
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

    SteeringWheel *steeringwheel = new SteeringWheel(this->_smgr, std::string("car/steeringwheel.obj"), 0, -1, irr::core::vector3df(1, 10, 1), irr::core::vector3df(0, 0, 0), irr::core::vector3df(1, 1, 1));
    this->_objectList.push_back(steeringwheel);

    loadMap();

    // Car *car = new Car(this->_smgr, "car/Lambo/MURCIELAGO640.obj", this->_world,
    //                    NULL, -1, 1, irr::core::vector3df(2, 40, 0), irr::core::vector3df(0, -90, 0), irr::core::vector3df(1, 1, 1));
    // this->_objectList.push_back(car);

}

void IndieGame::loadMap() {
    irr::scene::IMesh* mesh_road = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_1.obj").c_str());
    irr::scene::IMeshSceneNode *node_road = this->_smgr->addOctreeSceneNode(mesh_road, 0, -1, 1024);
    node_road->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    node_road->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road->addShadowVolumeSceneNode();
    ICollisionShape *shape_road = new IBvhTriangleMeshShape(node_road, mesh_road, 0);
    auto building_road = this->_world->addRigidBody(shape_road);
    building_road->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
    irr::scene::IMesh* mesh_road2 = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_2.obj").c_str());
    irr::scene::IMeshSceneNode *node_road2 = this->_smgr->addOctreeSceneNode(mesh_road2, 0, -1, 1024);
    node_road2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    node_road2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road2->addShadowVolumeSceneNode();
    ICollisionShape *shape_road2 = new IBvhTriangleMeshShape(node_road2, mesh_road2, 0);
    auto building_road2 = this->_world->addRigidBody(shape_road2);
    building_road2->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);

    #ifndef DEBUG
        irr::scene::IMesh* mesh = this->_smgr->getMesh(std::string("BigCity/BigCity_1.obj").c_str());
        irr::scene::IMeshSceneNode *node = this->_smgr->addOctreeSceneNode(mesh, 0, -1, 1024);
        node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node->addShadowVolumeSceneNode();
        ICollisionShape *shape = new IBvhTriangleMeshShape(node, mesh, 0);
        auto building = this->_world->addRigidBody(shape);
        building->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
        irr::scene::IMesh* mesh2 = this->_smgr->getMesh(std::string("BigCity/BigCity_2.obj").c_str());
        irr::scene::IMeshSceneNode *node2 = this->_smgr->addOctreeSceneNode(mesh2, 0, -1, 1024);
        node2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node2->addShadowVolumeSceneNode();
        ICollisionShape *shape2 = new IBvhTriangleMeshShape(node2, mesh2, 0);
        auto building2 = this->_world->addRigidBody(shape2);
        building2->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
    #endif
}

void IndieGame::addCameraObject() {
    irr::scene::ILightSceneNode *sun_node;
    irr::video::SLight sun_data;
    sun_node = this->_smgr->addLightSceneNode();
    sun_data.Direction = irr::core::vector3df(0,0,0);
    sun_data.Type = irr::video::ELT_DIRECTIONAL;
    sun_data.AmbientColor = irr::video::SColorf(0.5, 0.5, 0.5, 1);
    sun_data.SpecularColor = irr::video::SColorf(0.5, 0.5, 0.5, 1);
    sun_data.DiffuseColor = irr::video::SColorf(0.5, 0.5, 0.5, 1);
    sun_data.CastShadows = true;
    sun_node->setLightData(sun_data);
    sun_node->setPosition(irr::core::vector3df(50, 100, 50));
    sun_node->setRotation(irr::core::vector3df(45,0,0));

    this->_smgr->setAmbientLight(irr::video::SColorf(1.5,1.5,1.5,1));

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
    cameraFps1->setNearValue(0.1);
    this->_cameraList.push_back(cameraFps1);
}
