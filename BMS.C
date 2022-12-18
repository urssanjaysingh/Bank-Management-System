#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>

void logo();
void login_menu();
void login();
void main_menu();
void edit_menu();
void transaction_menu();
void new_acc();
void view_acc();
void update_acc();
void delete_acc();
void search_acc();
void balance();
void deposit();
void withdraw();

struct bank
{
    int acc_no;
    int day, month, year;
    int age;
    float amt;
    char pnumber[15];
    char adharnum[20];
    char name[20];
    char fathname[20];
    char address[50];
} b, t;

void logo()
{
    printf(
    "\n\t\t""==================================""\n"
    "\t\t"  "      BANK MANAGEMENT SYSTEM      ""\n"
    "\t\t"  "==================================""\n"
    );
}

void login_menu()
{
loop:
    system("cls");
    logo();
    printf(
    "\n\t\t""************* LOGIN **************""\n"
    "\t\t"  " ________________________________ ""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|_________ 1) Login _____________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|_________ 2) Exit ______________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|________________________________|""\n"
    );
    int choice;
    printf("\n\n\t\t\tYour choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            login();
            break;

        case 2:
            exit(0);

        default:
            printf("\n\n\t\t\tWrong Choice! Try Again.\n\n\n");
            system("pause");
            fflush(stdin);
            break;
    }
    goto loop;
}

void main_menu()
{
loop:
    system("cls");
    printf(
    "\n\t\t""*********** MAIN MENU ************""\n"
    "\t\t"  " ________________________________ ""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 1) Open New Account _______|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 2) View Accounts __________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 3) Edit Accounts __________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 4) Search Records _________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 5) Transactions ___________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 6) Exit __________________ |""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|________________________________|""\n"
    );
    int choice;
    printf("\n\n\t\t\tYour choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            new_acc();
            break;

        case 2:
            view_acc();
            printf("\n\n");
            system("pause");
            break;

        case 3:
            edit_menu();
            break;

        case 4:
            search_acc();
            break;

        case 5:
            transaction_menu();
            break;

        case 6:
            login_menu();
            break;

        default:
            printf("\n\n\t\t\tWrong Choice! Try Again.\n\n\n");
            system("pause");
            fflush(stdin);
            main_menu();
            break;
    }
    goto loop;
}

void edit_menu()
{
loop:
    system("cls");
    printf(
    "\n\t\t""*********** EDIT MENU ************""\n"
    "\t\t"  " ________________________________ ""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 1) Update Details _________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 2) Delete Records _________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|____ 3) Main Menu ______________|""\n"
    "\t\t"  "|                                |""\n"
    "\t\t"  "|________________________________|""\n"
    );
    int choice;
    printf("\n\n\t\t\tYour choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            update_acc();
            break;

        case 2:
            delete_acc();
            break;

        case 3:
            main_menu();
            break;

        default:
            printf("\n\n\t\t\tWrong Choice! Try Again.\n\n\n");
            system("pause");
            fflush(stdin);
            break;
    }
    goto loop;
}

void transaction_menu()
{
loop:
    system("cls");
    printf("\n\n");
    printf(
        "\n\t\t""********** TRANSACTIONS **********""\n"
        "\t\t"  " ________________________________ ""\n"
        "\t\t"  "|                                |""\n"
        "\t\t"  "|____ 1) Check Balance __________|""\n"
        "\t\t"  "|                                |""\n"
        "\t\t"  "|____ 2) Deposit Money __________|""\n"
        "\t\t"  "|                                |""\n"
        "\t\t"  "|____ 3) Withdraw Money _________|""\n"
        "\t\t"  "|                                |""\n"
        "\t\t"  "|____ 4) Main Menu ______________|""\n"
        "\t\t"  "|                                |""\n"
        "\t\t"  "|________________________________|""\n");
    int choice;
    printf("\n\n\t\t\t Your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        balance();
        break;

    case 2:
        deposit();
        break;

    case 3:
        withdraw();
        break;

    case 4:
        main_menu();
        break;

    default:
        printf("\n\n\t\t\tWrong Choice! Try Again.\n\n\n");
        system("pause");
        fflush(stdin);
        goto loop;
        break;
    }
}

