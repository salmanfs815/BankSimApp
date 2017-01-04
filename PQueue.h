/*
 * PQueue.h - Priority Queue class declaration
 *
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Date: 2016-06-15
 * Authors: Salman Siddiqui & Raj Mahey
 */

#pragma once
#include "EmptyDataCollectionException.h"
#include "Node.h"
#include <iostream>

class PQueue
{

	private:
   		Node* head; // "front" of queue (dequeue from front of list)
   		int size;
   		const int MIN_SIZE = 0;

	public:

		/* Constructors and Destructors */
	    PQueue();
	    ~PQueue();

	   	// Description: Returns "true" if this Priority Queue is empty, otherwise "false".
		// Time Efficiency: O(1)
		bool isEmpty() const;
			  
		// Description: Inserts newElement in sort order.
		//              It returns "true" if successful, otherwise "false".
		// Precondition: This Priority Queue is sorted.   
		// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
		bool enqueue(const Event& newElement);
			   
		// Description: Removes the element with the "highest" priority.
		//              It returns "true" if successful, otherwise "false".
		// Precondition: This Priority Queue is not empty.
		bool dequeue();

		// Description: Gets The size of the queue (number of elements) , returns it as an integer..
		// Precondition: None.
		int getSize();

		// Description: Retrieves (but does not remove) the element with the "highest" priority.
		// Precondition: This Priority Queue is not empty.
		// Postcondition: This Priority Queue is unchanged.
		// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
		Event peek() const throw(EmptyDataCollectionException);


   /* for testing purposes only */
	friend std::ostream& operator<<(std::ostream & os, /*const*/PQueue& rhs){
		os << "{ ";

		if(rhs.isEmpty())// empty list
		{ 
			//printf("FLAG ISEMTY"); //flag
			os << "}";
			return os;
		}

		Node* curr = rhs.head;
		int numberEls = rhs.getSize();
		if(numberEls ==1) //only one element
		{
			os << curr->data << " ";
			os << "}";
			return os;
		}
		while(curr != nullptr) 
		{
			os << curr->data << " ";
			curr = curr->next;
		} 
		os << "}";
		return os;
	};

};
