#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Entity.hpp"
#include "TextureManager.hpp"

class Gui
{
public:
   static const int WINDOW_WIDTH;
   static const int WINDOW_HEIGHT;
   static const sf::String WINDOW_TITLE;
   Gui();
   ~Gui();
   bool isInitialized() const;
   bool isWindowOpen() const;
   void draw();
   void addDrawable(std::shared_ptr<sf::Drawable> drawable);
   void removeDrawable(std::shared_ptr<sf::Drawable> drawable);
private:
   sf::RenderWindow window;
   bool initialized;
   std::vector<std::shared_ptr<sf::Drawable> > drawables;
};

#endif
