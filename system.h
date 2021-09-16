#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <math.h>
#define max 100
#include <string.h>
#ifdef _WIN32
#include <conio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int num = 0;

void welcome()
{
    int i, j;
    printf("\t\t\t\t\t   ########################################\t\n");
    printf("\t\t\t\t\t   #             --WELCOME TO--           #\t\n");
    printf("\t\t\t\t\t   #                                      #\t\n");
    printf("\t\t\t\t\t   #             CENTRAL HOSPITAL         #\t\n");
    printf("\t\t\t\t\t   #                                      #\t\n");
    printf("\t\t\t\t\t   ########################################\t\n");
    printf("\t\t\t\t\t-------------press any key to continue------------\t");
}

void title()
{

    printf("\t\t\t\t\t     ISEKAI HOSPITAL\n");
}

void mainscreen()
{
    int i;
    title();
    printf("\n");
    printf("\n");

    printf("\t 1. ADD NEW RECORDS\t\n");
    printf("\t 2. VIEW RECORDS \t\n");
    printf("\t 3. EDIT RECORDS \t\n");
    printf("\t 4. SEARCH RECORDS \t\n");
    printf("\t 5. DELETE RECORDS \t\n ");
    printf("\t 6. RETURN \t ");
    printf("\n");
    printf("\n");
}

struct patient
{
    int age;
    char gender[max];
    char name[max];
    char contact[max];
    char doctor;
    char problem[max];
};

struct patient patientrecord[5];

void displayspecialist(int current_num)
{
    int i;
    int check = 1;
    char problem_1[50] = "          GENERAL PHYSICIAN|     102, 103";
    char problem_2[50] = "                 E.N.T CARE|          402";
    char problem_3[50] = "               CARDIOLOGIST|      202,200";
    char problem_4[50] = "              DERMATOLOGIST|          308";

    printf("|        SPECIALISTS      |   ROOM NO.  |\n");
    printf("|-------------------------|-------------|\n");
    printf("|1. GENERAL PHYSICIAN     |   102, 103  |\n");
    printf("|2. E.N.T CARE            |     402     |\n");
    printf("|3. CARDIOLOGIST          |   202,200   |\n");
    printf("|4. DERMATOLOGIST         |     308     |\n");
    printf("|-----------------------  |-------------|\n\n");
    printf("ENTER YOUR PROBLEMS: ");
    scanf("%d", &i);

    if (i <= 4)
        switch (i)
        {
        case 1:

            strcpy(patientrecord[current_num].problem, problem_1);

            break;
        case 2:
            strcpy(patientrecord[current_num].problem, problem_2);
            break;
        case 3:
            strcpy(patientrecord[current_num].problem, problem_3);
            break;
        case 4:
            strcpy(patientrecord[current_num].problem, problem_4);
            break;
        }
}

void addrecord()
{

    int check = 1;



    printf("\n\t- ADD PATIENTS RECORD-\t\n ");

    while (check)
    {
        char temp[50];

        printf("enter name: \n");
        fflush(stdin);
        gets(temp);
        strcpy(patientrecord[num].name, temp);

        printf("enter gender: \n");
        fflush(stdin);
        gets(temp);
        strcpy(patientrecord[num].gender, temp);

        printf("enter age: \n");
        scanf("%d", &patientrecord[num].age);

        fflush(stdin);

        printf("contact: \n");
        fflush(stdin);
        gets(temp);
        strcpy(patientrecord[num].contact, temp);

        fflush(stdin);
        displayspecialist(num);

        printf("do you want to add more(1:yes, 0:no): ");
        scanf("%d", &check);
        num++;
    }
}

void view()
{
    clrscr();
    title();

    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!! PATIENT RECORD LIST !!!!!!!!!!!!!!!!!!\t\n\n");
    printf("seri num|           name|      gender|      age|       contact|                    problem|      room.no|\n");

    for (int i = 0; i < num; i++)
    {

        printf("%8d|", i + 1);

        printf("%15s|", patientrecord[i].name);
        printf("%12s|", patientrecord[i].gender);
        printf("%9d|", patientrecord[i].age);
        printf("%14s|", patientrecord[i].contact);
        printf("%27s|", patientrecord[i].problem);
        printf("\n");
    }
}

