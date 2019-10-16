// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SFML/x86/include/SFML/Graphics.hpp"

// Set up the window
sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game!!!", sf::Style::Default);

// Set up graphics
sf::Texture skyTexture;
sf::Sprite skySprite;

void init();
void draw();

int main()
{
	// Initialize Game Objects
	init();

	// Game loop
	while (window.isOpen()) 
	{
		// Handle Keyboard Events
		// Update Game Objects in the scene
		window.clear(sf::Color::Red);
		// Render game Objects
		draw();
		window.display();
	}
	return 0;
}

void init()
{
	// Load sky texture
	skyTexture.loadFromFile("Assets/graphics/sky.png");

	// Set and attach a texture to sprite
	skySprite.setTexture(skyTexture);
}

void draw()
{
	window.draw(skySprite);
}