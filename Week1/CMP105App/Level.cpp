#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;
	m_screenSize = window->getSize();
	
	// initialise game objects
	rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	circle.setFillColor(sf::Color::Blue);
	circle.setRadius(20);
	circle.setPosition(230, 45);
	circle.setOutlineColor(sf::Color::Cyan);
	circle.setOutlineThickness(5.f);

	rectouter.setSize(sf::Vector2f(300, 300));
	rectouter.setPosition(300, 300);
	rectouter.setFillColor(sf::Color::Green);
	rectmiddle.setSize(sf::Vector2f(200, 200));
	rectmiddle.setPosition(350, 350);
	rectmiddle.setFillColor(sf::Color::Magenta);
	rectinner.setSize(sf::Vector2f(100, 100));
	rectinner.setPosition(400, 400);
	rectinner.setFillColor(sf::Color::Yellow);

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font !!" << std::endl;
	}

	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString("nothello world >:(");
	text.setCharacterSize(55);
	textscale = text.getScale();
	text.setPosition(sf::Vector2f(((m_screenSize.x/2) - (55*4)), 0));

	rectbotright.setFillColor(sf::Color::Green);
	rectbotright.setSize(sf::Vector2f(150, 20));
	sf::Vector2f rectsize = rectbotright.getSize();
	rectbotright.setPosition(sf::Vector2f(m_screenSize.x - rectsize.x, m_screenSize.y - rectsize.y));
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	m_screenSize = window->getSize();
	text.setPosition(sf::Vector2f(((m_screenSize.x / 2) - (55 * 4)), 0));
	sf::Vector2f rectsize = rectbotright.getSize();
	rectbotright.setPosition(sf::Vector2f(m_screenSize.x - rectsize.x, m_screenSize.y - rectsize.y));
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(rect);
	window->draw(circle);

	window->draw(rectouter);
	window->draw(rectmiddle);
	window->draw(rectinner);

	window->draw(text);
	window->draw(rectbotright);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}