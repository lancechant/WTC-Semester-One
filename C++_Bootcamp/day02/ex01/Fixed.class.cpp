/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:18:16 by lchant            #+#    #+#             */
/*   Updated: 2018/06/07 13:22:36 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) {
    this->_fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &obj) {
    *this = obj;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Fixed   &Fixed::operator=(const Fixed &value) {
    if (this != &value)
        this->_fixedPointValue = value.getRawBits();
    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void    Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
    return ;
}

Fixed::Fixed(const int value) {
    this->_fixedPointValue = value << _fracBits;
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const float value) {
    this->_fixedPointValue = roundf(value * (1 << _fracBits));
    std::cout << "Float constructor called" << std::endl;
    return ;
}

std::ostream    &operator<<(std::ostream &out, Fixed const &in) {
    out << in.toFloat();
    return (out);
}

float   Fixed::toFloat(void) const {
    return ((float)(this->_fixedPointValue) / (1 << _fracBits));
}

int Fixed::toInt(void) const {
    return ((int)(this->_fixedPointValue >> _fracBits));
}
