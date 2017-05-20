/*
** song.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 14:33:37 2017 Vacca_J
** Last update Sat May 20 15:20:05 2017 Vacca_J
*/

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <irrlicht.h>
#include <ITexture.h>
#include <IGUIEnvironment.h>
#include "IGameObject.hpp"
#include "IGUI.hpp"

namespace indie {

class Audio : public IGUI {

private:
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

  Audio(irr::gui::IGUIEnvironment*, irr::video::IVideoDriver*, irr::core::dimension2du);
  ~Audio ();
  void setAudio();

  void SetupGUI();
  void setVisible(bool visible);
  bool isVisible(void) const;
  void OnFrame();

  };

}

#endif /* !AUDIO_HPP */
