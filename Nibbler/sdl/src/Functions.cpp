#include "../includes/Functions.hpp"
#include <iostream>

sdlClass::sdlClass() {
    Surf_Display = NULL;
	Running = true;
}

sdlClass::sdlClass(sdlClass const &src){
	*this = src;
}

sdlClass	&sdlClass::operator=(sdlClass const &rhs){
	if (this != &rhs){
		this->width = rhs.getWidth();
		this->height = rhs.getHeight();
		this->Running = rhs.getRunning();
		this->Surf_Display = rhs.getSurf_Display();
        this->renderer = rhs.getRenderer();
        this->Event = rhs.getEvent();
	}

	return *this;
}

sdlClass::~sdlClass() {
	OnCleanup();
}

//GETTERS

int		   		sdlClass::getWidth(void) const{
	return this->width;
}

int	    		sdlClass::getHeight(void) const{
	return this->height;
}

bool            sdlClass::getRunning(void) const{
	return this->Running;
}

SDL_Window		*sdlClass::getSurf_Display(void) const{
	return this->Surf_Display;
}

SDL_Renderer	*sdlClass::getRenderer(void) const{
    return this->renderer;
}
SDL_Event 		sdlClass::getEvent(void) const{
    return this->Event;
}


//IFUNCTIONS

bool	sdlClass::pollEvent() {
		return (SDL_PollEvent(&Event));
}

bool	sdlClass::OnInit(int height, int width) {
	this->height = height;
	this->width = width;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	if ((Surf_Display = SDL_CreateWindow("SDL WINDOW",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          width, height,
                          SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL))== NULL) {
		return false;
	}
	renderer = SDL_CreateRenderer(Surf_Display, -1, 0);
	return true;
}

Keys	sdlClass::OnEvent() {

		if (Event.type == SDL_KEYDOWN) {
			switch (this->Event.key.keysym.sym) {
				case SDLK_ESCAPE:
					return (Keys::quit);
					break;
				
				case SDLK_UP:
					return (Keys::key_up);
					break;

				case SDLK_LEFT:
					return (Keys::key_left);
					break;

				case SDLK_DOWN:
					return (Keys::key_down);
					break;

				case SDLK_RIGHT:
					return (Keys::key_right);
					break;
				case SDLK_1:
					return (Keys::key_one);
					break;
				case SDLK_2:
					return (Keys::key_two);
					break;
				case SDLK_3:
					return (Keys::key_three);
					break;
				default:
					break;
			}
		}
		else if (this->Event.type == SDL_QUIT)
			return (Keys::quit);
		
		return (Keys::nothing);
}
void	sdlClass::drawBorder() {

	
	SDL_Rect t;
		t.x = 0;
		t.y = 0;
		t.w = this->width; //change to input height
		t.h = 10;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect( renderer, &t );

	SDL_Rect l;
		l.x = 0;
		l.y = 0;
		l.w = 10;
		l.h = this->height - 10;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect( renderer, &l );

	SDL_Rect b;
		b.x = 0;
		b.y = this->height - 10;
		b.w = this->width;
		b.h = 10;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect( renderer, &b );

	SDL_Rect r;
		r.x = this->width - 10;
		r.y = 0;
		r.w = 10;
		r.h = this->height - 10;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect( renderer, &r );
}

void	sdlClass::drawFood(int y, int x) {
	SDL_Rect f;
		f.x = x;
		f.y = y;
		f.w = 10;
		f.h = 10;
	SDL_SetRenderDrawColor(renderer, 0, 255, 150, 255);
	SDL_RenderFillRect( renderer, &f );
}

void	sdlClass::drawSnake(std::vector<snakepart> &snake) {

	for (size_t i = 0; i < snake.size(); i++) {
		if (i % 2) {
			SDL_Rect even;
			even.x = snake[i].x * 10;
			even.y = snake[i].y * 10;
			even.w = 10;
			even.h = 10;
		SDL_SetRenderDrawColor(renderer, 85, 211, 228, 255);
		SDL_RenderFillRect( renderer, &even );
		}
		else {
		SDL_Rect s;
			s.x = snake[i].x * 10;
			s.y = snake[i].y * 10;
			s.w = 10;
			s.h = 10;
		SDL_SetRenderDrawColor(renderer, 0, 150, 0, 255);
		SDL_RenderFillRect( renderer, &s );
		}
		
	}
		SDL_Rect h;
			h.x = snake[0].x * 10;
			h.y = snake[0].y * 10;
			h.w = 10;
			h.h = 10;
		SDL_SetRenderDrawColor(renderer, 255, 0, 50, 255);
		SDL_RenderFillRect( renderer, &h );
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		
	SDL_RenderClear(renderer);
	drawBorder();
}

void	sdlClass::OnCleanup() {
	SDL_Quit();
}

void	sdlClass::Delay(int delay) {
	SDL_Delay(delay);
}

//DLHANDLE

sdlClass	*start() {
	return new sdlClass();
}

void	deletelib(sdlClass *sdl) {
	delete sdl;
}
