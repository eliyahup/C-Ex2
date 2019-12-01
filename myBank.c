#include <stdio.h>
#include "myBank.h"
#include <math.h>
double bank[NUM_OF_ACCOUNT][2] = {0};        //storge account and status(close/open)

int inValidNumAccount(int a){                // if the input of account not in range
    if(a<901||a>950){
        printf("invalid input the account number not exist\n");
        return 1;
     }
     else return 0;
}

void openAccount(double a){
    if(a<0){
        printf("can't open account with negative deposit\n");
        return;
    }
    for (int i = 0; i < NUM_OF_ACCOUNT; i++){
     if (bank[i][1]==0){                    //if the account number vacant-open acoount
         bank[i][1]=1;
         printf("your account number is: %d\n",901+i);
         bank[i][0] = a;
         bank[i][0] = floorf(100*bank[i][0])/100;     //stroge 2 digit after the point.
         return;
     } 
    }
    {
         printf("don't have a vacant account\n");
     }
    
}
void balanceInquiry(int a){
    if(inValidNumAccount(a)==1){
        return;
    }
    if(bank[a-901][1]==1)
    printf("your balance inquiry is: %0.2lf\n",bank[a-901][0]);
else
    printf("the account not exist\n");
}
void depositToAccount(int a , double b){
    if(inValidNumAccount(a)==1){
        return;
    }
     if(bank[a-901][1]==1){         //posible only if the account already open
    bank[a-901][0] += b;
    bank[a-901][0] = floorf(100*bank[a-901][0])/100;
    printf("The new balance inquiry is: %0.2lf\n",bank[a-901][0]);
     }
     else
     {
          printf("the account not exist\n");
     }
}
void withdawalFromAccount(int a , double b){
    if(inValidNumAccount(a)==1){
        return;
    }
    if(bank[a-901][1]==1&&bank[a-901][0]-b>=0){
    bank[a-901][0] -= b;
     bank[a-901][0] = floorf(100*bank[a-901][0])/100;
    printf("The new balance inquiry is: %0.2lf\n",bank[a-901][0]);
     }
     else if(bank[a-901][1]==0)
     {
          printf("the account not exist\n");
     }else if(bank[a-901][0]-b<0)
     {
         printf("don't have enough money to withdraw from the account\n");
     }  
}
void closeAccount(int a){
     if(inValidNumAccount(a)==1){            //check if account number is in range
        return;
    }
    if(bank[a-901][1]==0){
        printf("the acoount is already colsed\n");
    }
    else{
        bank[a-901][0]=0;
        bank[a-901][1]=0;
    }
}
void interestRate(double a){
    if(a<0){
    printf("interest can't be negative\n");
    return;
    }
    double percent = a/100;
    for(int i = 0; i < NUM_OF_ACCOUNT;i++){
        if(bank[i][1]==1){
            bank[i][0] += bank[i][0]*percent;
            bank[i][0] = floorf(100*bank[i][0])/100;
        }
    }
}
void  printAllAccounts(){
    for(int i = 0; i < NUM_OF_ACCOUNT ;i++){
        if(bank[i][1]==1){
            printf("account number: %d  is balance inquiry %0.2lf\n",i+901, bank[i][0]);
        }
    }
}
void closeAllAccounts(){
    for(int i = 0; i < NUM_OF_ACCOUNT ;i++){
        if(bank[i][1]==1){
            closeAccount(i+901);
        }
    }
}