void new_acc()
{
loop: ; // This is an empty statement
    int acn;
    FILE *fp;

    fp = fopen("bms.txt", "ab+");

    if (fp == NULL)
    {
        printf("\n\t\tError! Can't open the file!!\n");
        return;
    }

    system("cls");
    printf("\n\t\t*** Enter New Customer Details ***\n\n");

    fflush(stdin);
    printf("\n\t\tAccount Number: ");
    scanf("%d", &acn);
    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        if (acn == b.acc_no)
        {
            printf("\n\t\tAccount no. already in use!\n\n\n");
            system("pause");
            fclose(fp);
            goto loop;
        }
    }
    b.acc_no = acn;

    fflush(stdin);
    printf("\n\t\tName: ");
    gets(b.name);

    fflush(stdin);
    printf("\n\t\tFather's Name: ");
    gets(b.fathname);

    fflush(stdin);
    printf("\n\t\tDate of Birth(dd-mm-yyyy): ");
    scanf("%d-%d-%d", &b.day, &b.month, &b.year);

    fflush(stdin);
    printf("\n\t\tAge: ");
    scanf("%d", &b.age);

    fflush(stdin);
    printf("\n\t\tPhone Number: ");
    gets(b.pnumber);

    fflush(stdin);
    printf("\n\t\tAadhar Number: ");
    gets(b.adharnum);

    fflush(stdin);
    printf("\n\t\tAddress: ");
    gets(b.address);

    fflush(stdin);
    printf("\n\t\tEnter the amount to deposit: Rs. ");
    scanf("%f", &b.amt);

    fwrite(&b, sizeof(b), 1, fp);

    {
        printf("\n\n\t\tAccount Created Successfully!!!\n\n\n");
        system("pause");
    }

    fclose(fp);
}

void view_acc()
{
    system("cls");
    struct bank temp;
    struct bank arr[50];

    int i, j, k = 0;
    FILE *fp;
    fp = fopen("bms.txt", "rb");

    if (fp == NULL)
    {
        printf("\n\t\tError! Can't open the File!!\n\n\n");
        system("pause");
        main_menu();
        return;
    }

    i = 0;
    while (fread(&arr[i], sizeof(arr[i]), 1, fp) == 1)
    {
        i++;
        k++;
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (arr[j].acc_no > arr[j + 1].acc_no)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int w = 1; w <= 119; w++)
    {
        printf("%c", 205);
    }
    printf(
        "\nAcc No\tName\t\tFather Name\tDOB\t\tAge\tPhone No\tAadhar No\tAddress\t\tBalance\n");
    for (int w = 1; w <= 119; w++)
    {
        printf("%c", 205);
    }

    for (i = 0; i < k; i++)
    {
        printf("\n\n%d\t%s\t%s\t%d-%d-%d\t%d\t%s\t%s\t%-14s\t%.2f",
               arr[i].acc_no,
               arr[i].name,
               arr[i].fathname,
               arr[i].day, arr[i].month, arr[i].year,
               arr[i].age,
               arr[i].pnumber,
               arr[i].adharnum,
               arr[i].address,
               arr[i].amt);
    }
    fclose(fp);
}

void update_acc()
{
    system("cls");
    view_acc();
    int acn, flag = 0;
    FILE *fp, *ft;
    fp = fopen("bms.txt", "rb+");
    ft = fopen("bms1.txt", "ab+");

    if (fp == NULL)
    {
        return;
    }

    printf("\n\n\nEnter Account Number Where Details You Want to Update: ");
    scanf("%d", &acn);

    while (fread(&b, sizeof(b), 1, fp))
    {
        if (b.acc_no == acn)
        {
            flag = 1;
            system("cls");
            printf("\n*** Previously Stored Details of Given Account Number ***\n\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf(
                "\nAcc No\tName\t\tFather Name\tDOB\t\tAge\tPhone No\tAadhar No\tAddress\t\tBalance\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf("\n\n%d\t%s\t%s\t%d-%d-%d\t%d\t%s\t%s\t%s\t%.2f",
                   b.acc_no,
                   b.name,
                   b.fathname,
                   b.day, b.month, b.year,
                   b.age,
                   b.pnumber,
                   b.adharnum,
                   b.address,
                   b.amt);

            printf("\n\n\n\t*** Now Enter the New Details ***\n");

            b.acc_no = acn;

            fflush(stdin);
            printf("\n\tName: ");
            gets(b.name);

            fflush(stdin);
            printf("\n\tFather's Name: ");
            gets(b.fathname);

            fflush(stdin);
            printf("\n\tDate of Birth(dd-mm-yyyy): ");
            scanf("%d-%d-%d", &b.day, &b.month, &b.year);

            fflush(stdin);
            printf("\n\tAge: ");
            scanf("%d", &b.age);

            fflush(stdin);
            printf("\n\tPhone Number: ");
            gets(b.pnumber);

            fflush(stdin);
            printf("\n\tAadhar Number: ");
            gets(b.adharnum);

            fflush(stdin);
            printf("\n\tAddress: ");
            gets(b.address);

            fflush(stdin);
            printf("\n\tEnter the amount to deposit: Rs. ");
            scanf("%f", &b.amt);

            fwrite(&b, sizeof(b), 1, ft);

            printf("\n\n\tRecord Updated Successfully Check The Display\n\n\n");
            system("pause");
        }
        else
            fwrite(&b, sizeof(b), 1, ft);
    }

    if (flag == 0)
    {
        printf("\n\t\tError! Searching went wrong!!!\n\n\n");
        system("pause");
    }

    fclose(fp);
    fclose(ft);
    remove("bms.txt");
    rename("bms1.txt", "bms.txt");
}

