/*
** RandomEvent.hpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/includes
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 20 01:48:12 2017 Lucas Gambini
** Last update Sat May 20 16:41:37 2017 Lucas Gambini
*/

#ifndef RANDOM_EVENT_HPP
#define RANDOM_EVENT_HPP

#include "carWatcher.hpp"
#include "IGameObject.hpp"
#include <random>

namespace indie {

    class RandomEvent : public IGameObject {

        public:
            RandomEvent(irr::scene::ISceneManager *, carWatcher *);
            ~RandomEvent();

            void OnFrame();

        private:
            irr::scene::ISceneManager* _smgr;
            carWatcher *_watcher;
            int _currentOffset;
            irr::f32 _elapsedTime;
            std::vector<irr::core::vector3df> _preset;
            int _index;
            int _IMin;
            int _IMax;
    };

};

#endif /* !RANDOM_EVENT_HPP */
