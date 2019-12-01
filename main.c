#include <stdio.h>
#include "myBank.h"

int main(){
    double deposit = 0;
    double withdawal = 0;
    int numAccount = 0;
    char operator;
    double interest_rate = 0;
    do{                                               //Menu
    printf("\nfor open account press O (limited 50 account 901-950)\n");
    printf("for balance inquiry press B\n");
    printf("for deposit press D\n");
    printf("for withdawal from account press W\n");
    printf("for close account press C\n");
    printf("for interest rate to all accounts press I\n");
    printf("for print all vacant accounts and their balance inquiry press P\n");
    printf("for to close all account and exit press E\n");
     scanf(" %c",&operator);                //operation from menu
    switch (operator)
    {
    case 'O':
    printf("initial deposit?\n");            //input from user
    if(scanf("%lf" ,&deposit)!=1){           
    printf("error input in deposit\n");       //if input not matching to scaner 
    break;
    }
    openAccount(deposit);
        break;
        
    case 'B':
    printf("Account number?\n");
    if(scanf("%d" ,&numAccount)!=1){
        printf("error input in Account number\n");
    break;
    }
    balanceInquiry(numAccount);
        break;

         case 'D':
    printf("Account number?\n");
    if(scanf("%d" ,&numAccount)!=1){
        printf("error input in Account number\n");
    break;
    }
     printf("amount deposit?\n");
    if(scanf("%lf" ,&deposit)!=1){
         printf("error input in amount deposit\n");
    break;
    }
    depositToAccount(numAccount,deposit);
        break;

         case 'W':
    printf("Account number?\n");
    if(scanf("%d" ,&numAccount)!=1){
        printf("error input in Account number\n");
    break;
    }
     printf("amount withdawal?\n");
    if(scanf("%lf" ,&withdawal)!=1){
         printf("error input in amount withdawal\n");
    break;
    }
    withdawalFromAccount(numAccount,withdawal);
        break;

        case 'C':
        printf("Account number?\n");
       if(scanf("%d" ,&numAccount)!=1){
        printf("error input in Account number\n");
    break;
    }
        closeAccount(numAccount);
        break;
         case 'I':
         printf("interest rate?\n");
         if(scanf("%lf" ,&interest_rate)!=1){
            printf("error input in interest rate\n");
    break; 
         }
        interestRate(interest_rate);
        break;

          case 'P':
         printAllAccounts();
        break;
        
         case 'E':
         closeAllAccounts();
        break;
    
    default:                                       //if the input is not from menu option
     printf("the input operation is not valid \n");
        break;
    }
     } while(operator != 'E');          //while not exist present the nenu again
     

    return 0;
}
