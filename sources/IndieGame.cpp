//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Sat May 13 22:07:51 2017 Sousa Victor
//

#include "IndieGame.hpp"

using namespace indie;

IndieGame::IndieGame(int width, int height) : AGame(width, height) {
}

IndieGame::~IndieGame() {

}

void IndieGame::addGameObject() {
    this->_device->getFileSystem()->addFileArchive((std::string(SOURCES_PATH) + std::string("/Assets/")).c_str());

    irr::scene::ISceneNode* skydome = this->_smgr->addSkyDomeSceneNode(this->_driver->getTexture("skybox/Skydome1.png"),16,8,0.95f,2.0f);
    this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

//    this->_car = new Car(this->_smgr, this->_world, this);
//    this->_objectList.push_back(this->_car);

    loadMap();


    // Setup the light source node
    irr::scene::ILightSceneNode *sun_node;
    irr::video::SLight sun_data;
    sun_node = this->_smgr->addLightSceneNode();
    sun_data.Direction = irr::core::vector3df(0, 0, 0);
    sun_data.Type = irr::video::ELT_DIRECTIONAL;
    sun_data.AmbientColor = irr::video::SColorf(0.1f, 0.1f, 0.1f, 1);
    sun_data.SpecularColor = irr::video::SColorf(0.4f, 0.4f, 0.4f, 1);
    sun_data.DiffuseColor = irr::video::SColorf(1.0f, 1.0f, 1.0f, 1);
    sun_data.CastShadows = true;
    sun_node->setLightData(sun_data);
    sun_node->setPosition(irr::core::vector3df(0, 0, 0));
    sun_node->setRotation(irr::core::vector3df(0, 0, 0));
    this->_smgr->setAmbientLight(irr::video::SColorf(1.85, 1.85, 2, 2.5));
}

void IndieGame::addEventReceiver() {

}

void IndieGame::loadMap() {
    ILiquidBody* water = _world->addLiquidBody(irr::core::vector3df(-5000,0,5000),irr::core::aabbox3df(0, -10000, 0, 10000, 0, 10000), 500.0f, 200.0f);
    water->setCurrentDirection(irr::core::vector3df(0,0,0));
    water->setGlobalWaveChangeIncrement(0.01f);
    water->setGlobalWaveUpdateFrequency(1.0f);
    water->setMaxGlobalWaveHeight(4.0f);
    water->setMinGlobalWaveHeight(-1.0f);
    water->setLocalWaveValues(10,1,0.5f);
    water->setInfinite(true);
    water->setInfiniteDepth(true);
    water->setLiquidDensity(0.1f);

    irr::scene::IAnimatedMesh* mesh = _device->getSceneManager()->addHillPlaneMesh( "myHill",
                irr::core::dimension2d<irr::f32>(20,20),
                irr::core::dimension2d<irr::u32>(40,40), 0, 0,
                irr::core::dimension2d<irr::f32>(0,0),
                irr::core::dimension2d<irr::f32>(1000,1000));
    irr::scene::ISceneNode* node = _device->getSceneManager()->addWaterSurfaceSceneNode(mesh->getMesh(0), 0.0f, 300.0f, 30.0f);
    node->setPosition(irr::core::vector3df(0,5,0));
    node->setMaterialTexture(0, _device->getVideoDriver()->getTexture("water.jpg"));
    node->setScale(irr::core::vector3df(1000,1,1000));
    node->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    node->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, false);


    irr::scene::IMesh* mesh_road = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_1.obj").c_str());
    irr::scene::IMeshSceneNode *node_road = this->_smgr->addOctreeSceneNode(mesh_road, 0, -1);
    node_road->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    node_road->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
    node_road->addShadowVolumeSceneNode();
    ICollisionShape *shape_road = new IBvhTriangleMeshShape(node_road, mesh_road, 0);
    auto building_road = this->_world->addRigidBody(shape_road);
    building_road->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
    irr::scene::IMesh* mesh_road2 = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_2.obj").c_str());
    irr::scene::IMeshSceneNode *node_road2 = this->_smgr->addOctreeSceneNode(mesh_road2, 0, -1);
    node_road2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    node_road2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road2->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
    node_road2->addShadowVolumeSceneNode();
    ICollisionShape *shape_road2 = new IBvhTriangleMeshShape(node_road2, mesh_road2, 0);
    auto building_road2 = this->_world->addRigidBody(shape_road2);
    building_road2->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);

    #ifndef DEBUG
        irr::scene::IMesh* mesh1 = this->_smgr->getMesh(std::string("BigCity/BigCity_1.obj").c_str());
        irr::scene::IMeshSceneNode *node1 = this->_smgr->addOctreeSceneNode(mesh1, 0, -1);
        node1->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node1->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node1->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node1->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
        node1->addShadowVolumeSceneNode();
        ICollisionShape *shape1 = new IBvhTriangleMeshShape(node1, mesh1, 0);
        auto building1 = this->_world->addRigidBody(shape1);
        building1->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
        irr::scene::IMesh* mesh2 = this->_smgr->getMesh(std::string("BigCity/BigCity_2.obj").c_str());
        irr::scene::IMeshSceneNode *node2 = this->_smgr->addOctreeSceneNode(mesh2, 0, -1);
        node2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node2->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
        node2->addShadowVolumeSceneNode();
        ICollisionShape *shape2 = new IBvhTriangleMeshShape(node2, mesh2, 0);
        auto building2 = this->_world->addRigidBody(shape2);
        building2->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
    #endif

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
   GameCameraFPS *cameraFps1 = new GameCameraFPS(this->_smgr, 0, 100.0f, 0.5f, -1, keyMap1, 5, true, 0.1, false, true);
   cameraFps1->setFarValue(1000);
}
