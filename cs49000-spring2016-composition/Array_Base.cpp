// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 10

//
// Array_Base
//
template <typename T>
Array_Base<T>::Array_Base(void)
	:data_(new T[DEFAULT_SIZE]),
	cur_size_(0)
{

}

//
//Array_Base(size_t)
//
template <typename T>
Array_Base <T>::Array_Base(size_t length)
	:data_(new T[length]),
	cur_size_(length)
{

}

//
// Array_Base(size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base(size_t length, T fill)
	:data_(new T[length]),
	cur_size_(length)
{
	for (size_t i = 0; i < length; i++)
		this->data_[i] = fill;
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base(const Array_Base & array)
	:data_(new T[array.cur_size_]),
	cur_size_(array.cur_size_)
{
	for (size_t i = 0; i < array.cur_size_; i++)
	{
		this->data_[i] = array.data_[i];
	}
}
//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base(void)
{

}


//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if (index > this->cur_size_)
		throw std::out_of_range("index out of range");
	else
		return this->data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if (index >= this->cur_size_)
		throw std::out_of_range("index out of range");
	else
		return this->data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get(size_t index) const
{
	if (index <= cur_size_)
		return this->data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set(size_t index, T value)
{
	if (index <= cur_size_)
		this->data_[index] = value;
	else
		throw std::out_of_range("index out of range");
}


//
// find (char)
//
template  <typename T>
int Array_Base <T>::find(T value) const
{
	return this->find(value, 0);
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find(T val, size_t start) const
{
	if (start >= cur_size_)
		throw std::out_of_range("start index is out of range");
	else
		for (int i = start; i < cur_size_; i++)
			if (this->data_[i] == val)
				return i;

	return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{

	if (this->cur_size_ != rhs.cur_size_)
		return false;
	for (int i = 0; i < cur_size_; i++)
		if (this->data_[i] != rhs.data_[i])
			return false;

	return true;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	if (this->cur_size_ != rhs.cur_size_)
		return true;
	for (int i = 0; i < cur_size_; i++)
		if (this->data_[i] != rhs.data_[i])
			return true;

	return false;
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill(T value)
{
	for (size_t i = 0; i < this->cur_size_; i++)
		this->data_[i] = value;
}
