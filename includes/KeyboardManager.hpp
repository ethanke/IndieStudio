/*
** KeyboardManager.hpp for IndieStudio in /Users/gmblucas/Desktop/Shared/IndieStudio/includes
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Fri Jun 16 19:35:25 2017 Lucas Gambini
** Last update Fri Jun 16 21:17:48 2017 Lucas Gambini
*/

#ifndef KEYBOARDMANAGER_HPP
#define KEYBOARDMANAGER_HPP

#include "Keyboard.hpp"

namespace indie {

    class KeyboardManager {

    public:
        KeyboardManager();
        ~KeyboardManager();
        static KeyboardManager &Instance();
        void setMap(std::map<Keyboard::KEYCODE_TYPE, irr::EKEY_CODE> const &map);
        std::map<Keyboard::KEYCODE_TYPE, irr::EKEY_CODE> &getMap();

    private:
        static KeyboardManager _instance;
        std::map<Keyboard::KEYCODE_TYPE, irr::EKEY_CODE> _map;

    };

}

#else

namespace indie {

    class KeyboardManager;

}

#endif /* !KEYBOARDMANAGER_HPP */
