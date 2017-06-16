/*
** SoundManager.cpp for IndieStudio in /Users/gmblucas/Desktop/Shared/IndieStudio/sources
**
** Made by Lucas Gambini
** Login   <gmblucas@epitech.net>
**
** Started on  Fri Jun 16 18:17:19 2017 Lucas Gambini
** Last update Sat Jun 17 01:22:54 2017 Lucas Gambini
*/

#include "SoundManager.hpp"

using namespace indie;

SoundManager SoundManager::_instance = SoundManager();

SoundManager::SoundManager() {
    this->_engine = irrklang::createIrrKlangDevice();
    this->_engine->setSoundVolume(0.5f);
}

SoundManager::~SoundManager() {
    this->_engine = irrklang::createIrrKlangDevice();
}

SoundManager &SoundManager::Instance() {
    return _instance;
}

irrklang::ISoundEngine* SoundManager::getEngine() {
    return this->_engine;
}
