#pragma once

#include "../Ent.h"
#include <vector>
#include <iostream>
#include "Button.h"
#include "../Managers/EventListener.h"
#include "../Managers/EventManager.h"
#include "../Managers/GraphicsManager.h"
#include "../States/State.h"

using Managers::EventManager;
using Managers::EventListener;
using Managers::GraphicsManager;
using Key = Managers::EventManager::Key;

namespace Menus {
    class Menu : public Ent, public EventListener
    {
    protected:
        std::vector<Button*> options;
        unsigned int selectedOption;
        States::State *state;

    public:
        Menu() :
        Ent(),
        EventListener(),
        options(),
        selectedOption(0)
        {
            // EventManager *em = EventManager::getInstance();
            // em->subscribe(this);
        }

        virtual ~Menu()
        {
            // EventManager *em = EventManager::getInstance();
            // em->unsubscribe(this);

            std::vector<Button*>::iterator itr;
            for(itr = options.begin(); itr != options.end(); itr++)
                delete *itr;

            options.clear();
        }

        void setState(States::State *s) { state = s; }

        virtual void run(float dt)
        {
            std::vector<Button*>::iterator itr;
            for(itr = options.begin(); itr != options.end(); itr++)
                (*itr)->run(dt);
        }

        virtual void draw()
        {
            GraphicsManager *graphics = GraphicsManager::getInstance();
            graphics->resetView();

            std::vector<Button*>::iterator itr;
            for(itr = options.begin(); itr != options.end(); itr++)
                (*itr)->draw();
        }

        virtual void reset() = 0;

        virtual void onKeyPressed(Key k)
        {
            unsigned int oldOption = selectedOption;

            if (k == Key::Up && selectedOption > 0)
                selectedOption--;

            if (k == Key::Down && selectedOption < options.size() - 1)
                selectedOption++;

            if (oldOption != selectedOption) {
                options[oldOption]->setActive(false);
                options[selectedOption]->setActive(true);
            }
        }

        virtual void onKeyReleased(Key k) {}
    };
}
