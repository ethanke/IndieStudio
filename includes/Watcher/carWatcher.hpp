/*
** carWatcher.hpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/includes/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:21 2017 Lucas Gambini
** Last update Sat May 13 22:29:53 2017 Lucas Gambini
*/

#ifndef CAR_WATCHER_HPP
#define CAR_WATCHER_HPP

#include <irrlicht.h>
#include "Car.hpp"
#include "EventReceiver.hpp"
#include <functional>
#include <map>

namespace indie {

    class carWatcher : IGameObject {

    public:
        carWatcher(Car const &, EventReceiver *);
        virtual ~carWatcher();

        virtual void OnFrame();

    private:
        Car _car;
        std::map<std::map<int, int>, std::function<void(int)>> _checkpoints;
        EventReceiver *_eventReceiver;

    };

}

#endif /* !CAR_WATCHER_HPP */
