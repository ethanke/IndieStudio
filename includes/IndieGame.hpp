//
// IndieGame.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:42:36 2017 Sousa Victor
// Last update Thu Jun  1 04:37:10 2017 Sousa Victor
//

#ifndef INDIEGAME_HPP
#define INDIEGAME_HPP

#include <thread>
#include <vector>
#include "AGame.hpp"
#include "GameCameraFPS.hpp"
#include "GameCheckpoint.hpp"
#include "Minimap.hpp"
#include "Car.hpp"
#include "GeneticTrainer.hpp"
#include "carWatcher.hpp"
#include "Settings.hpp"
#include "Garage.hpp"
#include "Menu.hpp"
#include "Course.hpp"
#include "RandomEvent.hpp"
#include "Audio.hpp"
#include "Keyboard.hpp"
#include "Graphic.hpp"
#include "JoinServer.hpp"

namespace indie {

    class IndieGame: public AGame {

    public:
        IndieGame(int width = 1920, int height = 1080);
        ~IndieGame();

        virtual void OnFrame();
        virtual bool OnEvent(const irr::SEvent& event);

    private:
        void addGameObject();
        void addEventReceiver();

        void loadMap();

        virtual void OnEnterKey(irr::EKEY_CODE keyCode);
        virtual void OnReleaseKey(irr::EKEY_CODE keyCode);
        virtual void OnEnterGarage(void);
        virtual void OnLeavingGarage(void);

        virtual void OnOpenningMenu();
        virtual void OnLeavingMenu();

        virtual void OnEnterCourse();
        virtual void OnLeavingCourse();

        virtual void OnEnterMoney();

        virtual void OnEnterInCourseChPt(GameCheckpoint const &ch);

        virtual void OnEnterOnline();
        virtual void OnLeavingOnline();

        virtual void guiVisible(IGUI*);

    private:
        Car *_car;
        GeneticTrainer *_genTrainer;
        std::vector<GameCheckpoint> _checkpoints;
        carWatcher *_carWatch;
        Garage *_garage;
        Menu *_menu;
        Course *_course;
        RandomEvent *_events;
        Settings *_settings;
        JoinServer *_onlineUI;

        physics::CBulletPhysics* bulletPhysSys;
        physics::SPhysicsParams physicsParams;

        std::vector<IGUI*> _guiVisible;

        //Text debug
        irr::gui::IGUIStaticText *_pos;
    };

}

#else

namespace indie {
    class IGame;
    class IndieGame : public AGame;
}

#endif /*INDIEGAME_HPP*/
