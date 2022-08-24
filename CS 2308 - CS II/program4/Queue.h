 /*
    File: program4_dm1478.cpp

    Author: Dylan Messerly
    Date: 6/29/2020
    Assignment Number: 4
    CS 2308.501 Summer 2020
    Instructor: Dr. Palacios

    Description: Queue class header including inline definitions.
    Used with the TowerOfTerror.cpp program.

*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Queue
{
    public:

        Queue( )
        {
            front = nullptr;
            rear = nullptr;
            numGuests = 0;
        }

        int getSizeAtFront ()
        {
            int sizeFront;

            if (!isEmpty())
                sizeFront = front->size;
            else
                sizeFront = 0;

            return  sizeFront ;
        }

        bool sizeOk ( double percentCap )
        {
            bool sizeOk = true;
            ListNode *ptr;
            ptr = front;

            while (ptr != nullptr)
            {
                int grpSize = ptr->size;

                if (grpSize > (MAX_CAP * percentCap))
                    sizeOk = false;

                ptr = ptr->next;
            }

            return sizeOk;
        }

        void enqueue (string grpName, int grpSize)
        {
            ListNode *newNode = nullptr;

            newNode = new ListNode;

            newNode->name = grpName;
            newNode->size = grpSize;
            newNode->next = nullptr;

                if (isEmpty())
                {
                    front = newNode;
                    rear = newNode;
                }
                else
                {
                    rear->next = newNode;
                    rear = newNode;
                }
            numGuests += grpSize;
        }

        void dequeue ( string &grpName, int &grpSize)
        {
            ListNode *temp;

            if ( isEmpty() )
            {
                cout << "The queue is empty.\n";
            }
            else
            {
                grpName = front->name;
                grpSize = front->size;

                temp = front;

                front = front->next;
                delete temp;

                numGuests -= grpSize;
            }
        }

        bool isEmpty ()
        {
            bool status;

            if ( numGuests > 0)
                status = false;
            else
                status = true;

            return status;
        }

        bool isFull (double percentCap, int rideTotal)
        {
            bool status;

            if ( rideTotal + getSizeAtFront() <= MAX_CAP * percentCap )
                status = false;
            else
                status = true;

            return status;
        }

        void clear ()
        {
            int grpSize;
            string grpName;

            while(!isEmpty())
                dequeue(grpName, grpSize);
        }

    private:

        struct ListNode
        {
            string name;
            int size;
            ListNode *next;
        };

        ListNode *front;

        ListNode *rear;

        int numGuests;

        const int MAX_CAP = 50;
};

#endif // QUEUE_H
