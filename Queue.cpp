/*
 * Queue.cpp - Queue class  implementation
 *
 * Class invariants: FIFO or LILO
 *
 * Date: 2016-06-15
 * Authors: Salman Siddiqui & Raj Mahey
 */

#include "Event.h"
#include "Queue.h"

/*
private attributes:
   int front; // position of first element in queue
   int back; // position of last element in queue
   Event* events; // Queue - list of Event objects
*/


/* Constructors and Destructors */


//PRE: memory available to create a queue
//POST: Queue is created with front = 0th position, back uninitialized (-1 out of range)
Queue::Queue()
{
	front = 0;
	back = -1;
	events = new Event[MAX_QUEUE];
}

//POST: Queue events deleted, front and back reinitizlied to 0 and -1, respectively
Queue::~Queue()
{
	front = 0;
	back = -1;
	delete[] events;
}


/* Queue operations */

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
// PRE: queue exists
// POST: see Description (nothing changed in const function) 
bool Queue::isEmpty() const 
{
	return back < front;
}

// Description: Adds newElement to the "back" of this queue and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
//PRE: newElement is Event type and has all attributes succesfully set
//POST: the queue has newElement added to the back
bool Queue::enqueue(const Event& newElement){
	if( back < MAX_QUEUE-1 )// make sure array isn't full
	{ 
		events[++back] = newElement;
		return true;
	} 
	else // array is full
	{ 
		// might need to shift elements left if more than MAX_QUEUE customers expected
		return false;
	}
}

// Description: Removes the element at the "front" of this queue and 
//              returns "true" if successful, otherwise "false".
// PRE: This queue is not empty.
// POST: queue has one less element
// Time Efficiency: O(1)
bool Queue::dequeue()
{
   	if(isEmpty())
   	{
    	return false;
   	}

	front++;
	return true;
}

// Description: Retrieves (but does not remove) the element at the  
//              "front" of this queue and returns it.
// PRE: This queue is not empty.
// POST: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event Queue::peek() const throw(EmptyDataCollectionException)
{
	if(isEmpty()) //if the queue is empty
	{
		// throw exception
		throw EmptyDataCollectionException("Empty Queue");
	}
	return events[front];
}
