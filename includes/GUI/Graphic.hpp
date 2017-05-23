/*
** Graphic.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 22:09:37 2017 Vacca_J
** Last update Sat May 20 22:52:07 2017 Vacca_J
*/
  #ifndef GRAPHIC_HPP_
  #define GRAPHIC_HPP_

#include <irrlicht.h>
#include <ITexture.h>
#include <IGUIEnvironment.h>
#include "IGameObject.hpp"
#include "IGUI.hpp"

namespace indie {

class Graphic : public IGUI {

private:
  irr::gui::IGUIListBox *_list;
  irr::gui::IGUIWindow *_window;
  irr::gui::IGUIEnvironment *_gui;
  irr::video::IVideoDriver *_driver;
  irr::core::dimension2du _windowSize;

  irr::gui::IGUIStaticText *_title;
  irr::gui::IGUIButton *_plus;
  irr::gui::IGUIButton *_moin;
  irr::gui::IGUIButton *_exit;
  bool _isVisible;
public:

  Graphic(irr::gui::IGUIEnvironment*, irr::video::IVideoDriver*, irr::core::dimension2du);
  ~Graphic ();
  void setGraphic();

  void SetupGUI();
  void setVisible(bool visible);
  bool isVisible(void) const;
  void OnFrame();

  };

}

  #endif /* !GRAPHIC_HPP_ */
