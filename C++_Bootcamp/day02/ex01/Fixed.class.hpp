/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:18:23 by lchant            #+#    #+#             */
/*   Updated: 2018/06/07 13:22:47 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed &obj);
    Fixed(const int value);
    Fixed(const float value);
    int                 toInt(void) const;
    float               toFloat(void) const;
    Fixed               &operator=(const Fixed &value);
    int                 getRawBits(void) const;
    void                setRawBits(int const);

private:
    int                 _fixedPointValue;
    static const int    _fracBits = 8;
};

std::ostream            &operator<<(std::ostream &out, Fixed const &in);

#endif
