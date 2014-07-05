#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
   static const unsigned int WINDOW_WIDTH;
   static const unsigned int WINDOW_HEIGHT;
   static const sf::String WINDOW_TITLE;
   Game();
   ~Game();
   bool isInitialized() const;
   void run();
private:
   sf::RenderWindow window;
   bool initialized;
};

#endif
