//
// CarMotor.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat May 13 22:28:43 2017 Sousa Victor
// Last update Mon May 15 15:58:41 2017 Sousa Victor
//

#ifndef CARMOTOR_HPP_
#define CARMOTOR_HPP_

#include "CarWheel.hpp"
#include "Utils.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"

namespace indie {

    class CarMotor {

    public:
        CarMotor(irr::gui::IGUIEnvironment* guiManager, bool debugMode = false);
        ~CarMotor();

        void OnFrame(int inputX, int inputY);

    private:
        bool _debug;
        irr::gui::IGUIEnvironment* _gui;

        irr::gui::IGUIStaticText *_inputGui;

    };

}

#else

namespace indie {

    class CarMotor;

}

#endif /*CARMOTOR_HPP_*/
