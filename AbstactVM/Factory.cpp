#include "Factory.hpp"
#include "temp_operand.hpp"
//not needed below 
#include <string>

Factory::Factory() {

}

Factory::~Factory() {
    
}

Factory::Factory(Factory const &obj) {
    static_cast<void>(obj); 
}

Factory & Factory::operator=( Factory const & rhs ) { 
    static_cast<void>(rhs); 
    return *this; 
    }

IOperand const * Factory::createInt8( std::string const & value ) const {
	return new Operand<int8_t>(std::stoi(value));
}

IOperand const * Factory::createInt16( std::string const & value ) const{
     return new Operand<int16_t>(std::stoi(value));
}

IOperand const * Factory::createInt32( std::string const & value ) const{
     return new Operand<int32_t>(std::stoi(value));
}

IOperand const * Factory::createFloat( std::string const & value ) const{
     return new Operand<float>(std::stof(value));
}

IOperand const * Factory::createDouble( std::string const & value ) const{
     return new Operand<double>(std::stod(value));
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	static IOPFP creators[] = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	IOperand const * created = nullptr;
	try {
		IOPFP func = creators[type];
		created = (this->*func)(value);
	} catch(std::exception & e) {
        throw Errors::InvalidValue();
	}
	return created;
}