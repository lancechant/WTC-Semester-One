#ifndef ERRORS_HPP
#define ERRORS_HPP

# include <exception>

struct Errors {
	struct CannotOpenLib : public std::exception { char const * what( void ) const throw(); };
	struct WidthGreater : public std::exception { char const * what( void ) const throw(); };
	struct GreaterThanLimit   : public std::exception { char const * what( void ) const throw(); };
    struct HeightGreater   : public std::exception { char const * what( void ) const throw(); };
    struct SameSameButDifferent   : public std::exception { char const * what( void ) const throw(); };
};

#endif