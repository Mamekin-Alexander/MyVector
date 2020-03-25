#include <iostream>
#include <algorithm>
#include <utility>
#include "Vector.h"
int main()
{
	my::Vector<std::pair<int, int>> a;
	a.push_back(std::pair<int, int>(1, 2));
	my::Vector<std::pair<int, int>>::Iterator i (a.begin());
	while (i != a.end())
	{
		std::cout << i->second << " ";
		++i;
	}
    std::cout << "Hello World!\n";
}
