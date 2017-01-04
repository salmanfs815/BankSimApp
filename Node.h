/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Event class type.
 *
 * Created on: 
 * Author: 
 */
 
// #pragma once is shorthand for the 2 #include guards we've seen before:
// #ifndef _NODE and #define _NODE
#pragma once
#include "Event.h"

class Node
{
	public:
		// Public attributes 
		/*
			* Note, data and next pointer kept public as they may need to be 
			* 	accessed outside of this scope.
			*	ie. we may need to modify the data/delete the data, or point to a different object in our queue implementations
		*/
		Event data;   // The data in the node
		Node* next;   // Pointer to next node
	
		// Constructors and destructor
		//next = NULL, data = nullptr
		Node();

		//PRE: theData is correctly set,
		//POST: datais set as theData 
		Node(Event theData);
		Node(Event theData, Node* theNextNode);
		//Data deleted, next is null.

		~Node();

}; // end Node