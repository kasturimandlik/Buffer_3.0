#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct phone             //structure name
{
    char phone_no[10];  // structure member
};



struct time
{
    int start_hour;
    int start_minutes;
    int end_hour;
    int end_minutes;
};

struct date
{
    int day;
    int month;
};

struct Price
{
    float price;
};

// declaring nested structure
struct booking{
    char name[50];
    char id[15];
    char courtType[50];
    struct phone p;

    struct time t;
    struct Price o;
    struct date d;
    struct booking *next;
};

struct booking *head=NULL, *newptr=NULL, *current=NULL, *previous=NULL,*tail=NULL;

void push_booking();    // push or insert function declaration
void default_booking(char name[50], char id[15], char department[50], char phone_no[10], int start_hours, int start_minutes, int end_hours, int end_minutes, float price, int day, int year);

void update_byid();     //update function declaration

void delete_byid();     // pop or delete function declaration

void search_byid();     // search function declaration
void search_byCourt();  // search function declaration

void display_booking(); // display function declaration
void display_byCourt(); // display function declaration

//Calculation Function

int Calc_End_Time(int start_hour, int hours);  //function declaration
float Calc_Total_Price(int court, int hours);  //function declaration

void main()  //main function
{
    int choice, add, update, del, search, sort, display;


    default_booking("MANASI MORE", "9021", "BASKETBALL COURT", "9875217647", 8, 00, 10, 00, 100.00, 25, 1);
    default_booking("KASTURI MANDLIK", "9059", "TENNIS COURT", "9357486214",17, 30, 19, 30, 120.00, 26, 1);
    default_booking("TWARITA GHATAGE", "9056", "BADMINTON COURT", "8459854763", 8, 00, 12, 00, 140.00, 3, 2);


    do{
    jump1: system("CLS");
    printf("\n\n\t\t\t## Welcome To KTM Sport Centre Booking System ##\n\n"); // title
    printf("\t\t\t!!! The Booking Hours is from 08:00AM to 11:00PM !!!\n\n"); // conditions
    printf("\t\t\t!!! The Last Booking Will Be At 07:00PM !!!\n\n"); // conditions
    printf("\t\t\t[***THE MAXIMUM BOOKING HOURS IS 4 HOURS and THE MINIMUM BOOKING HOURS IS 1 HOURS***]\n\n"); // conditions
    printf("\t\t\t************ MENU for BOOKING ************\n\n"); //Menu Page
    printf("\t\t\t\t1. Add New Booking Detail\n\n"); // Push or Insert a new booking details
    printf("\t\t\t\t2. Update the Booking Detail\n\n"); // Update booking details
    printf("\t\t\t\t3. Delete Booking Detail\n\n"); // Pop or Delete the booking details at beginning, by matrix id or by name
    printf("\t\t\t\t4. Search Booking Details\n\n"); // search booking details

    printf("\t\t\t\t5. Display Booking List\n\n"); // display the booking details
    printf("\t\t\t\t6. Exit the Booking System\n\n");
    printf("\t\t\t\tPlease Enter your Choice: ");
    jump2: scanf("%d", &choice);
    switch(choice)
    {
        case 1: system("CLS");
                printf("\n\nPlease select from one of the following");
                printf("\n");
                printf("\n1. Add Booking Details");
                printf("\n0. Go Back to MENU !!!");
                printf("\n");
                printf("\nEnter your choice: ");
                jump3: scanf("%d", &add);
                if (add == 1)
                {
                    push_booking();  //calling insert or push function
                }
                else if (add == 0)
                {
                    goto jump1;
                }
                else
                {
                    printf("\nIncorrect selection, Please enter again: ");
                    goto jump3;
                }
                break;

        case 2: system("CLS");
                printf("\n\nPlease select from one of the following");
                printf("\n");

                printf("\n1. Update by ID");
                printf("\n0. Go Back to MENU !!!");
                printf("\n");
                printf("\nEnter your choice: ");
                jump4: scanf("%d", &update);

                if (update == 1)
                {
                    update_byid();  //calling update function
                }
                else if (update == 0)
                {
                    goto jump1;
                }
                else
                {
                    printf("\nIncorrect selection, Please enter again: ");
                    goto jump4;
                }
                break;

        case 3: system("CLS");
                printf("\n\nPlease select from one of the following");
                printf("\n");

                printf("\n1. Delete by ID ");

                printf("\n0. Go Back to MENU !!!");
                printf("\n");
                printf("\nEnter your choice: ");
                jump5: scanf("%d", &del);

                if (del == 1)
                {
                    delete_byid();  //calling delete or pop function
                }

                else if (del == 0)
                {
                    goto jump1;
                }
                else
                {
                    printf("\nIncorrect selection, Please enter again: ");
                    goto jump5;
                }
                break;

        case 4: system("CLS");
                printf("\n\nPlease select from one of the following");
                printf("\n");

                printf("\n1. Search by ID");
                printf("\n2. Search by Type of Court");
                printf("\n0. Go Back to MENU !!!");
                printf("\n");
                printf("\nEnter your choice: ");
                jump6: scanf("%d", &search);

                if (search == 1)
                {
                    search_byid();  //calling search function
                }
                else if (search == 2)
                {
                    search_byCourt();  //calling search function
                }
                else if (search == 0)
                {
                    goto jump1;
                }
                else
                {
                    printf("\n Incorrect selection, Please enter again: ");
                    goto jump6;
                }
                break;



        case 5: system("CLS");
                printf("\n\nPlease select from one of the following");
                printf("\n");
                printf("\n1. Display all the Booking Details");
                printf("\n2. Display the Booking Details According to the Type of Court");
                printf("\n0. Go Back to MENU !!!");
                printf("\n");
                printf("\nEnter your choice: ");
                jump8: scanf("%d", &display);
                if (display == 1)
                {
                    display_booking();  //calling display function
                }
                else if (display == 2)
                {
                    display_byCourt();  //calling display function
                }
                else if (display == 0)
                {
                    goto jump1;
                }
                else
                {
                    printf("\n Incorrect selection, Please enter again: ");
                    goto jump8;
                }
                break;

        case 6: printf("\n\n\t\t\t The KTM Sport Center Booking System will EXIT !!! \n");
                break;

        default: printf("\n Incorrect selection, please enter again");
                 goto jump2;
                 break;
    }
    }while(choice != 6);
    system("CLS");
    printf("\n\n\t\t\tThank You\n\n");
}

