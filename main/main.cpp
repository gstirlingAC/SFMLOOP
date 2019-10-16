// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SFML/x86/include/SFML/Graphics.hpp"

// Set up the window
sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game!!!", sf::Style::Default);

// Set up graphics
sf::Texture skyTexture, bgTexture, heroTexture;
sf::Sprite skySprite, bgSprite, heroSprite;

void init();
void draw();
void updateInput();

int main()
{
	// Initialize Game Objects
	init();

	// Game loop
	while (window.isOpen()) 
	{
		// Handle Keyboard Events
		updateInput();
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
	bgTexture.loadFromFile("Assets/graphics/bg.png");
	heroTexture.loadFromFile("Assets/graphics/hero.png");

	// Set and attach a texture to sprite
	skySprite.setTexture(skyTexture);
	bgSprite.setTexture(bgTexture);
	heroSprite.setTexture(heroTexture);

	// Initialise the hero sprite
	heroSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
	heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);
}

void draw()
{
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(heroSprite);
}

void updateInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
			window.close();
	}
}