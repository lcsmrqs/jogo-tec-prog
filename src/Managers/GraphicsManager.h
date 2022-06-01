#pragma once

//#define WINDOW_WIDTH 284
//#define WINDOW_HEIGHT 160

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450

#include "EventManager.h"
#include <SFML/Graphics.hpp>

namespace Managers {
    class GraphicsManager
    {
    private:
        GraphicsManager();
        static GraphicsManager *instance;

        sf::Clock clock;
        sf::RenderWindow window;
        EventManager *eventManager;

    public:
        ~GraphicsManager();
        static GraphicsManager* getInstance();

        bool isWindowOpen() const;
        void clearWindow();
        void draw();
        void processEvents();

        float resetClock();

        sf::RenderWindow* getWindow();
    };
}
