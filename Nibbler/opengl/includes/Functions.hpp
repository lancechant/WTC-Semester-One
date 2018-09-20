#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <GLFW/glfw3.h>
#include <unistd.h>
#include "../../includes/IFunctions.hpp"
#include "../../includes/SnakePart.hpp"


class openglClass : public IsdlClass {

public:
	openglClass();
	openglClass(openglClass const &src);
	openglClass	&operator=(openglClass const &rhs);
	virtual ~openglClass();

	//GETTERS
	Keys            getKey(void) const;
	float   		getWidth(void) const;
	float    		getHeight(void) const;
	bool            getRunning(void) const;
	GLFWwindow*		getSurf_Display(void) const;

	//IFUNCTIONS
	virtual bool    OnInit(int height, int width);
	virtual	Keys	OnEvent();
	virtual void	OnCleanup();
	virtual void	drawBorder();
	virtual void	drawFood(int y, int x);
	virtual void	drawSnake(std::vector<snakepart> &snake);
	virtual	bool	pollEvent();
	virtual void	Delay(int delay);

	//FUNCTIONS
	static void     error_callback(int error, const char* description);
	float           invertY(int y);

	//COLORS
	void            purple();
	void            red();
	void            green();
	void            blue();
	void            white();
	void            grey();
	void            black();

private:
	Keys            key;
	float   		width;
	float    		height;
	bool            Running;
	GLFWwindow*     Surf_Display;
};

extern "C" {
	openglClass	    *start(void);
	void		    deletelib(openglClass *ogl);
}

#endif
