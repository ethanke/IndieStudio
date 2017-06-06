/*
** MainMenu.cpp for IndieStudio
**
** Made by	Full Name
** Login	Full Name
**
** Started on	Tue Jun 06 15:36:49 2017 Full Name
** Last update	Tue Jun 06 18:47:51 2017 Full Name
*/

#include "MainMenu.hpp"

using namespace indie;

MainMenu::MainMenu(irr::gui::IGUIEnvironment *gui, irr::video::IVideoDriver *driver, irr::core::dimension2du windowSize)
{
    _gui = gui;
    _driver = driver;
    _windowSize = windowSize;
    _play = false;
}



MainMenu::~MainMenu()
{
    _start->remove();
    _multijoueur->remove();
    _quit->remove();
}

bool MainMenu::getPlay() const
{
    return _play;
}

void MainMenu::setPlay(bool play)
{
    _play = play;
}

void MainMenu::SetupGUI()
{
    // this->_image = this->_driver->getTexture("misc/mainmenu.png");
    // this->_driver->beginScene(true, true, irr::video::SColor(255,20,20,40));
    // irr::core::rect<irr::s32> rect(0, 0, this->_image->getSize().Width, this->_image->getSize().Height);
    // this->_driver->draw2DImage(this->_image, irr::core::position2d<irr::s32>(0, 0), irr::core::rect<irr::s32>(0, 0, this->_windowSize.Width, this->_windowSize.Height), &rect);
    this->_start = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 100, this->_windowSize.Height / 2 - 140, this->_windowSize.Width / 2 + 100, this->_windowSize.Height / 2 - 60), NULL, PLAY,
            L"PLAY", L"");
    this->_multijoueur = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 100, this->_windowSize.Height / 2 - 40, this->_windowSize.Width / 2 + 100, this->_windowSize.Height / 2 + 40), NULL, MULTIJOUEUR,
            L"MULTIJOUEUR", L"");
    this->_quit = this->_gui->addButton(irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 100, this->_windowSize.Height / 2 + 60, this->_windowSize.Width / 2 + 100, this->_windowSize.Height / 2 + 140), NULL, QUIT,
            L"QUIT", L"");
//    this->_driver->endScene();
}

void MainMenu::setVisible(bool visible)
{
    _isVisible = visible;
}

bool MainMenu::isVisible() const
{
    return _isVisible;
}

void MainMenu::OnFrame()
{
//    this->_driver->draw2DRectangle(irr::video::SColor(200,75,75,75), irr::core::rect<irr::s32>(this->_windowSize.Width / 2 - 140, this->_windowSize.Height / 2 - 200, this->_windowSize.Width / 2 + 140, this->_windowSize.Height / 2 + 200));
//    irr::core::rect<irr::s32> rect(0, 0, this->_image->getSize().Width, this->_image->getSize().Height);
//    this->_driver->draw2DImage(this->_image, irr::core::position2d<irr::s32>(0, 0), irr::core::rect<irr::s32>(0, 0, this->_windowSize.Width, this->_windowSize.Height), &rect);
    // this->_start->setVisible(true);
    // this->_multijoueur->setVisible(true);
    // this->_quit->setVisible(true);
}
