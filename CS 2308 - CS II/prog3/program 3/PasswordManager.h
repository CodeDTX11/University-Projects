#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

using namespace std;


class PasswordManager
{
    public:

        void setUsername( string storedUsername );

        string getUsername() const;

        void setEncryptedPassword( string storedPassword );

        string getEncryptedPassword() const;

        bool setNewPassword( string typedNewPassword );

        bool authenticate( string typedPassword);

    private:

        string encrypt( string passwrd );

        bool meetsCriteria ( string typedPassword );

        string username;

        string password;
};

#endif // PASSWORDMANAGER_H
