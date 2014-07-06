#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

class Gui
{
public:
   static const unsigned int WINDOW_WIDTH;
   static const unsigned int WINDOW_HEIGHT;
   static const sf::String WINDOW_TITLE;
   Gui();
   ~Gui();
   bool isInitialized() const;
   bool isWindowOpen() const;
   void draw();
private:
   sf::RenderWindow window;
   bool initialized;
};

#endif
