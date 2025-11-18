#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    //open file
    FILE *fptr = fopen("contacts.txt","w");

    if(fptr==NULL){
        printf("Error opening file for writing.\n");
        return;
    }

    //store contactcount to file
    fprintf(fptr,"%d\n",addressBook->contactCount);

    //store all contacts in array structure
    for(int i=0;i<addressBook->contactCount;i++){
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    //close the file
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) {
    //open the file in read mode
    FILE *fptr = fopen("contacts.txt","r");

    if(fptr==NULL){
        printf("No existing contact file found.....start fresh\n");
        return;
    }

    addressBook->contactCount=0;

    
    //read the contact count
    int count;
    fscanf(fptr,"%d\n",&count);

    for(int i = 0; i<count; i++){
        if(fscanf(fptr, " %49[^,], %19[^,], %49[^\n]\n", 
                 addressBook->contacts[addressBook->contactCount].name,
                 addressBook->contacts[addressBook->contactCount].phone,
                 addressBook->contacts[addressBook->contactCount].email) == 3) 
                 {
                    addressBook->contactCount++; // Increment contact count
                    // Stop if maximum capacity reached
                    if (addressBook->contactCount >= MAX_CONTACTS)
                    {
                        break; // Exit loop
                    } 
                }
        }
    fclose(fptr);
    printf("Contacts loaded from file.\n");
}
