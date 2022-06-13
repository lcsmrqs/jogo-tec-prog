#pragma once

#include "Enemy.h"

namespace Entities {
	namespace Characters {
		namespace Enemies {
			class MulaSemCabeca : public Enemy
			{
			protected:
				float fireballCooldown;

			public:
				MulaSemCabeca(const Vect pos = Vect(), Level *l = NULL);
				~MulaSemCabeca();

				void run(float dt);
				void throwFireball(Vect direction);

                const int getDamage() const override;
            };
		}
	}
}
