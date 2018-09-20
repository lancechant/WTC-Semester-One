#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <vector>
#include <unistd.h>

#include "IFunctions.hpp"
#include "Errors.hpp"
#include <dlfcn.h>

class SnakeClass{

public:
    SnakeClass();
    ~SnakeClass();
    SnakeClass(const SnakeClass &obj);
    SnakeClass &operator = (const SnakeClass &rhs);
    int    start(int height, int width);
    int     points, delay, maxW, maxH;
    char    direction, body, border, foodItem;
    bool    get;
    snakepart food;
    std::vector<snakepart> snake;
    

private:
    void    dlerror_wrapper();
    void    putfood();
    bool    collision();
    void    movesnake();
    IsdlClass   *Glibs;
    void    *dl_handle;
    bool    Running;
    void    OnEvent(Keys key, bool sdl_open, bool sfml_open, bool ogl_open);
    IsdlClass * (*func)(void);
    int i = 0;
    bool sdl_open;
	bool sfml_open;
	bool ogl_open;
};

#endif