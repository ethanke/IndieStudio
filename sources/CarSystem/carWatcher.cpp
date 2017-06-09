/*
** carWatcher.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:24 2017 Lucas Gambini
** Last update Fri Jun 09 20:55:31 2017 Lucas Gambini
*/

#include "carWatcher.hpp"

using namespace indie;

carWatcher::carWatcher(Car *car, std::vector<GameCheckpoint> const &checkpoints, EventReceiver *eventReceiver, irr::scene::ISceneManager* smgr)
{
    this->_smgr = smgr;
    this->_car = car;
    this->_eventReceiver = eventReceiver;
    this->_checkpoints = checkpoints;
    this->_needRemove = false;
}

carWatcher::~carWatcher()
{

}

bool carWatcher::inLine(float a, float new_a, float rad) const
{
    return (a > new_a && a < new_a + rad);
}

bool carWatcher::isCarInCheck(GameCheckpoint const &ch, irr::core::vector3df const &cpos) const {
    bool xIn = inLine(cpos.X, ch.getChPosition().X, ch.getRadius()) || inLine(ch.getChPosition().X, cpos.X, ch.getRadius());
    bool zIn = inLine(cpos.Z, ch.getChPosition().Z, ch.getRadius()) || inLine(ch.getChPosition().Z, cpos.Z, ch.getRadius());
    return xIn && zIn;
}

void carWatcher::OnFrame() {
    if (this->_car == NULL)
        return;
    bool check;
    int index = 0;
    irr::core::vector3df cpos = this->_car->getPosition();
    for (auto &x : this->_checkpoints) {
        if ((check = isCarInCheck(x, cpos)) == true && x.isBusy() == false && (this->_car->getVel() <= 1 || (x.getChType() == GameCheckpoint::MONEY || x.getChType() == GameCheckpoint::IN_COURSE)))
        {
            x.setBusy(true);
            switch (x.getChType()) {
                case GameCheckpoint::GARAGE:
                    _eventReceiver->OnEnterGarage();
                    break;
                case GameCheckpoint::COURSE:
                    _eventReceiver->OnEnterCourse(x);
                    break;
                case GameCheckpoint::MONEY:
                    x.remove();
                    this->_checkpoints.erase(this->_checkpoints.begin() + index);
                    Client::Instance().debug(std::to_string(this->_checkpoints.size()));
                    // _eventReceiver->OnEnterMoney();
                    break;
                case GameCheckpoint::IN_COURSE:
                    if (this->_needRemove == true) {
                        x.remove();
                        this->_checkpoints.erase(this->_checkpoints.begin() + index);
                    }
                    _eventReceiver->OnEnterInCourseChPt(x);
                    break;
                case GameCheckpoint::ONLINE:
                    _eventReceiver->OnEnterOnline();
                    break;
                case GameCheckpoint::CONCESSIONNAIRE:
                    _eventReceiver->OnEnterConcess();
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

std::vector<GameCheckpoint> carWatcher::getCheckpoints() const {
    return this->_checkpoints;
}

void carWatcher::setCar(Car *car) {
    this->_car = car;
}


bool carWatcher::getNeedRemove() const {
    return this->_needRemove;
}

void carWatcher::setNeedRemove(bool value) {
    this->_needRemove = value;
}
