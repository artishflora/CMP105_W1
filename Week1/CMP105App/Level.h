#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;
	sf::Vector2u m_screenSize;

	sf::RectangleShape rect;
	sf::CircleShape circle;
	sf::RectangleShape rectbotright;

	sf::RectangleShape rectouter;
	sf::RectangleShape rectmiddle;
	sf::RectangleShape rectinner;

	sf::Font font;
	sf::Text text;
	sf::Vector2f textscale;
};