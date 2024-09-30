#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
#include <exception>

template <typename T>
void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
class	Array {
	private:
		T*	_arr;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int& n);
		Array(const Array<T>& a);
		Array&	operator=(Array<T>& a);
		T&	operator[](unsigned int index);
		~Array();

		class	IndexOutOfBoundsException : public std::exception {
			public:
				const char *what() const throw();
		};

		unsigned int	size() const;
};


// defining the exception

template <typename T>
const  char	*Array<T>::IndexOutOfBoundsException::what() const throw() {
	return "Index is out of bounds.";
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw IndexOutOfBoundsException();
	}
	return this->_arr[index];
}

// defining the templates

template <typename T>
unsigned int	Array<T>::size() const {
	return _size;
}

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int& n) : _arr(NULL), _size(n) {
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(const Array<T>& a) : _size(a._size) {
	this->_arr = new T[a._size];
	for (unsigned int i = 0; i < _size; i++) {
		this->_arr[i] = a._arr[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T>& a) {
	if (this != &a) {
		::swap(this->_arr, a._arr);
		::swap(this->_size, a._size);
	}

	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (_arr != NULL) {
		delete[] _arr;
	}
	_size = 0;
}

#endif