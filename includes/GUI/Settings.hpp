/*
** Setting.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun May 14 15:15:48 2017 Vacca_J
** Last update Thu May 18 01:09:05 2017 Lucas Gambini
*/

#ifndef SETTING_HPP_
#define SETTING_HPP_

#include <irrlicht.h>
#include <IGUIEnvironment.h>
#include <IGUIContextMenu.h>
#include <IGUIStaticText.h>
#include <IGUISkin.h>

namespace indie {

class Settings {

private:
  //irr::gui::IGUISkin *_skin;
  irr::gui::IGUIEnvironment *_gui;
  irr::gui::IGUIStaticText *_text;
  irr::gui::IGUIContextMenu *_menu;
  irr::gui::IGUIButton *_button;
public:

  Settings (irr::gui::IGUIEnvironment* gui);
  virtual ~Settings ();

  };

}
#endif /* !SETTING_HPP_ */
