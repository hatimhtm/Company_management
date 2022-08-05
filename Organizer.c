/*This program is supposed to calculate and display in files all
my expenses in the company and all the transmited cash values to 
my employees. Files are going to be used severely in this project*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef struct tag {
    char name[40];
    char role[40];
    int n_gigs;
    char phone[11];
    struct  tag *left;
    struct  tag *right;
} employee_info;

typedef struct {
    int num;
    char title[100];
    char client[40];
    char employee[40];
    int price;
    int cut;
} gigs_info;


FILE *comp_worth, *employees, *gigs, *trans;

void cls () {
    for (int i = 0; i < 50; i++)
        printf("\n");
}

void first_output () {
    cls ();
    printf ("\t\t--------------------------------------------------\n");
    printf ("\n");
    printf ("\t\t\t\tLDH Technologies\n");
    printf ("\n");
    printf ("\t\t--------------------------------------------------\n");
    getchar ();
}

void main_menu () {
    cls ();
    printf("\t\t--------------------- Main Menu ---------------------\n");
    printf("\t\t1. Show company worth\n");
    printf("\t\t2. Deposit money to company\n");
    printf("\t\t3. Show company employees\n");
    printf("\t\t4. Show gigs details\n");
    printf("\t\t5. Add new gig\n");
    printf("\t\t6. Add a transaction\n");
    printf("\t\t7. Show transactions history\n");
    printf("\t\t8. Quit\n");
    printf("\t\t-----------------------------------------------------\n");
    printf("\n\t\tChoice: ");
}

void show_company_worth () {
    double worth;
    comp_worth = fopen ("company_worth.txt", "r");
    if (comp_worth == NULL) {
        printf ("\t\tError opening file\n");
        return;
    }
    fscanf (comp_worth, "%lf", &worth);
    fclose (comp_worth);
    printf ("\t\t--------------------- Company Worth ---------------------\n\n");
    printf ("\t\tCompany worth: %.2lf DH\n\n", worth);
    printf ("\t\t---------------------------------------------------------\n");
    getchar ();
    getchar ();
}

void deposit_money () {
    double deposit_amount, excisting_amount;
    printf ("\t\t--------------------- Deposit Money ---------------------\n\n");
    printf ("\t\tEnter deposit amount: ");
    scanf ("%lf", &deposit_amount);
    comp_worth = fopen ("company_worth.txt", "r");
    if (comp_worth == NULL) {
        printf ("\t\tError opening file\n");
        return;
    }
    fscanf (comp_worth, "%lf", &excisting_amount);
    fclose (comp_worth);
    comp_worth = fopen ("company_worth.txt", "w");
    if (comp_worth == NULL) {
        printf ("\t\tError opening file\n");
        return;
    }
    deposit_amount += excisting_amount;
    fprintf (comp_worth, "%lf", deposit_amount);
    fclose (comp_worth);
    printf ("\t\t---------------------------------------------------------\n");
    getchar ();
    getchar ();
}

void show_company_employees () {
    char employee_info[100];
    printf ("\t\t--------------------- Company Employees ---------------------\n\n");
    employees = fopen ("company_employees.txt", "r");
    if (employees == NULL) {
        printf ("\t\tError opening file\n");
        return;
    }
    while (!feof (employees)) {
        fscanf (employees, "%[^\n]%*c\n", employee_info);
        printf ("\t\tFull Name: %s\n", employee_info);
        fscanf (employees, "%[^\n]%*c\n", employee_info);
        printf ("\t\tRole in the Company: %s\n", employee_info);
        fscanf (employees, "%[^\n]%*c\n", employee_info);
        printf ("\t\tPhone Number: %s\n", employee_info);
        fscanf (employees, "%s\n", employee_info);
        printf ("\t\t%s\n", employee_info);
    }
    fclose (employees);
    printf ("\n\t\t-------------------------------------------------------------\n");
    getchar ();
    getchar ();
}

void show_a_gig () {
    int flag = 0;
    printf("\t\t--------------------- Show a Gig ---------------------\n\n");
    printf("\t\tEnter the number of the gig: ");
    int gig_number;
    scanf("%d", &gig_number);
    gigs = fopen ("company_gigs.txt", "r");
    if (gigs == NULL) {
        printf ("\t\tError opening file\n");
        return;
    }
    int temp_gig_number;
    char gig_info[100];
    while (!feof (gigs)) {
        fscanf (gigs, "%d\n", &temp_gig_number);
        if (temp_gig_number == gig_number) {
            flag = 1;
            fscanf (gigs, "%[^\n]%*c\n", gig_info);
            printf ("\t\tDescription: %s\n", gig_info);
            fscanf (gigs, "%[^\n]%*c\n", gig_info);
            printf ("\t\tClient: %s\n", gig_info);
            fscanf (gigs, "%[^\n]%*c\n", gig_info);
            printf ("\t\tEmployee on the Project: %s\n", gig_info);
            fscanf (gigs, "%[^\n]%*c\n", gig_info);
            printf ("\t\tTotal Price: %s\n", gig_info);
            fscanf (gigs, "%[^\n]%*c\n", gig_info);
            printf ("\t\tEmployee Salary: %s\n", gig_info);
            getchar ();
            break;
        }
        fscanf (gigs, "%[^\n]%*c\n", gig_info);
        fscanf (gigs, "%[^\n]%*c\n", gig_info);
        fscanf (gigs, "%[^\n]%*c\n", gig_info);
        fscanf (gigs, "%[^\n]%*c\n", gig_info);
        fscanf (gigs, "%[^\n]%*c\n", gig_info);
        fscanf (gigs, "%[^\n]%*c\n", gig_info);
        if (flag == 0) {
            printf ("\t\tGig not found\n");
        }
    }
    fclose (gigs);
    printf ("\t\t------------------------------------------------------\n");
    getchar ();
}

void add_gig () {
    int temp_num;
    double temi;
    char temps[100];
    printf ("\t\t--------------------- Add a Gig ---------------------\n\n");
    gigs = fopen ("company_gigs.txt", "r");
    while (!feof (gigs)) {
        fscanf (gigs, "%d\n", &temp_num);
        fscanf (gigs, "%[^\n]%*c\n", temps);
        fscanf (gigs, "%[^\n]%*c\n", temps);
        fscanf (gigs, "%[^\n]%*c\n", temps);
        fscanf (gigs, "%[^\n]%*c\n", temps);
        fscanf (gigs, "%[^\n]%*c\n", temps);
        fscanf (gigs, "%[^\n]%*c\n", temps);
    }
    fclose (gigs);
    gigs = fopen ("company_gigs.txt", "a");
    if (gigs == NULL) {
        printf ("\t\tError opening file\n");
        return;
    }
    char freak;
    fprintf (gigs, "%d", temp_num + 1);
    printf ("\t\tEnter the description of the gig: ");
    gets (temps);
    strtok (temps, "\n");
    fprintf (gigs, "%s\n", temps);
    printf ("\t\tEnter the client of the gig: ");
    getchar ();
    scanf ("%[^\n]%*c\n", temps);
    fprintf (gigs, "%s\n", temps);
    printf ("\t\tEnter the name of the employee on the project: ");
    getchar ();
    scanf ("%[^\n]%*c\n", temps);
    fprintf (gigs, "%s\n", temps);
    printf ("\t\tEnter the total price of the gig: ");
    getchar ();
    scanf ("%lf\n", &temi);
    fprintf (gigs, "%.2lf\n", temi);
    printf ("\t\tEnter the salary of the employee: ");
    getchar ();
    scanf ("%lf\n", &temi);
    fprintf (gigs, "%.2lf\n", temi);
    fprintf (gigs, "--------------------------\n");
    fclose (gigs);
    printf ("\t\t------------------------------------------------------\n");
}

void add_transaction () {
    char name[40];
    int amount;
    char reason[200];
    char date[20];
    char currency[10];
    trans = fopen("company_transactions.txt", "a");
    printf("\t\t--------------------- Add a Transaction ---------------------\n\n");
    getchar ();
    printf("\t\tEnter the receiver's name: ");
    scanf ("%[^\n]%*c", name);
    printf ("\t\tEnter the amount of the transaction: ");
    scanf ("%d", &amount);
    printf("\t\tEnter the reason of the transaction: ");
    getchar ();
    scanf ("%[^\n]%*c", reason);
    printf("\t\tEnter the date of the transaction: ");
    scanf ("%[^\n]%*c", date);
    printf ("\t\tEnter currency: ");
    scanf ("%[^\n]%*c", currency);
    printf("\t\t-------------------------------------------------------------\n");
    getchar ();
    fprintf(trans, "Transaction to Mr.%s for %s on %s with amount of %d%s\n", name, reason, date, amount, currency);
    fprintf(trans, "-------------------------------------------------------------\n");
    fclose(trans);
}

void show_trans_history () {
    char temp[100];
    trans = fopen ("company_transactions.txt", "r");
    if (trans == NULL) {
        printf("\n\nThe file doesn't exist!!!\n");
        getchar ();
        exit(1);
    }
    while (fgets(temp, 100, trans) != NULL) {
        printf ("%s\n", temp);
    }
    getchar ();
    getchar ();
    fclose (trans);
}

void quit () {
    printf ("\t\t--------------------- Quitting ---------------------\n\n");
    printf ("\t\t         Thanks for using our software\n\t\t              Have a great day");
    printf ("\t\t----------------------------------------------------\n");
}

int main () {
    employee_info *root = NULL;
    char username[49], password[49];
    int main_menu_choice, adding_trans;
    first_output ();
    do {
        main_menu ();
        scanf ("%d", &main_menu_choice);
        switch (main_menu_choice) {
            case 1:
                cls ();
                show_company_worth ();
                break;
            case 2:
                cls ();
                deposit_money ();
                break;
            case 3:
                cls ();
                show_company_employees ();
                break;
            case 4:
                cls ();
                show_a_gig ();
                break;
            case 5:
                cls ();
                add_gig ();
                break;
            case 6:
                cls ();
                add_transaction ();
                break;
            case 7:
                cls ();
                show_trans_history ();
                break;
            case 8:
                cls ();
                quit ();
                break;
            default:
                cls ();
        }
    } while (main_menu_choice != 8);
}