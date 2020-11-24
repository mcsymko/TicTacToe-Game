#include "stdafx.h"
#include "X.h"

//Private functions
void X::initX()
{
	this->texture.loadFromFile("Textures/X.png");

	this->sprite.setTexture(this->texture);
}

//Con/des
X::X()
{
	this->initX();
}

X::~X()
{

}

//Functions
void X::update()
{

}

void X::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
