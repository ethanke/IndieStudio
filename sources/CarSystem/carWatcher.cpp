/*
** carWatcher.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:24 2017 Lucas Gambini
** Last update Mon May 22 17:33:01 2017 Lucas Gambini
*/

#include "carWatcher.hpp"

using namespace indie;

carWatcher::carWatcher(Car *car, std::vector<GameCheckpoint> const &checkpoints, EventReceiver *eventReceiver, irr::scene::ISceneManager* smgr)
{
    this->_smgr = smgr;
    this->_car = car;
    this->_eventReceiver = eventReceiver;
    this->_checkpoints = checkpoints;
}

carWatcher::~carWatcher()
{

}

bool carWatcher::inLine(float a, float new_a) const
{
    return (a > new_a && a < new_a + 5);
}

bool carWatcher::isCarInCheck(GameCheckpoint const &ch, irr::core::vector3df const &cpos) const {
    bool xIn = inLine(cpos.X, ch.getPosition().X)
    || inLine(ch.getPosition().X, cpos.X);

    bool zIn = inLine(cpos.Z, ch.getPosition().Z)
    || inLine(ch.getPosition().Z, cpos.Z);

    return xIn && zIn;
}

void carWatcher::OnFrame() {
    if (this->_car == NULL)
        return;
    bool check;
    int index = 0;
    irr::core::vector3df cpos = this->_car->getPosition();
    for (auto &x : this->_checkpoints) {
        if ((check = isCarInCheck(x, cpos)) == true && x.isBusy() == false && (this->_car->getVel() <= 1 || x.getChType() == GameCheckpoint::MONEY))
        {
            x.setBusy(true);
            switch (x.getChType()) {
                case GameCheckpoint::GARAGE:
                    _eventReceiver->OnEnterGarage();
                    break;
                case GameCheckpoint::COURSE:
                    _eventReceiver->OnEnterCourse();
                    break;
                case GameCheckpoint::MONEY:
                    x.remove();
                    this->_checkpoints.erase(this->_checkpoints.begin() + index);
                    _eventReceiver->OnEnterMoney();
                    break;
                default:
                    break;
            }
        } else if (check == false) {
            x.setBusy(false);
        }
        index++;
    }
}

void carWatcher::addCheckpoint(GameCheckpoint &check) {
    this->_checkpoints.push_back(check);
}
