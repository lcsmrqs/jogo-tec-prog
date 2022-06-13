#include "Level.h"
#include "../Entities/Characters/Enemies/Enemy.h"
#include "../Entities/Projectiles/Projectile.h"
#include "../Managers/GraphicsManager.h"
#include "../Entities/Obstacles/Obstacle.h"
#include "../States/MenuState.h"
#include "../Menus/PauseMenu.h"

using namespace Levels;

using Managers::GraphicsManager;
using States::MenuState;
using Menus::PauseMenu;

Level::Level(const int _nPLayers, const float w) :
Ent(),
entities(),
collisionManager(),
nPlayers(_nPLayers),
players(),
background(),
checkpoint(),
toAddProj(),
toRemoveProj(),
toRemoveEnemies(),
toRemovePlayers(),
levelWidth(w)
{
    collisionManager.setLevel(this);
}

Level::~Level()
{
    for(int i = 0; i < entities.size(); i++)
        delete entities[i];

    entities.clear();

    delete checkpoint;

    players.clear();
}

void Level::run(float dt)
{
    updateView(dt);

    for(int i = 0; i < entities.size(); i++)
        entities[i]->run(dt);

    manageCollisions();

    std::list<Projectile*>::iterator projItr = toAddProj.begin();
    for( ; projItr != toAddProj.end(); projItr++)
    {
        Projectile *p = *projItr;
        addProjectile(p);
    }

    toAddProj.clear();

    projItr = toRemoveProj.begin();
    for( ; projItr != toRemoveProj.end(); projItr++)
    {
        Projectile *p = *projItr;
        removeProjectile(p);
        delete p;
    }
    toRemoveProj.clear();

    std::list<Enemy*>::iterator enemiesItr = toRemoveEnemies.begin();
    for( ; enemiesItr != toRemoveEnemies.end(); enemiesItr++)
    {
        Enemy *e = *enemiesItr;
        removeEnemy(e);
        delete e;
    }
    toRemoveEnemies.clear();

    std::list<Player*>::iterator playersItr = toRemovePlayers.begin();
    for( ; playersItr != toRemovePlayers.end(); playersItr++)
    {
        Player *p = *playersItr;
        removePlayer(p);
        delete p;
    }
    toRemovePlayers.clear();

    if(players.empty())
    {
        state->requestStackPop();
        state->requestResetTop();
    }
}

void Level::draw()
{
    drawBackground();
    for(int i = 0; i < entities.size(); i++)
        entities[i]->draw();
}

void Level::manageCollisions()
{
    collisionManager.manageCollisions();
}

void Levels::Level::onKeyPressed(Managers::Key k)
{
    if (k == Key::P)
        pause();
}

void Levels::Level::onKeyReleased(Managers::Key k) {}

void Level::setState(States::State *s)  { state = s; }

void Levels::Level::pause()
{
    PauseMenu *menu = new PauseMenu();
    state->requestStackPush(new MenuState(menu, state->getContext()));
}

void Level::addObstacle(Obstacle *po)
{
    entities.addEntity(static_cast<Entity*>(po));
    collisionManager.addObstacle(po);
}

void Level::addProjectile(Projectile *pp)
{
    entities.addEntity(static_cast<Entity*>(pp));
    collisionManager.addProjectile(pp);
}

void Levels::Level::removeProjectile(Projectile *pp)
{
    entities.removeEntity(static_cast<Entity*>(pp));
    collisionManager.removeProjectile(pp);
}

void Level::requestAddProj(Projectile *pp)
{
    toAddProj.push_back(pp);
}

void Levels::Level::requestRemoveProj(Projectile *pp)
{
    toRemoveProj.push_back(pp);
}

void Levels::Level::addEnemy(Enemy *pe)
{
    entities.addEntity(static_cast<Entity*>(pe));
    collisionManager.addEnemy(pe);
}

void Levels::Level::removeEnemy(Enemy *pe)
{
    entities.removeEntity(pe);
    collisionManager.removeEnemy(pe);
}

void Levels::Level::requestRemoveEnemy(Enemy *pe)
{
    toRemoveEnemies.push_back(pe);
}

void Levels::Level::addPlayer(Player *pp)
{
    entities.addEntity(static_cast<Entity*>(pp));
    collisionManager.addPlayer(pp);
    players.push_back(pp);
}

void Levels::Level::removePlayer(Player *pp)
{
    entities.removeEntity(static_cast<Entity*>(pp));
    collisionManager.removePlayer(pp);
    players.remove(pp);

    //
}

void Levels::Level::requestRemovePlayer(Player *pp)
{
    toRemovePlayers.push_back(pp);
}

void Levels::Level::updateView(const float dt)
{
    GraphicsManager *graphics = GraphicsManager::getInstance();
    std::list<Player*>::iterator playersItr = players.begin();
    Vect pos(0.0, 0.0), viewCenter(0.0, 0.0), ds(0.0, 0.0);
    float i = 0;

    for( ; playersItr != players.end(); playersItr++)
    {
        Player *p = *playersItr;
        pos += p->getPosition();
        i += 1;
    }

    pos /= i;

    viewCenter = graphics->getViewCenter();

    ds.setX((pos.getX() - viewCenter.getX()) * dt);

    if((viewCenter.getX() + ds.getX()) > WINDOW_WIDTH / 2 && (viewCenter.getX() + ds.getX()) < (levelWidth - WINDOW_WIDTH / 2))

    graphics->updateView(ds);
}

void Levels::Level::drawBackground()
{
    GraphicsManager *graphics = GraphicsManager::getInstance();
    graphics->getWindow()->draw(background);
}
