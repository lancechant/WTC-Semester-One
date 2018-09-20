/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:11:38 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 14:11:39 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int
main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::string     *ptr = &str;
    std::string     &ref = str;

    std::cout << "\033[1;31mThe Actual String: \033[0m" << str << std::endl;
    std::cout << "\033[1;31mThe Pointer: \033[0m" << *ptr << std::endl;
    std::cout << "\033[1;31mAnd Finally The Reference: \033[0m" << ref << std::endl;
    return (0);
}
