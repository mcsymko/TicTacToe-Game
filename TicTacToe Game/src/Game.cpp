#include "stdafx.h"
#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->mouseHeld = false;
	this->turnOfPlayer = 'X';
}

void Game::initWindow()
{
	this->window.create(sf::VideoMode(512, 512), "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initBackground()
{
	this->bgTexture.loadFromFile("Textures/background.png");

	this->background.setTexture(this->bgTexture);
}

void Game::initRectangles()
{
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

//Con/des
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initBackground();
	this->initRectangles();
}

Game::~Game()
{

}

//Functions
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

void Game::updateTurn()
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
					if (this->board[i][j] == ' ' && this->rects[i][j].getGlobalBounds().contains(this->mousePosView))
					{
						this->board[i][j] = 'X';

						this->turnOfPlayer = 'O';
					}
				}
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				std::cout << this->board[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else if (this->turnOfPlayer == 'O')
	{
		int buf1 = rand() % 2;
		int buf2 = rand() % 2;

		if (this->board[buf1][buf2] != 'X' && this->board[buf1][buf2] != 'O')
			this->board[buf1][buf2] = 'O';

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				std::cout << this->board[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game::update()
{
	this->updatePollEvents();
	this->updateMousePositions();
	this->updateTurn();
}

void Game::renderBackground()
{
	this->window.draw(this->background);
}

void Game::renderRects()
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			this->window.draw(this->rects[i][j]);
		}
	}
}

void Game::render()
{
	this->window.clear();
	this->renderBackground();
	this->renderRects();

	this->window.display();
}

void Game::run()
{
	while (this->window.isOpen())
	{
		this->update();
		this->render();
	}
}
