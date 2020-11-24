#pragma once
class Game
{
private:
	//Variables
	sf::RenderWindow window;
	sf::Event ev;

	//Background
	sf::Texture bgTexture;
	sf::Sprite background;

	//Private functions
	void initWindow();
	void initBackground();
public:
	//Con/des
	Game();
	~Game();

	//Functions
	void updatePollEvents();
	void update();

	void renderBackground();
	void render();

	void run();
};