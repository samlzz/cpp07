/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:18:04 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/21 20:22:52 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const& x)
{
	std::cout << x << " ";
}

void inc(int& x)
{
	++x;
}

void shout(std::string& s)
{
	for (size_t i=0; i<s.size(); ++i)
		s[i]=std::toupper(s[i]);
}

void	someparams(int a, int b)
{
	(void)a;
	(void)b;
}

int main()
{
	int a[] = {1,2,3,4,5};
	iter(a, 5, print<int>);	std::cout << "\n";
	iter(a, 5, inc);
	iter(a, 5, print<int>);	std::cout << "\n";

	const int b[] = {10,20,30};
	iter(b, 3, print<const int>); std::cout << "\n";

	float f[] = { 2.2, 3.3, 42.20 };
	iter(f, 3, print<const float>); std::cout << "\n";

	std::string s[] = {"hi","there"};
	iter(s, 2, shout);
	iter(s, 2, print<std::string>); std::cout << "\n";
}
