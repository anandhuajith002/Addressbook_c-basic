#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "contact.h"

int validate_name(char name[]);
int validate_phone(char phone[]);
int validate_email(char email[]);
int search_name(AddressBook* addressBook,char ser_name[],int index[]);
int search_phone(AddressBook* addressBook,char ser_phone[],int index[]);
int search_email(AddressBook* addressBook,char ser_email[],int index[]);
void print_details(AddressBook* addressBook,int i);
void edit_details(AddressBook* addressBook,int i);
void sort_name(AddressBook *addressBook);
void sort_phone(AddressBook *addressBook);
void sort_email(AddressBook *addressBook);
void swap(Contact *c1,Contact *c2);
void display_all(AddressBook *addressBook);
void delete_details(AddressBook *addressBook,int i);
int duplicate_phone(AddressBook *addressBook,char name[]);
int duplicate_email(AddressBook *addressBook,char email[]);



#endif