#include "EntitiesList.h"

using namespace Lists;

EntitiesList::EntitiesList() :
list()
{}

EntitiesList::~EntitiesList()
{
    clear();
}

bool EntitiesList::addEntity(Entity *e)
{
    return list.addData(e);
}

void EntitiesList::clear()
{
    list.clear();
}

const int EntitiesList::size() const
{
    return list.size();
}

Entity* EntitiesList::operator[](int index)
{
    return list[index];
}

void EntitiesList::removeEntity(Entity *e) {
    list.removeElement(e);
}
