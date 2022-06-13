#pragma once

#define WINDOW_WIDTH 825
#define WINDOW_HEIGHT 350

#include "EventManager.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "../Math/Vect.h"

using std::map;
using std::string;
using Math::Vect;

namespace Managers {
    class GraphicsManager
    {
    private:
        GraphicsManager();
        static GraphicsManager *instance;

        sf::Clock clock;
        sf::RenderWindow window;
        EventManager *eventManager;

        map<string, sf::Texture*> textures;
        sf::Font* font;

        sf::View view;

        bool loadTexture(const string t);

    public:
        ~GraphicsManager();
        static GraphicsManager* getInstance();

        bool isWindowOpen() const;
        void clearWindow();
        void draw();
        void processEvents();

        float resetClock();

        sf::RenderWindow* getWindow();

        void closeWindow();

        sf::Font* getFont();
        sf::Texture* getTexture(const string t);

        void updateView(const Vect v);
        void resetView();
        Vect getViewCenter();
    };
}
