/*
   File: program4_dm1478.cpp

   Author: Dylan Messerly
   Date: 6/29/2020
   Assignment Number: 4
   CS 2308.501 Summer 2020
   Instructor: Dr. Palacios

   Description: the program reads from a file the group names and number
   of guests in the groups and calculates the number of rides needed for the
   day based on the group sizes and the ride's capacity then outputs the results
   to the screen.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;

void readData(ifstream &, Queue &, double &);
void welcome (double &);
void queueCalculations ( Queue &, double , int &, int &);
void endOfDayTotals ( int, int );


const int MAX_CAP = 50; // maximum capacity the ride can hold

int main()
{
    int totalForDay = 0, // holds the total guests on the ride for the day
        ridecnt = 1; // holds the # of rides per day

    double percentCap; // holds the allowed % capacity

    Queue rideQueue;

    ifstream fin;

    fin.open("reservations.txt");

    if (!fin)
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        return 1;
    }

    readData( fin, rideQueue, percentCap );

    welcome (percentCap);

    // needed to make sure infinite loop isnt triggered with large groups
    if (!rideQueue.sizeOk(percentCap))
    {
        cout << "Error: at least one group size is too large for"
             << " current capacity";

        return -1;
    }

    queueCalculations ( rideQueue, percentCap, totalForDay, ridecnt );

    endOfDayTotals ( totalForDay, ridecnt );

    return 0;
}

/*
readData : reads the data from the given "reservations" file then inputs the
data into a linked list.

parameters: fin - needed to read the file
            rideQueue - needed to store the data in a linked list
            percentCap - needed to calculate the % capacity we are at for
            the day

returns: nothing

*/
void readData(ifstream &fin, Queue &rideQueue, double &percentCap)
{
    string grpName; // name of the group
    int grpSize; // size of the group

    fin >> percentCap;

    while (fin >> grpName)
    {
        fin >> grpSize;

        rideQueue.enqueue(grpName, grpSize);
    }

}
/*
welcome: displays the programs welcoming message to the screen as well as
the day's capacity limit

parameters: percent cap - used to display the capacity

returns: nothing

*/
void welcome ( double &percentCap )
{
    cout << "Welcome to the Twilight Zone Tower of Terror!" << endl
         << "We are currently running at " << percentCap *100 << " % capacity"
         << endl
         << "Below are the listed reservation results for today:"
         << endl << endl;
}

/*
queueCalculations: the function calculates the ride info and displays it to
the screen

parameters: rideQueue- needed to access the linked list
            percentCap - needed for capacity limit
            totalForDay - needed to increment the total guests for the ride
            ridecnt - needed to count the total # of rides per day

returns: nothing

*/
void queueCalculations ( Queue &rideQueue, double percentCap, int &totalForDay,
                         int & ridecnt)
{
    string grpName; // name of the group
    int grpSize; // size of the group

    while (!rideQueue.isEmpty())
    {
        int rideTotal = 0; // holds the total number of guests on the ride

        cout << "Ride #" << ridecnt << endl
             << "-------------" << endl;

        while (!rideQueue.isFull(percentCap, rideTotal) && !rideQueue.isEmpty())
        {
            rideQueue.dequeue( grpName, grpSize);
            cout << left << setw(10) << grpName << " " << grpSize << endl;

            rideTotal += grpSize;
        }

        totalForDay += rideTotal;

        cout << endl << "Total guests for ride #" << ridecnt << ": "
             << rideTotal << endl << endl;

        if (!rideQueue.isEmpty())
            ridecnt++;
    }
}

/*
endOfDayTotals: funtion that displays the end of day totals to the screen

parameters: totalForDay- used to display the total guests for the day
            ridecnt - used to display the # of rides for the day

returns: nothing

*/
void endOfDayTotals ( int totalForDay, int ridecnt )
{
    cout << "Total # of guests for the day: " << totalForDay << endl
         << "Total # of rides for the day:  " << ridecnt << endl;
}