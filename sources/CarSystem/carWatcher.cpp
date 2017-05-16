/*
** carWatcher.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:24 2017 Lucas Gambini
** Last update Tue May 16 12:34:56 2017 Lucas Gambini
*/

#include "carWatcher.hpp"

using namespace indie;

carWatcher::carWatcher(Car const &car, EventReceiver *eventReceiver, irr::scene::ISceneManager* smgr)
{
    _smgr = smgr;
    _car = car;
    _eventReceiver = eventReceiver;

}

carWatcher::~carWatcher()
{

}

void carWatcher::OnFrame() {
    if (_car.getCamera()->getPosition().X >= 0 && _car.getCamera()->getPosition().X <= 20 && // Condition de merde temporairement
        _car.getCamera()->getPosition().Y >= 0 && _car.getCamera()->getPosition().Y <= 20) {
            _eventReceiver->OnEnterGarage();
        }
}
