/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:36:38 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/24 21:27:07 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> a;
	Array<int> b(5);

	for (unsigned i = 0; i < b.size(); ++i)
		b[i] = (i + 1) * 10;

	Array<int> c = b;
	c[0] = 999;

	std::cout << "b[0]=" << b[0] << ", c[0]=" << c[0] << "\n";

	try {
		std::cout << b[42] << "\n";
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
	return 0;
}

