#include "Calculator.hpp"


Calculator::Calculator()
{
}

Calculator::Calculator(Calculator const &obj)
{
	*this = obj;
}

Calculator::~Calculator()
{
	Stack<IOperand const *>::iterator i;
	Stack<IOperand const *>::iterator end = this->stack.end();
	for (i = this->stack.begin(); i != end; i++)
		delete *i;
}

Calculator &Calculator::operator=(Calculator const &value)
{
	static_cast<void>(value);
	return *this;
}

void Calculator::Start(std::string input)
{
	static const std::vector<std::string> obj = {"add", "sub", "mul", "div", "mod"};

	if (input.find(';') != std::string::npos)
		input.erase(input.find(';'), std::string::npos);
	if (input.find_first_not_of(" \t") != 0)
		input.erase(0, input.find_first_not_of(" \t"));
	while (input.size() != 0 && input.find_last_of(" \t") == input.size()-1)
		input.pop_back();
	if (std::find(obj.begin(), obj.end(), input) != obj.end())
	{
		if (this->stack.size() < 2)
			throw Errors::NotEnoughValues();
		IOperand const *rhs = this->stack.top();
		this->stack.pop();
		IOperand const *lhs = this->stack.top();
		this->stack.pop();
		IOperand const *created = nullptr;
		if (input == "add")
		{
			created = *lhs + *rhs;
			std::cout << "adding complete" << std::endl;
		}
		if (input == "sub")
		{
			created = *lhs - *rhs;
			std::cout << "subtraction complete" << std::endl;
		}
		if (input == "mul")
		{
			created = *lhs * *rhs;
			std::cout << "multiply complete" << std::endl;
		}
		if (input == "div")
		{
			created = *lhs / *rhs;
			std::cout << "diving complete" << std::endl;
		}
		if (input == "mod")
		{
			created = *lhs % *rhs;
			std::cout << "modding complete" << std::endl;
		}
		else if (input == "dump")
			this->dump();
		std::cout << created->toString() << std::endl;
		this->stack.push(created);
		delete lhs;
		delete rhs;
	}
}

void Calculator::Assert(std::string input)
{
	try {
		if (this->stack.size() == 0)
			throw Errors::NotEnoughValues();
		std::cout << "Asserting " << std::endl;
		static std::string names[] = {"int8", "int16", "int32", "float", "double"};
		if (input.size() < 4)
			throw Errors::InvalidValue();
		if (input.find('(') == std::string::npos)
			throw Errors::InvalidValue();
		if (input.back() != ')')
			throw Errors::InvalidValue();
		input.pop_back();
		unsigned int open_p = input.find('(');
		std::string type_string = input.substr(0, open_p);
		input.erase(input.begin(), input.begin() + open_p + 1);
		int j;
		type_string.erase(remove_if(type_string.begin(), type_string.end(), isspace), type_string.end());
		for (int i = Int8; i <= Double; i++)
		{
			if (type_string == names[i])
			{
				j = i;
			}
		}
		IOperand const *lhs = factory.createOperand(static_cast<eOperandType>(j), input);
		IOperand const *rhs = this->stack.top();
		if (lhs->getType() != rhs->getType() || lhs->toString() != rhs->toString())
			throw Errors::AssertNotTrue();
		delete lhs;
	}
	catch (std::exception & e) {
		std::cout << "ASSERT ERROR: " << e.what() << std::endl;
	}
}
void Calculator::dump()
{
	Stack<IOperand const *>::iterator i;
	Stack<IOperand const *>::iterator end = this->stack.end();
	std::cout << "Dumping" << std::endl;
	for (i = this->stack.begin(); i != end; i++)
		std::cout << (*i)->toString() << std::endl;
}

void Calculator::Push(std::string val)
{
	
	try 
	{
		static std::string names[] = {"int8", "int16", "int32", "float", "double"};
		if (val.size() < 4)
			throw Errors::InvalidValue();
		if (val.find('(') == std::string::npos)
			throw Errors::InvalidValue();
		val = val.substr(0, val.find(';'));
		if (val.back() != ')')
			throw Errors::InvalidValue();
		val.pop_back();
		unsigned int open_p = val.find('(');
		std::string type_string = val.substr(0, open_p);
		val.erase(val.begin(), val.begin() + open_p + 1);
		type_string.erase(remove_if(type_string.begin(), type_string.end(), isspace), type_string.end());
		for (int i = Int8; i <= Double; i++)
		{
			if (type_string == names[i])
			{
				 std::string::size_type sz;
				val.erase(std::remove_copy(val.begin(), val.end(), val.begin(), ','), val.end());
				long double values = std::stold(val, &sz);
				if (type_string == "int8") {
					if (values > INT8_MAX)
						throw Errors::Overflow();
					else if (values < INT8_MIN)
						throw Errors::Underflow();
				}
				if (type_string == "int16") {
					if (values > INT16_MAX)
						throw Errors::Overflow();
					else if (values < INT16_MIN)
						throw Errors::Underflow();
				}
				if (type_string == "int32") {
					if (values > INT32_MAX)
						throw Errors::Overflow();
					else if (values < INT32_MIN)
						throw Errors::Underflow();
				}
				if (type_string == "float") {
					if (values > FLT_MAX)
						throw Errors::Overflow();
					else if (values < 0 && values < FLT_MIN)
						throw Errors::Underflow();
				}
				if (type_string == "double") {
					if (values > DBL_MAX)
						throw Errors::Overflow();
					else if (values < 0 && values < DBL_MIN)
						throw Errors::Underflow();
				}
				this->stack.push(factory.createOperand(static_cast<eOperandType>(i), val));
				return;
			}
		}
		throw Errors::InvalidValue();
	}
	catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void Calculator::pop(void)
{
	if (this->stack.size() < 1)
		throw Errors::PopOnEmpty();
	else
	{
		delete this->stack.top();
		this->stack.pop();
	}
}

void Calculator::print() {
	if (this->stack.size() < 1) throw Errors::StackEmpty();
	IOperand const * top = this->stack.top();
	if (top->getType() != Int8) throw Errors::PrintNotInt8();
	char c = std::stoi(top->toString());
	if (c > 32 && c < 127) { std::cout << c << '\n'; }
	else { std::cout << "Non-displayable character (" << std::stoi(top->toString()) << ')' << std::endl; }
}