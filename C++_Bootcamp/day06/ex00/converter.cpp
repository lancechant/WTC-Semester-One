#include "converter.hpp"

Conversion::Conversion(void)
{
	return ;
}

Conversion::Conversion(const Conversion &src)
{
	*this = src;
	return ;
}

Conversion::~Conversion(void)
{
	return ;
}

Conversion &Conversion::operator= (const Conversion &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

char    Conversion::convertToChar(double d)
{
	char    c;

	if (std::isnan(d) == true)
	{
		throw (Conversion::Impossible());
	}
	c = static_cast<char>(d);
	if (std::isprint(c) == false)
	{
		throw (Conversion::NonDisplayable());
	}
	return (c);
}

int     Conversion::convertToInt(double d)
{
	if (std::isnan(d) == true || std::isinf(d) == true)
	{
		throw (Conversion::Impossible());
	}
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
	{
		throw (Conversion::Impossible());
	}
	return (static_cast<int>(d));
}

float   Conversion::convertToFloat(double d)
{
	return (static_cast<float>(d));
}

double	Conversion::convertToDouble(double d)
{
	 return (static_cast<double>(d));
}

Conversion::NonDisplayable::NonDisplayable(void)
{
	return ;
}

Conversion::
NonDisplayable::NonDisplayable(Conversion::NonDisplayable const &src)
{
	*this = src;
	return ;
}

Conversion::
NonDisplayable::~NonDisplayable(void) throw()
{
	return ;
}

Conversion::NonDisplayable
&Conversion::NonDisplayable::\
operator= (const Conversion::NonDisplayable &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

const char
*Conversion::NonDisplayable::what(void) const throw()
{
	return("Non displayable");
}

Conversion::
Impossible::Impossible(void)
{
	return ;
}

Conversion::
Impossible::Impossible(Conversion::Impossible const &src)
{
	*this = src;
	return ;
}

Conversion::Impossible::~Impossible(void) throw()
{
	return ;
}

Conversion::Impossible
&Conversion::Impossible::
operator= (const Conversion::Impossible &rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

const char
*Conversion::Impossible::what(void) const throw()
{
	return("impossible");
}

void	checkChar(Conversion conversion, double value)
{
    try
    {
        std::cout << "char   : ";
        std::cout << conversion.convertToChar(value) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void	checkInt(Conversion conversion, double value)
{
    try
    {
        std::cout << "int    : ";
        std::cout << conversion.convertToInt(value) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void	checkDouble(Conversion conversion, double value, int precision)
{
    try
    {
        std::cout << "double : ";
        std::cout << std::setprecision(precision) \
        << std::fixed << conversion.convertToDouble(value) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void	checkFloat(Conversion conversion, double value, int precision)
{
    try
    {
        std::cout << "float  : ";
        std::cout << std::setprecision(precision) \
        << std::fixed << conversion.convertToFloat(value) << "f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}