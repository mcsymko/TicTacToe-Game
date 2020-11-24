#include "stdafx.h"
#include "Game.h"

//Private functions
void Game::initWindow()
{
	this->window.create(sf::VideoMode(256, 256), "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

//Con/des
Game::Game()
{
	this->initWindow();
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

void Game::update()
{
	this->updatePollEvents();
}

void Game::render()
{
	this->window.clear();



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
