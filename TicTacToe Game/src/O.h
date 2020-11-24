#pragma once
class O
{
private:
	//Variables
	sf::Texture texture;
	sf::Sprite sprite;

	//Private functions
	void initSprite();
public:
	//Con/des
	O();
	~O();

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};

