#include "Gui.hpp"

const int Gui::WINDOW_WIDTH = 800;
const int Gui::WINDOW_HEIGHT = 640;
const sf::String Gui::WINDOW_TITLE = "Ethereal Star";
const int Gui::FRAMERATE_LIMIT = 60;

Gui::Gui()
{
   initialized = true;
   window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
   window.setFramerateLimit(FRAMERATE_LIMIT);

   inMenu = true;

   // GUI components initialization
   joinRect.top = 100;
   joinRect.left = 100;
   joinRect.width = 100;
   joinRect.height = 50;

   settingsRect.top = 175;
   settingsRect.left = 100;
   settingsRect.width = 100;
   settingsRect.height = 50;

   quitRect.top = 250;
   quitRect.left = 100;
   quitRect.width = 100;
   quitRect.height = 50;

   font.loadFromFile("../resources/SourceSansPro-Regular.otf");
   text.setColor(sf::Color::Red);
   text.setFont(font);
   text.setCharacterSize(20);
   sf::RectangleShape rectShape;
   rectShape.setFillColor(sf::Color::White);
}

Gui::~Gui()
{
}

bool Gui::isInitialized() const
{
   return initialized;
}

bool Gui::isWindowOpen() const
{
   return window.isOpen();
}

bool Gui::isInMenu() const
{
   return inMenu;
}

void Gui::draw()
{
   lastEvent.reset();
   if(isWindowOpen())
   {
      sf::Event evt;
      while(window.pollEvent(evt))
      {
         if(evt.type == sf::Event::Closed)
         {
            window.close();
         }
         else
         {
            if(inMenu && evt.type == sf::Event::MouseButtonReleased &&
               evt.mouseButton.button == sf::Mouse::Button::Left)
            {
               if(quitRect.contains(evt.mouseButton.x, evt.mouseButton.y))
               {
                  window.close();
               }
               else if(joinRect.contains(evt.mouseButton.x, evt.mouseButton.y))
               {
                  inMenu = false;
               }
            }
            lastEvent.reset(new sf::Event(evt));
         }
      }

      window.clear();

      // Do drawing here
      if(!inMenu)
      {
         // Draw entities and other stuff
         for(unsigned int i = 0; i < drawables.size(); i++)
         {
            window.draw(*drawables[i]);
         }
      }
      else
      {
         // Draw the menu GUI
         // Draw rectangles first
         rectShape.setSize(sf::Vector2f(joinRect.width, joinRect.height));
         rectShape.setPosition(joinRect.left, joinRect.top);
         window.draw(rectShape);

         rectShape.setSize(sf::Vector2f(settingsRect.width, settingsRect.height));
         rectShape.setPosition(settingsRect.left, settingsRect.top);
         window.draw(rectShape);

         rectShape.setSize(sf::Vector2f(quitRect.width, quitRect.height));
         rectShape.setPosition(quitRect.left, quitRect.top);
         window.draw(rectShape);

         // Draw the text
         text.setString("Join");
         sf::FloatRect textRect = text.getGlobalBounds();
         text.setPosition(joinRect.left + (joinRect.width / 2) - (textRect.width / 2),
                          joinRect.top + (joinRect.height / 2) - (textRect.height / 2));
         window.draw(text);

         text.setString("Settings");
         textRect = text.getGlobalBounds();
         text.setPosition(settingsRect.left + (settingsRect.width / 2) - (textRect.width / 2),
                          settingsRect.top + (settingsRect.height / 2) - (textRect.height / 2));
         window.draw(text);

         text.setString("Quit");
         textRect = text.getGlobalBounds();
         text.setPosition(quitRect.left + (quitRect.width / 2) - (textRect.width / 2),
                          quitRect.top + (quitRect.height / 2) - (textRect.height / 2));
         window.draw(text);
      }

      window.display();
   }
}

void Gui::addDrawable(std::shared_ptr<sf::Drawable> drawable)
{
   drawables.push_back(drawable);
}

void Gui::removeDrawable(std::shared_ptr<sf::Drawable> drawable)
{
   // TODO: Actually test this
   drawables.erase(std::remove(drawables.begin(), drawables.end(), drawable), drawables.end());
}

std::shared_ptr<sf::Event> Gui::getLatestEvent()
{
   return lastEvent;
}
