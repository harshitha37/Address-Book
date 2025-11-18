#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#include "contact.h"
#include "file.h"
#include "populate.h"

/*
Name : Harshitha Reddy Kothakapu
Date of submission : 16.11.2025
Project : Address book project in C
*/

int check_phone(char *phone, AddressBook *addressBook){
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(phone,addressBook -> contacts[i].phone)==0){
            return 1;
        }
    }
    return 0;
}

int check_email(char *email, AddressBook *addressBook){
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(email,addressBook -> contacts[i].email)==0){
            return 1;
        }
    }
    return 0;
}

void listContacts(AddressBook *addressBook) 
{
    if(addressBook -> contactCount == 0){
        printf("No contacts to display.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-30s\n","SNo.","Name","Phone","Email");
    printf("----------------------------------------------------------\n");
    
    for(int i=0;i<addressBook->contactCount;i++){
        printf("%-5d %-20s %-15s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    printf("----------------------------------------------------------\n");
    printf("Total contacts: %d\n", addressBook->contactCount);
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    if(addressBook -> contactCount >= MAX_CONTACTS){
        printf("Address Book full!\n");
        return;
    }

    char name[200];
    char phone[200];
    char email[200];
    printf("Enter the name : \n");
    scanf(" %[^\n]", name);
    int res;

    do
    {
        printf("Enter the phone number : \n");
        scanf(" %[^\n]", phone);

        res = check_phone(phone, addressBook);
        if(res==1){
            printf("Phone number already exists!\n");
        }
    } while (res == 1);

    
    do{
        printf("Enter the email id : \n");
        scanf(" %[^\n]", email);

        res = check_email(email, addressBook);
        if(res == 1){
            printf("Email id already exists!\n");
        }
    }while (res == 1);

    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);

    (addressBook->contactCount)++;
    printf("Contact added successfully.\n");
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int option,flag=0;
    char name[200];
    char mail[200];
    char number[200];
    printf("1. search by name\n2. search by phone\n3. search by email\n");
    printf("Enter the option: ");
    scanf("%d",&option);

    switch(option){
        case 1:
            if (addressBook->contactCount <= 0) {
                printf("No contacts available.\n");
                return;
            }
            printf("Enter the name : ");
            scanf(" %[^\n]", name);
            for(int i=0; i<addressBook->contactCount; i++){
                if(strcmp(name, addressBook->contacts[i].name) == 0){
                    flag=1;
                    printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                }
            }
            if(flag==0){
                printf("\nName not found.\n");
            }
            break;
        case 2:
            if (addressBook->contactCount <= 0) {
                printf("No contacts available.\n");
                return;
            }
            printf("Enter the number : ");
            scanf(" %[^\n]", number);
            for(int i=0; i<addressBook->contactCount; i++){
                if(strcmp(number, addressBook->contacts[i].phone) == 0){
                    flag=1;
                    printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                }
            }
            if(flag==0){
                printf("\nNumber not found.\n");
            }
            break;
        case 3:
            if (addressBook->contactCount <= 0) {
                printf("No contacts available.\n");
                return;
            }
            printf("Enter the email : ");
            scanf(" %[^\n]", mail);
            for(int i=0; i<addressBook->contactCount; i++){
                if(strcmp(mail,addressBook->contacts[i].email) == 0){
                    flag=1;
                    printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                }
            }
            if(flag==0){
                printf("\nEmail not found.\n");
            }
            break;
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int option,index = -1,choice;
    char name[200];
    char mail[200];
    char number[200];
    printf("1. select by name\n2. select by ph no\n3. select by email id\n");
    printf("Enter the option : ");
    scanf("%d",&option);
    listContacts(addressBook);
    switch(option)
    {
        case 1 :
            if (addressBook->contactCount <= 0) {
                printf("No contacts available.\n");
                return;
            }
            printf("Enter the name : ");
            scanf(" %[^\n]",name);
                for(int i = 0; i < addressBook -> contactCount; i++)
                {
                    if(strcmp(name,addressBook -> contacts[i].name) == 0)
                    {
                        printf("%d %s %s %s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    }
                }
            printf(" Enter the index : ");
            scanf("%d", &index);
            if(index != -1)
            {
                printf("1.Edit name\n2.Edit ph no\n3.Edit mail\n4.Edit all details\n");
                printf("enter the choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1 :
                        printf("Enter the new name : ");
                        scanf(" %[^\n]",name);
                        strcpy(addressBook->contacts[index].name,name);
                        break;
                    case 2 :
                        printf("Enter the new number : ");
                        scanf(" %[^\n]",number);
                        strcpy(addressBook->contacts[index].phone,number);
                        break;
                    case 3 :
                        printf("Enter the new email : ");
                        scanf(" %[^\n]",mail);
                        strcpy(addressBook->contacts[index].email,mail);
                        break;
                    case 4 :
                        printf("Enter the new name : ");
                        scanf(" %[^\n]",name);
                        strcpy(addressBook->contacts[index].name,name);

                        printf("Enter the new number : ");
                        scanf(" %[^\n]",number);
                        strcpy(addressBook->contacts[index].phone,number);
                        
                        printf("Enter the new mail : ");
                        scanf(" %[^\n]",mail);
                        strcpy(addressBook->contacts[index].email,mail);
                        break;
                    default : 
                        printf("Invalid choice!\n");
                        break;
                }
            }else{
                printf("Name not found!\n");
            }
            break;
        case 2 :
            if (addressBook->contactCount <= 0) {
                printf("No contacts available.\n");
                return;
            }
            printf("Enter the phone number : ");
            scanf(" %[^\n]",number);
                for(int i = 0; i < addressBook -> contactCount; i++)
                {
                    if(strcmp(number,addressBook -> contacts[i].phone) == 0)
                    {
                        printf("%d %s %s %s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    }
                }
            printf(" Enter the index : ");
            scanf("%d", &index);
            if(index != -1)
            {
                printf("1.Edit name\n2.Edit ph no\n3.Edit mail\n4.Edit all details\n");
                printf("enter the choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1 :
                        printf("Enter the new name : ");
                        scanf(" %[^\n]",name);
                        strcpy(addressBook->contacts[index].name,name);
                        break;
                    case 2 :
                        printf("Enter the new number : ");
                        scanf(" %[^\n]",number);
                        strcpy(addressBook->contacts[index].phone,number);
                        break;
                    case 3 :
                        printf("Enter the new email : ");
                        scanf(" %[^\n]",mail);
                        strcpy(addressBook->contacts[index].email,mail);
                        break;
                    case 4 :
                        printf("Enter the new name : ");
                        scanf(" %[^\n]",name);
                        strcpy(addressBook->contacts[index].name,name);

                        printf("Enter the new number : ");
                        scanf(" %[^\n]",number);
                        strcpy(addressBook->contacts[index].phone,number);
                        
                        printf("Enter the new mail : ");
                        scanf(" %[^\n]",mail);
                        strcpy(addressBook->contacts[index].email,mail);
                        break;
                    default : 
                        printf("Invalid choice!\n");
                        break;
                }
            }else{
                printf("Number not found!\n");
            }
            break;
        case 3 :
            if (addressBook->contactCount <= 0) {
                printf("No contacts available.\n");
                return;
            }
            printf("Enter the email id : ");
            scanf(" %[^\n]",mail);
                for(int i = 0; i < addressBook -> contactCount; i++)
                {
                    if(strcmp(mail,addressBook -> contacts[i].email) == 0)
                    {
                        printf("%d %s %s %s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    }
                }
            printf(" Enter the index : ");
            scanf("%d", &index);
            if(index != -1)
            {
                printf("1.Edit name\n2.Edit ph no\n3.Edit mail\n4.Edit all details\n");
                printf("enter the choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1 :
                        printf("Enter the new name : ");
                        scanf(" %[^\n]",name);
                        strcpy(addressBook->contacts[index].name,name);
                        break;
                    case 2 :
                        printf("Enter the new number : ");
                        scanf(" %[^\n]",number);
                        strcpy(addressBook->contacts[index].phone,number);
                        break;
                    case 3 :
                        printf("Enter the new email : ");
                        scanf(" %[^\n]",mail);
                        strcpy(addressBook->contacts[index].email,mail);
                        break;
                    case 4 :
                        printf("Enter the new name : ");
                        scanf(" %[^\n]",name);
                        strcpy(addressBook->contacts[index].name,name);

                        printf("Enter the new number : ");
                        scanf(" %[^\n]",number);
                        strcpy(addressBook->contacts[index].phone,number);
                        
                        printf("Enter the new mail : ");
                        scanf(" %[^\n]",mail);
                        strcpy(addressBook->contacts[index].email,mail);
                        break;
                    default : 
                        printf("Invalid choice!\n");
                        break;
                }
            }else{
                printf("Name not found!\n");
            }
            break;
        default :
            printf("Invalid option\n");
            break;
    }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int option,index = -1;
    char name[200];
    char mail[200];
    char number[200];
    printf("1. select by name\n2. select by ph no\n3. select by email id\n");
    printf("Enter the option : ");
    scanf("%d",&option);
    if(addressBook->contactCount==0){
        printf("No contacts available\n");
        return;
    }
    switch(option)
    {
        case 1 :
            printf("Enter the name : ");
            scanf(" %[^\n]",name);
                for(int i = 0; i < addressBook -> contactCount; i++){
                    if(strcmp(name,addressBook -> contacts[i].name) == 0)
                    {
                        printf("%d %s %s %s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    }
                }
            printf(" Enter the index : ");
            scanf("%d", &index);
            if(index<0 || index >=addressBook->contactCount){
                printf("Invalid index!\n");
                return;
            }
            for(int i=index; i<addressBook->contactCount - 1 ; i++){
                addressBook->contacts[i] = addressBook->contacts[i+1];
            }
            (addressBook->contactCount)--;
            break;
        case 2 :
            printf("Enter the phone number : ");
            scanf(" %[^\n]",number);
                for(int i=0; i<addressBook -> contactCount; i++){
                    if(strcmp(number,addressBook -> contacts[i].phone) == 0){
                        printf("%d %s %s %s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    }
                }
            
            printf(" Enter the index : ");
            scanf("%d", &index);
            if(index<0 || index >=addressBook->contactCount){
                printf("Invalid index!\n");
                return;
            }
            for(int i=index; i<addressBook->contactCount; i++){
                addressBook->contacts[i] = addressBook->contacts[i+1];
            }
            (addressBook->contactCount)--;
            break;
        case 3 :
            printf("Enter the email id : ");
            scanf(" %[^\n]",mail);
                for(int i=0; i<addressBook -> contactCount; i++){
                    if(strcmp(mail,addressBook -> contacts[i].email) == 0){
                        printf("%d %s %s %s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    }
                }
            printf(" Enter the index : ");
            scanf("%d", &index);
            if(index<0 || index >=addressBook->contactCount){
                printf("Invalid index!\n");
                return;
            }
            for(int i=index; i<addressBook->contactCount; i++){
                addressBook->contacts[i] = addressBook->contacts[i+1];
            }
            (addressBook->contactCount)--;
            break;
        default :
            printf("Invalid option\n");
            break;
    }
}
