#include "system.h"

int main()
{
    int i;
    int check = 1;
    struct patient patientrecord[5];
    struct patient A;
    welcome();

    getch();

    clrscr();

    while (check)
    {
        mainscreen();
        printf("choose your option: ");

        scanf("%d", &i);

        switch (i)
        {
        case 1:
            clrscr();
            addrecord();
            view();
            break;
        case 2:
            clrscr();
            view();
            break;
        case 3:
            clrscr();
            edit();
            view();
            break;
        case 4:
            clrscr();
            search();
            break;
        case 5:
            clrscr();
            del();
            break;
        case 6:
            clrscr();
            thank();
            mainscreen();
            break;
        default:
            printf("Invalid input");
            break;
        }
        printf("Do you want to continue(1:yes)(0:no): ");
        scanf("%d", &check);
        if (check == 0)
        {
            thank();
        }
    }
    write();
    return 0;
}