/*
 * PQueue.cpp - Priority Queue class implementation
 *
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Date: 2016-06-15
 * Authors: Salman Siddiqui & Raj Mahey
 */

#include "Node.h"
#include "PQueue.h"

/*
private attributes:
   Node* head; // "front" of queue (dequeue from front of list)
*/

/* Constructors and Destructors */
PQueue::PQueue()
{
   head = nullptr;
   size = MIN_SIZE;
}

PQueue::~PQueue()
{
	if( head != nullptr )
	{
		Node* curr = head->next;
		Node* prev = head;
		while(curr != nullptr)
		{
			delete prev;
			prev = curr;
			curr = curr->next;
		}
		head = nullptr;
	}
}

// Description: Returns "true" if this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PQueue::isEmpty() const 
{
   return (size <= 0);
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
bool PQueue::enqueue(const Event& newElement)
{
	Node* newNode = new Node(newElement); //Create a new node for this event element

	if(size == 0)// empty list (puts at head)
	{ 
   		head = newNode;
    	size++;
   		return true;   
   	}
   	Node* curr = head;
   	Node* prev = nullptr;
   	if(newNode->data >= head->data) //if this item belongs at the very front
   	{
   		//printf("flag newnode >=head\n"); //testing
   		head = newNode;
   		newNode->next = curr;
   		size++;
   		return true;
   	}
   	while(newNode->data <= curr->data) // keep going until we find the correct position for newNode
   	{
   		if(curr->next == nullptr)
   		{
   			curr->next = newNode;
   			size++;
   			return true;
   			break; //just incase
   		}
   		prev = curr;
   		curr = curr->next;
   	}
   	if(prev==nullptr) //if prev is nullptr, that means newNode goes at head of list ! (newNode == all other list items)
   	{ 
   		head = newNode;
   		newNode->next = curr;
   		size++;
   		return true;
   	}
   	//now we can insert newNode after passing preRequisites, increase size, swap put newNode where curr is and put curr infront of newNode
   	size++;
   	Node* temp = curr;
   	curr = newNode;
   	prev->next = newNode;
   	newNode->next = temp;
   	return true;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
bool PQueue::dequeue()
{
   if( head == nullptr )
   {
      return false;
   }
   head = head->next;
   size--;
   return true;
}

// Description: Gets The size of the queue (number of elements) , returns it as an integer..
// Precondition: None.
int PQueue::getSize()
{
	return size;
}

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
Event PQueue::peek() const throw(EmptyDataCollectionException)
{
   if( head == nullptr )
      throw EmptyDataCollectionException("Empty PQueue");
   return head->data;
}
