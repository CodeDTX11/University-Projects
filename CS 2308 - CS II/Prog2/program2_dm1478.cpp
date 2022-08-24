 /*
    File: program2_dm1478.cpp

    Author: Dylan Messerly
    Date: 6/15/2020
    Assignment Number: 2
    CS 2308.501 Summer 2020
    Instructor: Dr. Palacios

    This program is used to read in a movie library from a file and display that
    info to the user using the redrbox app. The user has multiple options to
    sort or search the movie data base to see what redbox has to offer. After
    the user is done they can promptly exit the program.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_MOVIES = 100;

struct movieInfo
{
    string id,
           title,
           actor1,
           actor2;

    int yearReleased;

    double rating;

};

void readData( ifstream &fin, movieInfo movieLibrary[],
               int &movieCount );
void displayMenu( );
void titleSort( movieInfo movieLibrary[], int movieCount );
void ratingSort( movieInfo movieLibrary[], int movieCount );
void displayChoice( movieInfo movieLibrary[], int movieCount );
int searchById( movieInfo movieLibrary[], int movieCount );
int searchForId( movieInfo movieLibrary[], int movieCount );

int main ( )
{

    movieInfo movieLibrary[MAX_MOVIES];

    int position, // holds the index of the movie that was searched for
        choice, // user input for the menu option they want
        movieCount = 0; // counts the number of movies in the libary

    ifstream fin;
    fin.open("program2_library.txt");

    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        return 1;
    }

    readData( fin, movieLibrary, movieCount );

    do
    {
        displayMenu();

        while(!(cin >> choice) || choice > 5 || choice < 1)
        {
            cout <<"Invalid entry, try again: ";
            cin.clear();
            cin.ignore();
        }

        switch (choice)
        {
            case 1: titleSort( movieLibrary, movieCount );
                    displayChoice( movieLibrary, movieCount );

                    break;

            case 2: ratingSort( movieLibrary, movieCount );
                    displayChoice( movieLibrary, movieCount );

                    break;

            case 3: position = searchById( movieLibrary, movieCount );
                    if (position >=0)
                    {
                    cout << endl << "The movie with the id "
                         << movieLibrary[position].id << " is:" << endl
                         << movieLibrary[position].title << endl
                         << "Actors:" << endl
                         << movieLibrary[position].actor1 << endl
                         << movieLibrary[position].actor2 << endl << endl;
                    }

                    break;

            case 4: position = searchForId( movieLibrary, movieCount );
                    if (position >=0)
                    {
                       cout << "The id of " << movieLibrary[position].title
                            << " with " << movieLibrary[position].actor1
                            << " and " << movieLibrary[position].actor2
                            << " is " << movieLibrary[position].id
                            << endl << endl;
                    }

                    break;
        }
    }while( choice != 5);

    cout << "Thank you for using the redbox.com app." << endl;

    fin.close();

    return 0;
}

/*
   function definition readData: Reads the movie library info from the
            input file

   parameters: &fin - needed to access the input file
               movieLibrary - needed to initialize the array with the movie
               library data
               &movieCount- a counter needed to keep track of the size of the
               array

    returns: nothing
*/

void readData( ifstream &fin, movieInfo movieLibrary[], int &movieCount )
{

    while ( fin >> movieLibrary[movieCount].id )
    {
        fin >> ws;
        getline( fin, movieLibrary[movieCount].title );
        getline( fin, movieLibrary[movieCount].actor1 );
        getline( fin, movieLibrary[movieCount].actor2 );
        fin >> movieLibrary[movieCount].yearReleased
            >> movieLibrary[movieCount].rating;

        movieCount++;
    }
}

/*
    function display menu: Displays the redbox app menu when called

    parameters: none

    returns: nothing
*/

void displayMenu( )
{
    cout << "Menu" << endl << endl
         << "1. Display movies sorted by title" << endl
         << "2. Display movies sorted by rating" << endl
         << "3. Lookup title and actors by id" << endl
         << "4. Lookup id by title and either actor" << endl
         << "5. Quit the Program" << endl << endl
         << "Enter your choice: ";
}

