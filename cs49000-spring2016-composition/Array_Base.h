// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Array.h
*
* $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>          // for size_t definition

/**
* @class Array_Base
*
* Basic implementation of an abstract array class using templates
*/
template <typename T>
class Array_Base
{
public:
	/// Type definition of the element type.
	typedef T type;
	
	/// Default constructor.
	Array_Base(void);

	/**
	* Initializing constructor.
	*
	* @param[in]      length        Initial size
	*/
	Array_Base(size_t length);

	/**
	* Initializing constructor.
	*
	* @param[in]      length        Initial size
	* @param[in]      fill          Initial value for each element
	*/
	Array_Base(size_t length, T fill);

	/**
	* Copy constructor
	*
	* @param[in]     arr         The source array.
	*/
	Array_Base(const Array_Base & arr);



	/// Destructor.
	~Array_Base(void);

	/**
	* Retrieve the current size of the array.
	*
	* @return          The current size
	*/
	size_t size(void) const;

	

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
	* @overload
	*
	* The returned character is not modifiable.
	*/
	const T & operator [] (size_t index) const;

	/**
	* Get the character at the specified index. If the \a index is not within
	* the range of the array, then std::out_of_range exception is thrown.
	*
	* @param[in]       index                 Zero-based location
	* @return          Character at \index
	* @exception       std::out_of_range     Invalid index value
	*/
	 T get(size_t index) const;

	/**
	* Set the character at the specified \a index. If the \a index is not
	* within range of the array, then std::out_of_range exception is
	* thrown.
	*
	* @param[in]       index                 Zero-based location
	* @param[in]       value                 New value for character
	* @exception       std::out_of_range     Invalid \a index value
	*/
	void set(size_t index, T value);


	
	/**
	* Locate the specified character in the array. The index of the first
	* occurrence of the character is returned. If the character is not
	* found in the array, then -1 is returned.
	*
	* @param[in]        ch        Character to search for
	* @return           Index value of the character
	* @retval           -1        Character not found
	*/
	int find(T element) const;

	/**
	* @overload
	*
	* This version allows you to specify the start index of the search. If
	* the start index is not within the range of the array, then the
	* std::out_of_range exception is thrown.
	*
	* @param[in]       ch                   Character to search for
	* @param[in]       start                Index to begin search
	* @return          Index value of first occurrence
	* @retval          -1                   Character not found
	* @exception       std::out_of_range    Invalid index
	*/
	int find(T element, size_t start) const;

	/**
	* Test the array for equality.
	*
	* @param[in]       rhs                  Right hand side of equal to sign
	* @retval          true                 Left side is equal to right side
	* @retval          false                Left side is not equal to right side
	*/
	bool operator == (const Array_Base & rhs) const;

	/**
	* Test the array for inequality.
	*
	* @param[in]       rhs                  Right-hand size of not equal to sign
	* @retval          true                 Left side is not equal to right side
	* @retval          false                Left size is equal to right side
	*/
	bool operator != (const Array_Base<T> & rhs) const;

	/**
	* Fill the contents of the array.
	*
	* @param[in]       ch                   Fill character
	*/
	void fill(T element);

protected:
	/// Pointer to the actual data.
	T * data_;

	/// Current size of the array.
	size_t cur_size_;

};

#include "Array_Base.inl"
#include "Array_Base.cpp"


#endif   // !defined _ARRAY_BASE_H_#pragma once
