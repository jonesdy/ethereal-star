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
   while(gui.isWindowOpen())
   {
      gui.draw();
   }
}
