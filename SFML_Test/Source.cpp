#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Budget MS Paint!"); //set window

	sf::CircleShape shape(50.f); //set brush shape
	sf::RectangleShape shape2(sf::Vector2f(50, 50));

	sf::Shape* brush = nullptr;
	brush = &shape;

	sf::Uint8 RGB_brush = 255;
	sf::Uint8 A_brush = 255;

	float size_brush = 1.f;

	brush->setFillColor(sf::Color::Color(255, 255, 255, A_brush)); //set brush color 
	
	while (window.isOpen()) //main render loop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) //if closed event, then close window
				window.close();
		}

		//getting mouse position and setting the brush to it 
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		(*brush).setPosition(sf::Vector2f(localPosition) + sf::Vector2f(-50.f*size_brush, -50.f*size_brush)); //change position by offset to align the mouse with the center
		
		brush->setFillColor(sf::Color::Color(RGB_brush, RGB_brush, RGB_brush, A_brush)); //set the brush to the color

		shape.setScale(sf::Vector2f(size_brush, size_brush)); //set brush shape
		shape2.setScale(sf::Vector2f(size_brush, size_brush));
		
		//if LMB is held
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window.draw(*brush); //draw with current shape selected	
		}
		//if spacebar is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			window.clear(); //clear screen
		}

		//shape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			brush = &shape2;
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			brush = &shape;
		}
		//color
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			RGB_brush = 255;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			RGB_brush = 100;
		}
		//size
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			size_brush = 2.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			size_brush = 0.5f;
		}
			 

		//window.clear(); //clear screen
		//window.draw(shape); //draw with current shape selected	
		window.display(); //display buffer of shapes produced by draw

		
		
	}
	return 0;
}