/*
** Race.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Thu Jun 01 01:32:46 2017 Vacca_J
** Last update Sat Jun 03 19:17:58 2017 Vacca_J
*/

#include "Race.hpp"

Race::Race()
{

}

Race::Race(indie::Car *car, int circuit)
{
  this->_car = car;
  this->_circuit = circuit;
}

Race::~Race()
{

}

void Race::RaceManager()
{
  Spawn();
  Starter();
  //VERIFICATION DES DIFFERENTS CHECKPOINT PLACER SUR LE CIRCUIT JUSQUA CE QUE TOUT LES JOUEURS TERMINES LA COURSE
  EndRace();
  Score();

}

void Race::Spawn()
{
//  this->_car->setPosition((irr::core::vector3df(193.46, 0, -1432.01));
}

void Race::Starter()
{
  //TIMER 3 2 1 GO QUI BLOQUE/DEBLOQUE LA VITESSE DES JOUEURS
}

void Race::Score()
{
  //Ecran des scores de romain avec un bouton "quitter" pour faire respawn le joeur hors du circuit
}

void Race::EndRace()
{
  // FIN DE LA COURSE APRES QUE TOUT LES JOUEURS EST FINIS LE CIRCUIT OU APRES 30 SECONDES UNE FOIS
  //QUE PLUS DE LA MOITIER DES JOUEURS ON TERMINE LA COURSES
}

//DSL JAI UN REPAS DE FAMILLE
