/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:47:26 by mriant            #+#    #+#             */
/*   Updated: 2023/01/19 15:18:21 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Span.hpp"

//==============================================================================
// Constructors
//==============================================================================

Span::Span(void) : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span(void)
{
}

//==============================================================================
// Operators
//==============================================================================

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_array = rhs._array;
	}
	return *this;
}

//==============================================================================
// Functions
//==============================================================================

void Span::addNumber(int n)
{
	if (this->_array.size() == this->_maxSize)
		throw Span::FullSpanException();
	this->_array.insert(n);
}

unsigned int Span::shortestSpan(void) const
{
	if (this->_array.size() < 2)
		throw Span::SpanTooShortException();
	unsigned int span = this->longestSpan();
	for (std::multiset<int>::iterator it = this->_array.begin(); it != this->_array.end(); it++)
	{
		std::multiset<int>::iterator tempIt = it;
		tempIt++;
		long int start = static_cast<long int>(*it);
		long int end = static_cast<long int>(*tempIt);
		if (tempIt != this->_array.end() &&  static_cast<unsigned int>(labs(end - start)) < span)
			span =  static_cast<unsigned int>(labs(end - start));
	}
	return span;
}

unsigned int Span::longestSpan(void) const
{
	if (this->_array.size() < 2)
		throw Span::SpanTooShortException();
	long int start = static_cast<long int>(*this->_array.begin());
	long int end = static_cast<long int>(*this->_array.rbegin());
	return static_cast<unsigned int>(labs(end - start));
}
