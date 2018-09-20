
#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
#include <climits>
#include <iostream>
class Conversion {

public:
		class NonDisplayable : public std::exception
		{
		public:

			NonDisplayable(void);
			NonDisplayable(NonDisplayable const &src);
			virtual ~NonDisplayable(void) throw();

			NonDisplayable          &operator= (const NonDisplayable &rhs);

			const char              *what(void) const throw();
		};
		class Impossible : public std::exception
		{
		public:

			Impossible(void);
			Impossible(Impossible const &src);
			virtual ~Impossible(void) throw();

			Impossible              &operator= (const Impossible &rhs);

			const char              *what(void) const throw();
		};
	Conversion(void);
	~Conversion(void);
	Conversion(const Conversion &src);
	Conversion &operator= (const Conversion &value);
	char    convertToChar(double d);
	int     convertToInt(double d);
	float   convertToFloat(double d);
	double	convertToDouble(double d);

};

#endif