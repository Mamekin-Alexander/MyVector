#include <iostream>
#include <algorithm>
#include <utility>
#include "Vector.h"
int main()
{
	my::Vector<int> a{ 5,1,2,4 };
	std::sort(a.begin(), a.end());
	my::Vector<int>::Iterator i = a.begin();
	while (i != a.end())
	{
		std::cout << *i << " ";
		++i;
	}
	return 0;
}
