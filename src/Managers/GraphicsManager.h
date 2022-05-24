#pragma once

#define WINDOW_WIDTH 284
#define WINDOW_HEIGHT 160

#include <SFML/Graphics.hpp>
#include "../Ent.h"

namespace Managers {
    class GraphicsManager
    {
    private:
        GraphicsManager();
        static GraphicsManager *instance;
        sf::Clock clock;
        sf::RenderWindow window;

    public:
        // TODO: destructor?
        static GraphicsManager* getInstance();

        bool isWindowOpen() const;
        void clearWindow();
        void draw();
        void processEvents();

        void resetClock();
        float getDt();

        sf::RenderWindow* getWindow();

    };
} // Managers
