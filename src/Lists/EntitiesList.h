#pragma once

#include "List.h"
#include "../Entities/Entity.h"

using Entities::Entity;

namespace Lists {
    class EntitiesList
    {
    private:
        List<Entity> list;

    public:
        EntitiesList();
        ~EntitiesList();

        bool addEntity(Entity *e);
        // TODO: remove entity/index
        void clear();
        const int size() const;
        Entity* operator[](int index);
    };
}
