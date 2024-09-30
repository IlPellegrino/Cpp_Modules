#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	printItems(const T& element, const int& num)
{
	std::cout << "--------------------------------------\n";
	std::cout << "Index element ----> " << num << std::endl;
	std::cout << element << std::endl;
}

template <typename T, typename S, typename F>
void	iter(T* array, S length, F function)
{
	for (int i = 0; i < length; i++) {
		function(array[i], i);
	}
}

#endif