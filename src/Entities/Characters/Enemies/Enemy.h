#pragma once

#include "../Character.h"
#include "../Player.h"

namespace Entities {
    namespace Characters {
		namespace Enemies {
			class Enemy : public Character
			{
			protected:
                std::list<Player*> players;
                float maxSpeed;

			public:
				Enemy(const Vect pos = Vect(), Level *l = NULL);
				virtual ~Enemy();

				virtual void run(float dt);
                virtual const int getDamage() const = 0;

                void addPlayer(Player *pp);
                void removePlayer(Player *pp);
			};
		}
    }
}
