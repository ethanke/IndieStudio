/*
** Graphic.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 22:09:37 2017 Vacca_J
** Last update Thu Jun 08 14:40:02 2017 Vacca_J
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
  irr::gui::IGUIWindow *_window;
  irr::gui::IGUIEnvironment *_gui;
  irr::video::IVideoDriver *_driver;
  irr::core::dimension2du _windowSize;

  irr::gui::IGUIStaticText *_title;
  irr::gui::IGUIButton *_plus;
  irr::gui::IGUIButton *_moin;
  irr::gui::IGUIButton *_resol1;
  irr::gui::IGUIButton *_resol2;
  irr::gui::IGUIButton *_resol3;
  irr::gui::IGUIButton *_exit;
  irr::gui::IGUIButton *_change;

  bool _isVisible;
//  irr::gui::IGUIFileOpenDialog *_dialog;
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
