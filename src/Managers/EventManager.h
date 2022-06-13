#pragma once

#include <map>
#include <list>
#include <SFML/Window/Keyboard.hpp>

using std::map;
using std::list;

namespace Managers {
    class EventListener;

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
            D = sf::Keyboard::D,
            P = sf::Keyboard::P,
            Enter = sf::Keyboard::Enter
        };

    private:
        EventManager();
        static EventManager *instance;
        map<Key, bool> keys;
        list<EventListener*> listeners;

    public:

        ~EventManager();
        static EventManager* getInstance();

        void subscribe(EventListener *l);
        void unsubscribe(EventListener *l);

        void onKeyPressed(Key k);
        void onKeyReleased(Key k);

        bool isKeyPressed(Key k);
    };
}
