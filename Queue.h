// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include "Array.h"


/**
* @class Queue
*
* Implementation of a queue.
* It is derived from Array so it can inherit of
* the Array class's methods.
*/
// Kelly, You should use aggregation instead of inheritance since logically 
// a queue is not an array.
// To fix this, I implemented aggregation
template <typename T>
class Queue
{
public:
	/**
	* @class empty_exception
	*
	* Exception thrown to indicate the stack is empty.
	*/
	class empty_exception : public std::exception
	{
	public:
		/// Default constructor.
		empty_exception(void)
			: std::exception() { }

		/**
		* Initializing constructor.
		*
		* @param[in]      msg         Error message.
		*/
		//empty_exception(const char * msg)
		//: std::exception(msg) { }
	};

	/// Default constructor.
	Queue(void);

	/**
	* Copy constructor.
	*
	* @param[in]      arr        Source array
	*/
	Queue(const Queue <T> & queue);

	/// Destructor.
	~Queue(void);

	/**
	* Assignment operator
	*
	* @param[in]      rhs        Right-hand side of operator.
	*/
	const Queue & operator = (const Queue & rhs);

	/**
	* Get the character at the specified index. If the index is not
	* within the range of the array, then std::out_of_range exception
	* is thrown.
	*
	* @param[in]       index               Zero-based location
	* @exception       std::out_of_range   Invalid \a index value
	*/
	T & operator [] (size_t index);

	/**
	* Enqueue a new \a element onto the queue. The element is inserted
	* at the end of the list
	*
	* @param[in]      element       Element to add to the list
	*/
	void enqueue(T element);

	/**
	* Remove the oldest element from the stack.
	*
	* @exception      empty_exception    The stack is empty.
	*/
	T dequeue(void);

	/**
	* Test if the queue is empty
	*
	* @retval         true          The stack is empty
	* @retval         false         The stack is not empty
	*/
	bool is_empty(void) const;

	/**
	* Number of element on the queue.
	*
	* @return         Size of the queue.
	*/
	size_t size(void) const;

	/// Remove all elements from the queue.
	void clear(void);

private:
	int head_;
	int tail_;
	Array<T> queue_array_;

};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
