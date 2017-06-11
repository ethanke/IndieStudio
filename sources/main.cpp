//
// main.cpp for  in /Users/vicostudio/Documents/Shared Folder/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu May  4 17:46:24 2017 Sousa Victor
// Last update Sun Jun 11 17:24:25 2017 Sousa Victor
//

#include "IndieGame.hpp"

int main(int argc, char* argv[]) {
    indie::IndieGame game(1400, 800);

    game.Setup();
    game.Start();
    game.Clean();

    return 1;
}
