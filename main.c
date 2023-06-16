#include "main.h"


// Function to display the menu
void Menu(void){
    clock_t start =0 , end= 0; // To measure execution time
    double execution_time;
    int choix;
    const int maxContacts = 113;
    contact Database[maxContacts];
    // Uncomment the lines below to use a predefined test database without a file, used for test
    /*
    contact Database[6] = {
    {"Lea","FOUGERA","student",111111111},
    {"Corentin","GIGOT","student",222222222},
    {"Lea","FIGERA","student",333333333},
    {"Corentin","CUISSOT","student",444444444},
    {"Laura","FOUGERA","student",555555555},
    {"Valentin","GIGOT","student",666666666},
    };*/
    readContactsFromFile(Database,maxContacts);
    int sizeDatabase = sizeof(Database)/sizeof(Database[0]); 
do {
    printf ("-----menu-----\n");
	printf ("0-Leave the program \n");
	printf ("1-Searching for a phone number by name \n");
	printf ("2-Search for a phone number by first name\n");
	printf ("3-Searching for a name from a phone number\n");
	printf ("4-Search based on a function (Mathematics teacher, director, etc.)\n");
    printf ("5-Show the whole list\n");
	printf("\n Enter your choice:");
	scanf ("%d", &choix);
		switch(choix){
			case 0: printf ("Good bye !!\n") ;		
				break;
			case 1 : printf ("Enter the name\n") ;
                    char name[50];
                    scanf("%s",name);
                    start =clock();
                    qsort(Database, sizeDatabase, sizeof(contact), compareContacts);
                    PhoneSearch(Database, sizeDatabase, name);
                    end=clock();
                    execution_time=((double)(end - start))/CLOCKS_PER_SEC;
                    printf("Execution time: %f\n",execution_time);
				break;
			case 2: 
					printf("Enter the first name\n") ;
					char firstname[50];
                    scanf("%s",firstname);
                    start =clock();
                    qsort(Database, sizeDatabase, sizeof(contact), comparefirstname);
                    PhoneSearchfirst(Database,sizeDatabase,firstname);
                    end=clock();
                    execution_time=((double)(end - start))/CLOCKS_PER_SEC;
                    printf("Execution time: %f\n",execution_time);
				break;
			case 3 :printf("Enter the number you want to look for (without the +66): ");
                    int number;
                    scanf("%d",&number);
                    start =clock();
                    qsort(Database, sizeDatabase, sizeof(contact), compare);
                    NumberSearch(Database,sizeDatabase,number);
                    end=clock();
                    execution_time=((double)(end - start))/CLOCKS_PER_SEC;
                    printf("Execution time: %f\n",execution_time);
				break;
            case 4 : printf ("Search based on a Role (Mathematics teacher, director, etc.)\n");
                start =clock();
                search_with_fonction(Database,sizeDatabase);
                end=clock();
                    execution_time=((double)(end - start))/CLOCKS_PER_SEC;
                    printf("Execution time: %f\n",execution_time);
                break;
            case 5: printf ("Here is the whole list)\n");
                    displayFileContent(Database,sizeDatabase);
                break;
			default : printf ("Mauvaise saisie, recommencez\n") ;
			}
	}while (choix!= 0);
}


