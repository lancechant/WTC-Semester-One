/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:22:41 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 14:22:42 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>

class Brain
{
public:
    Brain(void);
    ~Brain(void);
    void        setAddress(void);
    std::string getAddress(void);
    std::string identify(void);

private:
    std::string _address;
};

#endif
