/*
** Keyboard.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 17:36:35 2017 Vacca_J
** Last update Sat May 20 18:36:10 2017 Vacca_J
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <irrlicht.h>
#include <ITexture.h>
#include <IGUIEnvironment.h>
#include <vector>
#include "IGameObject.hpp"
#include "IGUI.hpp"

namespace indie {

class Keyboard : public IGUI {

private:
  irr::gui::IGUIWindow *_window;
  irr::gui::IGUIEnvironment *_gui;
  irr::video::IVideoDriver *_driver;
  irr::core::dimension2du _windowSize;

  irr::gui::IGUIStaticText *_title;
  irr::gui::IGUIButton *_change;
  irr::gui::IGUIButton *_exit;
  std::vector<int> *_keyboard;
  bool _isVisible;
public:

  Keyboard(irr::gui::IGUIEnvironment*, irr::video::IVideoDriver*, irr::core::dimension2du);
  ~Keyboard ();
  void setKeyboard();

  void resetKeybord(void);
  void SetupGUI();
  void setVisible(bool visible);
  bool isVisible(void) const;
  void OnFrame();

  };

}


#endif /* !KEYBOARD_HPP_ */
