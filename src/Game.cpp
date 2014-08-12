#include "Game.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Map.hpp"

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
   std::shared_ptr<Player> player(new Player(5, 5));
   std::shared_ptr<Map> map(new Map());
   TextureManager textureManager;
   for(unsigned int i = 0; i < 4; i++)
   {
      for(unsigned int j = 0; j < 3; j++)
      {
         player->addSprite(std::shared_ptr<sf::Sprite>(new sf::Sprite(
            *textureManager.getTexture("../resources/Sprites.png",
             (i * 3 * 32) + (j * 32), 0, 32, 32))), j, Entity::Direction(i));
      }
   }

   for(unsigned int i = 0; i < 20; i++)
   {
      for(unsigned int j = 0; j < 25; j++)
      {
         map->addTile(std::shared_ptr<Tile>(new Tile(j * 32, i * 32,
            std::shared_ptr<sf::Sprite>(new sf::Sprite(
            *textureManager.getTexture("../resources/tiles0.png",
            32, 0, 32, 32))), Tile::Property::NONE)));
      }
   }

   gui.addDrawable(map);
   gui.addDrawable(player);
   sf::Clock clock;
   while(gui.isWindowOpen())
   {
      // Some test logic
      player->tick(clock.restart());
      player->handleEvent(gui.getLatestEvent());

      gui.draw();
   }
}
