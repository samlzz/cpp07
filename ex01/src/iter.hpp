/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:08:27 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/24 20:14:06 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <cstddef>

/*
Most generic version but more compile time error

template <typename T, typename F>
void	iter(T *array, size_t lenght, F f)
{
	if (!array)
		return ;
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}
*/

template <typename T>
void	iter(T *array, size_t lenght, void (*f)(T&))
{
	if (!array)
		return ;
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}

template <typename T>
void	iter(const T *array, size_t lenght, void (*f)(const T&))
{
	if (!array)
		return ;
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}


#endif
