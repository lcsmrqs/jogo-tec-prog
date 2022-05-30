#pragma once

#include <map>
#include <SFML/Window/Keyboard.hpp>

using std::map;

namespace Managers {
    class EventManager
    {
    public:
        enum Key {
            Up = sf::Keyboard::Up,
            Down = sf::Keyboard::Down,
            Right = sf::Keyboard::Right,
            Left = sf::Keyboard::Left,
            W = sf::Keyboard::W,
            A = sf::Keyboard::A,
            S = sf::Keyboard::S,
            D = sf::Keyboard::D
        };

    private:
        EventManager();
        static EventManager *instance;
        map<Key, bool> keys;

    public:

        ~EventManager();
        static EventManager* getInstance();

        void keyPressed(Key k);
        void keyReleased(Key k);

        bool isKeyPressed(Key k);
    };
}
