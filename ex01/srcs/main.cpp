/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:42:02 by mriant            #+#    #+#             */
/*   Updated: 2023/01/19 16:45:26 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

#include "Span.hpp"
#include "colors.h"

#define SIZE_VALUE 100000
#define RANDOMNESS 0

int main()
{
	if (RANDOMNESS)
		srand(1);
	else
		srand(time(NULL));
	std::cout << BCYN << "Basic span" << RES << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	std::cout << BCYN << "Little span" << RES << std::endl;
	std::cout << CYN << "Size 0" << RES << std::endl;
	Span littleSp(2);
	try
	{
		std::cout << "Shortest span: " << littleSp.shortestSpan() << std::endl;
	}
	catch(const Span::SpanTooShortException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Longest span: " << littleSp.longestSpan() << std::endl;
	}
	catch(const Span::SpanTooShortException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << CYN << "Size 1" << RES << std::endl;
	littleSp.addNumber(1);
	try
	{
		std::cout << "Shortest span: " << littleSp.shortestSpan() << std::endl;
	}
	catch(const Span::SpanTooShortException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Longest span: " << littleSp.longestSpan() << std::endl;
	}
	catch(const Span::SpanTooShortException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << CYN << "Size 2" << RES << std::endl;
	littleSp.addNumber(1);
	try
	{
		std::cout << "Shortest span: " << littleSp.shortestSpan() << std::endl;
	}
	catch(const Span::SpanTooShortException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Longest span: " << littleSp.longestSpan() << std::endl;
	}
	catch(const Span::SpanTooShortException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << CYN << "Full span" << RES << std::endl;
	try
	{
		littleSp.addNumber(1);
	}
	catch(const Span::FullSpanException &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << BCYN << "Big span" << RES << std::endl;
	Span bigSp(SIZE_VALUE);
	std::vector< int > bigVector;
	int maxRand = INT_MIN;
	int minRand = INT_MAX;
	for (int i = 0; i < SIZE_VALUE; i++)
	{
		int myRand = rand();
		if (i % 2)
			myRand = myRand * (-1);
		bigSp.addNumber(myRand);
		bigVector.push_back(myRand);
		if (myRand > maxRand)
			maxRand = myRand;
		if (myRand < minRand)
			minRand = myRand;
	}
	bigVector.pop_back();
	std::cout << "Shortest span: " << bigSp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSp.longestSpan() << std::endl;
	std::cout << "Max: " << maxRand << std::endl;
	std::cout << "Min: " << minRand << std::endl;
	std::cout << "Max - Min: " << static_cast< long int >(maxRand) - static_cast< long int >(minRand) << std::endl;
	std::cout << CYN << "Full span" << RES << std::endl;
	try
	{
		bigSp.addNumber(1);
	}
	catch(const Span::FullSpanException &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	std::cout << BCYN << "Big span with iterator range" << RES << std::endl;
	Span bigSp2(SIZE_VALUE);
	bigSp2.addMany< std::vector< int >::iterator >(bigVector.begin(), bigVector.end());
	std::cout << "Shortest span: " << bigSp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSp2.longestSpan() << std::endl;
	std::cout << "Max: " << maxRand << std::endl;
	std::cout << "Min: " << minRand << std::endl;
	std::cout << "Max - Min: " << static_cast< long int >(maxRand) - static_cast< long int >(minRand) << std::endl;
	std::cout << CYN << "Full span" << RES << std::endl;
	try
	{
		bigSp2.addMany< std::vector< int >::iterator >(bigVector.begin(), bigVector.end());
	}
	catch(const Span::FullSpanException &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		bigSp2.addNumber(1);
		std::cout << "Add one number works" << std::endl;
	}
	catch(const Span::FullSpanException &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	return 0;
}
