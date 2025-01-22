#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "functions.h"


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    
    switch(sortCriteria)
    {
        case 1:
            sort_name(addressBook);
            printf("\n----Sorted according to Name----\n");
            display_all(addressBook);
            break;
        case 2:
            sort_phone(addressBook);
            printf("\n----Sorted according to Phone----\n");
            display_all(addressBook);
            break;
        case 3:
            sort_email(addressBook);
            printf("\n----Sorted according to Email----\n");
            display_all(addressBook);
            break;

        default :
                getchar();
                printf("\nInvalid choice. Please try again.\n");

    }
    
}
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[50],phone[20],email[50];
    int i=addressBook->contactCount++;

lname:
    printf("\nEnter the Name : ");
    scanf(" %[^\n]",name);
    if(validate_name(name))
    {
        strcpy(addressBook->contacts[i].name,name);
    }
    else
    {
        printf("Entered name is not valid\n");
        goto lname;
    }


lphone:
    printf("Enter the Phone Number : ");
    scanf(" %[^\n]",phone);
    if(validate_phone(phone))
    {
        if(duplicate_phone(addressBook,phone)==0)
        {
            strcpy(addressBook->contacts[i].phone,phone);
        }
        else
        {
            printf("\nphone number already exists!!!\n");
            goto lphone;
        }

    }
    else
    {
        printf("Entered phone number is not valid\n\n");
        goto lphone;
    }

lemail:
    printf("Enter the e-mail : ");
    scanf(" %[^\n]",email);
    if(validate_email(email))
        if(duplicate_email(addressBook,email)==0)
        {
            strcpy(addressBook->contacts[i].email,email);
        }
        else
        {
            printf("\ne-mail already exists!!!\n");
            goto lemail;
        }
    else
    {
        printf("Entered email is not valid\n\n");
        goto lemail;
    }
    

    printf("\n----New data entered----\n");
    print_details(addressBook,i);
}
int searchContact(AddressBook *addressBook,int index[]) 
{
ser:
    printf("\nEnter the search criteria:\n");
    printf("1. Based on Name\n");
    printf("2. Based on Phone \n");
    printf("3. Based on e-mail\n");
    printf("4. Goto home\n");
    printf("Enter the choice : ");

    int choice;
    scanf("%d",&choice);
    int i;
    switch (choice)
    {
        case 1:
        n_ser:
            printf("Enter the Name to be searched : ");
            char s_name[50];
            scanf(" %[^\n]",s_name);

            i=search_name(addressBook,s_name,index);
            if(i==-2)
            {
                printf("Invalid name\n");
                goto n_ser;
            }
            if(i>=-1)printf("\n----Search Result----\n");
            if(i==-1)
            {
                printf("Invalid details\n");
                return -1;
            }
            for(int j=0;j<i;j++)
            {
                printf("%d  -> ",j+1);
                print_details(addressBook,index[j]);
                printf("\n");
            }
            break;
        case 2:
        p_ser:
            printf("Enter the Phone Number to be searched : ");
            char s_phone[20];
            scanf(" %[^\n]",s_phone);

            i=search_phone(addressBook,s_phone,index);
            if(i==-2)
            {
                printf("Invalid phone number\n");
                goto p_ser;
            }
            if(i>=-1)printf("\n----Search Result----\n");
            if(i==-1)
            {
                printf("Invalid details\n");
                return -1;
            }
            for(int j=0;j<i;j++)
            {
                printf("%d.\n",j+1);
                print_details(addressBook,index[j]);
                printf("\n");
            }
            break;
        case 3:
        e_ser:
            printf("Enter the email to be searched : ");
            char s_email[50];
            scanf(" %[^\n]",s_email);

            i=search_email(addressBook,s_email,index);
            if(i==-2)
            {
                printf("Invalid e-mail\n");
                goto e_ser;
            }
            if(i>=-1)printf("\n----Search Result----\n");
            if(i==-1)
            {
                printf("Invalid details\n");
                return -1;
            }

            for(int j=0;j<i;j++)
            {  
                printf("%d.\n",j+1);
                print_details(addressBook,index[j]);
                printf("\n");
            }
            break;
        case 4:
            return -3;
        default:
            getchar();
            printf("!!!!Invalid choice. Please try again!!!!\n");
            goto ser;
    }
    return i;

}
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    printf("How would you like to find the contact to be edited :");
    int index[MAX_CONTACTS];
    int i= searchContact(addressBook,index);
    // printf("\n\n%d\n\n",i);
    int op;
    if(i==-1 || i==-3)
        return;
edit: 
    if(i>1)
    {
        printf("Select the option to edit :");
        scanf("%d",&op);
        if(op<1 || op>i)
        {
            printf("Invalid option\n");
            goto edit;
        }
        printf("\n");
        print_details(addressBook,index[op-1]);
    }
    getchar();
    printf("\nIs it the detail to be deleted: y-confirm edit & n-go home : ");
    char ch;
    scanf("%c",&ch);
    if(ch=='y')
    {
        edit_details(addressBook,index[op-1]);
    }
    else
        return;   
}
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    printf("How would you like to find the contact to be deleted :\n");
    int index[MAX_CONTACTS];
    int i= searchContact(addressBook,index);
    int op;
    if(i==-1|| i==-3)
        return;
delete:
    if(i>1)
    {
        printf("Select the option to edit :");
        scanf("%d",&op);
        if(op<1 || op>i)
        {
            printf("Invalid option\n");
            goto delete;
        }
        printf("\n");
        print_details(addressBook,index[op-1]);
    } 
    getchar();
    printf("\nIs it the detail to be deleted: y-confirm delete & n-go home :");
    char ch;
    scanf("%c",&ch);
    if(ch=='y')
    {
        delete_details(addressBook,index[op-1]);
    }
    else
        return;    
}



