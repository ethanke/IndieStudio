//
// EventReceiver.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Mon May  8 19:54:43 2017 Sousa Victor
// Last update Fri May 12 01:24:17 2017 Sousa Victor
//

#ifndef EVENTRECEIVER_HPP_
#define EVENTRECEIVER_HPP_

#include <irrlicht.h>

namespace indie {

    class EventReceiver : public irr::IEventReceiver {

    public:
        EventReceiver();
        EventReceiver(const EventReceiver &receiver);
        EventReceiver &operator=(const EventReceiver &receiver);
        ~EventReceiver();

        virtual bool OnEvent(const irr::SEvent& event);
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

        virtual void OnEnterKey(irr::EKEY_CODE keyCode) = 0;
        virtual void OnReleaseKey(irr::EKEY_CODE keyCode) = 0;

        virtual void OnEnterGarage(void) = 0;


    private:
        bool _keyIsDown[irr::KEY_KEY_CODES_COUNT];

    };

}

#else

namespace indie {
    class EventReceiver;
}

#endif /*EVENTRECEIVER_HPP_*/
