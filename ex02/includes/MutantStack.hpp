/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:31:37 by mriant            #+#    #+#             */
/*   Updated: 2023/01/20 13:44:57 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
private:

public:
	MutantStack<T, Container>(void): std::stack<T, Container>() {}
	MutantStack<T, Container>(const Container &cont): std::stack<T, Container>(cont) {}
	MutantStack<T, Container>(const MutantStack<T, Container> &src): std::stack<T, Container>(src) {}
	~MutantStack<T, Container>(void) {}

	MutantStack<T, Container>& operator=(const MutantStack<T, Container> &rhs) {
		if (this != &rhs)
			this->std::stack<T, Container>::operator=(rhs);
		return *this;
	}

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	iterator begin(void){
		return this->c.begin();
	}
	iterator end(){
		return this->c.end();
	}

	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
	const_iterator begin() const {
		return this->c.begin();
	}
	const_iterator end() const {
		return this->c.end();
	}

	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}

	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}
	const_reverse_iterator rend() const {
		return this->c.rend();
	}
};

#endif