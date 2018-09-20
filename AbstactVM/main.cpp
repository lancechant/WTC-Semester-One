#include "Factory.cpp"
#include "Calculator.cpp"
#include <sstream>
#include <fstream>

void readStdIn()
{
	std::string i;
	Calculator calculator;
	try
	{

		while (std::cin)
		{
			std::getline(std::cin, i);

			if (i.substr(0, 5) == "push ")
			{
				calculator.Push(i.substr(5, std::string::npos)); // until the end of the string.
			}
			else if (i == "pop")
				calculator.pop();
			else if (i == "dump")
				calculator.dump();
			else if (i == "print")
				calculator.print();
			else if (i == "add" || i == "sub" || i == "mul" || i == "div" || i == "mod")
				calculator.Start(i);
			else if (i.substr(0, 7) == "assert ")
				calculator.Assert(i.substr(7, std::string::npos));
			else if (i.substr(0, 1) == ";" || i.substr(0, 2) == "; ")
				calculator.Start(i);
			else if (i == "pop")
				calculator.pop();
			else if (i == "exit")
				break;
			else
			{
				throw Errors::UnknownInstruction();
				// break;
			}
			if (i.find(";;") != std::string::npos)
				break;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

void readFile(char *file)
{
	Calculator calculator;
	std::string line;
	std::ifstream inFile(file);

	if (inFile.is_open())
	{
		try
		{
			while (getline(inFile, line))
			{
				if (line.substr(0, 5) == "push ")
				{
					calculator.Push(line.substr(5, std::string::npos)); // until the end of the string.
				}
				else if (line == "dump")
					calculator.dump();
				else if (line == "print")
					calculator.print();
				else if (line == "add" || line == "sub" || line == "mul" || line == "div" || line == "mod")
					calculator.Start(line);
				else if (line.substr(0, 7) == "assert ")
					calculator.Assert(line.substr(7, std::string::npos));
				else if (line.substr(0, 1) == ";" || line.substr(0, 2) == "; ")
					calculator.Start(line);
				else if (line == "pop")
					calculator.pop();
				
				else if (line == "exit")
					break;
				
				else 
					throw Errors::UnknownInstructions();
			}
			if (line != "exit")
					throw Errors::MissingExit();
			inFile.close();
		}
		catch (std::exception &e)
		{
			std::cout << "ERROR: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "cannot open file" << std::endl;
}

int main(int ac, char **av)
{
	if (ac == 1)
		readStdIn();
	else if (ac == 2)
	{
		readFile(av[1]);
	}
	else
		std::cout << "INCORRECT FORMAT" << std::endl;
}