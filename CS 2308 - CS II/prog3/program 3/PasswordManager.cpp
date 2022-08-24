/*
    File: PasswordManager.cpp

    Author: Dylan Messerly
    Date: 6/24/2020
    Assignment Number: 3
    CS 2308.501 Summber 2020
    Instructor: Dr. Palacios
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "PasswordManager.h"

using namespace std;

void PasswordManager::setUsername( string storedUsername )
{
    username = storedUsername;
}

string PasswordManager::getUsername() const
{
    return username;
}

void PasswordManager::setEncryptedPassword( string storedPassword )
{
    password = storedPassword;
}

string PasswordManager::getEncryptedPassword() const
{
    return password;
}

bool PasswordManager::setNewPassword( string typedNewPassword)
{
        bool valid = true;
        if (PasswordManager::meetsCriteria(typedNewPassword))
                password = PasswordManager::encrypt(typedNewPassword);
        else
            valid = false;

    return valid;
}

bool PasswordManager::authenticate( string typedPassword )
{
    bool authenticated = true;

    string encryptedPassword = PasswordManager::encrypt(typedPassword);

    if (encryptedPassword != password)
        authenticated = false;

    return authenticated;
}

string PasswordManager::encrypt( string passwrd )
{
    for (int i = 0; i< passwrd.length(); i++)
    {
      passwrd[i] = ((passwrd[i] - 33) + 25) %94 +33;
    }
    return passwrd;
}

bool PasswordManager::meetsCriteria ( string typedPassword )
{
    bool valid = false,
         upper = false,
         lower = false,
         digit = false,
         length = false;

    for (int i = 0; i< typedPassword.length(); i++)
    {
        if (isupper(typedPassword[i]))
             upper = true;

        if (islower(typedPassword[i]))
            lower = true;

        if (isdigit(typedPassword[i]))
            digit = true;
    }

    if ( typedPassword.length() >= 8)
        length = true;

    if ( upper == true && lower == true && digit == true && length == true)
        valid = true;

    return valid;
}
