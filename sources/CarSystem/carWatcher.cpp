/*
** carWatcher.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:24 2017 Lucas Gambini
** Last update Tue May 16 18:24:02 2017 Lucas Gambini
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

void carWatcher::OnFrame() {
    irr::core::vector3df cpos = this->_car->getPosition();
    for (auto &x : this->_checkpoints) {
        if (cpos.X >= x.getPosition().X - 5 && cpos.X <= x.getPosition().X + 5 &&
            cpos.Y >= x.getPosition().Y - 5 && cpos.Y >= x.getPosition().Y + 5)
        {
            x.setMesh(this->_smgr->getGeometryCreator()->createCylinderMesh(5, 2000, 50, irr::video::SColor(150, 0, 255, 0), true, 0.f));
            _eventReceiver->OnEnterGarage();
        } else {
            x.setMesh(this->_smgr->getGeometryCreator()->createCylinderMesh(5, 2000, 50, irr::video::SColor(150, 255, 0, 0), true, 0.f));
        }
    }
}
