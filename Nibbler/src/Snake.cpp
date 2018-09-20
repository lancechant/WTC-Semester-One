#include "../includes/Snake.hpp"

snakepart::snakepart(int col, int row) {

	x = col;
	y = row;
}

snakepart::snakepart() {

	x = 0;
	y = 0;
}

snakepart::snakepart(snakepart const &obj) {
	x = obj.x;
	y = obj.y;
}

snakepart & snakepart::operator=( snakepart const & rhs ) { 
	x = rhs.x;
	y = rhs.y;
	return *this; 
}

snakepart::~snakepart() {

}

SnakeClass::SnakeClass() {
	Running = true;
}

SnakeClass::~SnakeClass() {

}

SnakeClass::SnakeClass(SnakeClass const &obj) {
	static_cast<void>(obj); 
}

SnakeClass & SnakeClass::operator=( SnakeClass const & rhs ) { 
	static_cast<void>(rhs); 
	return *this; 
}

void    SnakeClass::putfood() {
	
	while(1) {
		int tmpx = rand()% maxH + 1;
		int tmpy = rand()% maxW + 1;

		for(size_t i = 0; i < snake.size(); i++)
		   if (snake[i].x == tmpx && snake[i].y==tmpy)
				continue;
		if (tmpx >=maxW / 10 - 2 || tmpy >=maxH / 10 - 3)
			continue;
		food.x = tmpx;
		food.y = tmpy;
		break;
	
	}
}

bool    SnakeClass::collision() {

	if (snake[0].x == 0 || snake[0].x == maxW / 10 - 1 || snake[0].y == 0 || snake[0].y == maxH / 10 - 1)
		return true;
	for (size_t i = 2; i < snake.size(); i++)
		if (snake[0].x == snake[i].x && snake[i].y == snake[0].y)
			return true;
	if (snake[0].x == food.x && snake[0].y == food.y) {

		get = true;
		putfood();
		points += 10;
		std::cout << "Your score is -> " << points <<std::endl;

		if ((points%50) == 0 && delay > 0) {
			std::cout << "Level " << ++i << std::endl;
			if (delay >= 30)
				delay -= 10;
		}
		
	}else 
		get = false;
	return false;
}

void    SnakeClass::movesnake() {

	if (!get) {
		snake.resize(snake.size());
		 this->Glibs->drawSnake(snake);
		
		snake.pop_back();
	}
	if (direction == 'l')
		snake.insert(snake.begin(), snakepart(snake[0]. x - 1, snake[0].y)); //mabye optimise
	else if (direction == 'r')
		snake.insert(snake.begin(), snakepart(snake[0]. x + 1, snake[0].y));
	else if (direction == 'u')
		snake.insert(snake.begin(), snakepart(snake[0]. x, snake[0].y - 1));
	else if (direction == 'd')
		snake.insert(snake.begin(), snakepart(snake[0]. x, snake[0].y + 1));
	this->Glibs->drawFood(food.y * 10, food.x * 10);
	this->Glibs->drawSnake(snake);
}

void    SnakeClass::OnEvent(Keys key, bool sdl_open, bool sfml_open, bool ogl_open) {
	try {
		void	(*del)(IsdlClass *);
		switch(key)
					{
						case Keys::key_left:
								if(direction!='r')
										direction='l';
								break;
						case Keys::key_up:
								if(direction !='d')
										direction='u';
								break;
						case Keys::key_down:
								if(direction!='u')
										direction='d';
								break;
						case Keys::key_right:
								if(direction!='l')
										direction='r';
								break;
						case Keys::quit:
								direction = 'q';
								break;
						case Keys::key_one:
								if (!sdl_open) {
									this->sdl_open = 1;
									del = (void (*)(IsdlClass *)) dlsym(dl_handle, "deletelib");
									dlclose(dl_handle);
									this->Glibs->OnCleanup();
									this->sfml_open = 0;
									this->ogl_open = 0;
									dl_handle = dlopen("sdl/libsdl.dylib", RTLD_LAZY);
									func = (IsdlClass * (*)(void)) dlsym(dl_handle, "start");
									if (!func)
										dlerror_wrapper();
									this->Glibs = NULL;
									this->Glibs = func();
									if (this->Glibs == NULL)
										throw Errors::CannotOpenLib();
									if (this->Glibs->OnInit(maxH, maxW) == false)
										Running = false;
								}
								break;
						case Keys::key_two:
								if (!sfml_open) {
									this->sfml_open = 1;
									del = (void (*)(IsdlClass *)) dlsym(dl_handle, "deletelib");
									dlclose(dl_handle);
									this->Glibs->OnCleanup();
									this->sdl_open = 0;
									this->ogl_open = 0;
									dl_handle = dlopen("sfml/libSFML.dylib", RTLD_LAZY);
									func = (IsdlClass * (*)(void)) dlsym(dl_handle, "start");
									if (!func)
										dlerror_wrapper();
									this->Glibs = NULL;
									this->Glibs = func();
									if (this->Glibs == NULL)
										throw Errors::CannotOpenLib();
									if (this->Glibs->OnInit(maxH, maxW) == false)
										Running = false;
								}
								break;
						case Keys::key_three:
								if (!ogl_open) {
									this->ogl_open = 1;
									del = (void (*)(IsdlClass *)) dlsym(dl_handle, "deletelib");
									dlclose(dl_handle);
									this->Glibs->OnCleanup();
									this->sdl_open = 0;
									this->sfml_open = 0;
									dl_handle = dlopen("opengl/libopengl.dylib", RTLD_LAZY);
									func = (IsdlClass * (*)(void)) dlsym(dl_handle, "start");
									if (!func)
										dlerror_wrapper();
									this->Glibs = NULL;
									this->Glibs = func();
									if (this->Glibs == NULL)
										throw Errors::CannotOpenLib();
									if (this->Glibs->OnInit(maxH, maxW) == false)
										Running = false;
								}
							break;
						default:
							break;
					if (key == Keys::nothing)
						break;
					}
	}
	catch (std::exception & e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void    SnakeClass::dlerror_wrapper(void) {
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int    SnakeClass::start(int height, int width) {
	try {
		dl_handle = dlopen("sdl/libsdl.dylib", RTLD_LAZY);
		func = (IsdlClass * (*)(void)) dlsym(dl_handle, "start");
		if (!func)
			dlerror_wrapper();
		this->Glibs = NULL;
		this->Glibs = func();
		if (this->Glibs == NULL)
			throw Errors::CannotOpenLib();
		maxH = height;
		maxW = width;
		if (this->Glibs->OnInit(maxH, maxW) == false)
		Running = false;
		for (int i = 0; i < 5; i++)
			snake.push_back(snakepart(40 + i, 10));
		points = 0;
		delay = 110;
		get = false;
		direction = 'l'; //snake moves to the left
		srand(time(NULL));
		this->sdl_open = 1;
		putfood();
			while(Running)
			{
				if(collision())
				{
					std::cout << "game over" << std::endl;
					break;
				}
				if(this->Glibs->pollEvent())
					OnEvent(this->Glibs->OnEvent(), sdl_open, sfml_open, ogl_open);
				movesnake();
				if(direction=='q')
						break;
				this->Glibs->Delay(delay);
			}
	}
	catch (std::exception & e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
   return (0);
}