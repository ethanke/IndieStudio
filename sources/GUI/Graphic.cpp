/*
** Graphic.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 22:17:17 2017 Vacca_J
** Last update Tue May 23 00:51:31 2017 Vacca_J
*/

#include "Graphic.hpp"

using namespace indie;

Graphic::Graphic(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
  this->_gui = gui;
  this->_driver = driver;
  this->_windowSize = windowSize;
  this->_isVisible = true;
}

Graphic::~Graphic()
{
}

void Graphic::SetupGUI()
{
  this->_list = this->_gui->addListBox (irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 220, this->_windowSize.Height / 2 - 40, this->_windowSize.Width / 2 - 130, this->_windowSize.Height / 2 + 60), NULL, -1, false);
  this->_exit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 + 130, this->_windowSize.Height / 2 - 40, this->_windowSize.Width / 2 + 220, this->_windowSize.Height / 2 + 60), NULL, -1,
    L"QUIT", L"Quit");
  this->_title = this->_gui->addStaticText(L"Graphic", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 120, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 - 80));
  this->_title->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_SCALE);
}

void Graphic::setVisible(bool visible)
{
  this->_isVisible = visible;
}

bool Graphic::isVisible(void) const
{
    return this->_isVisible;
}


void Graphic::OnFrame()
{
    if (_isVisible == true)
    {
        this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 250, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 250, this->_windowSize.Height / 2 + 180));
        this->_exit->setVisible(true);
        this->_title->setVisible(true);
        this->_list->setVisible(true);
    }
    else
    {
        this->_exit->setVisible(false);
        this->_title->setVisible(false);
        this->_list->setVisible(false);
    }
}
