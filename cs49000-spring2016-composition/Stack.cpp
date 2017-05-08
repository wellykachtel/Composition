// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#define DEFAULT_SIZE 10
//
// Stack
// Default constructor
// Kelly, once you use the aggregation,  you need to call the appropriate array constructor.
// To fix this, I used aggregation and called the correct array constructor
template <typename T>
Stack <T>::Stack(void)
	: top_(0),
	stack_array_(DEFAULT_SIZE)
{
}

//
// Stack
// Copy constructor
// Kelly, once you use the aggregation,  you need to call the appropriate array constructor.
// To fix this, I used aggregation and called the correct array constructor
template <typename T>
Stack <T>::Stack(const Stack & stack)
	:top_(stack.top_),
	stack_array_(stack.stack_array_)
{

}

//
// ~Stack
// Destructor
template <typename T>
Stack <T>::~Stack(void)
{

}

//
// push
// This method will push a new element onto the stack array at the end
// top_ keeps track of the last element.
//
//Kelly, you would not need to resize every time, if you use aggregation of array and use the correct constructor.
// To fix this I am only resizing when the array is completely full
template <typename T>
void Stack <T>::push(T element)
{
	this->stack_array_[top_] = element;

	//check if the stack array is full before moving the top ahead a space
	if (this->top_ == this->stack_array_.size())
	{
		this->stack_array_.resize(this->size() + 1);
		this->top_++;
	}
	else
		this->top_++;
}

//
// pop
// This method will remove the last element from the stack array
//
template <typename T>
void Stack <T>::pop(void)
{
	if (this->is_empty())
		throw std::out_of_range("Stack is empty");
	else
		this->top_--;
}

//
// operator =
//
// Kelly, always check for self assignment before continuing.
// To fix this, I checked for self assignment
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	this->top_ = rhs.top_;
	this->stack_array_ = rhs.stack_array_;

	return *this;
}

//
// operator []
//
template <typename T>
T & Stack <T>::operator [] (size_t index)
{
	if (index > this->stack_array_.size())
		throw std::out_of_range("index out of range");
	else
		return this->stack_array_[index];
}


