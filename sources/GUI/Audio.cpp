/*
** Audio.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 14:35:05 2017 Vacca_J
** Last update Sat May 20 17:26:30 2017 Vacca_J
*/

#include <Audio.hpp>

using namespace indie;

Audio::Audio(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
  this->_gui = gui;
  this->_driver = driver;
  this->_windowSize = windowSize;
  this->_isVisible = true;
}

Audio::~Audio()
{
}

void Audio::SetupGUI()
{
  this->_moin = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 200, this->_windowSize.Height / 2 - 25, this->_windowSize.Width / 2 - 150, this->_windowSize.Height / 2 + 25), NULL, -1,
          L"-", L"-");
  this->_plus = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 + 150, this->_windowSize.Height / 2 - 25, this->_windowSize.Width / 2 + 200, this->_windowSize.Height / 2 + 23), NULL, -1,
          L"+", L"+");
  this->_exit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 50, this->_windowSize.Height / 2 + 80, this->_windowSize.Width / 2 + 50, this->_windowSize.Height / 2 + 163), NULL, -1,
    L"QUIT", L"Quit");
  this->_title = this->_gui->addStaticText(L"Audio", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 120, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 - 80));
  this->_title->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_SCALE);
}

void Audio::setVisible(bool visible)
{
  this->_isVisible = visible;
}

bool Audio::isVisible(void) const
{
    return this->_isVisible;
}


void Audio::OnFrame()
{
    if (_isVisible == true)
    {
        this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 250, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 250, this->_windowSize.Height / 2 + 180));
        this->_plus->setVisible(true);
        this->_moin->setVisible(true);
        this->_exit->setVisible(true);
        this->_title->setVisible(true);
    }
    else
    {
        this->_plus->setVisible(false);
        this->_moin->setVisible(false);
        this->_exit->setVisible(false);
        this->_title->setVisible(false);
    }
}
