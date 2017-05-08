// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 10
//
// Array
//
template <typename T>
Array<T>::Array(void)
	:Array_Base<T>(),
	max_size_(DEFAULT_SIZE)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array(size_t length)
	:Array_Base<T>(length),
	max_size_(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array(size_t length, T fill)
	:Array_Base<T>(length,fill),
	max_size_(length)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array(const Array<T> & array)
	:Array_Base<T>(array),
	max_size_(array.max_size_)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array(void)
{
	
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array<T> & rhs)
{
	this->max_size_ = rhs.max_size_;
	this->cur_size_ = rhs.cur_size_;

	for (size_t i = 0; i < this->size(); i++)
		this->set(i, rhs.get(i));
	return *this;
}


//
// resize
//
template <typename T>
void Array <T>::resize(size_t new_size)
{
	if (new_size < 0)
		throw std::out_of_range("index out of range");

	if (new_size >= this->size())
	{
		T *arr = new T[new_size];
		
		for (int i = 0; i < this->size(); i++)
		{
			arr[i] = this->data_[i];
		}

		delete[] this->data_;

		this->data_ = new T[new_size];
		this->max_size_ = new_size;
		this->cur_size_ = new_size;

		for (int i = 0; i < new_size; i++)
		{
			this->data_[i] = arr[i];
		}

		delete[] arr;
	}

	else if (new_size < this->size())
	{
		this->cur_size_ = new_size;
	}
}

