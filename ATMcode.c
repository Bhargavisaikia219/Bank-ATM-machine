#include <stdio.h>

int ATM_Transaction(); 
int anotherTransaction,Widthdrawal_amount,Deposited_amount,pin; //Global variable
double balance = 1000; // Global variable, Initial  balance to be 1000 for everyone

int  main()

{
  printf("******** Welcome to ABC bank ******** \n");
  printf("Please enter your 4 digit pin number: \n");
  scanf("%d",&pin);
    if(pin != 1234)
   {
       printf("Incorrect pin.Please enter your pin correctly \n");
   }
   else
    {
      ATM_Transaction();     // function call
    }
}

int ATM_Transaction()
{
  int option;
  printf("Please select any option\n\n");
  printf("1. Balance Enquiry \n");
  printf("2. Cash Withdrawal\n");
  printf("3. Cash Deposit\n");
  printf("4. Exit \n");
  scanf("%d",  &option);

  switch(option)

  {

    case 1: // Balance Enquiry
    printf("Your available balance is: %f", balance);
    printf("\n\nDo you want to try another transaction?\nPress 1 to proceed and 2 to exit\n\n"); // request for another transaction
    scanf("%d",&anotherTransaction);
    if(anotherTransaction == 1)
      {
        ATM_Transaction();// call our transaction method here
      }
     break;

    case 2:// Second option should be for withdrawal
    printf("Please enter amount to withdraw: ");
    scanf("%d", &Widthdrawal_amount);
    if(Widthdrawal_amount <= balance) //balance = 1000
    {
     printf("Please collect your cash\n");
     balance=balance-Widthdrawal_amount;//
     printf("Your available balance is %lf\n",balance);
     printf("\n\nDo you want to try another transaction?\n Press 1 to proceed and 2 to exit\n\n");
     scanf("%d", &anotherTransaction);
       if(anotherTransaction == 1)
        {
             ATM_Transaction();  // call our ATM_Transaction method here
        }
    }
     else
    {
       printf("Sorry in-sufficient balance in your account");
       printf("\n\nDo you want to perform another transaction?\n Press 1 to proceed and 2 to exit\n\n");
       scanf("%d", &anotherTransaction);
       if(anotherTransaction == 1)
        {
             ATM_Transaction();  // call our ATM_Transaction method here
        }
    }
    break;

    case 3:// DEPOSIT
    printf("Please enter amount to deposit: ");
    scanf("%d", &Deposited_amount);
    balance = Deposited_amount + balance; 
    printf("Your available balance is: %f", balance);
    printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n");// request for another transaction
    scanf("%d", &anotherTransaction);
    if(anotherTransaction == 1)
     {
        ATM_Transaction(); // call our transaction method here
     }
    break;
    default:
     printf("Thank you for using ATM services\n");
  }

}




