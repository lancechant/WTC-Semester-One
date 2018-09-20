#include "../includes/Functions.hpp"
#include <iostream>

openglClass::openglClass() {
    this->Surf_Display = NULL;
    this->Running = true;
	this->key = Keys::nothing;
}

openglClass::openglClass(openglClass const &src){
    *this = src;
}

openglClass	&openglClass::operator=(openglClass const &rhs){
	if (this != &rhs){
		this->key = rhs.getKey();
		this->width = rhs.getWidth();
		this->height = rhs.getHeight();
		this->Running = rhs.getRunning();
		this->Surf_Display = rhs.getSurf_Display();
	}

	return *this;
}

openglClass::~openglClass() {
    OnCleanup();
}

//GETTERS

Keys            openglClass::getKey(void) const{
	return this->key;
}

float   		openglClass::getWidth(void) const{
	return this->width;
}

float    		openglClass::getHeight(void) const{
	return this->height;
}

bool            openglClass::getRunning(void) const{
	return this->Running;
}

GLFWwindow*		openglClass::getSurf_Display(void) const{
	return this->Surf_Display;
}

//IFUNCTIONS

bool	openglClass::pollEvent() {
    glfwPollEvents();
    this->key = Keys::nothing;

    int esc = glfwGetKey(this->Surf_Display, GLFW_KEY_ESCAPE);

	int up = glfwGetKey(this->Surf_Display, GLFW_KEY_UP);
	int left = glfwGetKey(this->Surf_Display, GLFW_KEY_LEFT);
	int down = glfwGetKey(this->Surf_Display, GLFW_KEY_DOWN);
	int right = glfwGetKey(this->Surf_Display, GLFW_KEY_RIGHT);

	int n1 = glfwGetKey(this->Surf_Display, GLFW_KEY_1);
	int n2 = glfwGetKey(this->Surf_Display, GLFW_KEY_2);
	int n3 = glfwGetKey(this->Surf_Display, GLFW_KEY_3);

	if (esc == GLFW_PRESS)
		this->key = Keys::quit;
	else if (up == GLFW_PRESS)
		this->key = Keys::key_up;
	else if (left == GLFW_PRESS)
		this->key = Keys::key_left;
	else if (down == GLFW_PRESS)
		this->key = Keys::key_down;
	else if (right == GLFW_PRESS)
		this->key = Keys::key_right;
	else if (n1 == GLFW_PRESS)
		this->key = Keys::key_one;
	else if (n2 == GLFW_PRESS)
		this->key = Keys::key_two;
	else if (n3 == GLFW_PRESS)
		this->key = Keys::key_three;

	return (this->key != Keys::nothing);
}

bool	openglClass::OnInit(int height, int width) {
	this->width = width;
	this->height = height;

	if (!glfwInit())
		return false;

	glfwSetErrorCallback(error_callback);

	this->Surf_Display = glfwCreateWindow(this->width, this->height, "Snake OPENGL", glfwGetPrimaryMonitor(), NULL);

	if (!this->Surf_Display) {
		return false;
	}

    glfwMakeContextCurrent(this->Surf_Display);

    glfwSetInputMode(this->Surf_Display, GLFW_STICKY_KEYS, 1);

    glViewport(0, 0, this->width, this->height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, this->height, 0, this->width, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	return true;
}

Keys	openglClass::OnEvent(){
	return (this->key);
}

void    openglClass::drawFood(int y, int x) {
	float fx = x;
	float fy = invertY(y);

	float square[] = {
			fx, fy, 0.0, //top left
			fx + 10, fy, 0.0, //top right
			fx + 10, fy - 10, 0.0, //bot right
			fx, fy - 10, 0.0 //bot left
	};

	glEnableClientState(GL_VERTEX_ARRAY);

	purple();
	glVertexPointer(3, GL_FLOAT, 0, square);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);

}

