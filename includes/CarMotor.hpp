//
// CarMotor.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat May 13 22:28:43 2017 Sousa Victor
// Last update Sat May 13 22:57:47 2017 Sousa Victor
//

#ifndef CARMOTOR_HPP_
#define CARMOTOR_HPP_

#include "IGameObject.hpp"

namespace indie {

    class CarMotor {

    public:
        CarMotor();
        ~CarMotor();

        void OnFrame(int inputX, int inputY);

    };

}

#endif /*CARMOTOR_HPP_*/