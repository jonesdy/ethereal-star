#include "Game.hpp"

const unsigned int Game::WINDOW_WIDTH = 800;
const unsigned int Game::WINDOW_HEIGHT = 640;
const sf::String Game::WINDOW_TITLE = "Ethereal Star";

Game::Game()
{
   initialized = true;
   window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
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
   while(window.isOpen())
   {
      sf::Event evt;
      while(window.pollEvent(evt))
      {
         if(evt.type == sf::Event::Closed)
         {
            window.close();
         }
      }

      window.clear();

      // Do drawing here
      //window.draw(testSprite);

      window.display();
   }
}
