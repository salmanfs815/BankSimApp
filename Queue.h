/*
 * Queue.h - Queue class  declaration
 *
 * Class invariants: FIFO or LILO
 *
 * Date: 2016-06-15
 * Authors: Salman Siddiqui & Raj Mahey
 */

#pragma once
#include "EmptyDataCollectionException.h"
#include "Event.h"

class Queue{

	private:

		const int MAX_QUEUE = 100; // length of queue
		int front; // position of first element in queue
		int back; // position of last element in queue
		Event* events; // Queue - list of Event objects


	public:

		/* Constructors and Destructors */

		//PRE: memory available to create a queue
		//POST: Queue is created with front = 0th position, back uninitialized (-1 out of range)
		Queue();

		//POST: Queue events deleted, front and back reinitizlied to 0 and -1, respectively
		~Queue();


		/* Queue operations */

		// Description: Returns "true" is this queue is empty, otherwise "false".
		// Time Efficiency: O(1)
		// PRE: queue exists
		// POST: see Description (nothing changed in const function) 
		bool isEmpty() const;
	   
		// Description: Adds newElement to the "back" of this queue and 
		//              returns "true" if successful, otherwise "false".
		// Time Efficiency: O(1)
		//PRE: newElement is Event type and has all attributes succesfully set
		//POST: the queue has newElement added to the back
		bool enqueue(const Event& newElement);

		// Description: Removes the element at the "front" of this queue and 
		//              returns "true" if successful, otherwise "false".
		// PRE: This queue is not empty.
		// POST: queue has one less element
		// Time Efficiency: O(1)
		bool dequeue();

		// Description: Retrieves (but does not remove) the element at the  
		//              "front" of this queue and returns it.
		// PRE: This queue is not empty.
		// POST: This queue is unchanged.
		// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
		// Time Efficiency: O(1)
		Event peek() const throw(EmptyDataCollectionException);

};