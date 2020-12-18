#pragma once
class X
{
public:
	//Con/des
	X();
	~X();

	//Accessors
	void setPosition(sf::Vector2f pos);

	//Functions
	void update();
	void render(sf::RenderTarget& target);

private:
	//Variables
	sf::Texture texture;
	sf::Sprite sprite;

	//Private functions
	void initX();
};

