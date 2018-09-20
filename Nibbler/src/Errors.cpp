#include "../includes/Errors.hpp"

char const * Errors::CannotOpenLib::what( void ) const throw() { return "Something happened while opening"; }
char const * Errors::WidthGreater::what( void ) const throw() { return "Please enter a width greater than 500"; }
char const * Errors::GreaterThanLimit::what( void )   const throw() { return "You have entered a height or width greater than our limit which is 1000"; }
char const * Errors::HeightGreater::what( void ) const throw() { return "Please enter a height greater than 500"; }
char const * Errors::SameSameButDifferent::what( void ) const throw() { return "Please make sure height and width are both the same value"; }
