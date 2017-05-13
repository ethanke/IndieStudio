/*
** carWatcher.cpp for Shared in /Users/gmblucas/Desktop/Shared/IndieStudio/sources/Watcher
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Sat May 13 20:18:24 2017 Lucas Gambini
** Last update Sat May 13 22:28:15 2017 Lucas Gambini
*/

#include "carWatcher.hpp"

using namespace indie;

carWatcher::carWatcher(Car const &car, EventReceiver *eventReceiver)
{
    _car = car;
    _eventReceiver = eventReceiver;
}

carWatcher::~carWatcher()
{

}

void carWatcher::OnFrame() {
}
