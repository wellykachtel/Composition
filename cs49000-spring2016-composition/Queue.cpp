// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#define DEFAULT_SIZE 3

//
// Queue
// Default constructor
// Kelly, once you use the aggregation,  you need to call the appropriate array constructor.
//To fix this, I am using aggregation and initalizing the correct variables.
template <typename T>
Queue <T>::Queue(void)
	:head_(-1),
	tail_(0),
	queue_array_(DEFAULT_SIZE)
{

}

//
// Queue
// Copy constructor
// Kelly, once you use the aggregation,  you need to call the appropriate array constructor.
// To fix this, I am using aggregation and initalizing the correct variables
template <typename T>
Queue <T>::Queue(const Queue & queue)
	:head_(queue.head_),
	tail_(queue.tail_),
	queue_array_(queue.queue_array_)
{

}

//
// ~Queue
// Destructor
template <typename T>
Queue <T>::~Queue(void)
{

}

//
//operator overload
//
// Kelly, make sure you are copying correctly.
// To fix this, I used the correct methods to copy data, set and get
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	this->head_ = rhs.head_;
	this->tail_ = rhs.tail_;
	this->queue_array_ = rhs.queue_array_;

	return *this;
}

//
// operator []
//
template <typename T>
T & Queue <T>::operator [] (size_t index)
{
	if (index > this->queue_array_.size())
		throw std::out_of_range("index out of range");
	else
		return this->queue_array_[index];
}

//
//enqueue
// This method will add element to the end of the list
//
// Kelly, although this may work, the loop will take lot of time if there are a lot of elements in the array.
// You should do something in your dequeue method that would let you use the spaces in the front when you dequeue an element.
// To fix this, I created two new variables, head and tail, to create a circular array
template <typename T>
void Queue <T>::enqueue(T element)
{
	//check if circular queue is full
	if (this->head_ == (this->tail_ + 1) % this->size())
	{
		int iterH = this->head_;
		int iterT = this->tail_;
		int i = 0;
		int ind = this->size()-1; //this is the index of the last element before we resize
		this->queue_array_.resize(this->size() + 1);
		
		if (iterT < iterH)
		{
			for (size_t i = ind; i >= iterH; i--)
				this->queue_array_.set(i + 1, this->queue_array_.get(i));

			this->head_++;
		}
	}
		//write the new element to the tail end of the queue
		this->queue_array_[this->tail_] = element;
		//advance the tail to the next queue position
		this->tail_ = (this->tail_ + 1) % this->size();

		if (this->head_ == -1)
			this->head_++;
}

	//
	//dequeue
	//This method will remove the first element in the list
	//
	// Kelly, dequeue should remove an element from the front of the list.
	//To fix this, I am moving head up one space as to dequeue from the front of the list
	template <typename T>
	T Queue <T>::dequeue(void)
	{
		if (this->is_empty())
			throw std::out_of_range("The queue is empty");
		else
		{
			int temp = this->head_;
			T temp2 = this->queue_array_[temp];
			//advance the head to the next position, dequeueing the first element
			this->head_ = (this->head_ + 1) % (this->size());
			return temp2;
		}
	}

