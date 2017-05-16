/*
** Checkpoint.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Tue May 16 12:44:22 2017 Lucas Gambini
** Last update Tue May 16 17:08:10 2017 Lucas Gambini
*/

#include "GameCheckpoint.hpp"

using namespace indie;

GameCheckpoint::GameCheckpoint(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world, irr::f32 size, irr::f32 mass, irr::scene::ISceneNode *parent, irr::s32 id,
                   const irr::core::vector3df &position, const irr::core::vector3df &rotation, const irr::core::vector3df &scale)
                   : AGameObject (sceneManager), IMeshSceneNode(parent, sceneManager, id, position, rotation, scale) {

    irr::scene::IMesh *_mesh = this->_smgr->getGeometryCreator()->createCylinderMesh(5, 2000, 50, irr::video::SColor(150, 255, 0, 0), true, 0.f);
    this->_cylindre = this->_smgr->addMeshSceneNode(_mesh, 0, -1, position, rotation, scale);
    this->_cylindre->getMaterial(0).AmbientColor.set(0,255,0,0);
    this->_cylindre->getMaterial(0).DiffuseColor.set(0,255,0,0);
    this->_cylindre->getMaterial(0).Lighting = true;
    this->_cylindre->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
    this->_cylindre->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    this->_cylindre->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    this->_cylindre->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    this->_cylindre->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, true);

    this->_shape = new ICylinderShape(this->_cylindre, mass, false);
    this->_body = world->addRigidBody(this->_shape);
}

GameCheckpoint::GameCheckpoint(const GameCheckpoint &obj) : AGameObject (obj._smgr), IMeshSceneNode(obj._cylindre->getParent(), obj._cylindre->getSceneManager(), obj._cylindre->getID(), obj._cylindre->getPosition(), obj._cylindre->getRotation(), obj._cylindre->getRotation()) {
    this->_cylindre = obj._cylindre;
}

GameCheckpoint &GameCheckpoint::operator=(const GameCheckpoint &obj) {
    AGameObject::operator=(obj);
    this->_cylindre = obj._cylindre;
    return *this;
}


GameCheckpoint::~GameCheckpoint() {

}

void GameCheckpoint::OnFrame() {

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
