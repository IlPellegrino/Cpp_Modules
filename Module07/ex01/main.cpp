#include "include/iter.hpp"
#include <cctype>

int	main()
{
	int	array[] = {31, 10, 2017, 15, 2001, 02};
	int	size = sizeof(array) / sizeof(array[0]);

	::iter(array, size, printItems<int>);

	double	arr[] = {2.3, 35.45, 928439284284294, 0.00002};
	size = sizeof(arr) / sizeof(arr[0]);

	iter(arr, size, printItems<double>);
	return 0;
}