#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename Val>
void	swap(Val& a, Val&b)
{
	Val temp = a;
	a = b;
	b = temp;
}

template <typename Val>
Val	max(Val& a, Val& b)
{
	if (a > b)
		return a;
	else if (a < b)
		return b;
	else
		return b;
}

template <typename Val>
Val	min(Val& a, Val& b)
{
	if (a < b)
		return a;
	else if (b < a)
		return b;
	else
		return b;
}

#endif