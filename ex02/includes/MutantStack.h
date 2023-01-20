/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:29:42 by mriant            #+#    #+#             */
/*   Updated: 2023/01/20 16:18:49 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include<list>

#include "MutantStack.hpp"

template<typename T, typename U>
void testStack(MutantStack<T, U> &mstack)
{
		std::cout << "Last element: " << mstack.top() << std::endl;
		std::cout << "Size before pop: " << mstack.size();
		mstack.pop();
		std::cout << " Size after pop: " << mstack.size() << std::endl;
		typename MutantStack<T, U>::iterator it = mstack.begin();
		typename MutantStack<T, U>::iterator ite = mstack.end();
		std::cout << "Content: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		typename MutantStack<T, U>::reverse_iterator rit = mstack.rbegin();
		typename MutantStack<T, U>::reverse_iterator rite = mstack.rend();
		std::cout << "Content with reverse iterator: ";
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
		std::stack<T, U> s(mstack);
		std::cout << std::endl;
}

template<typename T>
void testList(std::list<T> &mstack)
{
		std::cout << "Last element: " << mstack.back() << std::endl;
		std::cout << "Size before pop: " << mstack.size();
		mstack.pop_back();
		std::cout << " Size after pop: " << mstack.size() << std::endl;
		typename std::list<T>::iterator it = mstack.begin();
		typename std::list<T>::iterator ite = mstack.end();
		std::cout << "Content: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		typename std::list<T>::reverse_iterator rit = mstack.rbegin();
		typename std::list<T>::reverse_iterator rite = mstack.rend();
		std::cout << "Content with reverse iterator: ";
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
}


#endif