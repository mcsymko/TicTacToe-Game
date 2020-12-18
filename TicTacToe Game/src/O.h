#pragma once
class O
{
public:
	//Con/des
	O();
	~O();

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
	void initSprite();
};

