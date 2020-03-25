#include <iostream>
#include <algorithm>
#include <utility>
#include "Vector.h"
int main()
{
	my::Vector<int> a{ 1,2,3,4,5 };
	my::Vector<int>::Iterator i = a.begin();
	*i++ = 5;
	while (i != a.end())
	{
		std::cout << *i<< " ";
		++i;
	}
	std::cout << *a.begin();
}
