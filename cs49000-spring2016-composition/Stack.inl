// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $
//#include "Array.h"
// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
// This method returns the current size of the stack array
//
template <typename T>
inline
size_t Stack <T>::size(void) const
{
	return this->top_;
}

//
// top
// The method returns the top most element index
//
// Kelly, make sure you are throwing the right exception.
// To fix this, I changed the exception
template <typename T>
inline
T Stack <T>::top(void) const
{
	if (this->is_empty())
		throw std::out_of_range("Stack is empty");
	return this->top_;
}

//
// is_empty
// if the stack array is empty, a TRUE is returned
// if the stack array is not empty, a FALSE is returned
//
template <typename T>
inline
bool Stack <T>::is_empty(void) const
{
	return (this->top_ == 0);
}

//
// clear
//
template <typename T>
inline
void Stack <T>::clear(void)
{
	this->top_ = 0;
}