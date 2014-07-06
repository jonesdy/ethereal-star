#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Gui.hpp"

class Game
{
public:
   Game();
   ~Game();
   bool isInitialized() const;
   void run();
private:
   bool initialized;
   Gui gui;
};

#endif
