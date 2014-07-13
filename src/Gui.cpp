#include "Gui.hpp"

const int Gui::WINDOW_WIDTH = 800;
const int Gui::WINDOW_HEIGHT = 640;
const sf::String Gui::WINDOW_TITLE = "Ethereal Star";

Gui::Gui()
{
   initialized = true;
   window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
   srand(time(NULL));
   start = clock();
   end = clock();
}

Gui::~Gui()
{
}

bool Gui::isInitialized() const
{
   return initialized;
}

bool Gui::isWindowOpen() const
{
   return window.isOpen();
}

void Gui::draw()
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
      for(unsigned int i = 0; i < entities.size(); i++)
      {
         // Get the current sprite info
         SpriteInfo si = entities[i]->getCurrentSpriteInfo();

         // See if we have set it up already
         if(sprites.count(si) != 1)
         {
            // We don't, create the sprite first
            sprites[si] = sf::Sprite(*textureManager.getTexture(si.getFileName(),
               si.getImageX(), si.getImageY(), si.getImageWidth(), si.getImageHeight()));
         }
         
         // Don't bother drawing if the sprite is off the screen
         if((entities[i]->getX() > 0) &&
            (entities[i]->getX() - entities[i]->getWidth() < WINDOW_WIDTH) && 
            (entities[i]->getY() > 0) &&
            (entities[i]->getY() - entities[i]->getHeight() < WINDOW_HEIGHT))
         {
            sprites[si].setPosition(entities[i]->getX(), entities[i]->getY());
            window.draw(sprites[si]);
         }

         // Some test logic
         clock_t delta = end - start;
         if((((float)delta) / CLOCKS_PER_SEC) >= 0.1)
         {
            start = clock();
            int action = rand() % 5;
            if(action != 4)
            {
               Entity::Direction dir = (Entity::Direction)action;
               switch(dir)
               {
                  case Entity::Direction::UP:
                     entities[i]->move(0, -4);
                     break;
                  case Entity::Direction::DOWN:
                     entities[i]->move(0, 4);
                     break;
                  case Entity::Direction::LEFT:
                     entities[i]->move(-4, 0);
                     break;
                  case Entity::Direction::RIGHT:
                     entities[i]->move(4, 0);
                     break;
               }
            }
         }
      }

      window.display();
      end = clock();
   }
}

void Gui::addEntity(std::shared_ptr<Entity> ent)
{
   entities.push_back(ent);
}
