#pragma once

#include "X.h"
#include "O.h"

class Game
{
private:
	//Variables
	sf::RenderWindow window;
	sf::Event ev;

	//Timers
	//Timer for smooth spawn of player O
	sf::Clock clock;
	float timer;
	float delay;

	//Creating 9 rectangles to check if mouse is clicked on them
	sf::RectangleShape rects[3][3];	

	//Players
	X* playerX;
	O* playerO;

	//Positions
	sf::Vector2f positions[3][3];

	//Board
	char board[3][3];
	char turnOfPlayer;

	//Background
	sf::Texture bgTexture;
	sf::Sprite background;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseHeld;

	//Private functions
	void initVariables();
	void initWindow();
	void initBackground();
	void initRectangles();
	void initBoard();
	void initPositions();
public:
	//Con/des
	Game();
	~Game();

	//Functions
	void checkWin();

	void updatePollEvents();
	void updateMousePositions();
	void updateTurnX();
	void updateTurnO();
	void update();

	void renderBackground();
	void renderRects();
	void renderPlayer();
	void render();

	void run();
};