/*
    function titleSort: function that sorts the movieLibrary array alphabetically
            by the movie's title

    parameters: movieLibrary - needed to access the library data
                movieCount- needed to know the size of the array

    returns: nothing
*/

void titleSort( movieInfo movieLibrary[], int movieCount )
{
    int minIndex;
    string minValue;

    for ( int start = 0; start < ( movieCount - 1); start++ )
    {
        minIndex = start;
        minValue = movieLibrary[start].title;
            for ( int index = start + 1; index < movieCount; index++)
            {
                if ( movieLibrary[index].title < minValue )
                {
                    minValue = movieLibrary[index].title;
                    minIndex = index;
                }
            }swap( movieLibrary[minIndex], movieLibrary[start] );
    }
}

/*
   function ratingSort: function that sorts the movieLibrary array
            by the movie's rating

    parameters: movieLibrary - needed to access the library data
                movieCount- needed to know the size of the array

    returns: nothing

*/

void ratingSort( movieInfo movieLibrary[], int movieCount )
{
    int startIndex;
    double highValue;

    for ( int start = 0; start < ( movieCount - 1); start++ )
    {
        startIndex = start;
        highValue = movieLibrary[start].rating;
            for ( int index = start + 1; index < movieCount; index++)
            {
                if ( movieLibrary[index].rating > highValue )
                {
                    highValue = movieLibrary[index].rating;
                    startIndex = index;
                }
            }swap( movieLibrary[startIndex], movieLibrary[start] );
    }
}

/*
   function displayChoice: function that displays the choice that the user
            has input when called, used for choices 1 & 2, will display either
            alphabetically or by rating depending on user choice

    parameters: movieLibrary - needed to access the library data
                movieCount- needed to know the size of the array

    returns: nothing
*/

void displayChoice( movieInfo movieLibrary[MAX_MOVIES], int movieCount)
{
    cout << endl;
    for ( int i = 0; i < movieCount; i++)
    {
        cout << left << setw(24) << movieLibrary[i].title  << setw(20)
             << movieLibrary[i].actor1 << setw(15)
             << movieLibrary[i].actor2 << right << setw(6)
             << movieLibrary[i].yearReleased << setw(6)
             << movieLibrary[i].rating << endl;
    }
    cout << endl;
}

/*
   function searchById: function that searches the library data base
            by the movie's Id

    parameters: movieLibrary - needed to access the library data
                movieCount- needed to know the size of the array

    returns: the index/position of the id that the user is seeking

*/

int searchById( movieInfo movieLibrary[], int movieCount )
{
    string movieId;

    int first = 0,
        middle,
        last = movieCount -1,
        position = -1;

    bool found = false;

    cout << "Enter the id of the movie: ";

    cin >> movieId;

    while (!found && first <= last)
    {
        middle = (first + last)/2;

        if (movieLibrary[middle].id == movieId)
        {
            found = true;
            position = middle;
        }
        else if (movieLibrary[middle].id > movieId )
            last = middle -1;
        else
            first = middle + 1;
    }

    if( found == false)
    {
        cout << endl << "No movie found with that id." << endl << endl;
    }
   return position;
}

/*
    function searchForId: function that searches the library data base
                for the movie's Id by the title and either of the 2 actors
                associated with the movie

    parameters: movieLibrary - needed to access the library data
                movieCount - needed to know the size of the array

    returns: the index/position of the id that the user is seeking

*/

int searchForId( movieInfo movieLibrary[], int movieCount )
{
    int index = 0;
    int position = -1;

    bool found = false;

    string searchTitle,
           searchActor;

    cout << "Enter the title: ";
    cin >> ws;
    getline(cin, searchTitle);
    cout << "Enter either actor: ";
    cin >> ws;
    getline(cin, searchActor);

    while ( index < movieCount && !found )
    {
        if( movieLibrary[index].title == searchTitle &&
            movieLibrary[index].actor1 == searchActor ||
            movieLibrary[index].actor2 == searchActor )
        {
                found = true;
                position = index;
        }
        index++;
    }
     if( found == false)
     {
        cout << endl << "No movie found with that info." << endl << endl;
     }

    return position;
}
