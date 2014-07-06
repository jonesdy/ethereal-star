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
   gui.addEntity(std::shared_ptr<Entity>(new Entity(128, 128, 32, 32)), "../resources/Sprites.png", 0, 0);
   while(gui.isWindowOpen())
   {
      gui.draw();
   }
}
