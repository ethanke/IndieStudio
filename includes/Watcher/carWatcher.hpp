/*
** carWatcher.hpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/includes/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:21 2017 Lucas Gambini
** Last update Sat May 13 20:53:05 2017 Lucas Gambini
*/

#ifndef CAR_WATCHER_HPP
#define CAR_WATCHER_HPP

#include "Car.hpp"
#include <functional>
#include <map>

namespace indie {

    class carWatcher : IGameObject {

    public:
        carWatcher(Car const &);
        virtual ~carWatcher();

        virtual void OnFrame();

    private:
        Car _car;
        std::map<std::map<int, int>, std::function<void(int)>> _checkpoints;

    };

}

#endif /* !CAR_WATCHER_HPP */
