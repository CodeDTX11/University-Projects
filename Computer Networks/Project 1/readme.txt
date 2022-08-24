Dylan Messerly
CS 4310 Computer Networks

How to compile and run.

Included files: client_tcp.c, server_tcp.c, database.txt and readme.txt

Compile: gcc client_tcp.c -o client
Compile: gcc server_tcp.c -o server

Run the server program first on eros: ./server
Then run the client program on zeus with a parameter: ./client eros.cs.txstate.edu

Once started the program will display menu options and the user will make integer
selection and will follow prompts until user selects 6 to exit the program. 

!!SPECIAL NOTES!!:
The folder includes a simple database.txt file witch stores one student entry per line in a string. Please use the given database.txt file.
The individual student's info has 4 fields that are seperated by spaces in the format:

ID first_name last_name score

Example format:
123456 Dylan Messerly 100

The ID entry should only be 6 digits. The program will break if anything other then 6 digits are used.
Score should be an integer between 0-100.

When adding student please follow the above format or code will break.
