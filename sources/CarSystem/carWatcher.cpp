/*
** carWatcher.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:24 2017 Lucas Gambini
** Last update Wed May 17 00:44:20 2017 Lucas Gambini
*/

#include "carWatcher.hpp"

using namespace indie;

carWatcher::carWatcher(Car *car, std::vector<GameCheckpoint> const &checkpoints, EventReceiver *eventReceiver, irr::scene::ISceneManager* smgr)
{
    _smgr = smgr;
    _car = car;
    _eventReceiver = eventReceiver;
    _checkpoints = checkpoints;
}

carWatcher::~carWatcher()
{

}

bool carWatcher::inLine(float a, float new_a) const
{
    return (a >= new_a && a <= new_a + 5);
}

bool carWatcher::isCarInCheck(GameCheckpoint const &ch) const {
    bool xIn = inLine(_car->getPosition().X, ch.getPosition().X)
    || inLine(ch.getPosition().X, _car->getPosition().X);

    bool zIn = inLine(_car->getPosition().Z, ch.getPosition().Z)
    || inLine(ch.getPosition().Z, _car->getPosition().Z);

    return xIn && zIn;
}

void carWatcher::OnFrame() {
    if (this->_car == NULL)
        return;
    irr::core::vector3df cpos = this->_car->getPosition();

    for (auto const &x : this->_checkpoints) {
        if (isCarInCheck(x) == true)
        {
            switch (x.getChType()) {
                case GameCheckpoint::GARAGE:
                    _eventReceiver->OnEnterGarage();
                    break;
                default:
                    break;
            }
        }
    }
}
