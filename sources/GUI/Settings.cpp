/*
** Setting.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun May 14 15:39:14 2017 Vacca_J
** Last update Mon May 15 20:04:39 2017 Vacca_J
*/

#include <Settings.hpp>

using namespace indie;

Settings::Settings(irr::gui::IGUIEnvironment* gui)
{
  this->_gui = gui;
  //this->_skin = this->_gui->createSkin(irr::gui::EGST_BURNING_SKIN);
//  this->_gui->setSkin(this->_skin);
  //this->_text = this->_gui->addStaticText (L"TESTTESTEST", irr::core::rect<irr::s32>(40, 40, 200, 100), true, true, 0, -1, true);
  this->_button = this->_gui->addButton(irr::core::rect<irr::s32>(40, 40, 400, 500), NULL, NULL, L"OUI", L"TESTS");

  //this->_skin->drop();
  //this->_menu = this->_gui->addContextMenu(irr::core::rect<irr::s32>(500, 500, 400, 500), NULL, NULL);
  

}

Settings::~Settings()
{

}

void Settings::OnFrame()
{

}
