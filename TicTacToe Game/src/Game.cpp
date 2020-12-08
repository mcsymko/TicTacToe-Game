#include "stdafx.h"
#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->turnOfPlayer = 'X';
	this->mouseHeld = false;

	this->playerX = new X;
	this->playerO = new O;
	
	this->timer = 0;
	this->delay = 1.f;
}

void Game::initWindow()
{
	this->window.create(sf::VideoMode(512, 512), "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initGUI()
{
	//Background board
	this->bgTexture.loadFromFile("Textures/background.png");

	this->background.setTexture(this->bgTexture);

	//End game text initialization
	if (!this->font.loadFromFile("Fonts/Texturina-VariableFont_opsz,wght.ttf"))
		std::cout << "ERROR::GAME::INITGUI::Could not load font" << std::endl;

	this->gameOverText.setFont(this->font);
	this->gameOverText.setFillColor(sf::Color::Black);
	this->gameOverText.setCharacterSize(60);
}

void Game::initRectangles()
{
	//Rectangles for mouseclicking at some position
	this->rects[0][0].setSize(sf::Vector2f(140.f, 140.f));
	this->rects[0][0].setPosition(sf::Vector2f());

	this->rects[0][1].setSize(sf::Vector2f(160.f, 140.f));
	this->rects[0][1].setPosition(sf::Vector2f(256.f - this->rects[0][1].getGlobalBounds().width / 2, 70.f - this->rects[0][1].getGlobalBounds().height / 2));

	this->rects[0][2].setSize(sf::Vector2f(140.f, 140.f));
	this->rects[0][2].setPosition(sf::Vector2f(442.f - this->rects[0][2].getGlobalBounds().width / 2, 70.f - this->rects[0][2].getGlobalBounds().height / 2));

	this->rects[1][0].setSize(sf::Vector2f(140.f, 160.f));
	this->rects[1][0].setPosition(sf::Vector2f(70.f - this->rects[1][0].getGlobalBounds().width / 2, 256.f - this->rects[1][0].getGlobalBounds().height / 2));

	this->rects[1][1].setSize(sf::Vector2f(160.f, 160.f));
	this->rects[1][1].setPosition(sf::Vector2f(256.f - this->rects[1][1].getGlobalBounds().width / 2, 256.f - this->rects[1][1].getGlobalBounds().height / 2));

	this->rects[1][2].setSize(sf::Vector2f(140.f, 160.f));
	this->rects[1][2].setPosition(sf::Vector2f(442.f - this->rects[1][2].getGlobalBounds().width / 2, 256.f - this->rects[1][2].getGlobalBounds().height / 2));

	this->rects[2][0].setSize(sf::Vector2f(140.f, 140.f));
	this->rects[2][0].setPosition(sf::Vector2f(70.f - this->rects[2][0].getGlobalBounds().width / 2, 442.f - this->rects[2][0].getGlobalBounds().height / 2));

	this->rects[2][1].setSize(sf::Vector2f(160.f, 140.f));
	this->rects[2][1].setPosition(sf::Vector2f(256.f - this->rects[2][1].getGlobalBounds().width / 2, 442.f - this->rects[2][1].getGlobalBounds().height / 2));

	this->rects[2][2].setSize(sf::Vector2f(140.f, 140.f));
	this->rects[2][2].setPosition(sf::Vector2f(442.f - this->rects[2][2].getGlobalBounds().width / 2, 442.f - this->rects[2][2].getGlobalBounds().height / 2));

	
}

void Game::initBoard()
{
	//Initializing board
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			this->board[i][j] = '1';
		}
	}
}

void Game::initPositions()
{
	//Positioning the sprites. 65 pixels is half size of sprite either in width and height
	this->positions[0][1].x = 256.f - 65.f;
	this->positions[0][1].y = 70.f - 65.f;

	this->positions[0][2].x = 442.f - 65.f;
	this->positions[0][2].y = 70.f - 65.f;

	this->positions[1][0].x = 70.f - 65.f;
	this->positions[1][0].y = 256.f - 65.f;

	this->positions[1][1].x = 256.f - 65.f;
	this->positions[1][1].y = 256.f - 65.f;

	this->positions[1][2].x = 442.f - 65.f;
	this->positions[1][2].y = 256.f - 65.f;

	this->positions[2][0].x = 70.f - 65.f;
	this->positions[2][0].y = 442.f - 65.f;

	this->positions[2][1].x = 256.f - 65.f;
	this->positions[2][1].y = 442.f - 65.f;

	this->positions[2][2].x = 442.f - 65.f;
	this->positions[2][2].y = 442.f - 65.f;
}

void Game::initEndGameText(const char& ch)
{
	//Game over text
	switch (ch)
	{
	case 'X':
		this->gameOverText.setString("Player X won!");
		this->gameOverText.setPosition(sf::Vector2f(
			this->window.getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
			this->window.getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f));
		break;
	case 'O':
		this->gameOverText.setString("Player O won!");
		this->gameOverText.setPosition(sf::Vector2f(
			this->window.getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
			this->window.getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f));
		break;
	case 'D':
		this->gameOverText.setString("DRAW");
		this->gameOverText.setPosition(sf::Vector2f(
			this->window.getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
			this->window.getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f));
		break;
	}
}

