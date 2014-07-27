#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <map>
#include <utility>
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
public:
   enum Direction {UP, DOWN, LEFT, RIGHT};
   Entity();
   Entity(int xPos, int yPos);
   ~Entity();
   void create(int xPos, int yPos);
   int getX() const;
   int getY() const;
   int getWidth() const;
   int getHeight() const;
   void move(int dx, int dy);
   void addSprite(sf::Sprite sprite, int f, Direction dir);
private:
   virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
   int x;
   int y;
   int frame;
   int maxFrame;
   Direction direction;
   Direction prevDirection;
   std::map<std::pair<int, Direction>, sf::Sprite> sprites;    // Frame, direction
};

#endif