void edit()
{
    int q = 6, p;

    printf("\nwhat do you want to edit?\n");
    printf("enter your option\n");
    printf("1.Name\n2.gender\n3.age\n4.contact\n5.problem\n");

    if (q < 7)
    {
        printf("what is your option: ");
        fflush(stdin);
        scanf("%d", &q);
    }

    printf("enter the patients seri num: ");
    scanf("%d", &p);
    p--;

    if (p < num || p == num)
    {
        switch (q)
        {
        case 1:

            printf("please enter your new name: ");
            fflush(stdin);
            gets(patientrecord[p].name);

            break;
        case 2:

            printf("please enter your new gender: ");
            fflush(stdin);
            gets(patientrecord[p].gender);
            break;
        case 3:

            printf("please enter your new age: ");
            scanf("%d", &patientrecord[p].age);
            break;
        case 4:

            printf("please enter your new contact: ");
            fflush(stdin);
            gets(patientrecord[p].contact);
            break;
        case 5:

            printf("please choose a new problem: ");
            fflush(stdin);
            displayspecialist(p);

            break;
        }
    }
    else
    {
        printf("invalid value");
    }
}

void search()
{
    int s;
    
    printf("enter serial number of the patient: ");
    scanf("%d", &s);
    s--;
    if (s <= num)
    {
        printf("\n");
        printf("seri num:            %d\n", s + 1);
        printf("name                = ");
        puts(patientrecord[s].name);
        printf("gender              = ");
        puts(patientrecord[s].gender);
        printf("age= %d\n", patientrecord[s].age);
        printf("contact             =");
        puts(patientrecord[s].contact);
        printf("problem and room no =");
        puts(patientrecord[s].problem);
    }
    else
    {
        printf("not found");
    }
}

void del()
{
    int f, h;
    printf("enter the seri number of the patient that you want to delete: ");
    scanf("%d", &f);
    f--;
    if (f <= num)
    {
        printf("1.remove the patient record\n2.remove name\n3.remove gender\n4.remove age\n5.remove contact\n6.remove problem\n");
        printf("what do you want to do?\n");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f <= num)
            {
                strcpy(patientrecord[f].name, patientrecord[f + 1].name);
                strcpy(patientrecord[f].gender, patientrecord[f + 1].gender);
                strcpy(patientrecord[f].contact, patientrecord[f + 1].contact);
                patientrecord[f].age = patientrecord[f + 1].age;
                strcpy(patientrecord[f].problem, patientrecord[f + 1].problem);
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(patientrecord[f].name, "cleared");
        }
        else if (h == 3)
        {
            strcpy(patientrecord[f].gender, "cleared");
        }
        else if (h == 4)
        {
            patientrecord[f].age = 0;
        }
        else if (h == 5)
        {
            strcpy(patientrecord[f].contact, "cleared|      cleared");
        }
        else if (h == 6)
        {
            strcpy(patientrecord[f].problem, "cleared");
        }
    }
}

void traitim(int n)
{

    for (int i = n / 2; i <= n; i += 2)
    {
        for (int j = 1; j < n - i; j += 2)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("*");
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j < n; j++)
            printf(" ");
        for (int j = 1; j <= (i * 2) - 1; j++)
            printf("*");
        printf("\n");
    }
}

void thank()
{

    printf("!!!!!!!!!!!!!!!!!!!!!!! THANK YOU FOR USING OUR SERVICES !!!!!!!!!!!!!!!!!!!!!!");

    traitim(10);
}

void write()
{
    FILE *fptr;
    fptr = fopen("name_list.txt", "w");
    if (fptr == NULL)
    {
        printf("file does not exist");
        exit(1);
    }
    for (int i = 0; i < num; i++)
    {

        printf("%7d|", i);

        printf("%15s|", patientrecord[i].name);
        printf("%12s|", patientrecord[i].gender);
        printf("%9d|", patientrecord[i].age);
        printf("%14s|", patientrecord[i].contact);
        printf("%27s|", patientrecord[i].problem);
        printf("\n");
    }

    fclose(fptr);
}