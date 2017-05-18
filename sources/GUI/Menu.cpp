/*
** Menu.cpp for IndieStudio
**
** Made by	Full Name
** Login	Full Name
**
** Started on	Thu May 18 15:46:39 2017 Full Name
** Last update	Thu May 18 19:40:09 2017 Full Name
*/

#include "Menu.hpp"

using namespace indie;

Menu::Menu(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
    this->_gui = gui;
    this->_driver = driver;
    this->_windowSize = windowSize;
}

Menu::~Menu(){

}

void Menu::SetupGUI() {
    irr::gui::IGUISkin* skin = this->_gui->getSkin();
    irr::gui::IGUIFont* font = this->_gui->getFont("misc/fontcourier.bmp");
    if (font)
        skin->setFont(font);
    skin->setFont(this->_gui->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);

    this->_setting = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 80, this->_windowSize.Height / 2 - 60), NULL, -1,
            L"Settings", L"Settings");
    this->_resume = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 - 40, this->_windowSize.Width / 2 + 80, this->_windowSize.Height / 2 + 40), NULL, -1,
            L"Resume", L"Resume");
    this->_quit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 80, this->_windowSize.Height / 2 + 60, this->_windowSize.Width / 2 + 80, this->_windowSize.Height / 2 + 140), NULL, -1,
            L"Quit", L"Quit");
    this->_title = this->_gui->addStaticText(L"Menu", irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 180, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 + 200));
    this->_title->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_SCALE);
}

void Menu::OnFrame()
{
    this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 200, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 + 200));
}
