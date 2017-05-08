// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $
//#include "Array.h"
// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.
//#include "Queue.h"


//
// size
// This method will return the size of the queue array
//
template <typename T>
inline
size_t Queue <T>::size(void) const
{
	return this->queue_array_.size();
}


//
// is_empty
// This method checks to see if the circular array is empty by
// seeing if the head and tail are pointed to the same spot
// if the queue array is empty, a TRUE is returned
// if the queue array is not empty, a FALSE is returned
//
template <typename T>
inline
bool Queue<T>::is_empty(void) const
{
	return (this->head_ == this->tail_);
}

//
// clear
// This method "clears" the array by setting the head and tail to the 
// same location in the circular array
//
template <typename T>
inline
void Queue<T>::clear(void)
{
	this->head_ = this->tail_;
}