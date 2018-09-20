#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../_deps/sfml_downloaded-src/include/SFML/Graphics.hpp"
#include "../../includes/IFunctions.hpp"

class SFML :public IsdlClass {

public:
	SFML();
	SFML(SFML const &src);
	SFML &operator=(SFML const &rhs);
	virtual ~SFML();

	//GETTERS
	sf::ContextSettings getSettings(void) const;
	sf::Event 			getEvent(void) const;
	int					getHeight(void) const;
	int					getWidth(void) const;

	//FUNCTIONS
	virtual bool   		OnInit(int height, int width);
	virtual	Keys		OnEvent();
	virtual void		OnCleanup();
	virtual	bool		pollEvent();
	virtual	void		drawBorder();
	virtual void    	drawFood(int y, int x);
	virtual void		Delay(int delay);
	virtual void		drawSnake(std::vector<snakepart> &snake);
	sf::RenderWindow	window;

private:
	sf::ContextSettings settings;
	sf::Event 			event;
	int					height;
	int 				width;

};

extern "C" {
	SFML				*start(void);
	void				deletelib(SFML *sfml);
}

#endif