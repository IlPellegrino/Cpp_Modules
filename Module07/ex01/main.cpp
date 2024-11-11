#include "include/iter.hpp"
#include <cctype>

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }


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