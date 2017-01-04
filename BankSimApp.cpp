/*
 * BankSimApp.cpp
 *
 * Created: 2016-06-16
 * Authors: Salman Siddiqui & Raj Mahey
 */


#include <iostream>
#include <limits>
#include <stdio.h>
#include "Event.h"
#include "Queue.h"
#include "PQueue.h"


/* Global variable declarations */



//PRE: time has length length
//POST: Returns average time taken as a float or -1 if len =0
float averageTime(int time, int len)
{
	if(len==0) //if the length is 0 then we would be dividing by zero, so lets return -1
	{
		return -1;
	}
	return (float)time/len;
}


//PRE: At least one element in eventListPQueue, room in bankQueue and room in eventListPQueue
//Post: eventListPQueue has at most one less element
void processArrival(Event arrivalEvent,PQueue& eventListPQueue, Queue& bankQueue, bool& tellerAvailable,const int& currentTime, float& totalWaitTime)
{
    cout << "Processing an arrival event at time:   ";
    if(currentTime < 10) // add extra space to make sure ones column of output is lined up properly
    	cout << " ";
    cout << currentTime << endl; //print flag for arrival event
	eventListPQueue.dequeue();   //dequeue from priority queue (get rid of earliest element)

	if(bankQueue.isEmpty() && tellerAvailable) //ensure there is a teller available and the bankQueue is empty (no one infront)
	{
		int departureTime = currentTime + arrivalEvent.getLength(); //departure time will be the current time plus how long this customer needs
		totalWaitTime+= (currentTime - arrivalEvent.getTime());
		Event newDepartureEvent("D",departureTime); //Create a new departure event 
		eventListPQueue.enqueue(newDepartureEvent); //put this departure event on the priority queue
		tellerAvailable = false; //no teller available now (until bankqueue is empty again)
	} 
	else 
	{
		bankQueue.enqueue(arrivalEvent); //there wasnt a teller available or the bankQueue had people, so we throw this customer there too
	}
	return;
}

//PRE: At least one element in eventListPQueue, room in bankQueue and room in eventListPQueue
//Post: eventListPQueue has at most one less element
//			bankQueue may have less elements
void processDeparture(Event departureEvent,PQueue& eventListPQueue,Queue& bankQueue,bool& tellerAvailable, const int& currentTime, float& totalWaitTime)
{
    cout << "Processing a departure event at time:  ";
    if(currentTime < 10) // add extra space to make sure ones column of output is lined up properly
    	cout << " ";
    cout << currentTime << endl; //flag to let us know we are dealing with a departure
	eventListPQueue.dequeue(); //dequeue customer departure
	try
	{
		Event customer = bankQueue.peek(); //peek the bank queue to get the current customer
		bankQueue.dequeue(); //now we have the customer from above, so we get rid of him/her in the bankqueue
		totalWaitTime+= (currentTime - customer.getTime());
		int departureTime = currentTime + customer.getLength(); //the departure time will be the current time + the customers time
		Event newDepartureEvent("D",departureTime); //create a new departure event
		eventListPQueue.enqueue(newDepartureEvent); //queue this departure event
		//cout << endl << endl << endl << "bank queue not mepty"<< endl << endl << endl;
		return;
	}
	catch(EmptyDataCollectionException e) //if the bankQueue is empty!
	{
		tellerAvailable = true;
		return;
	}
}

//Description: This is the main simulation, this function accepts inputs and then simulates the bank
//PRE: None
//POST: None
void simulate()
{
	PQueue eventListPQueue;
	bool tellerAvailable = true;
	int arrivalTime;
	int duration;
    bool bln=true; //boolean for while loop (make sure integers are input)
    int totalCustomers=0;
	Queue bankQueue;
	int currentTime;
	float totalWaitTime=0;

	//cout << "Please enter input now" << endl; // for testing purposes
	while(bln) // read input and add arrivals to queue
	{
	    while(!(cin >> arrivalTime >> duration)) //this loop ensures that only integers are input until EOF (CTRL + D in linux, CTRL + Z in windows_shell/cmd)
	    {

            if (cin.eof()) //sets bln to false when EOF was entered
            {
                bln = false;
                break;
            }

		    cin.clear(); //flush errors from cin so we can accept new values
		    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore values infinitely until we see a newline (newline == enter)
		    cout << "Invalid input.  Try again: ";

	    }

    	if(bln==false) //breaks the loop when EOF was entered
    	{
         	break;
      	}

		//cout << "currently enqueueing: arrivalTime " << arrivalTime << " and duration " << duration << " ... " << endl; //flag for current enqueue

		Event newArrivalEvent("A",arrivalTime,duration); //create a new arrival event if input was succesful and enqueue to priority queue eventListPQueue
		eventListPQueue.enqueue(newArrivalEvent);
		totalCustomers++;

      	//cout << eventListPQueue << endl; //test print queue

      	if(eventListPQueue.isEmpty() == true)//Flag letting us know PQueue is empty (should never execute)
      	{
      		cout << "isempty";
      	}

		//cout << endl <<"Please enter next input:" << endl; //asking user for next input
	}

	//cout << "All input has been enqueued" << endl; // for testing purposes

    

	// event loop
	//cout << eventListPQueue.peek() << endl; //peek the queue for testing
	//cout << eventListPQueue << endl; //test print queee

	cout << "Simulation Begins" << endl;
	while(!eventListPQueue.isEmpty())
	{
			//cout << eventListPQueue << endl; //test print queee
		try
		{
			Event newEvent = eventListPQueue.peek(); //get an event by peeking the queue
			currentTime = newEvent.getTime();

			if(newEvent.getType() == "A") //IF THE EVENT IS arrival
			{
				processArrival(newEvent, eventListPQueue,bankQueue,tellerAvailable, currentTime, totalWaitTime);
			}
			else //if the event is departure
			{
				processDeparture(newEvent, eventListPQueue,bankQueue,tellerAvailable,currentTime,totalWaitTime);
			}
		}
		catch(EmptyDataCollectionException e)
		{
			break;
		}
	}

	//Block below prints stats
    cout << "Simulation Ends" << endl<< endl << "Final Statistics:" << endl;
    cout << "\tTotal number of people processed:  " << totalCustomers << endl;
    cout << "\tAverage amount of time spent waiting: " << averageTime(totalWaitTime,totalCustomers);


	// for testing purposes only
	//cout << eventListPQueue << endl;
}

//main just calls simulate
int main(){

	simulate();

	return 0;
}
