#include <stdio.h>
#include<string.h>
#include "file.h"
#include "functions.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr=fopen("contacts.csv","w");
    int len=addressBook->contactCount,j;
    char name[50],phone[20],email[50];

    fprintf(fptr,"#%d\n",addressBook->contactCount);
    for(int i=0;i<len;i++)
    {
        strcpy(name,addressBook->contacts[i].name);
        strcpy(phone,addressBook->contacts[i].phone);
        strcpy(email,addressBook->contacts[i].email);

        fprintf(fptr,"%s,%s,%s\n",name,phone,email);

        // j=0;
        // while(name[j]!='\0')
        // {
        //     fputc(name[j],fptr);
        //     j++;
        // }
        // fputc(',',fptr);

        // j=0;
        // while(phone[j]!='\0')
        // {
        //     fputc(phone[j],fptr);
        //     j++;
        // }
        // fputc(',',fptr);

        // j=0;
        // while(email[j]!='\0')
        // {
        //     fputc(email[j],fptr);
        //     j++;
        // }
        // fputc('\n',fptr);
    }  
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr=fopen("contacts.csv","r");
    // char ch=fgetc(fptr);
    // int i=0,col=0,x=0;
    char name[50],phone[20],email[50];
    if(fptr == NULL)
    {
        printf("File not opened\n");
        return;
    }


    fscanf(fptr,"#%d\n", &addressBook->contactCount);
    // printf("%d\n", addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",name,phone,email);
        strcpy(addressBook->contacts[i].name,name);
        strcpy(addressBook->contacts[i].phone,phone);
        strcpy(addressBook->contacts[i].email,email);

    }

    // while(ch!='\n' && x <MAX_CONTACTS)
    // {

    //     i=0;
    //     while(col==0 && ch!=',' && ch != EOF)
    //     {
    //         name[i]=ch;
    //         ch=fgetc(fptr);
    //         i++; 
    //     }
    //     col++;
    //     name[i]='\0';
    //     strcpy(addressBook->contacts[x].name,name);
    //     ch=fgetc(fptr);

    //     i=0;
    //     while(col==1 && ch!=',' && ch != EOF)
    //     {
    //         phone[i]=ch;
    //         ch=fgetc(fptr);
    //         i++;
    //     }
    //     col++;
    //     phone[i]='\0';
    //     strcpy(addressBook->contacts[x].phone,phone);
    //     ch=fgetc(fptr);

    //     i=0;
    //     while(col==2 && ch!=EOF && ch!='\n' )
    //     {
    //         email[i]=ch;
    //         ch=fgetc(fptr);
    //         i++;
    //     }
    //     col=0;
    //     email[i]='\0';
    //     strcpy(addressBook->contacts[x].email,email);
    //     // print_details(addressBook,x);
    //     addressBook->contactCount++;
    //     x++;
    //     if(ch==EOF)
    //         break;
    //     ch=fgetc(fptr);
    //     if(ch==EOF)
    //         break;
        
        
    // }
    fclose(fptr);
}
