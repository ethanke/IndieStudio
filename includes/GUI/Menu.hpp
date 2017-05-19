/*
** Menu.hpp for IndieStudio
**
** Made by	Full Name
** Login	Full Name
**
** Started on	Thu May 18 15:44:55 2017 Full Name
** Last update	Thu May 18 19:40:13 2017 Full Name
*/

#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <irrlicht.h>
#include <IGUIEnvironment.h>
#include "IGameObject.hpp"

namespace indie {

    class Menu : public IGameObject {
    public:
        Menu(irr::gui::IGUIEnvironment*, irr::video::IVideoDriver*, irr::core::dimension2du);
        ~Menu();
         void SetupGUI();
         void OnFrame(void);
    //
    private:
        irr::gui::IGUIEnvironment *_gui;
        irr::gui::IGUIWindow *_window;
        irr::video::IVideoDriver *_driver;
        irr::core::dimension2du _windowSize;

        irr::gui::IGUIStaticText *_title;

        irr::gui::IGUIButton *_setting;
        irr::gui::IGUIButton *_resume;
        irr::gui::IGUIButton *_quit;

    };
}


#endif /* !_MENU_HPP_ */
