#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

int main()
{
   Game game;

   if(game.isInitialized())
   {
      game.run();
   }
   else
   {
      std::cerr<<"Failed to initialize"<<std::endl;
      return 1;
   }
   
   return 0;
}
