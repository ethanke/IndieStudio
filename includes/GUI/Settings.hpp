/*
** Setting.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun May 14 15:15:48 2017 Vacca_J
** Last update Mon May 15 20:04:52 2017 Vacca_J
*/

#ifndef SETTING_HPP_
#define SETTING_HPP_

#include <irrlicht.h>
#include <IGUIEnvironment.h>
#include <IGUIContextMenu.h>
#include <IGUIStaticText.h>
#include <IGUISkin.h>
#include "IGameObject.hpp"

namespace indie {


class Settings : public IGameObject {

private:
  //irr::gui::IGUISkin *_skin;
  irr::gui::IGUIEnvironment *_gui;
  irr::gui::IGUIStaticText *_text;
  irr::gui::IGUIContextMenu *_menu;
  irr::gui::IGUIButton *_button;
public:
  void OnFrame();

  Settings (irr::gui::IGUIEnvironment* gui);

  virtual ~Settings ();
  };

}
#endif /* !SETTING_HPP_ */
