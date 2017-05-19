/*
** carWatcher.hpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/includes/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:21 2017 Lucas Gambini
** Last update Fri May 19 20:15:21 2017 Lucas Gambini
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
        bool isCarInCheck(GameCheckpoint const &ch, irr::core::vector3df const &cpos) const;
        bool inLine(float a, float new_a) const;

    private:
        irr::scene::ISceneManager* _smgr;
        Car *_car;
        EventReceiver *_eventReceiver;
        std::vector<GameCheckpoint> _checkpoints;
    };

}

#endif /* !CAR_WATCHER_HPP */
