 /*
    File: program3_dm1478.cpp

    Author: Dylan Messerly
    Date: 6/24/2020
    Assignment Number: 3
    CS 2308.501 Summer 2020
    Instructor: Dr. Palacios

    Description: A password change utility program that displays the
    criteria for a new password and lets the user know if the password has
    successfully changed or if not changed, then the program displays
    the first error that occured.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "PasswordManager.h"

using namespace std;

const int NUM_USERS = 3;

void displayRequirements( );
void readFile( ifstream &fin, PasswordManager objectArr[] );
int searchUsername( string username, PasswordManager objectArr[] );

int main ( )
{
    int user; // index value of the user's info

    string username, // takes user's input for username
           oldPasswrd, // takes user's input for old password
           newPasswrd; // takes user's input for new password

    bool validUsername = true, // verifies validity of typed username
         validPassword, // verifies validity of old password
         criteriaMet; // verifies if new password meets criteria

    PasswordManager objectArr[NUM_USERS];

    ifstream fin;
    fin.open("passwords.txt");

    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        return 1;
    }

    readFile( fin, objectArr );

    fin.close( );

    displayRequirements( );

    cin >> username;

    user = searchUsername( username, objectArr );

    if ( user > NUM_USERS || user < 0 )
            validUsername = false;

    cout << endl << "Please enter your old password: ";
    cin >> oldPasswrd;

    validPassword = ( (objectArr+user)->authenticate(oldPasswrd) );

    cout << endl << "Please enter your new password: ";
    cin >> newPasswrd;
    cout << endl;

    if ( validPassword == true )
        criteriaMet = (objectArr+user)->setNewPassword(newPasswrd);

    if ( validUsername == false )
        cout << "Username is invalid, password not changed." << endl;
    else if ( validPassword == false )
        cout << "Old password is incorrect." << endl;
    else if ( criteriaMet == false )
        cout << "New password does not meet criteria." << endl;
    else
    {
        cout << "Password has been successfully changed for user name: "
             << (objectArr+user)->getUsername() << endl;

        fstream fout;
        fout.open("passwords.txt");

        for ( int i= 0; i < NUM_USERS; i++ )
        {
            fout << (objectArr+i)->getUsername() << " " <<
                    (objectArr+i)->getEncryptedPassword() << endl;
        }

        fout.close();
    }
    return 0;
}

/*
readFile: reads contents of the passwords.txt file

parameters: &fin- needed to read the input file's content
            objectArr[] - needed to store the file's contents read

returns: nothing
*/
void readFile( ifstream &fin, PasswordManager objectArr[] )
{
    string id,
           passwrd;
    int i = 0;

    while (fin >> id)
    {
        fin >> passwrd;

        (objectArr+i)->setUsername(id);
        (objectArr+i)->setEncryptedPassword(passwrd);
        i++;
    }
}

/*
displayRequirements: displays the criteria for the new password and prompts
                     the user for username

parameters: none

retuns: nothing
*/
void displayRequirements( )
{
    cout << "Password requirements: " << endl
         << "1. Must be a minimum of 8 characters" << endl
         << "2. Must contain at least 1 uppercase letter" << endl
         << "3. Must contatin at least 1 lowercase letter" << endl
         << "4. Must contatin at least 1 digit" << endl << endl

         << "Please enter your username: ";
}

/*
searchUsername: searches for the correct username's index value or returns an
                invalid value to let the user know of the error

parameters: username - needed to search for the correct user's index
            objectArr[] - holds the correct usernames and will be used to
                          check for valid username and index

returns: the index value of the user if found, else returns -1
*/
int searchUsername( string username, PasswordManager objectArr[] )
{
    int user = -1;

    for ( int i = 0; i < NUM_USERS; i++ )
    {
        if ( (objectArr+i)->getUsername() == username )
            user = i;
    }
    return user;
}