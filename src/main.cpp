#include "test.hpp"
#include <SFML/Graphics.hpp>

int main()
{
   Test t;

   t.print();

   sf::RenderWindow window(sf::VideoMode(800, 640), "Ethereal Star");
   sf::Sprite testSprite;
   sf::Texture testTexture;
   if(!testTexture.loadFromFile("./../resources/test.png"))
   {
      std::cout<<"Failed to open image"<<std::endl;
      return 1;
   }

   testSprite.setTexture(testTexture);
   testSprite.setPosition(sf::Vector2f(100, 100));

   while(window.isOpen())
   {
      sf::Event evt;
      while(window.pollEvent(evt))
      {
         if(evt.type == sf::Event::Closed)
         {
            window.close();
         }
      }

      window.clear();
      window.draw(testSprite);
      window.display();
   }

   return 0;
}