void push_booking()  //insert or push function definition
{
    char name[50], id[15], courtType[50], phone_no[10];
    int i, j, start_hour, start_minutes, end_hour, end_minutes, court, hours, day, month;
    float price;

    printf("\n");
    printf("\t\tInsert Booking Details !!! \n");
    printf("\n");
    printf("\t\tEnter the Student Name: ");
    scanf(" %[^\n]s", &name);
    for (i = 0; i < strlen(name); i++)
    {
        name[i] = toupper(name[i]);
    }

    printf("\t\tEnter the ID: ");
    scanf(" %[^\n]s", &id);
    for (j = 0; j < strlen(id); j++)
    {
        id[j] = toupper(id[j]);
    }
    printf("\n");
    printf("\t\t\tType of Court Available");
    printf("\n");
    printf("\n\t\t 1. Basketball Court - [Rs50.00 per hour]");
    printf("\n\t\t 2. Badminton Court - [Rs70.00 per hour]");
    printf("\n\t\t 3. Tennis Court - [Rs60.00 per hour]");

    printf("\n");
    printf("\n\t\t[***THE MAXIMUM BOOKING HOURS IS 4 HOURS and THE MINIMUM BOOKING HOURS IS 1 HOURS***]");
    printf("\n");
    jump9: printf("\n\t\tEnter type of Court to book: ");
    scanf("%d", &court);
    if (court == 1)
    {
        strcpy(courtType, "BASKETBALL COURT"); //type of court
    }

    else if (court == 2)
    {
        strcpy(courtType, "BADMINTON COURT"); //type of court
    }
    else if (court == 3)
    {
        strcpy(courtType, "TENNIS COURT"); //type of court
    }

    else
    {
        printf("\n\t\tInvalid Selection !!!");
        printf("\n\t\tPlease try again !!!\n");
        goto jump9;
    }
    printf("\n");
    printf("\t\tEnter the Student Phone Number: ");
    scanf("%s", &phone_no);
    printf("\n");

    jump10: printf("\t\tEnter the Start Booking Hours [MAX 19 hours (07:00PM)] and [MIN 8 hours (08:00AM)]: ");
    scanf("%d", &start_hour);
    if (start_hour > 19 && start_hour < 8)
    {
        printf("\n\t\tKTM Sport Center CLOSED !!! \n");
        printf("\n\t\tPlease enter again. \n");
        goto jump10;
    }
    else
    {
        ;
    }
    printf("\n");
    jump11: printf("\t\tEnter the Start Booking Minutes[max 59 minutes]: ");
    scanf("%d", &start_minutes);
    if (start_minutes > 59)
    {
        printf("\n\t\tInvalid Start Minutes !!! \n");
        printf("\n\t\tPlease enter again. \n");
        goto jump11;
    }
    else
    {
        ;
    }
    printf("\n");
    jump12: printf("\t\tEnter Booking Hours [MAX 4 Hours and MIN 1 Hours]: ");
    scanf("%d", &hours);
    if (hours > 4)
    {
        printf("\n\t\tBooking Hours Over Limit !!!\n");
        goto jump12;
    }
    else if (hours < 1)
    {
        printf("\n\t\tBooking Hours Not Reach the Minimum Booking Hours !\n");
        goto jump12;
    }

    printf("\n");

    jump13: printf("\t\tEnter Day and Month (separate each input by space) for Year 2022 : ");
    scanf("%d %d", &day, &month);
    if (day > 31)
    {
        printf("\n\t\tInvalid Day !!! \n");
        goto jump13;
    }
    else
    {
        ;
    }
    if (month > 12)
        {
            printf("\n\t\tInvalid Month !!! \n");
            goto jump13;
        }
        else
        {
            ;
        }

    printf("\n");

    end_hour = Calc_End_Time(start_hour, hours);  //calling function
    end_minutes = start_minutes;

    price = Calc_Total_Price(court, hours);  //calling function

    newptr = (struct booking *)malloc(sizeof(struct booking));

    strcpy(newptr->name, name);
    strcpy(newptr->id, id);
    strcpy(newptr->courtType, courtType);
    strcpy(newptr->p.phone_no, phone_no);

    newptr->t.start_hour = start_hour;
    newptr->t.start_minutes = start_minutes;
    newptr->t.end_hour = end_hour;
    newptr->t.end_minutes = end_minutes;
    newptr->o.price = price;
    newptr->d.day = day;
    newptr->d.month = month;

    if (head == NULL)
    {
        head = newptr;
        newptr->next = NULL;
        tail=newptr;
    }
    else
    {
        tail->next = newptr;
        tail = newptr;
    }
    printf("\n\n\t\t Success");
    printf("\n\t\tPress Enter to continue");
    getch();
}

