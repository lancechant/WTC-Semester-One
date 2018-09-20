#include "Errors.hpp"

char const * Errors::DivideByZero::what( void ) const throw() { return "Cannot divide by zero"; }
char const * Errors::ModByZero::what( void ) const throw() { return "Cannot Mod by zero"; }
char const * Errors::PopOnEmpty::what( void )   const throw() { return "Cannot pop empty stack"; }
char const * Errors::InvalidValue::what( void ) const throw() { return "Instructions contain invalid value"; }
char const * Errors::PrintNotInt8::what( void ) const throw() { return "Cannot print top value not 8-bit integer"; }
char const * Errors::StackEmpty::what( void ) const throw() { return "Stack empty"; }
char const * Errors::UnknownInstruction::what( void ) const throw() { return "UNKNOWN COMMAND"; }
char const * Errors::UnknownInstructions::what( void ) const throw() { return "UNKNOWN COMMANDS"; }
char const * Errors::UnknownOperation::what( void ) const throw() { return "Unknown operation"; }
char const * Errors::NotEnoughValues::what( void ) const throw() { return "Not enough values in stack for the operation"; }
char const * Errors::AssertNotTrue::what( void ) const throw() { return "Assert evaluated to false"; }
char const * Errors::Overflow::what( void ) const throw() { return "Overflow on a value"; }
char const * Errors::Underflow::what( void ) const throw() { return "Underflow on a value"; }
char const * Errors::MissingExit::what( void ) const throw() { return "No Exit Found ERROR"; }
