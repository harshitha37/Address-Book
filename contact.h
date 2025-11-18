#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[200];
    char phone[200];
    char email[200];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
