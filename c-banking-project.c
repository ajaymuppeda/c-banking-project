#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define PASSWORD_LENGTH 20

struct Account 
{
    int accountNumber;
    char name[50];
    char password[50];
    float balance;
    char branch[50];
    char ifsc[50];
    char mobile[10];
};
//Array to Store accounts
struct Account accounts[100];
int accountCount = 0;
// Function to generate random account number
int randomaccountnumber()
{
    srand(time(NULL));
return rand() %90000000000 +1000000000;} 
//Function
void addAccount();
void listAccounts();
void removeAccount();
void transactions();

int main() {
    int choice;
    while (1) 
    {
        // Main menu to Display menu
        printf("\n\t*** WELCOME TO NOVA BANK****\t\t\n");
        printf("\t\t\t1. Add Account\n");
        printf("\t\t\t2. List Accounts\n");
        printf("\t\t\t3. Remove Account\n");
        printf("\t\t\t4. Transactions\n");
        printf("\t\t\t5. Exit\n");
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                addAccount();
                break;
            case 2:
                listAccounts();
                break;
            case 3:
                removeAccount();
                break;
            case 4:
                transactions();
                break;
            case 5:
                return 0;
            default:
      printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
//Function to add new account
void addAccount() 
{
    if (accountCount < 100) 
    
    { 
        printf("Enter Your Full name: ");
        scanf("%s", &accounts[accountCount].name);
         printf("Enter Branch name: ");
        scanf("%s", &accounts[accountCount].branch);
       accounts[accountCount].accountNumber=randomaccountnumber();
         printf("Enter account IFSC code: ");
        scanf("%s", &accounts[accountCount].ifsc);
        printf("Enter password: ");
        scanf("%s", &accounts[accountCount].password);
         printf("Enter Mobile number: ");
        scanf("%d", &accounts[accountCount].mobile);
        printf("Enter initial balance: ");
        scanf("%f", &accounts[accountCount].balance);
        accountCount++;
         for (int i = 0; i < accountCount; i++) {
        printf("\nWELCOME TO NOVA BANKING!1\n");
       printf("Thank you %s for registering your new account in %s Branch\n",accounts[i].name,accounts[i].branch);
       printf(" Your account number :%d\n HAPPY BANKING",accounts[i].accountNumber);
    }}
    else 
    {
        printf("Maximum accounts reached!\n");
    }
}
//Function to List all account that you are created
void listAccounts() 
{
    if (accountCount == 0) 
    {
        printf("No accounts available!\n");
    }
    else 
    {
        printf("List of Accounts:\n");
        for (int i = 0; i < accountCount; i++) 
        {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder's Name: %s\n", accounts[i].name);
        printf("Branch Name: %s\n", accounts[i].branch);
        printf("IFSC code: %s\n", accounts[i].ifsc);
        printf("Mobile number: %d\n", accounts[i].mobile);
        printf("Balance: %.2f\n\n", accounts[i].balance);
        }
    }
}
//Function to remove an account
void removeAccount() 
{
    int accountNumber;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < accountCount; i++) 
    {
        if (accounts[i].accountNumber == accountNumber) 
        {
     for (int j = i; j < accountCount - 1; j++) 
     {
                accounts[j] = accounts[j + 1];
            }
            accountCount--;
            printf("Account removed successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}
//Function  to perform transactions
void transactions() 
{
    int accountNumber;
    char password[50];
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter password: ");
    scanf("%s",&password);
    for (int i = 0; i < accountCount; i++) 
    {
        if (accounts[i].accountNumber == accountNumber && strcmp(accounts[i].password,password)==0) 
        {
            while (1) 
            {
                printf("\nTransaction of Account %d\n", accountNumber);
                printf("1. Deposit\n");
                printf("2. Withdraw\n");
                printf("3. Transfer\n");
                printf("4. Return to  main menu\n");
                printf("Enter your choice: ");
                int choice;
                scanf("%d", &choice);
                switch (choice) 
 {
   case 1:
   float depositAmount;
   printf("Enter amount to deposit: ");
    scanf("%f", &depositAmount);
    accounts[i].balance += depositAmount;
    printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
         break;
   case 2:
    float withdrawAmount;
    printf("Enter amount to withdraw: ");
     scanf("%f", &withdrawAmount);
       if (accounts[i].balance >= withdrawAmount)
       {
          accounts[i].balance -= withdrawAmount;
printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
        } 
        else  
            {
             printf("Insufficient balance!\n");
            }
             break;
    case 3:
         int toAccount;
        float transferAmount;
            printf("Enter account number to transfer to: ");
            scanf("%d", &toAccount);
             printf("Enter amount to transfer: ");
             scanf("%f", &transferAmount);
      for (int j = 0; j < accountCount; j++) 
      {
        if (accounts[j].accountNumber == toAccount) 
        {
     if (accounts[i].balance >= transferAmount) 
     {
                 accounts[i].balance -= transferAmount;
                     accounts[j].balance += transferAmount;
           printf("Transfer successful!\n");
         }
         else 
         {
              printf("Insufficient balance!\n");
              }
            break;
            }
        }
          break;
     case 4:
           return;
     default:
      printf("Invalid choice. Please enter a valid option.\n");
                }
            }
        }
    }
    printf("INVAILD Account number or password!\n");
}