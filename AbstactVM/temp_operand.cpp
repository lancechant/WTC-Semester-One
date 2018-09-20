#include "temp_operand.hpp"
#include "Factory.hpp"
#include <iostream>

template<class T> Operand<T>::Operand() {
    this->_temp = std::to_string(static_cast<T>(0));
}

template<class T> Operand<T>::Operand(Operand<T> const &obj) {
    *this = obj;
}

template<class T> Operand<T>::~Operand() {

}

template<class T> Operand<T> & Operand<T>::operator=( Operand<T> const & rhs ) { 
    this->_temp = rhs._temp; 
    return *this; 
}

template<class T> Operand<T>::Operand(T value) {
    this->_temp = std::to_string(value);
}

template<class T> Operand<T>::Operand(std::string str) {
    this->_temp = std::to_string(static_cast<T>(stod(str)));
}

template<class T>void addition_check(T a, T b) {
    T sumOf = a + b;
    if ((a < 0) == (b < 0)) {
        if (a < 0 && sumOf > b)
            throw Errors::Underflow();
        else if (sumOf < b)
            throw Errors::Overflow();
    }
}

template<class T>void multiply_check(T a, T b) {
    // T max_limit = std::numeric_limits<T>::max();
    long double ans = a * b;
    // std::cout << std::stold(max_limit); << "max limit" << std::endl;
    // std::cout << a_check.to_string() << "a check" << std::endl;
    // std::cout << b_check.to_string() << "b check" << std::endl;
    if (ans > std::numeric_limits<T>::max() || ans < -std::numeric_limits<T>::max())
        throw Errors::Overflow();
    else if ((ans < std::numeric_limits<T>::min() &&  ans > 0) ||
             (ans > -std::numeric_limits<T>::min() &&  ans < 0))
        throw  Errors::Underflow();
}

template<class T> IOperand const * Operand<T>::operator+( IOperand const & value) const {
    std::string::size_type sz;
    long double temp_check = (stold(this->_temp, &sz));
    long double value_check = (stold(value.toString(), &sz));
    addition_check<T>(temp_check, value_check);
    Factory * factory = new Factory();
    eOperandType t;
    if (this->getPrecision() < value.getPrecision())
        t = value.getType();
    else
        t = this->getType();
    IOperand const * ret_val = factory->createOperand(t, std::to_string(temp_check + value_check));
    delete factory;
    return ret_val;
}

template<class T> IOperand const * Operand<T>::operator-( IOperand const & value ) const {
	std::string::size_type sz;
    long double temp_check = (stold(this->_temp, &sz));
    long double value_check = (stold(value.toString(), &sz));
	addition_check<T>(temp_check, value_check * -1);
	Factory * factory = new Factory();
    eOperandType t;
    if (this->getPrecision() < value.getPrecision())
        t = value.getType();
    else
        t = this->getType();
	IOperand const * ret_val = factory->createOperand(t, std::to_string(temp_check - value_check));
	delete factory;
	return ret_val;
}

template<class T> IOperand const * Operand<T>::operator*( IOperand const & value ) const {
	std::string::size_type sz;
    long double temp_check = (stold(this->_temp, &sz));
    long double value_check = (stold(value.toString(), &sz));
	multiply_check<T>(temp_check, value_check);
	Factory * factory = new Factory();
    eOperandType t;
    if (this->getPrecision() < value.getPrecision())
        t = value.getType();
    else
        t = this->getType();
	IOperand const * ret_val = factory->createOperand(t, std::to_string(temp_check * value_check));
	delete factory;
	return ret_val;
}

template<class T> IOperand const * Operand<T>::operator/(IOperand const & value) const {
	std::string::size_type sz;
    long double temp_check = (stold(this->_temp, &sz));
    long double value_check = (stold(value.toString(), &sz));
	if (value_check == 0) throw Errors::DivideByZero();
	eOperandType final_type = (this->getPrecision() < value.getPrecision() ? value.getType() : this->getType());
	Factory * factory = new Factory();
	IOperand const * ret_val = factory->createOperand(final_type, std::to_string(temp_check / value_check));
	delete factory;
	return ret_val;
}

template<class T> IOperand const * Operand<T>::operator%(IOperand const & value) const {
	long temp_check = stol(this->toString());
	long value_check = stol(value.toString());
	if (value_check == 0) throw Errors::ModByZero();
	eOperandType final_type = (this->getPrecision() < value.getPrecision() ? value.getType() : this->getType());
	Factory * factory = new Factory();
	IOperand const * ret_val = factory->createOperand(final_type, std::to_string(temp_check % value_check));
	delete factory;
	return ret_val;
}

template<class T> std::string const & Operand<T>::toString( void ) const {
	return this->_temp;
}
template<> int	Operand<int8_t>::getPrecision( void ) const {
     return Int8; 
}

template<> eOperandType	Operand<int8_t>::getType( void ) const { 
    return Int8; 
}

template<> int	Operand<int16_t>::getPrecision(void) const {
	return Int16;
}

template<> eOperandType	Operand<int16_t>::getType(void) const {
	return Int16;
}

template<> int	Operand<int32_t>::getPrecision(void) const {
	return Int32;
}

template<> eOperandType	Operand<int32_t>::getType(void) const {
	return Int32;
}

template<> int	Operand<float>::getPrecision(void) const {
	return Float;
}

template<> eOperandType	Operand<float>::getType(void) const {
	return Float;
}

template<> int	Operand<double>::getPrecision(void) const {
	return Double;
}

template<> eOperandType	Operand<double>::getType(void) const {
	return Double;
}

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;