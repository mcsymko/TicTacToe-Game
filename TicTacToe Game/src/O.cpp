#include "stdafx.h"
#include "O.h"

//Private functions
void O::initSprite()
{
	this->texture.loadFromFile("Textures/O.png");

	this->sprite.setTexture(this->texture);
}

//Con/des
O::O()
{
	this->initSprite();
}

O::~O()
{

}

//Accessors
void O::setPosition(sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

//Functions
void O::update()
{

}

void O::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
