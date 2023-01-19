/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:10 by mriant            #+#    #+#             */
/*   Updated: 2023/01/19 09:32:53 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>

#include "easyfind.h"
#include "colors.h"

int main(void)
{
	{
		std::cout << BYEL << "Vectors" << RES << std::endl;
		std::cout << std::endl;

		std::vector< int > myVector;
		std::vector< int > emptyVector;
		for (int i = 0; i < 10; i++)
			myVector.push_back(i);

		std::vector< int >::iterator it;
		std::cout << CYN << "Size 10 vector" << RES << std::endl;
		it = easyfind< std::vector< int > >(myVector, 2);
		if (it != myVector.end())
			std::cout << *it << " OK" << std::endl;
		it = easyfind< std::vector< int > >(myVector, 12);
		if (it != myVector.end())
			std::cout << *it << " OK" << std::endl;

		std::cout << CYN << "Empty vector" << RES << std::endl;
		it = easyfind< std::vector< int > >(emptyVector, 2);
		if (it != emptyVector.end())
			std::cout << *it << " OK" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << BYEL << "Lists" << RES << std::endl;
		std::cout << std::endl;
		std::list< int > myList;
		std::list< int > emptyList;
		for (int i = 0; i < 10; i++)
			myList.push_back(i);

		std::list< int >::iterator it;
		std::cout << CYN << "Size 10 list" << RES << std::endl;
		it = easyfind< std::list< int > >(myList, 2);
		if (it != myList.end())
			std::cout << *it << " OK" << std::endl;
		it = easyfind< std::list< int > >(myList, 12);
		if (it != myList.end())
			std::cout << *it << " OK" << std::endl;

		std::cout << CYN << "Empty list" << RES << std::endl;
		it = easyfind< std::list< int > >(emptyList, 2);
		if (it != emptyList.end())
			std::cout << *it << " OK" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << BYEL << "Double ended queues" << RES << std::endl;
		std::cout << std::endl;
		std::deque< int > myDeque;
		std::deque< int > emptyDeque;
		for (int i = 0; i < 10; i++)
			myDeque.push_back(i);

		std::deque< int >::iterator it;
		std::cout << CYN << "Size 10 double ended queue" << RES << std::endl;
		it = easyfind< std::deque< int > >(myDeque, 2);
		if (it != myDeque.end())
			std::cout << *it << " OK" << std::endl;
		it = easyfind< std::deque< int > >(myDeque, 12);
		if (it != myDeque.end())
			std::cout << *it << " OK" << std::endl;
		std::cout << std::endl;

		std::cout << CYN << "Empty double ended queue" << RES << std::endl;
		it = easyfind< std::deque< int > >(emptyDeque, 2);
		if (it != emptyDeque.end())
			std::cout << *it << " OK" << std::endl;
	}
}
