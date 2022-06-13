#pragma once

#include "EventManager.h"

namespace Managers {
    using Key = EventManager::Key;

    class EventListener
    {
    public:
        EventListener() {};
        virtual ~EventListener() {};

        virtual void onKeyPressed(Key k) = 0;
        virtual void onKeyReleased(Key k) = 0;
    };
}
