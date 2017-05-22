/*
** Keyboard.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 17:38:44 2017 Vacca_J
** Last update Sat May 20 22:13:52 2017 Vacca_J
*/

#include "Keyboard.hpp"

using namespace indie;

Keyboard::Keyboard(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
  this->_gui = gui;
  this->_driver = driver;
  this->_windowSize = windowSize;
  this->_isVisible = true;
}

Keyboard::~Keyboard()
{
}

void Keyboard::SetupGUI()
{
  this->_change = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 220, this->_windowSize.Height / 2 - 40, this->_windowSize.Width / 2 - 130, this->_windowSize.Height / 2 + 60), NULL, -1,
          L"change", L"change");
  this->_exit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 + 130, this->_windowSize.Height / 2 - 40, this->_windowSize.Width / 2 + 220, this->_windowSize.Height / 2 + 60), NULL, -1,
    L"QUIT", L"Quit");
  this->_title = this->_gui->addStaticText(L"Keyboard", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 120, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 - 80));
  this->_title->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_SCALE);
}

void Keyboard::setVisible(bool visible)
{
  this->_isVisible = visible;
}

bool Keyboard::isVisible(void) const
{
    return this->_isVisible;
}

void Keyboard::resetKeybord(void)
{

}

void Keyboard::OnFrame()
{
    if (_isVisible == true)
    {
        this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 250, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 250, this->_windowSize.Height / 2 + 180));
        this->_change->setVisible(true);
        this->_exit->setVisible(true);
        this->_title->setVisible(true);
    }
    else
    {
        this->_change->setVisible(false);
        this->_exit->setVisible(false);
        this->_title->setVisible(false);
    }
}
