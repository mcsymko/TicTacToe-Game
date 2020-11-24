#pragma once
class Game
{
private:
	//Variables
	sf::RenderWindow window;
	sf::Event ev;

	//Private functions
	void initWindow();
public:
	//Con/des
	Game();
	~Game();

	//Functions
	void updatePollEvents();
	void update();

	void render();

	void run();
};