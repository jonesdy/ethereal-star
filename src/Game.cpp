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
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 32, 0, 32, 32),
      1, Entity::Direction::UP);
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 64, 0, 32, 32),
      2, Entity::Direction::UP);

   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 96, 0, 32, 32),
      0, Entity::Direction::DOWN);
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 128, 0, 32, 32),
      1, Entity::Direction::DOWN);
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 160, 0, 32, 32),
      2, Entity::Direction::DOWN);

   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 192, 0, 32, 32),
      0, Entity::Direction::LEFT);
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 224, 0, 32, 32),
      1, Entity::Direction::LEFT);
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 256, 0, 32, 32),
      2, Entity::Direction::LEFT);

   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 288, 0, 32, 32),
      0, Entity::Direction::RIGHT);
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 320, 0, 32, 32),
      1, Entity::Direction::RIGHT);
   ent->addSpriteInfo(SpriteInfo("../resources/Sprites.png", 352, 0, 32, 32),
      2, Entity::Direction::RIGHT);

   gui.addEntity(ent);
   while(gui.isWindowOpen())
   {
      gui.draw();
   }
}
