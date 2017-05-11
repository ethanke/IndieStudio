//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Fri May 12 01:30:37 2017 Sousa Victor
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

    this->_car = new Car(this->_smgr, this->_world, this);
    this->_objectList.push_back(this->_car);

    loadMap();

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

}

void IndieGame::addEventReceiver() {

}

void IndieGame::loadMap() {
    irr::scene::IMesh* mesh_road = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_1.obj").c_str());
    irr::scene::IMeshSceneNode *node_road = this->_smgr->addOctreeSceneNode(mesh_road, 0, -1);
    node_road->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    node_road->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road->addShadowVolumeSceneNode();
    ICollisionShape *shape_road = new IBvhTriangleMeshShape(node_road, mesh_road, 0);
    auto building_road = this->_world->addRigidBody(shape_road);
    building_road->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
    irr::scene::IMesh* mesh_road2 = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_2.obj").c_str());
    irr::scene::IMeshSceneNode *node_road2 = this->_smgr->addOctreeSceneNode(mesh_road2, 0, -1);
    node_road2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    node_road2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road2->addShadowVolumeSceneNode();
    ICollisionShape *shape_road2 = new IBvhTriangleMeshShape(node_road2, mesh_road2, 0);
    auto building_road2 = this->_world->addRigidBody(shape_road2);
    building_road2->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);

    #ifndef DEBUG
        irr::scene::IMesh* mesh = this->_smgr->getMesh(std::string("BigCity/BigCity_1.obj").c_str());
        irr::scene::IMeshSceneNode *node = this->_smgr->addOctreeSceneNode(mesh, 0, -1);
        node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node->addShadowVolumeSceneNode();
        ICollisionShape *shape = new IBvhTriangleMeshShape(node, mesh, 0);
        auto building = this->_world->addRigidBody(shape);
        building->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
        irr::scene::IMesh* mesh2 = this->_smgr->getMesh(std::string("BigCity/BigCity_2.obj").c_str());
        irr::scene::IMeshSceneNode *node2 = this->_smgr->addOctreeSceneNode(mesh2, 0, -1);
        node2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node2->addShadowVolumeSceneNode();
        ICollisionShape *shape2 = new IBvhTriangleMeshShape(node2, mesh2, 0);
        auto building2 = this->_world->addRigidBody(shape2);
        building2->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
    #endif
}
