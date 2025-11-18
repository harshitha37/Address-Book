Project Name : Address Book in C.

Description:
A modular Address Book application written in C that allows you to **create, store, search, edit, delete, and list contacts**, all using plain text files for persistence. It is designed with separation of concerns through multiple header and source files for clarity and maintainability.

Purpose : 
- Store and manage contact information  
- Perform CRUD operations: **Create, Read, Update, Delete**  
- Save and load data using a plain text file  
- Maintain clean, modular design in C  

Files : main.c , contact.c , contact.h , populate.c , populate.h , file.c , file.h , contacts.txt

- main.c : program menu and control loop
- contact.c and contact.h : core functionality : create, search, edit, delete, list, initialise. (CRUD operations)
- file.c and file.h : persistent I/O : save and load contacts.txt
- populate.c and populate.h : dummy contacts inserted at start up.
- contacts.txt : persisted contacts file.
    **First line** : integer N (number of contacts)
    **Next N lines** : name, phone, email.

- Run the program : (terminal)
- Compile : gcc *.c
- Run : ./a.out

Author : Harshitha Reddy Kothakapu
