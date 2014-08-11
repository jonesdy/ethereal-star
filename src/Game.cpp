#include "Game.hpp"
#include "TextureManager.hpp"
#include <ctime>
#include "Player.hpp"

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
   TextureManager textureManager;
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 0, 0, 32, 32)),
      0, Entity::Direction::UP);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 32, 0, 32, 32)),
      1, Entity::Direction::UP);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 64, 0, 32, 32)),
      2, Entity::Direction::UP);

   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 96, 0, 32, 32)),
      0, Entity::Direction::DOWN);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 128, 0, 32, 32)),
      1, Entity::Direction::DOWN);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 160, 0, 32, 32)),
      2, Entity::Direction::DOWN);

   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 192, 0, 32, 32)),
      0, Entity::Direction::LEFT);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 224, 0, 32, 32)),
      1, Entity::Direction::LEFT);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 256, 0, 32, 32)),
      2, Entity::Direction::LEFT);

   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 288, 0, 32, 32)),
      0, Entity::Direction::RIGHT);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 320, 0, 32, 32)),
      1, Entity::Direction::RIGHT);
   player->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 352, 0, 32, 32)),
      2, Entity::Direction::RIGHT);

   gui.addDrawable(player);
   sf::Clock clock;
   while(gui.isWindowOpen())
   {
      // Some test logic
      player->tick(clock.restart());
      player->handleEvent(gui.getLatestEvent());
      /*int action = rand() % 4;
      if(action != 4)
      {
         Entity::Direction dir = (Entity::Direction)action;
         switch(dir)
         {
            case Entity::Direction::UP:
               player->moveUp();
               break;
            case Entity::Direction::DOWN:
               player->moveDown();
               break;
            case Entity::Direction::LEFT:
               player->moveLeft();
               break;
            case Entity::Direction::RIGHT:
               player->moveRight();
               break;
         }
      }*/

      gui.draw();
   }
}
