/*
** Setting.hpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources/GUI
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Sun May 14 15:39:14 2017 Vacca_J
** Last update Fri May 19 21:40:26 2017 Vacca_J
*/

#include <Settings.hpp>

using namespace indie;

Settings::Settings(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
  this->_gui = gui;
  this->_driver = driver;
  this->_windowSize = windowSize;
  this->_isVisible = true;
}

Settings::~Settings()
{
}

void Settings::setSettings()
{
  this->_graphic = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 80, this->_windowSize.Height / 2 - 60), NULL, -1,
          L"Affichage", L"Affichage");
  this->_song = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 - 40, this->_windowSize.Width / 2 + 80, this->_windowSize.Height / 2 + 40), NULL, -1,
          L"Audio", L"Audio");
  this->_keyboard = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 + 60, this->_windowSize.Width / 2 + 80, this->_windowSize.Height / 2 + 140), NULL, -1,
          L"Clavier", L"Clavier");
  this->_title = this->_gui->addStaticText(L"Settings", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 180, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 - 140));
  this->_title->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_SCALE);
}

void Settings::setVisible(bool visible)
{
  this->_isVisible = visible;
}

bool Settings::isVisible(void) const
{
    return this->_isVisible;
}

void Settings::OnFrame()
{
    if (_isVisible == true)
    {
        this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 200, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 + 200));
        this->_graphic->setVisible(true);
        this->_song->setVisible(true);
        this->_keyboard->setVisible(true);
        this->_title->setVisible(true);
        if (this->_graphic->isPressed() == true)
          {
            this->_graphic->setImage(this->_images = this->_driver->getTexture("../../Assets/guiskin/button.png"), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 80, this->_windowSize.Height / 2 - 60));
          }
    }
    else
    {
        this->_graphic->setVisible(false);
        this->_song->setVisible(false);
        this->_keyboard->setVisible(false);
        this->_title->setVisible(false);
    }
}
