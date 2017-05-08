// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

// Kelly, You need to handle the resize() method on Array correctly.
// To fix this, I added the resize method to Fixed_array

//
// Fixed_Array
// Default Constructor
//
// Kelly, you should call the appropriate base class constructor here instead of calling the resize method.
// To address this, I called the Array constructor that takes an initial size
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(void)
	:Array_Base<T>(N)
{

}

// HELP
// Fixed_Array
// Copy Constructor
//
// Kelly, you should call the appropriate base class constructor here instead of calling the resize method and copying elements over.
// To fix this, I called the Array initializing constructor
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(const Fixed_Array <T, N> & arr)
	:Array_Base<T>(arr)
{

}

//
// Fixed_Array
// This constructor will fill the Fixed Array with data "fill"
//
// Kelly, you should call the appropriate base class constructor here.
// To fix this, I am calling the Array fill constructor.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(T fill)
	:Array_Base<T>(N, fill)
{

}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array(void)
{

}

//HELP
// operator =
//
//This function will overload the = operator when the two arrays are of the same size.
//
// Kelly, It would be better suited if you let the base class handle the copying logic by pass control to it.
// To fix this, I am using the = overload defined in Array class
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{	
	this->cur_size_ = rhs.cur_size_;
	for (size_t i = 0; i < this->size(); i++)
		this->data_[i] = rhs.data_[i];
	return *this;
}

