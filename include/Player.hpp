#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include <memory>

class Player : public Entity
{
public:
   Player();
   Player(int tx, int ty);
   virtual ~Player();
   void handleEvent(std::shared_ptr<sf::Event> evt);
private:
};

#endif
