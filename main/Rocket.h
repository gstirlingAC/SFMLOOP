#ifndef ROCKET

#include "SFML/x86/include/SFML/Graphics.hpp"

class Rocket
{
public:
	Rocket();
	~Rocket();

	void init(std::string textureName, sf::Vector2f position, float _speed);
	void update(float dt);
	sf::Sprite getSprite();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_pos;
	float m_speed;
};

#endif // !ROCKET

