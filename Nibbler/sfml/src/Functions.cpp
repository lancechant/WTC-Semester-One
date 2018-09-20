#include "../includes/Functions.hpp"
#include <iostream>

SFML::SFML() {}

SFML::SFML(SFML const &src){
	*this = src;
}

SFML	&SFML::operator=(SFML const &rhs){
	if (this != &rhs){
	    this->settings = rhs.getSettings();
	    this->event = rhs.getEvent();
	    this->height = rhs.getHeight();
	    this->width = rhs.getWidth();
	}

	return *this;
}

SFML::~SFML() {
	OnCleanup();
}

//GETTERS

sf::ContextSettings SFML::getSettings(void) const{
	return this->settings;
}

sf::Event 			SFML::getEvent(void) const{
	return this->event;
}

int					SFML::getHeight(void) const{
	return this->height;
}

int					SFML::getWidth(void) const{
	return this->width;
}

//FUNCTIONS

bool	SFML::pollEvent() {
		return (window.pollEvent(event));
}

bool	SFML::OnInit(int height, int width) {
	this->width = width;
	this->height = height;
	window.create(sf::VideoMode(width, height), "SFML WINDOW", sf::Style::None, settings);
	window.setActive(false);
	return true;
}

Keys	SFML::OnEvent() {
			
			if (event.type == sf::Event::KeyPressed)
				switch (event.key.code) {
					case sf::Event::Closed:
						window.close();
						break;
					
					case sf::Keyboard::Left:
					
						return (Keys::key_left);
						break;
					
					case sf::Keyboard::Right:
					
						return (Keys::key_right);
						break;
					
					case sf::Keyboard::Down:
					
						return (Keys::key_down);
						break;
					
					case sf::Keyboard::Up:
					
						return (Keys::key_up);
						break;
					
					case sf::Keyboard::Escape:
					
						return (Keys::quit);
						break;
					
					case sf::Keyboard::Num1:
					
						return (Keys::key_one);
						break;
					
					case sf::Keyboard::Num2:
					
						return (Keys::key_two);
						break;
					
					case sf::Keyboard::Num3:
					
						return (Keys::key_three);
						break;
					default:
						break;
				}
		return (Keys::nothing);
}

void    SFML::drawFood(int y, int x) {

	sf::RectangleShape food(sf::Vector2f(10, 10));
	food.setOrigin(sf::Vector2f( - x, - y));
	food.setFillColor(sf::Color(0, 0, 255));
	window.draw(food);
}

void    SFML::Delay(int delay) {
	sf::Time time = sf::milliseconds(delay);
	sf::sleep(time);
}

void    SFML::drawSnake(std::vector<snakepart> &snake) {
	for (size_t i = 1; i < snake.size(); i++) {
		if (i % 2) {
			int xevenpos = snake[i].x * 10;
			int yevenpos = snake[i].y * 10;
			sf::RectangleShape snakeBodyeven(sf::Vector2f(10, 10));
			snakeBodyeven.setOrigin(sf::Vector2f( - xevenpos, - yevenpos));
			snakeBodyeven.setFillColor(sf::Color(255, 150, 0));
			window.draw(snakeBodyeven);
		}
		else {
			int xpos = snake[i].x * 10;
			int ypos = snake[i].y * 10;
			sf::RectangleShape snakeBody(sf::Vector2f(10, 10));
			snakeBody.setOrigin(sf::Vector2f( - xpos, - ypos));
			snakeBody.setFillColor(sf::Color(85, 211, 228));
			window.draw(snakeBody);
		}
	}
	int xpos = snake[0].x * 10;
	int ypos = snake[0].y * 10;
	sf::RectangleShape snakeHead(sf::Vector2f(10, 10));
	snakeHead.setOrigin(sf::Vector2f( - xpos, - ypos));
	snakeHead.setFillColor(sf::Color(255, 0, 0));
	window.draw(snakeHead);
	window.display();
	drawBorder();
	
}

void	SFML::drawBorder() {
	window.clear(sf::Color::Green);
	sf::RectangleShape rectangle(sf::Vector2f(10, this->height - 10)); //left
	sf::RectangleShape rectangleTop(sf::Vector2f(this->width, 10)); //top
	sf::RectangleShape rectangleRight(sf::Vector2f(10, this->height - 20)); //right
	rectangleRight.setOrigin(sf::Vector2f( - this->width + 10, - 10));
	sf::RectangleShape rectangleBot(sf::Vector2f(this->width, 10)); //bottom
	rectangleBot.setOrigin(sf::Vector2f( 0, - this->height + 10));

	rectangle.setFillColor(sf::Color(255, 0, 0));
	rectangleRight.setFillColor(sf::Color(255, 0, 0));
	rectangleBot.setFillColor(sf::Color(255, 0, 0));
	rectangleTop.setFillColor(sf::Color(255, 0, 0));

	window.draw(rectangle);
	window.draw(rectangleTop);
	window.draw(rectangleRight);
	window.draw(rectangleBot);
}

void	SFML::OnCleanup() {
	window.close();
}

//DLHANDLE

SFML	*start() {
	std::cout << "create\n";
	return new SFML();
}

void	deletelib(SFML *sfml) {
	delete sfml;
}