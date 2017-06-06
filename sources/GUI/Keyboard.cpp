/*
** Keyboard.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sat May 20 17:38:44 2017 Vacca_J
** Last update Tue Jun 06 19:17:11 2017 Vacca_J
*/

#include "Keyboard.hpp"

using namespace indie;

Keyboard::Keyboard(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
  this->_gui = gui;
  this->_driver = driver;
  this->_windowSize = windowSize;
  this->_isVisible = true;
  this->_mymap[UP] = irr::KEY_UP;
  this->_mymap[DOWN] = irr::KEY_DOWN;
  this->_mymap[LEFT] = irr::KEY_LEFT;
  this->_mymap[RIGHT] = irr::KEY_RIGHT;
  this->_mymap[FORWARD] = irr::KEY_KEY_D;
  this->_mymap[BACKWARD] = irr::KEY_KEY_R;
  this->_id = 0;
}

Keyboard::~Keyboard()
{
}

void Keyboard::SetupGUI()
{
  this->_exit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 45, this->_windowSize.Height / 2 + 110, this->_windowSize.Width / 2 + 45, this->_windowSize.Height / 2 + 160), NULL, 1008,
    L"EXIT", L"EXIT");
  this->_left = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 320, this->_windowSize.Height / 2 - 25, this->_windowSize.Width / 2 - 270, this->_windowSize.Height / 2 + 25), NULL, 1003,
    L"LEFT", L"LEFT");
  this->_right = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 200, this->_windowSize.Height / 2 - 25, this->_windowSize.Width / 2 - 150, this->_windowSize.Height / 2 + 25), NULL, 1004,
    L"RIGHT", L"RIGHT");
  this->_down = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 270, this->_windowSize.Height / 2 + 35, this->_windowSize.Width / 2 - 200, this->_windowSize.Height / 2 + 85), NULL, 1002,
    L"DOWN", L"DOWN");
  this->_up = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 270, this->_windowSize.Height / 2 - 85, this->_windowSize.Width / 2 - 200, this->_windowSize.Height / 2 - 35), NULL, 1001,
    L"UP", L"UP");
  this->_forward = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 + 200, this->_windowSize.Height / 2 - 85, this->_windowSize.Width / 2 + 270, this->_windowSize.Height / 2 - 35), NULL, 1005,
    L"FORWARD", L"FORWARD");
  this->_backward = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 + 200, this->_windowSize.Height / 2 + 35, this->_windowSize.Width / 2 + 270, this->_windowSize.Height / 2 + 85), NULL, 1006,
    L"BACKWARD", L"BACKWARD");
  this->_space = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 85, this->_windowSize.Height / 2 + 25, this->_windowSize.Width / 2 + 85, this->_windowSize.Height / 2 + 55), NULL, 1007,
    L"FREIN", L"FREIN");

  this->_title2 = this->_gui->addStaticText(L"Press new KEY", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 120, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 - 80));
  this->_title2->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_SCALE);
  this->_title = this->_gui->addStaticText(L"Keyboard", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 150, this->_windowSize.Height / 2 - 190, this->_windowSize.Width / 2 + 150, this->_windowSize.Height / 2 - 170));
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

void Keyboard::resetUp(void)
{
  this->_id = KEYCODE_TYPE::UP;

}

void Keyboard::resetDown(void)
{
  this->_id = KEYCODE_TYPE::DOWN;
}

void Keyboard::resetLeft(void)
{
  this->_id = KEYCODE_TYPE::LEFT;
}

void Keyboard::resetRight(void)
{
  this->_id = KEYCODE_TYPE::RIGHT;
}

void Keyboard::resetForward(void)
{
  this->_id = KEYCODE_TYPE::FORWARD;
}

void Keyboard::resetBackward(void)
{
  this->_id = KEYCODE_TYPE::BACKWARD;
}

void Keyboard::resetBrake(void)
{
  this->_id = KEYCODE_TYPE::SPACE;
}

void Keyboard::OnEnterKey(irr::EKEY_CODE keycode)
{
  if (this->_id == 0)
    return;
  this->_mymap[static_cast<KEYCODE_TYPE>(this->_id)] = keycode;
  this->_id = 0;
}

void Keyboard::OnFrame()
{
    if (_isVisible == true)
    {
        this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 350, this->_windowSize.Height / 2 - 200, this->_windowSize.Width / 2 + 350, this->_windowSize.Height / 2 + 180));
        this->_exit->setVisible(true);
        this->_up->setVisible(true);
        this->_down->setVisible(true);
        this->_right->setVisible(true);
        this->_left->setVisible(true);
        this->_forward->setVisible(true);
        this->_backward->setVisible(true);
        this->_space->setVisible(true);
        this->_title->setVisible(true);
        this->_title2->setVisible(true);
    }
    else
    {
      this->_up->setVisible(false);
      this->_down->setVisible(false);
      this->_right->setVisible(false);
      this->_left->setVisible(false);
      this->_forward->setVisible(false);
      this->_backward->setVisible(false);
      this->_exit->setVisible(false);
      this->_space->setVisible(false);
      this->_title->setVisible(false);
      this->_title2->setVisible(false);
    }
}