void delete_acc()
{
    system("cls");
    view_acc();
    int acn, flag = 0;
    FILE *fp, *ft;
    fp = fopen("bms.txt", "rb+");
    ft = fopen("bms1.txt", "ab+");

    if (fp == NULL)
    {
        return;
    }

    printf("\n\n\nEnter Account Number Where Details You Want to Delete: ");
    scanf("%d", &acn);

    while (fread(&b, sizeof(b), 1, fp))
    {
        if (b.acc_no != acn)
        {
            fwrite(&b, sizeof(b), 1, ft);
        }
        else
            flag = 1;
    }

    if (flag == 1)
    {
        printf("\n\tDeletion Successfull!!\n\n\n");
        system("pause");
    }

    if (flag == 0)
    {
        printf("\n\n\t\tNo Such Record Found!!!\n\n\n");
        system("pause");
    }
    fclose(fp);
    fclose(ft);
    remove("bms.txt");
    rename("bms1.txt", "bms.txt");
}

void search_acc()
{
    system("cls");
    char key[40];
    unsigned flag = 0;
    FILE *fp;
    fp = fopen("bms.txt", "rb");

    if (fp == NULL)
    {
        printf("\n\t\tError! Can't open the file!!\n\n\n");
        system("pause");
        return;
    }

    fflush(stdin);
    printf("Enter any Name to Search Record: ");
    gets(key);

    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        if (strcmp(key, b.name) == 0)
        {
            flag = 1;
            printf("\n");
            printf(
                "\n\tAccount Number   :   %d\n"
                "\n\tName             :   %s\n"
                "\n\tFather Name      :   %s\n"
                "\n\tDate of Birth    :   %d-%d-%d\n"
                "\n\tAge              :   %d\n"
                "\n\tPhone Number     :   %s\n"
                "\n\tAadhar Number    :   %s\n"
                "\n\tAddress          :   %s\n"
                "\n\tBalance          :   %.2f\n",
                b.acc_no,
                b.name,
                b.fathname,
                b.day, b.month, b.year,
                b.age,
                b.pnumber,
                b.adharnum,
                b.address,
                b.amt);
            printf("\n\n");
            system("pause");
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\tNo Such Record Found!!!\n\n\n");
        system("pause");
    }
    fclose(fp);
}

void balance()
{
    system("cls");
    int acn, flag = 0;
    FILE *fp;
    fp = fopen("bms.txt", "rb+");

    if (fp == NULL)
    {
        printf("\n\t\tError! Can't open the file!!\n\n\n");
        system("pause");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acn);

    while (fread(&b, sizeof(b), 1, fp))
    {
        if (b.acc_no == acn)
        {

            flag = 1;
            system("cls");
            printf("*** Account Details ***\n\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf(
                "\nAcc No\tName\t\tFather Name\tDOB\t\tAge\tPhone No\tAadhar No\tAddress\t\tBalance\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf("\n\n%d\t%s\t%s\t%d-%d-%d\t%d\t%s\t%s\t%s\t%.2f",
                   b.acc_no,
                   b.name,
                   b.fathname,
                   b.day, b.month, b.year,
                   b.age,
                   b.pnumber,
                   b.adharnum,
                   b.address,
                   b.amt);
        }
    }

    if (flag == 0)
    {
        printf("\n\t\tError! Searching went wrong!!!\n\n\n");
        system("pause");
    }

    fclose(fp);
    printf("\n\n\n");
    system("pause");
    transaction_menu();
}

