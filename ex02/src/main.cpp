/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:18:36 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/26 21:18:37 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

static void sep(const char* t)
{
	std::cout << "\n=== " << t << " ===" << std::endl;
}

template <typename T>
void showElem(const Array<T>& arr, unsigned int index, const std::string& name)
{
	std::cout << name << "[" << index << "] = " << arr[index];
}

template <typename T>
void showArray(const Array<T>& arr, const std::string& name)
{
	for (unsigned int i = 0; i < arr.size(); ++i)
	{
		std::cout << name << "[" << i << "] = " << arr[i];
		if (i + 1 < arr.size())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

// ? Type custom for test Array<Tracked>
struct Tracked {
	int id;
	Tracked(int v = 0) : id(v) {
		std::cout << "Tracked(" << id << ") constructed\n";
	}
	Tracked(const Tracked& other) : id(other.id) {
		std::cout << "Tracked(" << id << ") copied\n";
	}
	Tracked& operator=(const Tracked& other) {
		std::cout << "Tracked(" << id << ") assigned from " << other.id << "\n";
		id = other.id;
		return *this;
	}
	~Tracked() {
		std::cout << "Tracked(" << id << ") destroyed\n";
	}
};

int main()
{
	sep("1. Default constructor");
	Array<int> a;
	std::cout << "Size: " << a.size() << std::endl;

	sep("2. Constructor with size");
	Array<int> b(5);
	std::cout << "Size: " << b.size() << std::endl;
	showArray(b, "b");

	sep("3. Assign values");
	for (unsigned int i = 0; i < b.size(); ++i)
		b[i] = (i + 1) * 10;
	showArray(b, "b");

	sep("4. Copy constructor (deep copy)");
	Array<int> c(b);
	std::cout << "Modifying copy...\n";
	c[0] = 999;
	showElem(b, 0, "b");
	std::cout << " | ";
	showElem(c, 0, "c");
	std::cout << std::endl;

	sep("5. Assignment operator");
	Array<int> d;
	d = b;
	d[1] = 777;
	showElem(b, 1, "b");
	std::cout << " | ";
	showElem(d, 1, "d");
	std::cout << std::endl;

	sep("6. Out of range access");
	try {
		std::cout << b[42] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	sep("7. Const array");
	const Array<int> e(b);
	std::cout << "e.size() = " << e.size() << std::endl;
	showArray(e, "e");

	sep("8. Array of std::string");
	Array<std::string> f(3);
	f[0] = "Hello";
	f[1] = "Module";
	f[2] = "07";
	showArray(f, "f");

	sep("9. Array of custom objects (Tracked)");
	{
		Array<Tracked> g(3);
		for (unsigned int i = 0; i < g.size(); ++i)
			g[i].id = i * 100;
		std::cout << "Copying array...\n";
		Array<Tracked> h = g;
		std::cout << "Assigning array...\n";
		h = g;
	} // destruction automatique testée ici

	sep("10. Empty array behavior");
	Array<double> empty;
	try {
		std::cout << empty[0] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	sep("Tests complete");
	return 0;
}

