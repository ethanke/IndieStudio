/*
** Concessionnaire.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/includes/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 23:54:13 2017 Vacca_J
** Last update Sun Jun 11 05:46:30 2017 Vacca_J
*/

#ifndef CONCESSIONNAIRE_HPP_
#define CONCESSIONNAIRE_HPP_

#include <irrlicht.h>
#include <ITexture.h>
#include <vector>
#include <IGUIImage.h>
#include <IGUIEnvironment.h>
#include "IGameObject.hpp"
#include "IGUI.hpp"

namespace indie {

class Concessionnaire : public IGUI {

  public: enum CONCESSIONNAIRE_BTNS
  {
      LEAVE = 20001,
      NEXTC,
      PREVC,
      CHANGEC,
      QUITC,
      NEXTL,
      PREVL,
      CHANGEL,
      QUITL,
  };

private:
  irr::gui::IGUIWindow *_window;
  irr::gui::IGUIEnvironment *_gui;
  irr::video::IVideoDriver *_driver;
  irr::core::dimension2du _windowSize;
  irr::gui::IGUIStaticText *_title;

  //CONCESSIONNAIRE
  irr::gui::IGUIButton *_carcolor;
  irr::gui::IGUIButton *_carlist;
  irr::gui::IGUIButton *_leave;
  irr::video::ITexture *_colorpng;
  irr::video::ITexture *_listpng;


  //COLOR
  irr::gui::IGUIButton *_next1;
  irr::gui::IGUIButton *_previous1;
  irr::gui::IGUIButton *_exit1;
  irr::gui::IGUIButton *_enter1;
  irr::gui::IGUIStaticText *_title1;
  irr::gui::IGUIImage *_color;
  //CAR
  irr::gui::IGUIButton *_next2;
  irr::gui::IGUIButton *_previous2;
  irr::gui::IGUIButton *_exit2;
  irr::gui::IGUIButton *_enter2;
  irr::gui::IGUIStaticText *_title2;
  irr::gui::IGUIImage *_cars;

  // ALL COLOR

  irr::video::ITexture *_tred;
  irr::video::ITexture *_tpink;
  irr::video::ITexture *_tblue;
  irr::video::ITexture *_tgreen;
  irr::video::ITexture *_tyellow;
  irr::video::ITexture *_torange;
  std::vector<irr::video::ITexture *> _mycolor;

  // ALL CAR

  irr::video::ITexture *_toyotayaris;
  irr::video::ITexture *_fiatpounto;
  irr::video::ITexture *_twingo;
  irr::video::ITexture *_renofuego;
  irr::video::ITexture *_katrekatre;
  irr::video::ITexture *_ferari;
  std::vector<irr::video::ITexture *> _mycars;


  // OTHER
  bool _isVisible;
  bool _isVisible1;
  bool _isVisible2;
  int _compt = 0;
public:

  Concessionnaire(irr::gui::IGUIEnvironment*, irr::video::IVideoDriver*, irr::core::dimension2du);
  ~Concessionnaire ();
  void setConcessionnaire();

  void colorManager(int flag);
  void colorMenu();
  void listcarMenu();
  void SetupCARLIST();
  void SetupCOLOR();
  void SetupGUI();
  void setVisible(bool visible);
  bool isVisible(void) const;
  void OnFrame();

  };

}

#endif /* !CONCESSIONNAIRE_HPP_ */
