/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:26:31 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/24 21:25:10 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdint.h>

# define PRINT_CALLER

template <typename T>
class Array {

private:
	T			*_data;
	uint32_t	_size;

public:
	Array();
	explicit Array(uint32_t n);
	Array(const Array& other);
	~Array();

	Array& 		operator=(const Array& other);
	T&			operator[](uint32_t index);
	const T&	operator[](uint32_t index) const;

	uint32_t	size(void) const;
};

# ifndef ARRAY_TPP
#  include "Array.tpp"
# endif

#endif
