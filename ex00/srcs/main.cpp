/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:10 by mriant            #+#    #+#             */
/*   Updated: 2023/01/18 17:18:06 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

#include "easyfind.h"
#include "colors.h"

int main(void)
{
	{
		std::cout << BYEL << "Vectors" << RES << std::endl;
		std::cout << std::endl;

		std::vector< int > myVector;
		for (int i = 0; i < 10; i++)
			myVector.push_back(i);

		std::vector< int >::iterator it;
		it = easyfind< std::vector< int > >(myVector, 2);
		if (it != myVector.end())
			std::cout << *it << std::endl;
		it = easyfind< std::vector< int > >(myVector, 12);
		if (it != myVector.end())
			std::cout << *it << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << BYEL << "Double ended queues" << RES << std::endl;
		std::cout << std::endl;
		std::deque< int > myDeque;
		for (int i = 0; i < 10; i++)
			myDeque.push_back(i);

		std::deque< int >::iterator it;
		it = easyfind< std::deque< int > >(myDeque, 2);
		if (it != myDeque.end())
			std::cout << *it << std::endl;
		it = easyfind< std::deque< int > >(myDeque, 12);
		if (it != myDeque.end())
			std::cout << *it << std::endl;
		std::cout << std::endl;
	}
}