/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:15:14 by mriant            #+#    #+#             */
/*   Updated: 2023/01/20 10:33:38 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <set>

class Span
{
private:
	unsigned int _maxSize;
	std::multiset<int> _array;

	Span(void);

public:
	Span(unsigned int n);
	Span(Span const &src);
	~Span(void);

	Span &operator=(Span const &rhs);

	void addNumber(int n);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

	template <typename T_iterator>
	void addMany(T_iterator first, T_iterator last)
	{
		unsigned int size = 0;
		for (T_iterator it = first; it != last; it++)
			size++;
		if (this->_array.size() + size > this->_maxSize)
			throw Span::FullSpanException();
		this->_array.insert(first, last);
	}

	class FullSpanException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "The span is full";
		}
	};
	class SpanTooShortException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "There must be at least 2 elements to compute a span";
		}
	};
};

#endif
