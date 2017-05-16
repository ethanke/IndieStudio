//
// GameCube.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 20:29:22 2017 Sousa Victor
// Last update Tue May  9 19:33:35 2017 Sousa Victor
//

#include "GameCube.hpp"

using namespace indie;

GameCube::GameCube(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world, irr::f32 size, irr::f32 mass, irr::scene::ISceneNode *parent, irr::s32 id,
                   const irr::core::vector3df &position, const irr::core::vector3df &rotation, const irr::core::vector3df &scale)
                   : AGameObject (sceneManager), IMeshSceneNode(parent, sceneManager, id, position, rotation, scale) {

    this->_cube = this->_smgr->addCubeSceneNode(size, parent, id, position, rotation, scale);
    setMaterialFlag(irr::video::EMF_LIGHTING, true);
    setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);

    this->_shape = new IBoxShape(this->_cube, mass, false);
    this->_body = world->addRigidBody(this->_shape);

}

GameCube::GameCube(const GameCube &obj) : AGameObject (obj._smgr), IMeshSceneNode(obj._cube->getParent(), obj._cube->getSceneManager(), obj._cube->getID(), obj._cube->getPosition(), obj._cube->getRotation(), obj._cube->getScale()) {
    this->_cube = obj._cube;
}

GameCube &GameCube::operator=(const GameCube &obj) {
    AGameObject::operator=(obj);
    this->_cube = obj._cube;
    return *this;
}


GameCube::~GameCube() {

}

void GameCube::OnFrame() {

}

//CCubeSceneNode
void GameCube::render() {
    return this->_cube->render();
}

const irr::core::aabbox3d<irr::f32> &GameCube::getBoundingBox() const {
    return this->_cube->getBoundingBox();
}


//IMeshSceneNode
void GameCube::setMesh(irr::scene::IMesh *mesh) {
    this->_cube->setMesh(mesh);
}

irr::scene::IMesh *GameCube::getMesh(void) {
    return this->_cube->getMesh();
}

irr::scene::IShadowVolumeSceneNode *GameCube::addShadowVolumeSceneNode(const irr::scene::IMesh *shadowMesh, irr::s32 id, bool zfailmethod, irr::f32 infinity) {
    return this->_cube->addShadowVolumeSceneNode(shadowMesh, id, zfailmethod, infinity);
}

void GameCube::setReadOnlyMaterials(bool readonly) {
    this->_cube->setReadOnlyMaterials(readonly);
}

bool GameCube::isReadOnlyMaterials() const {
    return this->_cube->isReadOnlyMaterials();
}
