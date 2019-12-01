#ifndef myBank_h
#define myBank_h
#define NUM_OF_ACCOUNT 50
extern double bank[NUM_OF_ACCOUNT][2];

int inValidNumAccount(int a);
void openAccount(double a);
void balanceInquiry(int a);
void depositToAccount(int a , double b);
void withdawalFromAccount(int a , double b);
void closeAccount(int a);
void interestRate(double a);
void  printAllAccounts();
void closeAllAccounts();

#endif