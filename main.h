#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"


typedef struct contact {
    char firstname[50];
    char name[50];
    char function[50];
    int phoneNumber;
}contact;

void Menu(void);
void PhoneSearch(contact Database[],int sizeDatabase, char* nameYouSearch);
void PhoneSearchfirst(contact Database[],int sizeDatabase, char* firstnameYouSearch);
int compareContacts(const void* a, const void* b);
int compare(const void *a, const void *b);
void NumberSearch(contact Database[],int sizeDatabase, int number);
int main(void);
int comparefirstname(const void* a, const void* b);
void readContactsFromFile(contact contacts[], int maxContacts);
void displayFileContent(contact contacts[], int maxContacts) ;
void search_with_fonction(contact Database[],int sizeDatabase);