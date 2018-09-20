#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../libsdld/include/SDL2/SDL.h"
#include "../../includes/IFunctions.hpp"

class sdlClass :public IsdlClass {

public:
	sdlClass();
	sdlClass(sdlClass const &src);
	sdlClass	&operator=(sdlClass const &rhs);
	virtual ~sdlClass();

	//GETTERS
	int  	 		getWidth(void) const;
	int	    		getHeight(void) const;
	bool            getRunning(void) const;
	SDL_Window      *getSurf_Display(void) const;
    SDL_Renderer	*getRenderer(void) const;
    SDL_Event 		getEvent(void) const;

	//IFUNCTIONS
	virtual bool    OnInit(int height, int width);
	virtual	Keys	OnEvent();
	virtual void	OnCleanup();
	virtual void	drawBorder();
	virtual void	drawFood(int y, int x);
	virtual void	drawSnake(std::vector<snakepart> &snake);
	virtual	bool	pollEvent();
	virtual void	Delay(int delay);

private: 
	bool			Running;
	SDL_Window		*Surf_Display;
	SDL_Renderer	*renderer;
	SDL_Event 		Event;
	int 			height;
	int 			width;
};

extern "C" {
	sdlClass		*start(void);
	void			deletelib(sdlClass *sdl);
}

#endif