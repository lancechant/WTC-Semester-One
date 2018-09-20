#ifndef ERRORS_HPP
#define ERRORS_HPP

# include <exception>

struct Errors {
	struct DivideByZero : public std::exception { char const * what( void ) const throw(); };
	struct ModByZero : public std::exception { char const * what( void ) const throw(); };
	struct PopOnEmpty   : public std::exception { char const * what( void ) const throw(); };
	struct InvalidValue : public std::exception { char const * what( void ) const throw(); };
	struct PrintNotInt8 : public std::exception { char const * what( void ) const throw(); };
	struct StackEmpty : public std::exception { char const * what( void ) const throw(); };
	struct UnknownInstruction : public std::exception { char const * what( void ) const throw(); };
	struct UnknownInstructions : public std::exception { char const * what( void ) const throw(); };
	struct UnknownOperation : public std::exception { char const * what( void ) const throw(); };
	struct NotEnoughValues : public std::exception { char const * what( void ) const throw(); };
	struct AssertNotTrue : public std::exception { char const * what( void ) const throw(); };
	struct Overflow : public std::exception { char const * what( void ) const throw(); };
	struct Underflow : public std::exception { char const * what( void ) const throw(); };
	struct MissingExit : public std::exception { char const * what( void ) const throw(); };
};

#endif