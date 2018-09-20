/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:35:44 by lchant            #+#    #+#             */
/*   Updated: 2018/06/06 13:35:45 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"
void ponyOnTheStack()
{
	Pony ponyStack = Pony("PonyStack");
	std::cout << "\033[1;31m The pony hay stack is there\033[0m" << std::endl;
}

Pony *ponyOnTheHeap()
{
	Pony *ponyHeap = new Pony("PonyHeap");
    std::cout << "\033[1;31m The pony hay Heap is there\033[0m" << std::endl;
	return (ponyHeap);
}

int main()
{
	Pony *ponyHeap = ponyOnTheHeap();
	ponyOnTheStack();
	delete ponyHeap;
	return (0);
}
