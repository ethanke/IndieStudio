/*
** Graphic.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 22:17:17 2017 Vacca_J
** Last update Thu Jun 08 14:45:40 2017 Vacca_J
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
  this->_exit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 + 25, this->_windowSize.Height / 2 + 135, this->_windowSize.Width / 2 + 125, this->_windowSize.Height / 2 + 185), NULL, -1,
    L"QUIT", L"QUIT");
  this->_exit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 125, this->_windowSize.Height / 2 + 135, this->_windowSize.Width / 2 - 25, this->_windowSize.Height / 2 + 185), NULL, -1,
    L"CHANGE", L"CHANGE");
  this->_resol1 = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 410, this->_windowSize.Height / 2 - 130, this->_windowSize.Width / 2 - 320, this->_windowSize.Height / 2 - 40), NULL, -1,
    L"RESOL", L"RESOL");
  this->_resol2 = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 290, this->_windowSize.Height / 2 - 130, this->_windowSize.Width / 2 - 200, this->_windowSize.Height / 2 - 40), NULL, -1,
    L"RESOL2", L"RESOL2");
  this->_resol3 = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 170, this->_windowSize.Height / 2 - 130, this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 - 40), NULL, -1,
    L"RESOL3", L"RESOL3");

  this->_title = this->_gui->addStaticText(L"Graphic", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 240, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 - 220));
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
        this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 450, this->_windowSize.Height / 2 - 250, this->_windowSize.Width / 2 + 450, this->_windowSize.Height / 2 + 250));
        this->_exit->setVisible(true);
        this->_title->setVisible(true);
        this->_resol1->setVisible(true);
        this->_resol2->setVisible(true);
        this->_resol3->setVisible(true);
    }
    else
    {
        this->_exit->setVisible(false);
        this->_title->setVisible(false);
        this->_resol1->setVisible(false);
        this->_resol2->setVisible(false);
        this->_resol3->setVisible(false);

    }
}
