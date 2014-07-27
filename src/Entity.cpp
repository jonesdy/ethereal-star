#include "Entity.hpp"

Entity::Entity()
{
   create(0, 0);
}

Entity::Entity(int xPos, int yPos)
{
   create(xPos, yPos);
}

Entity::~Entity()
{
}

void Entity::create(int xPos, int yPos)
{
   x = xPos;
   y = yPos;
   frame = 0;
   maxFrame = 0;
   direction = Direction::UP;
   prevDirection = direction;
}

int Entity::getX() const
{
   return x;
}

int Entity::getY() const
{
   return y;
}

int Entity::getWidth() const
{
   return sprites.at(std::pair<int, Direction>(frame, direction)).getLocalBounds().width;
}

int Entity::getHeight() const
{
   return sprites.at(std::pair<int, Direction>(frame, direction)).getLocalBounds().height;
}

void Entity::move(int dx, int dy)
{
   x += dx;
   y += dy;

   // Determine which frame to use
   if(frame < maxFrame)
   {
      frame++;
   }
   else
   {
      frame = 0;
   }

   // Determine which direction to use
   if(dx > 0)
   {
      direction = Direction::RIGHT;
   }
   else if(dx < 0)
   {
      direction = Direction::LEFT;
   }
   else if(dy > 0)
   {
      direction = Direction::DOWN;
   }
   else if(dy < 0)
   {
      direction = Direction::UP;
   }

   if(prevDirection != direction)
   {
      prevDirection = direction;
      frame = 0;
   }
}

void Entity::addSprite(sf::Sprite sprite, int f, Direction dir)
{
   sprites[std::pair<int, Direction>(f, dir)] = sprite;
   if(f > maxFrame)
   {
      maxFrame = f;
   }
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
   sf::Sprite curSprite = sprites.at(std::pair<int, Direction>(frame, direction));
   curSprite.setPosition(x, y);
   target.draw(curSprite, states);
}
