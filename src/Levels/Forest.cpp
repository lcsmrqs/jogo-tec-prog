#include "Forest.h"
#include "../Managers/GraphicsManager.h"
#include "../Entities/Characters/Enemies/Enemy.h"
#include "../Entities/Characters/Enemies/MulaSemCabeca.h"
#include "../Entities/Characters/Enemies/Curupira.h"
#include "../Entities/Characters/Enemies/Cuca.h"
#include "../Entities/Floor.h"
#include "../Entities/Obstacles/Platform.h"
#include "../Entities/Obstacles/Bush.h"
#include "../States/PlayingState.h"
#include "../Levels/Cave.h"
#include <cstdlib>
#include <ctime>

using namespace Levels;

using Managers::GraphicsManager;
using States::PlayingState;
using Entities::Characters::Enemies::Enemy;
using Entities::Characters::Enemies::MulaSemCabeca;
using Entities::Characters::Enemies::Curupira;
// using Entities::Characters::Enemies::Cuca;
using Entities::Obstacles::Platform;
using Entities::Obstacles::Bush;
using Levels::Cave;

Forest::Forest(const int players, const float w) :
Level(players, w)
{
    init();
}

Forest::~Forest() {}

void Forest::init()
{
    sf::Texture* bgTexture = GraphicsManager::getInstance()->getTexture("forest");
    background.setTexture(*bgTexture);

    checkpoint = new Checkpoint(Vect(levelWidth + 16, WINDOW_HEIGHT / 2), Vect(32, WINDOW_HEIGHT));
    collisionManager.setCheckpoint(checkpoint);

    generateLevel();
}

void Forest::generateLevel()
{
    srand(time(NULL));
    int i, r1=0, r2=0, r3=0, aux=0;
    float width = 0.0;
    float division = 0.0;

    std::map<float, Enemy*> _enemies;
    std::map<float, Enemy*>::iterator eItr;

    // floor
    floor = new Floor(Vect(levelWidth / 2, WINDOW_HEIGHT - 16), Vect(levelWidth, 32));
    collisionManager.setFloor(floor);
    entities.addEntity(static_cast<Entity*>(floor));

    // players
    Player *player1 = new Player(Vect(32.0f, 275.0f), this);
    addPlayer(player1);

    if(nPlayers == 2)
    {
        Player *player2 = new Player(Vect(96.0f, 275.0f), this, true);
        addPlayer(player2);
    }

    // obstaculos
    width = 200.0;
    division = (levelWidth - 375) / 12;
    r1 = (rand() % 3) + 3;
    for(i = 0; i < r1; i++) // plataformas
    {
        r2 += (rand() % 12) + 1;
        r3 = (rand() % 4) + 7;
        Platform *p = new Platform(Vect(350 + (i * division) + r2 * width / 5, 225.0f), Vect(r3 * width / 10, 16));

        r3 = rand() % 3;
        if(r3 == 0)
        {
            Curupira *curupira = new Curupira(Vect(p->getPosition().getX() + p->getSize().getX() / 2, p->getPosition().getY() - 100), this);
            addEnemy(curupira);
            _enemies[curupira->getPosition().getX()] = curupira;
        }

        addObstacle(static_cast<Obstacle*>(p));
    }

    width = 60.0;
    division = (levelWidth - 375) / 25;
    r2 = 0;
    r1 = (rand() % 3) + 3;
    for(i = 0; i < r1; i++) // arbustos
    {
        r2 += (rand() % 4) + 2;
        Bush *pBush = new Bush(Vect(350 + (r2 * division), 302.0f));
        addObstacle(static_cast<Obstacle*>(pBush));
    }

    // criar inimigos
    r2 = 0;
    division = (levelWidth - 375) / 10;
    r1 = (rand() % 2) + 3;
    for(i = 0; i < r1; i++) // curupira
    {
        r2 = (rand() % 5) + 1;
        float _x = 350 + (i+r2) * division;
        if(!_enemies[_x]) // verifica se ja possui um inimigo na coordenada _x
        {
            Curupira *curupira = new Curupira(Vect(_x, 315), this);
            _enemies[curupira->getPosition().getX()] = curupira;
            addEnemy(curupira);
        }
        else
            i--;
    }

    r2 = 0;
    division = (levelWidth - 375) / 11;
    r1 = (rand() % 3) + 3;
    for(i = 0; i < r1; i++) // mula
    {
        r2 = (rand() % 6) + 1;
        float _x = 350 + (i+r2) * division;
        if(!_enemies[_x]) // verifica se ja possui um inimigo na coordenada _x
        {
            MulaSemCabeca *mula = new MulaSemCabeca(Vect(_x, 315), this);
            _enemies[mula->getPosition().getX()] = mula;
            addEnemy(mula);
        }
        else
            i--;
    }

    // adicionar player aos inimigos
    std::list<Player*>::iterator pItr = players.begin();
    for( ; pItr != players.end(); pItr++)
        for(eItr = _enemies.begin(); eItr != _enemies.end(); eItr++)
            (*eItr).second->addPlayer((*pItr));
}

void Forest::reset()
{
    for(int i = 0; i < entities.size(); i++)
        delete entities[i];

    entities.clear();

    players.clear();
    collisionManager.clearAll();

    generateLevel();
}

void Forest::finish()
{
    GraphicsManager::getInstance()->resetView();
    PlayingState *nextState = new PlayingState(new Cave(nPlayers), state->getContext());
    state->requestStackPop();
    state->requestStackPush(nextState);
}

void Forest::onKeyPressed(Managers::Key k)
{
    Level::onKeyPressed(k);
}
