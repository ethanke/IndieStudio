//
// AGame.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Mon May  8 22:20:36 2017 Sousa Victor
// Last update Sun May 14 01:36:08 2017 Sousa Victor
//

#ifndef AGAME_HPP_
#define AGAME_HPP_

#include <irrlicht.h>
#include <irrBullet.h>
#include <exception>
#include <string>
#include <vector>

#include "IndieStudioConfig.h"

#include "IGame.hpp"
#include "EventReceiver.hpp"
#include "EventDelegate.hpp"
#include "IGameObject.hpp"
#include "AGameCamera.hpp"
#include "Minimap.hpp"

namespace indie {

    class AGame: public IGame, public EventReceiver {

    public:
        AGame(int width = 1080, int height = 720);
        ~AGame();

        virtual void Setup();
        virtual void Start();
        virtual void Clean();

        virtual void OnFrame() = 0;

        irr::core::dimension2du const &getWindowSize() const;
        bool isRunning() const;

        virtual bool OnEvent(const irr::SEvent& event);

    protected:
        virtual void addGameObject() = 0;
        virtual void addEventReceiver() = 0;
        virtual void processDeltaTime();
        virtual void loop();
        virtual void objectOnFrame();

    protected:
        bool _isRunning;
        irr::u32 _oldTime;
        irr::core::dimension2du _windowSize;
        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver* _driver;
        irr::scene::ISceneManager* _smgr;
        irr::gui::IGUIEnvironment* _gui;
        std::shared_ptr<irrBulletWorld> _world;
        std::vector<IGameObject *> _objectList;
        std::vector<EventDelegate *> _eventReceiverList;
        AGameCamera *_minimapCamera;

    };

}

#endif /*AGAME_HPP_*/
