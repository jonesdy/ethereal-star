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
   static const int FRAMERATE_LIMIT;
   Gui();
   ~Gui();
   bool isInitialized() const;
   bool isWindowOpen() const;
   bool isInMenu() const;
   void draw();
   void addDrawable(std::shared_ptr<sf::Drawable> drawable);
   void removeDrawable(std::shared_ptr<sf::Drawable> drawable);
   std::shared_ptr<sf::Event> getLatestEvent();
private:
   sf::RenderWindow window;
   bool initialized;
   std::vector<std::shared_ptr<sf::Drawable> > drawables;
   std::shared_ptr<sf::Event> lastEvent;
   bool inMenu;
   sf::IntRect joinRect;
   sf::IntRect settingsRect;
   sf::IntRect quitRect;
   sf::Font font;
   sf::Text text;
   sf::RectangleShape rectShape;
};

#endif
