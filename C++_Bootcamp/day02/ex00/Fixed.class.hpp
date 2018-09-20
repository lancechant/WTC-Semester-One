/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:18:23 by lchant            #+#    #+#             */
/*   Updated: 2018/06/07 11:18:24 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed &obj);
    Fixed               &operator=(const Fixed &value);
    int                 getRawBits(void) const;
    void                setRawBits(int const);

private:
    int                 _fixedPointValue;
    static const int    _fracBits = 8;
};

#endif
