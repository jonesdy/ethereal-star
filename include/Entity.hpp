#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>
#include <utility>
#include <SFML/Graphics.hpp>
#include <memory>

class Entity : public sf::Drawable
{
public:
   enum Direction {UP, DOWN, LEFT, RIGHT};
   Entity();
   Entity(int tx, int ty);
   virtual ~Entity();
   void create(int tx, int ty);
   float getX() const;
   float getY() const;
   int getWidth() const;
   int getHeight() const;
   void moveUp();
   void moveDown();
   void moveLeft();
   void moveRight();
   void tick(sf::Time delta);
   void addSprite(std::shared_ptr<sf::Sprite> sprite, int f, Direction dir);
private:
   bool positionMatchesTilePosition() const;
   void updateFrame(float moved);
   virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
   sf::Vector2f position;        // The entity position overall
   sf::Vector2i tilePosition;    // The entity position, in the grid of tiles
   int frame;
   int maxFrame;
   Direction direction;
   Direction prevDirection;
   std::map<std::pair<int, Direction>, std::shared_ptr<sf::Sprite>> sprites;    // Frame, direction
   float moveSinceLastFrame;
};

#endif
