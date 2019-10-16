// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SFML/x86/include/SFML/Graphics.hpp"

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game!!!", sf::Style::Default);

int main()
{
	// Initialize Game Objects
	while (window.isOpen()) 
	{
		// Handle Keyboard Events
		// Update Game Objects in the scene
		window.clear(sf::Color::Red);
		// Render game Objects
		window.display();
	}
	return 0;
}

