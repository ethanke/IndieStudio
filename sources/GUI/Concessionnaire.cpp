/*
** Concessionnaire.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 23:55:02 2017 Vacca_J
** Last update Mon May 22 17:52:17 2017 Vacca_J
*/

#include "Concessionnaire.hpp"

using namespace indie;

Concessionnaire::Concessionnaire(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
  this->_gui = gui;
  this->_driver = driver;
  this->_windowSize = windowSize;
  this->_isVisible = true;
}

Concessionnaire::~Concessionnaire()
{
}

void Concessionnaire::SetupGUI()
{
  this->_previous = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 200, this->_windowSize.Height / 2 - 25, this->_windowSize.Width / 2 - 150, this->_windowSize.Height / 2 + 25), NULL, -1,
          L"<", L"<");
  this->_previous = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 + 150, this->_windowSize.Height / 2 - 25, this->_windowSize.Width / 2 + 200, this->_windowSize.Height / 2 + 23), NULL, -1,
          L">", L">");
  this->_exit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 50, this->_windowSize.Height / 2 + 80, this->_windowSize.Width / 2 + 50, this->_windowSize.Height / 2 + 163), NULL, -1,
    L"QUIT", L"Quit");

  this->_title = this->_gui->addStaticText(L"Concessionnaire", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 120, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 - 80));
  this->_title->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_SCALE);
}

void Concessionnaire::setVisible(bool visible)
{
  this->_isVisible = visible;
}

bool Concessionnaire::isVisible(void) const
{
    return this->_isVisible;
}


void Concessionnaire::OnFrame()
{
    if (_isVisible == true)
    {
        this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 250, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 250, this->_windowSize.Height / 2 + 180));
        this->_previous->setVisible(true);
        this->_previous->setVisible(true);
        this->_exit->setVisible(true);
        this->_title->setVisible(true);
    }
    else
    {
        this->_previous->setVisible(false);
        this->_previous->setVisible(false);
        this->_exit->setVisible(false);
        this->_title->setVisible(false);
    }
}