//research by family name
void PhoneSearch(contact Database[],int sizeDatabase, char* nameYouSearch){
    int start=0;
    int end = sizeDatabase-1;
    int flag=0;
    
    while(start <= end){
        int mid=(start+end)/2;
        int compareResult = strcmp(Database[mid].name, nameYouSearch);

        if (compareResult == 0){    
            flag=1;
            int left = mid - 1;
            int right = mid + 1;
            printf("Mr/Ms %s %s : +66 %d\n",Database[mid].firstname, nameYouSearch, Database[mid].phoneNumber);
            //break;
            
            //Display the contacts with the same first name BEFORE the current contact.
            while (left >= 0 && strcmp(Database[left].name, nameYouSearch) == 0) {
                printf("Mr/Ms %s %s : +66 %d\n", Database[left].firstname, nameYouSearch, Database[left].phoneNumber);
                left--;
            }
            // Display the contacts with the same first name AFTER the current contact.
            while (right < sizeDatabase && strcmp(Database[right].name, nameYouSearch) == 0) {
                printf("Mr/Ms %s %s : +66 %d\n", Database[right].firstname, nameYouSearch, Database[right].phoneNumber);
                right++;
            }

            break;
        }
        else if (compareResult < 0) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    if (flag==0){
    printf("number unfindable in the list\n");}
}

//Research by FirstName
void PhoneSearchfirst(contact Database[], int sizeDatabase, char* firstnameYouSearch) {
    int start = 0;
    int end = sizeDatabase - 1;
    int flag = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        int compareResult = strcmp(Database[mid].firstname, firstnameYouSearch);

        if (compareResult == 0) {
            flag = 1;
            int left = mid - 1;
            int right = mid + 1;
            printf("Mr/Ms %s %s : +66 %d\n", firstnameYouSearch, Database[mid].name, Database[mid].phoneNumber);

            // Display the contacts with the same name BEFORE the current contact.
            while (left >= 0 && strcmp(Database[left].firstname, firstnameYouSearch) == 0) {
                printf("Mr/Ms %s %s : +66 %d\n", firstnameYouSearch, Database[left].name, Database[left].phoneNumber);
                left--;
            }
            // Display the contacts with the same name AFTER the current contact.
            while (right < sizeDatabase && strcmp(Database[right].firstname, firstnameYouSearch) == 0) {
                printf("Mr/Ms %s %s : +66 %d\n", firstnameYouSearch, Database[right].name, Database[right].phoneNumber);
                right++;
            }

            break;
        }
        else if (compareResult < 0) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    if (flag==0){
    printf("number unfindable in the list\n");}
}

// Comparison function used by qsort to sort contacts by first name
int comparefirstname(const void* a, const void* b) {
    const contact* contactA = (const contact*)a;
    const contact* contactB = (const contact*)b;
    return strcmp(contactA->firstname, contactB->firstname);
}
// Comparison function used by qsort to sort contacts by name
int compareContacts(const void* a, const void* b) {
    const contact* contactA = (const contact*)a;
    const contact* contactB = (const contact*)b;
    return strcmp(contactA->name, contactB->name);
}
// Comparison function used by qsort to sort contacts by phone number
int compare(const void* a, const void* b)
{
    const contact* contactA = (const contact*)a;
    const contact* contactB = (const contact*)b;

    if (contactA->phoneNumber > contactB->phoneNumber)
        return 1;
    else if (contactA->phoneNumber < contactB->phoneNumber)
        return -1;
    else
        return 0;
}


int main(void){
    Menu();
}

// Function to search By Number Phone
void NumberSearch(contact Database[],int sizeDatabase, int number) {
    int compareResult;
    int start=0;
    int mid = 0;
    int end = sizeDatabase-1;
    int flag=0;
    while(start <= end){
        mid=(start+end)/2;
        compareResult=Database[mid].phoneNumber-number;
        if (compareResult==0){
            printf("Name : %s %s  +66 %d\n",Database[mid].name,Database[mid].firstname,Database[mid].phoneNumber);
            flag=1;
            break;
        }
        else if (compareResult < 0){
            start = mid +1;
        }
        else { end = mid -1;}
    }
    if (flag==0){
    printf("number unfindable in the list\n");}
}

//Display all database data
void displayFileContent(contact contacts[], int maxContacts) {
    for (int i = 0; i < maxContacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Firstname: %s\n", contacts[i].firstname);
        printf("Name: %s\n", contacts[i].name);
        printf("Function: %s\n", contacts[i].function);
        printf("Phone Number: +66 %d\n", contacts[i].phoneNumber);
        printf("-------------------\n");
}
}

// Put data into an array 
void readContactsFromFile(contact contacts[], int maxContacts){
    FILE* file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }
    int i = 0;
    while (i < maxContacts){
    fscanf(file, "%[^,],%[^,],%[^,],%d\n",contacts[i].firstname, contacts[i].name, contacts[i].function, &contacts[i].phoneNumber);
    i++;
    }
    fclose(file);
}

// Function to Research by Roles
void search_with_fonction(contact Database[], int sizeDatabase){
    int choix;
    printf("choose the Role of the person you are looking for : \n");
    printf("0.Student \n");
    printf("1.Administrator \n");
    printf("2.Professor_of_Language \n");
    printf("3.Professor_of_Physics   \n");
    printf("4.Professor_of_Math \n");
    printf("5.Professor_of_History \n");
    printf("6.leave\n");
    printf("enter your choose :\n");
    scanf("%d", &choix);
        switch (choix){
            case 0 : printf("here is the list of students\n");
                for (int i=0; i<sizeDatabase ;i++){
                     if (strcmp("Student", Database[i].function)==0){
                       printf("%s %s %s +66 %d\n",Database[i].name, Database[i].firstname,Database[i].function,Database[i].phoneNumber);
                     }     
                }
            break;
            case 1 : printf("here is the list of administrator\n");
            for (int i=0; i<sizeDatabase ;i++){
                     if (strcmp("Administrator", Database[i].function)==0){
                       printf("%s %s %s +66 %d\n",Database[i].name, Database[i].firstname,Database[i].function,Database[i].phoneNumber);
                     }     
                }
            break;
            case 2 : printf("here is the list of Professor_of_language\n");
            for (int i=0; i<sizeDatabase ;i++){
                     if (strcmp("Professor_of_language", Database[i].function)==0){
                       printf("%s %s %s +66 %d\n",Database[i].name, Database[i].firstname,Database[i].function,Database[i].phoneNumber);
                     }     
                }
            break;
            case 3 : printf("here is the list of Professor_of_Physique\n");
            for (int i=0; i<sizeDatabase ;i++){
                     if (strcmp("Professor_of_Physics", Database[i].function)==0){
                       printf("%s %s %s +66 %d\n",Database[i].name, Database[i].firstname,Database[i].function,Database[i].phoneNumber);
                     }     
                }
            break;
            case 4 : printf("here is the list of Professor_of_Math\n");
            for (int i=0; i<sizeDatabase ;i++){
                     if (strcmp("Professor_of_Math", Database[i].function)==0){
                       printf("%s %s %s +66 %d\n",Database[i].name, Database[i].firstname,Database[i].function,Database[i].phoneNumber);
                     }     
                }
            break;
            case 5 : printf("here is the list of Professor_of_History\n");
            for (int i=0; i<sizeDatabase ;i++){
                     if (strcmp("Professor_of_History", Database[i].function)==0){
                       printf("%s %s %s +66 %d\n",Database[i].name, Database[i].firstname,Database[i].function,Database[i].phoneNumber);
                     }     
                }
            break;
            case 6 : printf("good bye !\n");
            break;
            default: printf("error\n");
        }
Menu();
}