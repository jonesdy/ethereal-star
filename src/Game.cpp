#include "Game.hpp"

Game::Game()
{
   initialized = gui.isInitialized();
}

Game::~Game()
{
}

bool Game::isInitialized() const
{
   return initialized;
}

void Game::run()
{
   std::shared_ptr<Entity> ent(new Entity(128, 128, 32, 32));
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 0, 0, 32, 32),
      0, Entity::Direction::UP);
   gui.addEntity(ent);
   while(gui.isWindowOpen())
   {
      gui.draw();
   }
}
