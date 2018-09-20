#include <iostream>
#include "Snake.cpp"

int main(int argc, char *argv[]) {
    try {
        SnakeClass s;
        if (argc == 3)
            if (atoi(argv[1]) == atoi(argv[2])) {
                if (atoi(argv[1]) > MAX_HEIGHT || atoi(argv[2]) > MAX_WIDTH)
                    throw Errors::GreaterThanLimit();
                else
                    if (atoi(argv[1]) >= MIN_HEIGHT)
                        if (atoi(argv[2]) >= MIN_WIDTH)
                            s.start(atoi(argv[1]), atoi(argv[2]));
                        else 
                            throw Errors::WidthGreater();
                    else 
                        throw Errors::HeightGreater();
            }
            else 
                throw Errors::SameSameButDifferent();
        else
            std::cerr << "Usage: " << argv[0] << " height width\n";
    }
    catch (std::exception & e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
    return 0;
}