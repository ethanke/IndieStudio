//
// IndieGame.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:42:36 2017 Sousa Victor
// Last update Wed May 10 16:08:03 2017 Sousa Victor
//

#ifndef INDIEGAME_HPP
#define INDIEGAME_HPP

#include "AGame.hpp"

#include "FolderLoader.hpp"
#include "GameCube.hpp"
#include "GameCameraFPS.hpp"

namespace indie {

    class IndieGame: public AGame {

    public:
        IndieGame(int width = 1080, int height = 720);
        ~IndieGame();

    private:
        void addGameObject();
        void addCameraObject();

    };

}

#else

namespace indie {
    class IGame;
    class IndieGame: public AGame;
}

#endif /*INDIEGAME_HPP*/
