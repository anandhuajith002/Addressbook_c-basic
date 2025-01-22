#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>
#include "contact.h"
#include "functions.h"

int search_name(AddressBook* addressBook,char ser_name[],int index[])
{
    int flag=0;
    if(validate_name(ser_name))
    {
        int x=0;
        int count=addressBook->contactCount;
        for(int i=0; i<count; i++)
        {
            if(strstr(addressBook->contacts[i].name,ser_name)!=NULL)
            {
                flag=1;
                printf("%d",i);
                index[x]=i;
                x++;
            }
        }
        if(flag==0)
            return -1;
        return x;
    }
    else
    {
        return -2;
    }

}
int search_phone(AddressBook* addressBook,char ser_phone[],int index[])//
{
    int flag=0; //
    if(validate_phone(ser_phone))
    {
        int x=0; //
        int count= addressBook->contactCount;
        for(int i=0; i<count; i++)
        {
            // if(!strcmp(addressBook->contacts[i].phone,ser_phone))
            if(strstr(addressBook->contacts[i].phone,ser_phone)!=NULL)
            {
                // return i;
                flag=1;
                printf("%d",i);
                index[x]=i;
                x++;

            }
        }
        if(flag==0)
            return -1;
        return x;
    }
    else
    {
        return -2;
    }

}
int search_email(AddressBook* addressBook,char ser_email[],int index[])
{
    int flag=0;
    if(validate_email(ser_email))
    {
        int x=0;
        int count= addressBook->contactCount;
        for(int i=0; i<count; i++)
        {
            // if(!strcmp(addressBook->contacts[i].email,ser_email))
            if(strstr(addressBook->contacts[i].email,ser_email)!=NULL)
            {
                // return i;
                flag=1;
                printf("%d",i);
                index[x]=i;
                x++;
            }
        }
        if(flag==0)
            return -1;
        return x;
    }
    else
    {
        return -2;
    }

}
void print_details(AddressBook* addressBook,int i)
{
    if(i==-1)
    {
        printf("Invalid details\n");
        return;
    }
    // printf("The details are :\n");
    printf("Name : %-15s",addressBook->contacts[i].name);
    printf("Phone : %10s",addressBook->contacts[i].phone);
    printf("Email : %s\n",addressBook->contacts[i].email);
}
int validate_name(char name[])
{
    int i=0;

    if(name[i]=='\0')
        return 0;

    while(name[i])
    {
        if(isalpha(name[i])==0 && name[i]!=' ')
        {
            return 0;
        }
        i++;
    }
    return 1;

}
int validate_phone(char phone[])
{
    int i=0;
    while(phone[i])
    {
        if(isdigit(phone[i])==0)
        {
            return 0;
        }
        i++;
    }
    if(i!=10)
        return 0;
    return 1;

}
int validate_email(char email[])
{
    int i=0;
    int at_count = 0, dot_count = 0;
    
    if (email[i] == '\0')
        return 0;

    
    while(email[i])
    {
        if(email[i]=='@')
        {
            at_count++;
            if (at_count > 1 || i == 0)
                return 0;        
        }

        else if(email[i]=='.')
        {
            if (i == 0 || email[i - 1] == '.') 
                return 0;
            if (at_count == 1 && email[i+1] == 'c' && email[i+2]=='o' && email[i+3]=='m' )
            {
                dot_count++;

            }
        }
        else if (!isalnum(email[i]) && email[i] != '_' && email[i] != '-' && email[i] != '+')
        {
            if (at_count == 0) // Invalid character before '@'
                return 0;
            else if (at_count == 1 && !isalnum(email[i]) && email[i] != '-') // Invalid character in domain
                return 0;
        }
        i++;
    }
    if(at_count!=1 || dot_count==0 )
    {
        return 0;
    }
    return 1;

}
void edit_details(AddressBook* addressBook,int i)
{
    printf("Enter what you want to edit :\n");
    printf("1.Name\n2.Phone\n3.Email\n4.All three\n");
    int choice;
    printf("Enter the choice: ");
    scanf("%d",&choice);
    char name[50],phone[20],email[50];

    switch(choice)
    {
        case 1:
        llname:
            printf("Enter the new name : ");
            scanf(" %[^\n]",name);
            if(validate_name(name))
                strcpy(addressBook->contacts[i].name,name);
            
            else
            {
                printf("Entered name is not valid\n");
                goto llname;
            }
            break;
        case 2:
        llphone:
            printf("Enter the new phone number : ");
            scanf(" %[^\n]",phone);
            if(validate_phone(phone))
                strcpy(addressBook->contacts[i].phone,phone);
            else
            {
                printf("Entered phone number is not valid\n");
                goto llphone;
            }
            break;
        case 3:
        llemail:
            printf("Enter the new email : ");
            scanf(" %[^\n]",email);
            if(validate_email(email))
                strcpy(addressBook->contacts[i].email,email);
            else
            {
                printf("Entered email is not valid\n");
                goto llemail;
            }
            break;
        case 4:

        lllname:
            printf("Enter the new name : ");
            scanf(" %[^\n]",name);
            if(validate_name(name))
                strcpy(addressBook->contacts[i].name,name);
            
            else
            {
                printf("Entered name is not valid\n");
                goto lllname;
            }


        lllphone:
            printf("Enter the new phone number : ");
            scanf(" %[^\n]",phone);
            if(validate_phone(phone))
                strcpy(addressBook->contacts[i].phone,phone);
            else
            {
                printf("Entered phone number is not valid\n");
                goto lllphone;
            }


        lllemail:
            printf("Enter the new email : ");
            scanf(" %[^\n]",email);
            if(validate_email(email))
                strcpy(addressBook->contacts[i].email,email);
            else
            {
                printf("Entered email is not valid\n");
                goto lllemail;
            }
            break;
    }
    printf("The edited details are :\n");
    print_details(addressBook,i);
}
void sort_name(AddressBook *addressBook)
{
    int len=addressBook->contactCount;
    int min_i;
    for(int i=0;i<len-1;i++)
    {
        min_i=i;
        for(int j=i+1;j<len;j++)
        {
            if(strcmp(addressBook->contacts[min_i].name,addressBook->contacts[j].name)>0)
            {
                min_i=j;
            }
        }
        swap(&(addressBook->contacts[i]),&(addressBook->contacts[min_i]));

    }
}
void sort_phone(AddressBook *addressBook)
{
    int len=addressBook->contactCount;
    int min_i;
    for(int i=0;i<len-1;i++)
    {
        min_i=i;
        for(int j=i+1;j<len;j++)
        {
            if(strcmp(addressBook->contacts[min_i].phone,addressBook->contacts[j].phone)>0)
            {
                min_i=j;
            }
        }
        swap(&(addressBook->contacts[i]),&(addressBook->contacts[min_i]));

    }

}
void sort_email(AddressBook *addressBook)
{
    int len=addressBook->contactCount;
    int min_i;
    for(int i=0;i<len-1;i++)
    {
        min_i=i;
        for(int j=i+1;j<len;j++)
        {
            if(strcmp(addressBook->contacts[min_i].email,addressBook->contacts[j].email)>0)
            {
                min_i=j;
            }
        }
        swap(&(addressBook->contacts[i]),&(addressBook->contacts[min_i]));

    }
}
void swap(Contact *c1,Contact *c2)
{
    Contact temp;
    temp=*c1;
    *c1=*c2;
    *c2=temp;
}
void display_all(AddressBook *addressBook)
{
    int len=addressBook->contactCount;
    char name[50],phone[20],email[50];   
    printf("The contact list is : \n");
    for(int i=0;i<len;i++)
    {
        strcpy(name,addressBook->contacts[i].name);
        strcpy(phone,addressBook->contacts[i].phone);
        strcpy(email,addressBook->contacts[i].email);
        printf("%3d -> Name : %-15s   Phone : %10s   email : %s\n",i+1,name,phone,email);

    }
}
void delete_details(AddressBook *addressBook,int i) 
{
    int len=addressBook->contactCount;
    for(int j=i+1;j<len;j++)
    {
        addressBook->contacts[j-1]=addressBook->contacts[j];
    }
    addressBook->contactCount--;
}
int duplicate_phone(AddressBook *addressBook,char phone[])
{
    int count= addressBook->contactCount;

    for(int i=0; i<count; i++)
    {
        if(strcmp(addressBook->contacts[i].phone,phone)==0)
        {
            return 1;
        }
    }
    return 0;

}
int duplicate_email(AddressBook *addressBook,char email[])
{
    int count= addressBook->contactCount;

    for(int i=0; i<count; i++)
    {
        if(strcmp(addressBook->contacts[i].email,email)==0)
        {
            return 1;
        }
    }
    return 0;

}