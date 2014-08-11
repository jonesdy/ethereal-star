#include "Entity.hpp"

Entity::Entity()
{
   create(0, 0);
}

Entity::Entity(int tx, int ty)
{
   create(tx, ty);
}

Entity::~Entity()
{
}

void Entity::create(int tx, int ty)
{
   tilePosition.x = tx;
   tilePosition.y = ty;
   position.x = tilePosition.x * 32.0;
   position.y = tilePosition.y * 32.0;
   frame = 0;
   maxFrame = 0;
   direction = Direction::UP;
   prevDirection = direction;
}

float Entity::getX() const
{
   return position.x;
}

float Entity::getY() const
{
   return position.y;
}

int Entity::getWidth() const
{
   return sprites.at(std::pair<int, Direction>(frame, direction)).getLocalBounds().width;
}

int Entity::getHeight() const
{
   return sprites.at(std::pair<int, Direction>(frame, direction)).getLocalBounds().height;
}

void Entity::moveUp()
{
   if(positionMatchesTilePosition())
   {
      tilePosition.y--;
      prevDirection = direction;
      direction = Direction::UP;
   }
}

void Entity::moveDown()
{
   if(positionMatchesTilePosition())
   {
      tilePosition.y++;
      prevDirection = direction;
      direction = Direction::DOWN;
   }
}

void Entity::moveLeft()
{
   if(positionMatchesTilePosition())
   {
      tilePosition.x--;
      prevDirection = direction;
      direction = Direction::LEFT;
   }
}

void Entity::moveRight()
{
   if(positionMatchesTilePosition())
   {
      tilePosition.x++;
      prevDirection = direction;
      direction = Direction::RIGHT;
   }
}

void Entity::tick(sf::Time delta)
{
   // Continue moving towards the tile position, if needed
   if(!positionMatchesTilePosition())
   {
      // TODO: Float rounding issues?
      float deltaPos = delta.asSeconds() * 120.0;
      float needToMove = 0.0;
      if(position.x < tilePosition.x * 32.0)
      {
         if(position.x + deltaPos > tilePosition.x * 32.0)
         {
            needToMove = tilePosition.x * 32.0 - position.x;
         }
         else
         {
            needToMove = deltaPos;
         }
         position.x += needToMove;
      }
      else if(position.x > tilePosition.x * 32)
      {
         if(position.x - deltaPos < tilePosition.x * 32.0)
         {
            needToMove = position.x - tilePosition.x * 32.0;
         }
         else
         {
            needToMove = deltaPos;
         }
         position.x -= needToMove;
      }
      else if(position.y < tilePosition.y * 32)
      {
         if(position.y + deltaPos > tilePosition.y * 32.0)
         {
            needToMove = tilePosition.y * 32.0 - position.y;
         }
         else
         {
            needToMove = deltaPos;
         }
         position.y += needToMove;
      }
      else if(position.y > tilePosition.y * 32)
      {
         if(position.y - deltaPos < tilePosition.y * 32.0)
         {
            needToMove = position.y - tilePosition.y * 32.0;
         }
         else
         {
            needToMove = deltaPos;
         }
         position.y -= needToMove;
      }

      updateFrame(needToMove);
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

bool Entity::positionMatchesTilePosition() const
{
   return (position.x == tilePosition.x * 32) && 
      (position.y == tilePosition.y * 32);
}

void Entity::updateFrame(float moved)
{
   moveSinceLastFrame += moved;
   if(moveSinceLastFrame >= 4.0)
   {
      moveSinceLastFrame -= 4.0;
      if(frame < maxFrame)
      {
         frame++;
      }
      else
      {
         frame = 0;
      }
   }
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
   sf::Sprite curSprite = sprites.at(std::pair<int, Direction>(frame, direction));
   curSprite.setPosition(position.x, position.y);
   target.draw(curSprite, states);
}
