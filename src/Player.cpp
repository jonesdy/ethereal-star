#include "Player.hpp"

Player::Player() : Entity()
{
}

Player::Player(int tx, int ty) : Entity(tx, ty)
{
}

Player::~Player()
{
}

void Player::handleEvent(std::shared_ptr<sf::Event> evt)
{
   if(evt != nullptr && evt->type == sf::Event::KeyPressed)
   {
      switch(evt->key.code)
      {
      case sf::Keyboard::W:
      case sf::Keyboard::Up:
         moveUp();
         break;
      case sf::Keyboard::S:
      case sf::Keyboard::Down:
         moveDown();
         break;
      case sf::Keyboard::A:
      case sf::Keyboard::Left:
         moveLeft();
         break;
      case sf::Keyboard::D:
      case sf::Keyboard::Right:
         moveRight();
         break;
      default:
         break;
      }
   }
}
