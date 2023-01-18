/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:40:04 by mriant            #+#    #+#             */
/*   Updated: 2023/01/18 16:59:19 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &intContainer, int value)
{
	typename T::iterator result;
	
	result = find(intContainer.begin(), intContainer.end(), value);
	if (result == intContainer.end())
		std::cerr << value << " not found" << std::endl;
	return result;
}

#endif