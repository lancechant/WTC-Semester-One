#ifndef IFUNCTIONS_HPP
#define IFUNCTIONS_HPP

#include "SnakePart.hpp"
#include <vector>
#define MIN_HEIGHT 500
#define MIN_WIDTH 500
#define MAX_HEIGHT 1000
#define MAX_WIDTH 1000


enum class Keys {
	key_up,
	key_down,
	key_left,
	key_right,
	quit,
	key_one,
	key_two,
	key_three,
	nothing,
	};
class IsdlClass {

public:
	virtual bool    OnInit(int height, int width) = 0;
	virtual Keys	OnEvent() = 0;
	virtual void	OnCleanup() = 0;
	virtual	void	drawBorder() = 0;
	virtual	void	drawFood(int y, int x) = 0;
	virtual	void	drawSnake(std::vector<snakepart> &snake) = 0;
	virtual	bool	pollEvent() = 0;
	virtual	void	Delay(int delay) = 0;	
};

#endif