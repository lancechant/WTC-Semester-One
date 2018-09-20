#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "IOperand.hpp"


// #include <iostream>

class Factory {
public:
typedef IOperand const * (Factory::*IOPFP)(std::string const &) const;
    Factory();
    ~Factory();
    Factory(Factory const &obj);
    Factory & operator=( Factory const & rhs );

    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;
};

#endif