void deposit()
{
    system("cls");
    int acn, flag = 0;
    FILE *fp, *ft;
    fp = fopen("bms.txt", "rb+");
    ft = fopen("bms1.txt", "ab+");

    if (fp == NULL)
    {
        printf("\n\t\tError! Can't open the file!!\n\n\n");
        system("pause");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acn);

    while (fread(&b, sizeof(b), 1, fp))
    {
        if (b.acc_no == acn)
        {
            flag = 1;
            system("cls");
            printf("*** Account Details ***\n\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf(
                "\nAcc No\tName\t\tFather Name\tDOB\t\tAge\tPhone No\tAadhar No\tAddress\t\tBalance\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf("\n\n%d\t%s\t%s\t%d-%d-%d\t%d\t%s\t%s\t%s\t%.2f",
                   b.acc_no,
                   b.name,
                   b.fathname,
                   b.day, b.month, b.year,
                   b.age,
                   b.pnumber,
                   b.adharnum,
                   b.address,
                   b.amt);

            printf("\n\n\n\tEnter the amount you want to deposit: Rs. ");
                scanf("%f", &t.amt);
                b.amt += t.amt;
                fwrite(&b, sizeof(b), 1, ft);
                printf("\n\n\tDeposited successfully!\n\n\n");
                system("pause");
        }
        else
            fwrite(&b, sizeof(b), 1, ft);
    }

    if (flag == 0)
    {
        printf("\n\t\tError! Searching went wrong!!!\n\n\n");
        system("pause");
    }

    fclose(fp);
    fclose(ft);
    remove("bms.txt");
    rename("bms1.txt", "bms.txt");
    transaction_menu();
}

void withdraw()
{
    system("cls");
    int acn, flag = 0;
    FILE *fp, *ft;
    fp = fopen("bms.txt", "rb+");
    ft = fopen("bms1.txt", "ab+");

    if (fp == NULL)
    {
        printf("\n\t\tError! Can't open the file!!\n\n\n");
        system("pause");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acn);

    while (fread(&b, sizeof(b), 1, fp))
    {
        if (b.acc_no == acn)
        {
        loop:
            system("cls");
            printf("*** Account Details ***\n\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf(
                "\nAcc No\tName\t\tFather Name\tDOB\t\tAge\tPhone No\tAadhar No\tAddress\t\tBalance\n");
            for (int w = 1; w <= 119; w++)
            {
                printf("%c", 205);
            }
            printf("\n\n%d\t%s\t%s\t%d-%d-%d\t%d\t%s\t%s\t%s\t%.2f",
                   b.acc_no,
                   b.name,
                   b.fathname,
                   b.day, b.month, b.year,
                   b.age,
                   b.pnumber,
                   b.adharnum,
                   b.address,
                   b.amt);

            printf("\n\n\n\tEnter the amount you want to withdraw: Rs. ");
            scanf("%f", &t.amt);
            if(t.amt <= b.amt && t.amt >= 0)
            {
                b.amt -= t.amt;
                fwrite(&b, sizeof(b), 1, ft);
                flag = 1;
                break;
            }
            else if(t.amt > 50000)
            {
                printf("\n\n\tWithdraw Limit of 50,000 Exceeds!\n\n\n");
                system("pause");
                goto loop;
            }
            else
            {
                printf("\n\n\tInsufficient Balance!\n\n\n");
                system("pause");
                goto loop;
            }
        }
        else
            fwrite(&b, sizeof(b), 1, ft);
    }

    if (flag == 1)
    {
        printf("\n\n\tWithdrawn successfully!\n\n\n");
        system("pause");
    }

    if (flag == 0)
    {
        printf("\n\t\tError! Searching went wrong!!!\n\n\n");
        system("pause");
    }

    fclose(fp);
    fclose(ft);
    remove("bms.txt");
    rename("bms1.txt", "bms.txt");
    transaction_menu();
}

void login()
{
    char pass[15],password[15]="urssanjaysingh";
    printf("\n\n\t\t\tEnter the password to login: ");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {
            main_menu();
        }
    else
        {
            printf("\n\n\t\t\tWrong password!!\n\n\n");
            system("pause");
        }
}

int main()
{
    login_menu();

    return 0;
}
