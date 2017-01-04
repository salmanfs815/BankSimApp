/*
 * Event.cpp - Event class implementation
 *
 * Class Invariants:
 *  - type is either "A" or "D"; no other value is allowed
 *  - time is a nonnegative integer
 *  - length is -1 unless type is "A"; nonnegative integer otherwise
 *
 * Date: 2016-06-15
 * Authors: Salman Siddiqui & Raj Mahey
 */

#include "Event.h"
 #include <string>

#include <iostream>
/*
private attributes:
	char type; // type is either "A" (for arrival) or "D" (for departure); no other value is allowed
	int time; // time is the arrival or departure time of the event
	int length; // length is -1 unless type is "A"; positive integer otherwise
*/

/* Constructors and Destructors */

// default constructor; arrival event at time 0 of length 0
Event::Event()
{
	type = "A";
	time = 0;
	length = 0;
}

// ideal constructor for departure events
//PRE: We only need a type and a time (of arrival)
//POST: Set attributes, length = -1 if departure
Event::Event(const char* newType, int newTime)
{
	type = newType;
	time = newTime;
	length = ((type == "D") ? -1 : 0); //departure does not have length (ie length -1)
}

// ideal constructor for arrival events
//PRE: we need a Type, a time AND a length
//POST: set attributes
Event::Event(const char* newType, int newTime, int newLength)
{
	type = newType;
	time = newTime;
	length = ((type == "D") ? -1 : newLength);
}

// destructor
Event::~Event()
{

}


/* Getters and Setters */

// return the event type
const char* Event::getType() const 
{
	return type;
}

// set the event type to newType if it is valid and return true; o/w return false w/o modifying
bool Event::setType(const char* newType)
{
	if( newType == "A" || newType == "D" )
	{
		type = newType;
		return true;
	}

	return false;
}

// return the event time
int Event::getTime() const 
{
	return time;
}

// set the event time to newTime if it is valid and return true; o/w return false w/o modifying
bool Event::setTime(int newTime)
{
	if( newTime >= 0 )
	{
		time = newTime;
		return true;
	}
	return false;
}

// return the event length
int Event::getLength() const 
{
	return length;
}

// set the event length to newLength if it is valid and return true; o/w return false w/o modifying
bool Event::setLength(int newLength)
{
	if( type == "A" && newLength >= 0 )
	{
		length = newLength;
		return true;
	}
	if( type == "D" && newLength == -1 )
	{
		length = newLength;
		return true;
	}
	return false;
}

/* OVERLOADED RELATIONAL OPERATORS!
	- an Event is compared on the basis of its priority 
	   - "high priority" is "greater than"
	   - "low priority" is "less than"  				 */

//LESS THAN OR EQUALS OPERATOR <=
// returns true if rhs has higher priority than this; otherwise returns false
bool Event::operator<=(const Event& rhs)
{
	int thisTime = this->getTime();
	int rhsTime = rhs.getTime();
	std::string thisType = this->getType();
	std::string rhsType = rhs.getType();
	if(thisTime == rhsTime)
	{
		if(!thisType.compare("D") && !rhsType.compare("A"))
		{
			return true;
		}
		return false;
	}

	if(thisTime < rhsTime)//if this time < time on right hand side, then of course we return false
	{
		return false;
	}

	return true;
}

//GREATER THAN OR EQUALS OPERATOR >=
// returns false if rhs has higher priority than this; otherwise returns true
bool Event::operator>=(const Event& rhs)
{
	int thisTime = this->getTime();
	int rhsTime = rhs.getTime();
	std::string thisType = this->getType();
	std::string rhsType = rhs.getType();

	if(thisTime == rhsTime) //times are equal?
	{
		if(!rhsType.compare("D") && !thisType.compare("A")) //Arrival before Departure!
		{
			return true;
		}
		return false;
	}

	if(thisTime < rhsTime) //if this time < time on right hand side, then of course we return true
	{
		return true;
	}

	return false;
}
