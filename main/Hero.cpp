#include "Hero.h"



Hero::Hero()
{
}


Hero::~Hero()
{
}

void Hero::init(std::string textureName, sf::Vector2f position, float mass)
{
	m_pos = position;
	m_mass = mass;

	m_grounded = false;

	// Load a texture
	m_texture.loadFromFile(textureName.c_str());

	// Create sprite and attach a texture
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_pos);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}

void Hero::update(float dt)
{
	m_vel -= m_mass * m_grav * dt;
	m_pos.y -= m_vel * dt;
	m_sprite.setPosition(m_pos);

	if (m_pos.y >= 768 * 0.75f)
	{
		m_pos.y = 768 * 0.75f;
		m_vel = 0;
		m_grounded = true;
		jumpCount = 0;
	}
}

void Hero::jump(float vel)
{
	if (jumpCount < 2)
	{
		jumpCount++;

		m_vel = vel;
		m_grounded = false;
	}
}

sf::Sprite Hero::getSprite()
{
	return m_sprite;
}
