#ifndef TEMP_OPERAND_HPP
#define TEMP_OPERAND_HPP

#include "IOperand.hpp"
# include <limits>

template <class T> class Operand : public IOperand {
public:
    Operand();
    Operand(std::string str);
    Operand( T value );
    ~Operand();
    Operand(Operand const & obj);
    Operand & operator=(Operand const & value);
    eOperandType getType( void ) const;
    IOperand const * operator+( IOperand const & rhs ) const;
    IOperand const * operator-( IOperand const & rhs ) const;
    IOperand const * operator*( IOperand const & rhs ) const;
    IOperand const * operator/( IOperand const & rhs ) const;
    IOperand const * operator%( IOperand const & rhs ) const;
    std::string const & toString( void ) const;
    int getPrecision() const;
protected:
    std::string _temp;
};

#include "temp_operand.cpp"
#endif