void    openglClass::drawSnake(std::vector<snakepart> &snake) {
	float				sx, sy, hx, hy;


	for (unsigned long i = 1; i < snake.size(); i++){
		if (i % 2) {
			sx = snake[i].x * 10;
			sy = snake[i].y * 10;

			float square[4][3] = {
					{sx, invertY(sy), 0.0}, //top left
					{sx + 10, invertY(sy), 0.0}, //top right
					{sx + 10, invertY(sy) - 10, 0.0}, //bot right
					{sx, invertY(sy) - 10, 0.0} //bot left
			};

			glEnableClientState(GL_VERTEX_ARRAY);

			green();
			glVertexPointer(3, GL_FLOAT, 0, square);
			glDrawArrays(GL_QUADS, 0, 4);

			glDisableClientState(GL_VERTEX_ARRAY);
		} else {
			sx = snake[i].x * 10;
			sy = snake[i].y * 10;

			float square[4][3] = {
					{sx, invertY(sy), 0.0}, //top left
					{sx + 10, invertY(sy), 0.0}, //top right
					{sx + 10, invertY(sy) - 10, 0.0}, //bot right
					{sx, invertY(sy) - 10, 0.0} //bot left
			};

			glEnableClientState(GL_VERTEX_ARRAY);

			blue();
			glVertexPointer(3, GL_FLOAT, 0, square);
			glDrawArrays(GL_QUADS, 0, 4);

			glDisableClientState(GL_VERTEX_ARRAY);
		}

	}
		hx = snake[0].x * 10;
		hy = snake[0].y * 10;

		float head[4][3] = {
                {hx, invertY(hy), 0.0}, //top left
                {hx + 10, invertY(hy), 0.0}, //top right
                {hx + 10, invertY(hy) - 10, 0.0}, //bot right
                {hx, invertY(hy) - 10, 0.0} //bot left
		};

		glEnableClientState(GL_VERTEX_ARRAY);

		red();
		glVertexPointer(3, GL_FLOAT, 0, head);
		glDrawArrays(GL_QUADS, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);

	drawBorder();
}

void	openglClass::drawBorder() {
	float width = this->width;
	float height = this->height;

	float topWall[] = {
			0.0, height, 0.0, //top left
			width, height, 0.0, //top right
			width, height - 10, 0.0, //bot right
			0.0, height - 10, 0.0 //bot left
	};

	float rightWall[] = {
			width - 10, height, 0.0, //top left
			width, height, 0.0, //top right
			width, 0.0, 0.0, //bot right
			width - 10, 0.0, 0.0 //bot left
	};

	float btmWall[] = {
			0.0, 10.0, 0.0, //top left
			width, 10.0, 0.0, //top right
			width, 0.0, 0.0, //bot right
			0.0, 0.0, 0.0 //bot left
	};

	float leftWall[] = {
			0.0, height, 0.0, //top left
			10.0, height, 0.0, //top right
			10.0, 0.0, 0.0, //bot right
			0.0, 0.0, 0.0 //bot left
	};


	glEnableClientState(GL_VERTEX_ARRAY);

	grey();
	glVertexPointer(3, GL_FLOAT, 0, topWall);
	glDrawArrays(GL_QUADS, 0, 4);
	glVertexPointer(3, GL_FLOAT, 0, rightWall);
	glDrawArrays(GL_QUADS, 0, 4);
	glVertexPointer(3, GL_FLOAT, 0, btmWall);
	glDrawArrays(GL_QUADS, 0, 4);
	glVertexPointer(3, GL_FLOAT, 0, leftWall);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);

	glfwSwapBuffers(this->Surf_Display);

	//clear background screen to black
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	//clear information from last draw
	glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

}

void	openglClass::OnCleanup() {
	glfwDestroyWindow(this->Surf_Display);
	glfwTerminate();
}

void	openglClass::Delay(int delay) {
   	usleep(delay * 1000);
}


//FUNCTIONS

void    openglClass::error_callback(int error, const char* description) {
    fputs(description, stderr);
}

float   openglClass::invertY(int y){
    return (this->height - y);
}

//COLORS

void    openglClass::purple(){
	glColor3f(0.5f, 0.0f, 0.5f);
}

void    openglClass::red(){
	glColor3f(0.5f, 0.0f, 0.0f);
}

void    openglClass::green(){
	glColor3f(0.0f, 0.5f, 0.0f);
}

void    openglClass::blue(){
	glColor3f(0.0f, 0.0f, 0.5f);
}

void    openglClass::white(){
	glColor3f(1.0f, 1.0f, 1.0f);
}

void    openglClass::grey(){
	glColor3f(0.5f, 0.5f, 0.5f);
}

void    openglClass::black(){
	glColor3f(0.0f, 0.0f, 0.0f);
}


//DLHANDLE

openglClass	*start() {
	return new openglClass();
}

void	deletelib(openglClass *ogl) {
	delete ogl;
}

