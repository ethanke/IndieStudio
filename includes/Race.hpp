/*
** Race.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Thu Jun 01 01:30:32 2017 Vacca_J
** Last update Wed Jun 07 15:10:49 2017 Vacca_J
*/

#ifndef RACE_HPP_
#define RACE_HPP_

#include <irrlicht.h>
#include <exception>
#include <time.h>
#include <string>
#include <vector>
#include "Race.hpp"
#include "Car.hpp"

class Race {

  public: enum circuit
  {
    VILLE,
    PLAGE
  };

private:
  indie::Car *_car;
  int _circuit;

public:
  Race();
  Race(indie::Car *car, int circuit);
  ~Race();
  void RaceManager();
  void Spawn();
  void Starter();
  void Score();
  void EndRace();
};

#endif /* !RACE_HPP_ */