//Con/des
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initGUI();
	this->initRectangles();
	this->initBoard();
	this->initPositions();
}

Game::~Game()
{
	delete this->playerX;
	delete this->playerO;
}

//Functions
void Game::checkWin()
{
	//Win check
	if (this->board[0][0] == 'X' && this->board[0][1] == 'X' && this->board[0][2] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][0] == 'O' && this->board[0][1] == 'O' && this->board[0][2] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}
	else if (this->board[1][0] == 'X' && this->board[1][1] == 'X' && this->board[1][2] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[1][0] == 'O' && this->board[1][1] == 'O' && this->board[1][2] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}
	else if (this->board[2][0] == 'X' && this->board[2][1] == 'X' && this->board[2][2] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[2][0] == 'O' && this->board[2][1] == 'O' && this->board[2][2] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][0] == 'X' && this->board[1][0] == 'X' && this->board[2][0] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][0] == 'O' && this->board[1][0] == 'O' && this->board[2][0] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][1] == 'X' && this->board[1][1] == 'X' && this->board[2][1] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][1] == 'O' && this->board[1][1] == 'O' && this->board[2][1] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][2] == 'X' && this->board[1][2] == 'X' && this->board[2][2] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][2] == 'O' && this->board[1][2] == 'O' && this->board[2][2] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][0] == 'X' && this->board[1][1] == 'X' && this->board[2][2] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][0] == 'O' && this->board[1][1] == 'O' && this->board[2][2] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][2] == 'X' && this->board[1][1] == 'X' && this->board[2][0] == 'X')
	{
		this->render();
		this->result = 'X';
		this->initEndGameText(this->result);
	}
	else if (this->board[0][2] == 'O' && this->board[1][1] == 'O' && this->board[2][0] == 'O')
	{
		this->render();
		this->result = 'O';
		this->initEndGameText(this->result);
	}

	//Draw check
	else
	{
		int buf = 0;
		
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (this->board[i][j] == '1')
					buf++;
			}
		}
		if (buf == 0)
		{
			this->render();
			this->result = 'D';
			this->initEndGameText(this->result);
		}
	}
}

void Game::updatePollEvents()
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();
	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(this->window);
	this->mousePosView = this->window.mapPixelToCoords(this->mousePosWindow);
}

void Game::updateTurnX()
{
	//Put X if its turn of player X
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->turnOfPlayer == 'X')
	{
		if (!this->mouseHeld)
		{
			this->mouseHeld = true;

			for (size_t i = 0; i < 3; ++i)
			{
				for (size_t j = 0; j < 3; ++j)
				{
					if (this->rects[i][j].getGlobalBounds().contains(this->mousePosView) && this->board[i][j] == '1')
					{
						this->board[i][j] = 'X';

						this->turnOfPlayer = 'O';
					}
				}
			}
		}
		//Start delay when X made a turn
		this->clock.restart();
	}
	else
	{
		//Banning mouseholding
		this->mouseHeld = false;
	}
}

void Game::updateTurnO()
{
	//Put O if its turn of player O
	if (this->turnOfPlayer == 'O')
	{
		this->mouseHeld = true;

		int buf1 = rand() % 3;
		int buf2 = rand() % 3;

		if (this->board[buf1][buf2] == '1')
		{
			//Delayed spawning of player O
			float time = clock.getElapsedTime().asSeconds();
			this->clock.restart();
			this->timer += time;
			if (this->timer > this->delay)
			{
				this->timer = 0;
				this->board[buf1][buf2] = 'O';
				this->turnOfPlayer = 'X';
			}
		}
	}
}

void Game::update()
{
	this->updateMousePositions();
	this->updateTurnX();
	this->updateTurnO();
	this->checkWin();
}

void Game::renderBackground()
{
	this->window.draw(this->background);
}

void Game::renderRects()
{
	//Draw rects which checks if mouse is pressed
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			this->window.draw(this->rects[i][j]);
		}
	}
}

void Game::renderPlayer()
{
	//Draw player's sprite if mouseclicked by X or spawned by O
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
			{
				this->playerX->setPosition(positions[i][j]);
				this->playerX->render(this->window);
			}
			else if (board[i][j] == 'O')
			{
				this->playerO->setPosition(positions[i][j]);
				this->playerO->render(this->window);
			}
		}
	}
}

void Game::renderEndGameText()
{
	//If there is a winner ---> draw endgame text
	if (this->result == 'X' || this->result == 'O' || this->result == 'D')
	{
		this->window.clear(sf::Color::White);
		this->window.draw(this->gameOverText);
	}
}

void Game::render()
{
	this->window.clear();
	this->renderBackground();
	this->renderRects();
	this->renderPlayer();
	this->renderEndGameText();
	this->window.display();
}

void Game::run()
{
	while (this->window.isOpen())
	{
		this->updatePollEvents();

		//Stop doing something if game is over
		if (this->result != 'X' && this->result != 'O' && this->result != 'D')
		{
			this->update();
			this->render();
		}
	}
}