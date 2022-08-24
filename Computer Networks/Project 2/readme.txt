Name: Dylan Messerly
student id: dm1478

CS 4310 Computer Networks
Project 2

How to compile and run.

Included files: client_tcp.c, server_tcp.c, database.txt and readme.txt

Compile: gcc dm1478_client_tcp.c -o client
Compile: gcc dm1478_server_tcp.c -o server

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

ID must be 6 integer digits and score must be an integer between 0-100.

User input is checked by the program and appropriate warning messages are displayed when needed.


