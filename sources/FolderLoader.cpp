//
// FolderLoader.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_github/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 10 15:49:51 2017 Sousa Victor
// Last update Thu May 11 04:40:26 2017 Sousa Victor
//

#include "FolderLoader.hpp"

using namespace indie;

FolderLoader::FolderLoader(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world,
             std::string const &extension, std::string const &folder) {

    this->_smgr = sceneManager;
    this->_world = world;
    this->_extension = extension;
    this->_folderPath = folder;

}

FolderLoader::~FolderLoader() {

}

void FolderLoader::execute(irr::core::vector3df const &scale, irr::core::vector3df const &position) {
    if(boost::filesystem::is_directory(this->_folderPath)) {
        for(auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(this->_folderPath), {})) {
            std::string path = entry.path().string();
            std::string::size_type idx;
            idx = path.rfind('.');
            if(idx != std::string::npos) {
                std::string extension = path.substr(idx + 1);
                if (extension == this->_extension) {
                    irr::scene::IMesh* mesh = this->_smgr->getMesh(path.c_str());
                    irr::scene::ISceneNode *node = this->_smgr->addOctreeSceneNode(mesh, 0, -1, 1024);
                    node->setScale(scale);
                    node->setPosition(position);
                    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
                    ICollisionShape *shape = new IBvhTriangleMeshShape(node, mesh, 0);
                    auto building = this->_world->addRigidBody(shape);
                    building->setCollisionFlags(ECollisionFlag::ECF_STATIC_OBJECT);
                }
            }
        }
    }
}
