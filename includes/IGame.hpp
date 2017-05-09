//
// IGame.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Mon May  8 22:00:26 2017 Sousa Victor
// Last update Mon May  8 22:01:07 2017 Sousa Victor
//

#ifndef IGAME_HPP_
#define IGAME_HPP_

namespace indie {

    class IGame {

    public:
        virtual ~IGame() {};

        virtual void Setup() = 0;
        virtual void Start() = 0;
        virtual void Clean() = 0;

        virtual irr::core::dimension2du const &getWindowSize() const = 0;
        virtual bool isRunning() const = 0;

        static irr::f32 DeltaTime;

    };

}

#endif /*IGAME_HPP_*/
