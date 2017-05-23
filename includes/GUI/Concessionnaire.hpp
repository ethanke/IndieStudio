/*
** Concessionnaire.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 23:54:13 2017 Vacca_J
** Last update Mon May 22 18:01:37 2017 Vacca_J
*/

#ifndef CONCESSIONNAIRE_HPP_
#define CONCESSIONNAIRE_HPP_

#include <irrlicht.h>
#include <ITexture.h>
#include <IGUIEnvironment.h>
#include "IGameObject.hpp"
#include "IGUI.hpp"

namespace indie {

class Concessionnaire : public IGUI {

  public: enum SETTINGS_BTNS
  {
      GRAPHIC = 8001,
      AUDIO,
      KEYBOARD,
  };

private:
  irr::gui::IGUIWindow *_window;
  irr::gui::IGUIEnvironment *_gui;
  irr::video::IVideoDriver *_driver;
  irr::core::dimension2du _windowSize;
  irr::gui::IGUIStaticText *_title;
  irr::gui::IGUIButton *_next;
  irr::gui::IGUIButton *_previous;
  irr::gui::IGUIButton *_exit;
  bool _isVisible;
public:

  Concessionnaire(irr::gui::IGUIEnvironment*, irr::video::IVideoDriver*, irr::core::dimension2du);
  ~Concessionnaire ();
  void setConcessionnaire();

  void SetupGUI();
  void setVisible(bool visible);
  bool isVisible(void) const;
  void OnFrame();

  };

}

#endif /* !CONCESSIONNAIRE_HPP_ */
