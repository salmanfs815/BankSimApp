/*
 * Event.h - Event class declaration
 *
 * Class Invariants:
 *  - type is either "A" or "D"; no other value is allowed
 *  - time is a nonnegative integer
 *  - length is -1 unless type is "A"; nonnegative integer otherwise
 *
 * Date: 2016-06-15
 * Authors: Salman Siddiqui & Raj Mahey
 */
#pragma once
#include <iostream>

class Event{

	private:

		const char* type; // type is either "A" (for arrival) or "D" (for departure); no other value is allowed
		int time; // time is the arrival or departure time of the event
		int length; // length is -1 unless type is "A"; positive integer otherwise

	public:


		/* Constructors and Destructors */

		Event(); // default constructor
		
		//PRE: We only need a type and a time (of arrival)
		//POST: Set attributes, length = -1 if departure
		Event(const char* newType, int newTime); // ideal constructor for departure events

		//PRE: we need a Type, a time AND a length
		//POST: set attributes
		Event(const char* newType, int newTime, int newLength); // ideal constructor for arrival events
		~Event(); // destructor


		/* Getters and Setters */

		//POST:
		// return the event type
		const char* getType() const;
		//POST
		// set the event type to newType if it is valid and return true; o/w return false w/o modifying
		bool setType(const char* newType);

		//POST:
		// return the event time
		int getTime() const;

		//POST:
		// set the event time to newTime if it is valid and return true; o/w return false w/o modifying
		bool setTime(int newTime);

		//POST:
		// return the event length
		int getLength() const;

		//PRE: length attribute defined
		//POST: 
		// set the event length to newLength if it is valid and return true; o/w return false w/o modifying
		bool setLength(int newLength);


		/* for testing purposes only */
		friend std::ostream & operator<<(std::ostream& os, const Event& rhs)
		{
			os << "[ " << rhs.getType() << ", " << rhs.getTime() << ", " << rhs.getLength() << " ]";
			return os;
		};


		/* Overloaded operators */

		// the relational operators compare Event priority; an Event is "greater than"
		// 		another Event if it has "higher priority" than that Event
		/*bool operator<(const Event& rhs);
		bool operator>(const Event& rhs);*/
		bool operator<=(const Event& rhs);
		bool operator>=(const Event& rhs);

};