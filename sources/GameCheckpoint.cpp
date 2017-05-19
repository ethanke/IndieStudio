/*
** Checkpoint.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Tue May 16 12:44:22 2017 Lucas Gambini
** Last update Fri May 19 20:17:00 2017 Lucas Gambini
*/

#include "GameCheckpoint.hpp"

using namespace indie;

GameCheckpoint::GameCheckpoint(irr::scene::ISceneManager *sceneManager, irr::f32 size, irr::f32 mass, irr::scene::ISceneNode *parent, irr::s32 id,
                   Type type, const irr::core::vector3df &position, const irr::core::vector3df &rotation, const irr::core::vector3df &scale)
                   : AGameObject (sceneManager), IMeshSceneNode(parent, sceneManager, id, position, rotation, scale) {

    irr::scene::IMesh *_mesh = this->_smgr->getGeometryCreator()->createCylinderMesh(5, 2000, 50, irr::video::SColor(150, 255, 0, 0), true, 0.f);
    this->_cylindre = this->_smgr->addMeshSceneNode(_mesh, 0, -1, position, rotation, scale);
    this->_cylindre->getMaterial(0).AmbientColor.set(255,255,0,0);
    this->_cylindre->getMaterial(0).DiffuseColor.set(255,255,0,0);
    this->_cylindre->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

    this->_type = type;
    this->_isBusy = false;
}

GameCheckpoint &GameCheckpoint::operator=(const GameCheckpoint &obj) {
    AGameObject::operator=(obj);
    this->_cylindre = obj._cylindre;
    this->_type = obj._type;
    this->_isBusy = obj._isBusy;
    return *this;
}


GameCheckpoint::~GameCheckpoint() {

}

void GameCheckpoint::OnFrame() {

}

GameCheckpoint::Type GameCheckpoint::getChType() const {
    return _type;
}

bool GameCheckpoint::isBusy() const {
    return this->_isBusy;
}

void GameCheckpoint::setBusy(bool value) {
    this->_isBusy = value;
}

//CCubeSceneNode
void GameCheckpoint::render() {
    return this->_cylindre->render();
}

const irr::core::aabbox3d<irr::f32> &GameCheckpoint::getBoundingBox() const {
    return this->_cylindre->getBoundingBox();
}


//IMeshSceneNode
void GameCheckpoint::setMesh(irr::scene::IMesh *mesh) {
    this->_cylindre->setMesh(mesh);
}

irr::scene::IMesh *GameCheckpoint::getMesh(void) {
    return this->_cylindre->getMesh();
}

irr::scene::IShadowVolumeSceneNode *GameCheckpoint::addShadowVolumeSceneNode(const irr::scene::IMesh *shadowMesh, irr::s32 id, bool zfailmethod, irr::f32 infinity) {
    return this->_cylindre->addShadowVolumeSceneNode(shadowMesh, id, zfailmethod, infinity);
}

void GameCheckpoint::setReadOnlyMaterials(bool readonly) {
    this->_cylindre->setReadOnlyMaterials(readonly);
}

bool GameCheckpoint::isReadOnlyMaterials() const {
    return this->_cylindre->isReadOnlyMaterials();
}
