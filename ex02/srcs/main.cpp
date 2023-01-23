/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:01:45 by mriant            #+#    #+#             */
/*   Updated: 2023/01/23 10:54:01 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <string>

#include "MutantStack.h"
#include "colors.h"

int main()
{
	std::cout << BYEL << "MutantStack with deque (default)" << RES << std::endl;
	std::cout << std::endl;
	std::cout << CYN << "Int" << RES << std::endl;
	std::cout << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		testStack(mstack);

		std::cout << CYN << "Copy Constructor" << RES << std::endl;
		std::cout << std::endl;
		MutantStack<int> mstack2(mstack);
		testStack(mstack2);

		std::cout << CYN << "Assignment" << RES << std::endl;
		std::cout << std::endl;
		MutantStack<int> mstack3;
		mstack3 = mstack;
		testStack(mstack3);

	}
	std::cout << CYN << "String" << RES << std::endl;
	std::cout << std::endl;
	{

		MutantStack<std::string> mstack;
		mstack.push("cinq");
		mstack.push("dix-sept");
		mstack.push("trois");
		mstack.push("cinq");
		mstack.push("sept-cent-trente-sept");
		mstack.push("zero");
		testStack(mstack);
	}
	std::cout << BYEL << "MutantStack with list" << RES << std::endl;
	std::cout << std::endl;
	std::cout << CYN << "Int" << RES << std::endl;
	std::cout << std::endl;
	{
		MutantStack<int, std::list<int> > mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		testStack(mstack);
	}
	std::cout << CYN << "String" << RES << std::endl;
	std::cout << std::endl;
	{

		MutantStack<std::string, std::list<std::string> > mstack;
		mstack.push("cinq");
		mstack.push("dix-sept");
		mstack.push("trois");
		mstack.push("cinq");
		mstack.push("sept-cent-trente-sept");
		mstack.push("zero");
		testStack(mstack);
	}
	std::cout << BYEL << "List" << RES << std::endl;
	std::cout << std::endl;
	std::cout << CYN << "Int" << RES << std::endl;
	std::cout << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		testList(mstack);
	}
	std::cout << CYN << "String" << RES << std::endl;
	std::cout << std::endl;
	{

		std::list<std::string> mstack;
		mstack.push_back("cinq");
		mstack.push_back("dix-sept");
		mstack.push_back("trois");
		mstack.push_back("cinq");
		mstack.push_back("sept-cent-trente-sept");
		mstack.push_back("zero");
		testList(mstack);
	}
	return 0;
}
