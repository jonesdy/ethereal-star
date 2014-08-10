#include "Game.hpp"
#include "TextureManager.hpp"
#include <ctime>

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
   std::shared_ptr<Entity> ent(new Entity(128, 128));
   TextureManager textureManager;
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 0, 0, 32, 32)),
      0, Entity::Direction::UP);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 32, 0, 32, 32)),
      1, Entity::Direction::UP);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 64, 0, 32, 32)),
      2, Entity::Direction::UP);

   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 96, 0, 32, 32)),
      0, Entity::Direction::DOWN);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 128, 0, 32, 32)),
      1, Entity::Direction::DOWN);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 160, 0, 32, 32)),
      2, Entity::Direction::DOWN);

   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 192, 0, 32, 32)),
      0, Entity::Direction::LEFT);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 224, 0, 32, 32)),
      1, Entity::Direction::LEFT);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 256, 0, 32, 32)),
      2, Entity::Direction::LEFT);

   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 288, 0, 32, 32)),
      0, Entity::Direction::RIGHT);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 320, 0, 32, 32)),
      1, Entity::Direction::RIGHT);
   ent->addSprite(sf::Sprite(*textureManager.getTexture("../resources/Sprites.png", 352, 0, 32, 32)),
      2, Entity::Direction::RIGHT);

   gui.addDrawable(ent);
   sf::Clock clock;
   while(gui.isWindowOpen())
   {
      // Some test logic
      ent->tick(clock.restart());
      int action = rand() % 4;
      if(action != 4)
      {
         Entity::Direction dir = (Entity::Direction)action;
         switch(dir)
         {
            case Entity::Direction::UP:
               ent->moveUp();
               break;
            case Entity::Direction::DOWN:
               ent->moveDown();
               break;
            case Entity::Direction::LEFT:
               ent->moveLeft();
               break;
            case Entity::Direction::RIGHT:
               ent->moveRight();
               break;
         }
      }

      gui.draw();
   }
}
