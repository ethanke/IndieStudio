/*
** carWatcher.hpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/includes/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:21 2017 Lucas Gambini
** Last update Sun May 14 00:22:29 2017 Lucas Gambini
*/

#ifndef CAR_WATCHER_HPP
#define CAR_WATCHER_HPP

#include <irrlicht.h>
#include <vector3d.h>
#include "Car.hpp"
#include "EventReceiver.hpp"
#include <functional>
#include <map>

namespace indie {

    class carWatcher : public IGameObject {

    public:
        carWatcher(Car const &, EventReceiver *, irr::scene::ISceneManager*);
        virtual ~carWatcher();

        virtual void OnFrame();

    private:
        irr::scene::ISceneManager* _smgr;
        Car _car;
        std::map<std::map<int, int>, std::function<void(int)>> _checkpoints;
        EventReceiver *_eventReceiver;

    };

}

#endif /* !CAR_WATCHER_HPP */
