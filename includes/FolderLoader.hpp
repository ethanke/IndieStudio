//
// FolderLoader.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_github/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Wed May 10 15:46:10 2017 Sousa Victor
// Last update Wed May 10 23:50:30 2017 Sousa Victor
//

#ifndef FOLDERLOADER_HPP
#define FOLDERLOADER_HPP

#include <irrlicht.h>
#include <irrBullet.h>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

namespace indie {

    class ILoader {

    public:
        virtual ~ILoader() {};

        virtual void execute(irr::core::vector3df const &scale, irr::core::vector3df const &position) = 0;

    };

    class FolderLoader: public ILoader {

    public:
        FolderLoader(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world,
                     std::string const &extension, std::string const &folder);
        ~FolderLoader();

        virtual void execute(irr::core::vector3df const &scale = irr::core::vector3df(1, 1, 1), irr::core::vector3df const &position = irr::core::vector3df(0, 0, 0));

    private:
        irr::scene::ISceneManager *_smgr;
        std::shared_ptr<irrBulletWorld> _world;
        std::string _extension;
        std::string _folderPath;

    };

}
#endif /*FOLDERLOADER_HPP*/