void default_booking(char name[50], char id[15], char courtType[50], char phone_no[10],int start_hour, int start_minutes, int end_hour, int end_minutes, float price, int day, int month)
{
    newptr = (struct booking *)malloc(sizeof(struct booking));
    strcpy(newptr->name, name);
    strcpy(newptr->id, id);
    strcpy(newptr->courtType, courtType);
    strcpy(newptr->p.phone_no, phone_no);

    newptr->t.start_hour = start_hour;
    newptr->t.start_minutes = start_minutes;
    newptr->t.end_hour = end_hour;
    newptr->t.end_minutes = end_minutes;
    newptr->o.price = price;
    newptr->d.day = day;
    newptr->d.month = month;

    if (head == NULL)
    {
        head = newptr;
        newptr->next = NULL;
        tail=newptr;
    }
    else
    {
        tail->next = newptr;
        tail = newptr;
    }
}


void update_byid()  //update function definition
{
    char id[15];
    int i;

if (head==NULL)
    {
        printf("\nThe list is empty, cannot be Update.");
        printf("\nPress Enter to continue.");
    }
else
{
        printf("\nEnter ID to Update: ");
scanf(" %[^\n]s", &id);

for (i = 0; i < strlen(id); i++)
        {
            id[i] = toupper(id[i]);
        }

    current=head;

        while(current->next !=NULL )
        {
            if (strcmp(current->id, id)==0)
            {
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (strcmp(current->id, id)==0)
        {
            if (current==head)
            {
                head=current->next;
                free(current);
            }
            else
            {
                previous->next=current->next;
                free(current);
            }
            printf("\nID Found !!!\n");
            printf("\n");
            push_booking();
        }
        else
        {
            printf("ID of the Student to be Update is not in the list!");
            printf("\nPress Enter to continue.");
        }
    }

    getch();
}



void delete_byid()  //delete or pop function definition
{
    char id[15];
    int i;

if (head==NULL)
    {
        printf("\nThe list is empty, cannot be delete.");
        printf("\nPress Enter to continue.");
    }
else
{
        printf("\nEnter ID to delete: ");
scanf(" %[^\n]s", &id);

for (i = 0; i < strlen(id); i++)
        {
            id[i] = toupper(id[i]);
        }

    current=head;

        while(current->next != NULL)
        {
            if (strcmp(current->id, id)==0)
            {
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (strcmp(current->id, id)==0)
        {
            if (current==head)
            {
                head=current->next;
                free(current);
            }
            else
            {
                previous->next=current->next;
                free(current);
            }
            printf("\nThe record was deleted.");
            printf("\nPress Enter to continue.");
        }
        else
        {
            printf("\nID of the Student to be deleted is not in the list!");
            printf("\nPress Enter to continue.");
        }
    }
    getch();
}




void search_byid()  //search function definition
{
    char id[15];
    int i, count=0;

if (head==NULL)
    {
        printf("\nThe list is empty, cannot be search.");
        printf("\nPress Enter to continue.");
    }
else
{
        printf("\nEnter ID to be searched: ");
scanf(" %[^\n]s", &id);
        for (i = 0; i < strlen(id); i++)
        {
            id[i] = toupper(id[i]);
        }
        printf("\n\nNo\tID\tStudent Name\t\tPhone Number\tCourt Type\t\tTime(From)\tTime(To)\tDate\t\tPrice to Pay (Rs)\n");
        printf("\n");
        for (current=head; current!=NULL; current=current->next)
        {
            if (strcmp(current->id, id)==0)
            {
                count++;
                printf("%d\t%-10s\t%-20s\t%-10s\t%-16s\t%02d:%02d\t\t%02d:%02d\t\t%02d/%02d/2021\t%.2f\n", count, current->id, current->name, current->p.phone_no, current->courtType, current->t.start_hour, current->t.start_minutes, current->t.end_hour, current->t.end_minutes, current->d.day, current->d.month, current->o.price);
                printf("\n");
            }

        }
        if (count==0)
        {
            printf("\n");
            printf("\n");
            printf("\nID of the Student to be found is not in the list!");
            printf("\nPress Enter to continue.");
        }
        else
        {
            printf("\n");
            printf("\n");
            printf("\nThe record was found.");
            printf("\nPress Enter to continue.");
        }
    }

    getch();
}

void search_byCourt()  //search function definition
{
    char courtType[50];
    int i, court, count=0;

if (head==NULL)
    {
        printf("\nThe list is empty, cannot be search.");
        printf("\nPress Enter to continue.");
    }
else
{
        printf("\n");
        printf("\t\t\tPlease select the Court to Search");
        printf("\n");
        printf("\n\t\t\t 1. Basketball Court");
        printf("\n\t\t\t 2. Badminton Court");
        printf("\n\t\t\t 3. Tennis Court");

        printf("\n");
        printf("\n\t\t\tEnter type of Court to Search: ");
        jump14: scanf("%d", &court);
        if (court == 1)
        {
            strcpy(courtType, "BASKETBALL COURT"); //type of court
        }
        else if (court == 2)
        {
            strcpy(courtType, "BADMINTON COURT"); //type of court
        }
        else if (court == 3)
        {
            strcpy(courtType, "TENNIS COURT"); //type of court
        }

        else
        {
            printf("\n Invalid Selection \n");
            goto jump14;
        }
        for (i = 0; i < strlen(courtType); i++)
        {
            courtType[i] = toupper(courtType[i]);
        }
        printf("\n\nNo\tID\tStudent Name\t\tPhone Number\tCourt Type\t\tTime(From)\tTime(To)\tDate\t\tPrice to Pay (Rs)\n");
        printf("\n");
        for (current=head; current!=NULL; current=current->next)
        {
            if (strcmp(current->courtType, courtType)==0)
            {
                count++;
                printf("%d\t%-10s\t%-20s\t%-10s\t%-16s\t%02d:%02d\t\t%02d:%02d\t\t%02d/%02d/2021\t%.2f\n", count, current->id, current->name, current->p.phone_no, current->courtType, current->t.start_hour, current->t.start_minutes, current->t.end_hour, current->t.end_minutes, current->d.day, current->d.month, current->o.price);
                printf("\n");
            }

        }
        if (count==0)
        {
            printf("\n");
            printf("\n");
            printf("\nType of Court to be found is not in the list!");
            printf("\nPress Enter to continue.");
        }
        else
        {
            printf("\n");
            printf("\n");
            printf("\nThe record was found.");
            printf("\nPress Enter to continue.");
        }
    }

    getch();
}



void display_booking()  //display function definition
{
    int i = 1;
    if (head == NULL)
    {
        printf("\n\nEmpty list");
    }
    else
    {
        printf("\n");
        printf("\t\t\t\t\t\tList Of KTM Sport Center Booking that currently be recorded\n");
        current = head;
        printf("\n\nNo.     ID\tStudent Name\t\tPhone Number\tCourt Type\t\tTime(From)\tTime(To)\tDate\t\tPrice to Pay (Rs)");
        printf("\n");
        while(current != NULL)
        {
            printf("\n%d ", i);
            printf("\t%-10s\t%-20s\t%-10s\t%-16s\t%02d:%02d\t\t %02d:%02d\t\t%02d/%02d/2021\t%.2f\n", current->id, current->name, current->p.phone_no, current->courtType, current->t.start_hour, current->t.start_minutes, current->t.end_hour, current->t.end_minutes, current->d.day, current->d.month, current->o.price);
            current = current->next;
            i++;
        }
    }
    printf("\nPress Enter to continue");
    getch();
}

void display_byCourt()  //display function definition
{
    int i;
    char courtType[50];

    if (head == NULL)
    {
        printf("\n\nEmpty list");
    }
    else
    {
        printf("\n\nBASKETBALL COURT\n");
        printf("No.     ID\tStudent Name\t\tPhone Number\tCourt Type\t\tTime(From)\tTime(To)\tDate\t\tPrice to Pay (Rs)");
        printf("\n");
        printf("\n");
        i=0;
        for (current=head; current!=NULL; current=current->next)
        {
            if (strcmp(current->courtType, "BASKETBALL COURT")==0)
            {
                i++;
                printf("%d\t%-10s\t%-20s\t%-10s\t%-16s\t%02d:%02d\t\t %02d:%02d\t\t%02d/%02d/2021\t%.2f\n", i, current->id, current->name, current->p.phone_no, current->courtType, current->t.start_hour, current->t.start_minutes, current->t.end_hour, current->t.end_minutes, current->d.day, current->d.month, current->o.price);
            }
        }

        printf("\n\nBadminton COURT\n");
        printf("No.     ID\tStudent Name\t\tPhone Number\tCourt Type\t\tTime(From)\tTime(To)\tDate\t\tPrice to Pay (Rs)");
        printf("\n");
        printf("\n");
        i=0;
        for (current=head; current!=NULL; current=current->next)
        {
            if (strcmp(current->courtType, "BADMINTON COURT")==0)
            {
                i++;
                printf("%d\t%-10s\t%-20s\t%-10s\t%-16s\t%02d:%02d\t\t %02d:%02d\t\t%02d/%02d/2021\t%.2f\n", i, current->id, current->name, current->p.phone_no, current->courtType, current->t.start_hour, current->t.start_minutes, current->t.end_hour, current->t.end_minutes, current->d.day, current->d.month, current->o.price);
            }
        }

        printf("\n\nTENNIS COURT\n");
        printf("No.     ID\tStudent Name\t\tPhone Number\tCourt Type\t\tTime(From)\tTime(To)\tDate\t\tPrice to Pay (Rs)");
        printf("\n");
        printf("\n");
        i=0;
        for (current=head; current!=NULL; current=current->next)
        {
            if (strcmp(current->courtType, "TENNIS COURT")==0)
            {
                i++;
                printf("%d\t%-10s\t%-20s\t%-10s\t%-16s\t%02d:%02d\t\t %02d:%02d\t\t%02d/%02d/2021\t%.2f\n", i, current->id, current->name, current->p.phone_no, current->courtType, current->t.start_hour, current->t.start_minutes, current->t.end_hour, current->t.end_minutes, current->d.day, current->d.month, current->o.price);
            }
        }


    }
    printf("\nPress Enter to continue");
    getch();
}

int Calc_End_Time(int start_hour, int hours)  // function definition
{
    int EndTime;

    EndTime = start_hour + hours;

    return EndTime;
}

float Calc_Total_Price(int court, int hours)  // function definition
{
    float courtPrice, totalPrice;

    if (court == 1)
    {
        courtPrice = 50.00;
    }
    else if (court == 2)
    {
        courtPrice = 70.00;
    }
    else if (court == 3)
    {
        courtPrice = 60.00;
    }

    else
    {
        printf("\n Invalid Selection");
    }

    totalPrice = hours * courtPrice;

    return totalPrice;
}
