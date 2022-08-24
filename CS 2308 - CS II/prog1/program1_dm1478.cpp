 /*
    File: program1_dm1478.cpp

    Author: Dylan Messerly
    Date: 6/8/2020
    Assignment Number: 1
    CS 2308.501 Summer 2020
    Instructor: Dr. Palacios

    This program takes product orders based on this menu,  produces each
    order’s total, and summarizes the end-of-day information.
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct menuItem
{
    string description;
    double price;
    int timesOrdered;
};

const int NUM_ITEMS = 6;

void displayMenu( menuItem itemList[] );
double orderTaker( menuItem itemList[] );
int calculations( menuItem itemList[] );

int main ( )
{
    const double TAX_RATE = .0825;

    int mostOrdered;     // used to determine the item ordered most frequent

    double tax,         // calculates the tax
           subTotal,    // holds the subtotal calculated by the function
           orderTotal,  // adds the tax and the subtotal for the order
           grandTotal;  // adds the grand total for the day

    char command;       // used to enter new order or exit menu

    menuItem itemList[NUM_ITEMS]; // the array of type menuItem to
                                  //  store the items info

    itemList[0] = {"Rolex Watch    ", 1099, 0};
    itemList[1] = {"MacBook Pro    ", 1299, 0};
    itemList[2] = {"Men's Cufflinks", 499, 0};
    itemList[3] = {"iPad Pro 11-in ", 799, 0};
    itemList[4] = {"Ladies Ring    ", 999, 0};
    itemList[5] = {"Watch S4       ", 399, 0};

    do
    {
        displayMenu( itemList );
        subTotal = orderTaker( itemList );

        tax = subTotal * TAX_RATE;
        orderTotal = subTotal + tax;

        cout << "Subtotal...$ " << subTotal << endl
             << "Tax........$ " << tax << endl
             << "Total......$ " << orderTotal << endl << endl

             << "Please enter 'N' to take a new order and 'E' to exit: ";

        do     // do while used to make sure the user inputs valid command
        {cin >> command;

            if ( command != 'N' && command != 'n' && command != 'E'
                && command != 'e' )
                cout << "Error, please input valid command: ";

        }while ( command != 'N' && command != 'n' && command != 'E'
                && command != 'e' );

        grandTotal += orderTotal;

    }while ( command == 'N' || command == 'n' );

    mostOrdered = calculations ( itemList );

    cout << "*** End of day:" << endl
         << "Total sales: $" << grandTotal << endl
         << "Item ordered most often: " << itemList[mostOrdered].description
         << " was purchased " << itemList[mostOrdered].timesOrdered
         << " time(s)";

    return 0;
}

/*
function displayMenu: Displays the menu for the customer

parameter menuItem itemList: this array parameter is needed to provide the names
            and prices of the items for the menu.

returns: Nothing, it displays the menu.
*/

void displayMenu( menuItem itemList[NUM_ITEMS] )
{
    cout << fixed << setprecision(2);

        for (int i= 0; i< NUM_ITEMS; i++)
        {
            cout << "[" <<  i + 1 << "] " << itemList[i].description
                 << setw(5) << "$" << setw(7) << itemList[i].price << endl;
        }

    cout << "Input the item number for the order, 0 to quit " << endl;
}

/*
function orderTaker: Takes the customer's input and calculates subtotal

parameter menuItem itemList: this array parameter is needed to calculate the
            price of the item and also to increment the number of times
            the item is ordered.

returns: the subtotal for the order and also increments the number of times the
        item is ordered.

*/

double orderTaker( menuItem itemList[NUM_ITEMS] )
{
    int itemNumber;
    double subTotal = 0;

    while ( itemNumber != 0 )
    {
        cin >> itemNumber;

            if ( itemNumber > NUM_ITEMS || itemNumber < 0 )
                cout << "Error: There is no item " << itemNumber << "." << endl
                     << "Processing other items..." << endl;

        int i = itemNumber - 1;

        itemList[i].timesOrdered += 1;

        subTotal += itemList[i].price;

    }

    return subTotal;
}

/*
function calculations: this function is used to calculate the item that has
            been ordered the most for the day.

parameter menuItem itemList: this array is used to determine the item in the
            array that was ordered most and stores it.

returns: the position of the item in the array that was ordered most.

*/

int calculations( menuItem itemList[NUM_ITEMS] )
{
    int highest = 0;

    for ( int i = 0; i < NUM_ITEMS; i++)
        if ( itemList[highest].timesOrdered < itemList[i].timesOrdered )
            highest = i;

    return highest;
}
