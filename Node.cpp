/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of Event class type.
 *
 * Created on: 
 * Author: 
 */

#include "Node.h"

//POST: next pointer set to null! (data un<changed/set>)
Node::Node()
{
	next = nullptr;
}

//PRE: theData is correctly set,
//POST: datais set as theData 
Node::Node(Event theData)
{
	data = theData;
	next = nullptr;
}

Node::Node(Event theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

//Data deleted, next is null.
Node::~Node()
{
	delete &data;
	next = nullptr;
}

// end Node.cpp