/*
** carWatcher.hpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/includes/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:21 2017 Lucas Gambini
** Last update Tue May 16 18:23:52 2017 Lucas Gambini
*/

#ifndef CAR_WATCHER_HPP
#define CAR_WATCHER_HPP

#include <irrlicht.h>
#include <vector3d.h>
#include "Car.hpp"
#include "EventReceiver.hpp"
#include "GameCheckpoint.hpp"
#include <map>

namespace indie {

    class carWatcher : public IGameObject {

    public:
        carWatcher(Car *, std::vector<GameCheckpoint> const &, EventReceiver *, irr::scene::ISceneManager *);
        virtual ~carWatcher();

        virtual void OnFrame();

    private:
        irr::scene::ISceneManager* _smgr;
        Car *_car;
        EventReceiver *_eventReceiver;
        std::vector<GameCheckpoint> _checkpoints;
    };

}

#endif /* !CAR_WATCHER_HPP */
