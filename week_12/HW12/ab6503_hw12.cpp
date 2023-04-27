#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Money{
private:
    long allCents;

public:
    // Constructors
    Money(); //Default Constructor
    Money(long dollars);
    Money(long dollars, int cents);
    // Accessors & Mutators (getters & setters)
    double getAllCents() const;
    // Overloaded Operators
    friend Money operator +(const Money& amt1, const Money& amt2);
    friend Money operator -(const Money& amt1, const Money& amt2);
    Money& operator +=(const Money& rhs);
    friend istream& operator >>(istream& ins, Money& amt);
    friend ostream& operator <<(ostream& outs, const Money& amt);
    
};

class Check{
private:
    int number;
    Money amt;
    bool isCashed;

public:
    // Constructors
    Check(); //Default Constructor
    Check(int number, long dollars, bool isCashed);
    Check(int number, long dollars, int cents, bool isCashed);
    // Accesors & Mutators (getters and setters)
    int getNumber() const;
    Money getAmt() const;
    bool getIsCashed() const;
    // Overloaded Operators
    friend bool operator <(const Check& lhs, const Check& rhs);
    friend istream& operator >>(istream& ins, Check& check);
    friend ostream& operator <<(ostream& outs, const Check& check);
};

void introPrompt();
void checkRulesPrompt(int& checkCount);
void depositRulesPrompt(int& depositCount);
void prevAccountBalancePrompt(Money& previousBalance);
void seperator();
int charToInt(char cent);
void fillChecksArray(Check checks[], int checkCount);
void fillDepositsArray(Money deposits[], int depositCount);
Money getCashedChecksTotal(const Check checks[], int checkCount);
Money getNonCashedChecksTotal(const Check checks[], int checkCount);
Money getDepositsTotal(const Money deposits[], int depositCount);
void cashedChecksList(const Check checks[], int checkCount);
void nonCashedChecksList(const Check checks[], int checkCount);

int main() {

    introPrompt();
    seperator();

    // checks
    int checkCount;
    checkRulesPrompt(checkCount);

    Check* checks = new Check[checkCount];
    fillChecksArray(checks, checkCount);
    seperator();

    // deposits
    int depositCount;
    depositRulesPrompt(depositCount);

    Money* deposits = new Money[depositCount];
    fillDepositsArray(deposits, depositCount);
    seperator();

    // previous account balance
    Money previousBalance;
    prevAccountBalancePrompt(previousBalance);
    seperator();

    // build aggregator Money objects
    Money cashedCheckTotal = getCashedChecksTotal(checks, checkCount);
    Money nonCashedCheckTotal = getNonCashedChecksTotal(checks, checkCount);
    Money depositsTotal = getDepositsTotal(deposits, depositCount);
    Money bankBalance = previousBalance - cashedCheckTotal + depositsTotal;
    Money personalBalance = previousBalance - (cashedCheckTotal + nonCashedCheckTotal) + depositsTotal;

    // display totals
    cout << "Summary Of Totals: " << endl << endl;
    cout << "Cashed Checks: " << cashedCheckTotal << endl;
    cout << "Deposits: " << depositsTotal << endl;
    cout << "Bank Ledger Account Balance: " << bankBalance << endl;
    cout << "Personal Ledger Account Balance: " << personalBalance << endl;
    cout << "Bank and Personal Ledger Difference (Non-cashed Checks): " << nonCashedCheckTotal << endl;
    seperator();

    // display lists of cash and non-cashed checks
    sort(checks, checks + checkCount);
    cashedChecksList(checks, checkCount);
    nonCashedChecksList(checks, checkCount);


    delete [] checks; 
    delete [] deposits;

    return 0;
};

//Non-Member functions
void introPrompt(){
    cout << endl;
    cout << "Checkbook Balancing Program" << endl;
}

void checkRulesPrompt(int& checkCount){
    cout << "Rules for entering checks: " << endl << endl;
    cout << "1) Please enter the checks in a seperate line." << endl;
    cout << "2) For each check, enter the serial number of the check, the amount of the check, and whether or not it has been cashed (each criteria seperated by a space)." << endl;
    cout << "3) Use the exact order when entering check details as listed in rule #2." << endl;
    cout << "4) The number of the check should be a non-negative number." << endl;
    cout << "5) The amount of the check should be in the format: ####.##" << endl;
    cout << "6) Enter y if the check has been cashed, enter n if the check has not been cashed." << endl;
    cout << "Ex: Cashed Check = \"1 17.00 y\" or Non-cashed Check = \"5 35.00 n\"" << endl << endl;

    cout << "Please enter the number of checks you will be inserting today: ";
    cin >> checkCount;
}

void depositRulesPrompt(int& depositCount){
    cout << "Rules for entering deposits: " << endl << endl;
    cout << "1) Please enter the deposits each in a seperate line." << endl;
    cout << "2) The amount of a deposit should be in the following format: ####.##" << endl << endl;

    cout << "Please enter the number of deposits you will be inserting today: ";
    cin >> depositCount;
}

void prevAccountBalancePrompt(Money& previousBalance){
    cout << "Rules for entering previous account balance: " << endl << endl;
    cout << "1) The amount of the previous account balance should be in the following format: ####.##" << endl << endl;
    
    cout << "Please enter the previous account balance: ";
    cin >> previousBalance;
}

void seperator(){
    cout << "-----------------------------------------------------" << endl << endl;
}

int charToInt(char cent){
    return static_cast<int>(cent) - static_cast<int>('0');
}

void fillChecksArray(Check checks[], int checkCount){
    if(checkCount != 0){
        cout << "Please enter your checks: " << endl; 

        for (int i = 0; i < checkCount; i++){
            cin >> checks[i];
        }
    }
}

void fillDepositsArray(Money deposits[], int depositCount){
    if(depositCount != 0){
        cout << "Enter your deposits: " << endl;

        for (int i = 0; i < depositCount; i++){
            cin >> deposits[i];
        }
    }  
}

Money getCashedChecksTotal(const Check checks[], int checkCount){
    Money temp;

    for (int i = 0; i < checkCount; i++){
        if(checks[i].getIsCashed()){
            temp += checks[i].getAmt();
        }
    }

    return temp;
}

Money getNonCashedChecksTotal(const Check checks[], int checkCount){
    Money temp;

    for (int i = 0; i < checkCount; i++){
        if(!checks[i].getIsCashed()){
            temp += checks[i].getAmt();
        }
    }

    return temp;
}

Money getDepositsTotal(const Money deposits[], int depositCount){
    Money temp;

    for (int i = 0; i < depositCount; i++) {
        temp += deposits[i];
    }

    return temp;
}

void cashedChecksList(const Check checks[], int checkCount){
    cout << "List of Cashed Checks: " << endl;
    for (int i = 0; i < checkCount; i++){
        if(checks[i].getIsCashed()){
            cout << checks[i] << endl;
        }
    }
    cout << endl;
}

void nonCashedChecksList(const Check checks[], int checkCount){
    cout << "List of Non-Cashed Checks: " << endl; 
    for (int i = 0; i < checkCount; i++){
        if(!checks[i].getIsCashed()){
            cout << checks[i] << endl;
        }
    }
    cout << endl;
}

//Money Class Constructors - Member Initalizers
Money::Money(){
    allCents = 0;
}

Money::Money(long dollars){
    allCents = dollars * 100;
}

Money::Money(long dollars, int cents){
    if (dollars * 100 + cents < 0){
        cout << "Error: You have entered a negative amount of combined dollars and cents." << endl;
        exit(1);
    }

    allCents = dollars * 100 + cents;
}

//Money Class - Public Member Functions
double Money::getAllCents() const {
    return allCents * 0.01;
}

Money operator +(const Money& amt1, const Money& amt2){
    Money temp;
    temp.allCents = amt1.allCents + amt2.allCents;

    return temp;
}

Money operator -(const Money& amt1, const Money& amt2){
    Money temp;
    temp.allCents = amt1.allCents - amt2.allCents;

    return temp;
}

Money& Money::operator+=(const Money& rhs){
    this->allCents += rhs.allCents;

    return *this;
}


istream& operator >>(istream& ins, Money& amt){
    char decimal, tensCent, onesCent;
    long dollars;
    int cents;

    ins >> dollars >> decimal >> tensCent >> onesCent;

    if (decimal != '.' || !isdigit(tensCent) || !isdigit(onesCent)){
        cout << "Error: Illigal entry for the money input" << endl;
        cout << "Please use the following format: ####.##" << endl;
        exit(1);
    }

    dollars = dollars * 100;
    tensCent = charToInt(tensCent) * 10;
    onesCent = charToInt(onesCent);
    cents = tensCent + onesCent;

    amt.allCents = dollars + cents;

    return ins;
}

ostream& operator <<(ostream& outs,const Money& amt){
    long totalCents, dollars, cents;
    totalCents = labs(amt.allCents);
    dollars = totalCents / 100;
    cents = totalCents % 100;

    if (amt.allCents < 0){
        outs << "-$" << dollars << '.';
    }
    else{
        outs << '$' << dollars << '.';
    }

    if (cents < 10){
        outs << '0';
    }
    
    outs << cents;

    return outs; 

}


//Check Class Constructors - Member Initializers 
Check::Check(){
    number = 0;
    amt = Money();
    isCashed = false;
}

Check::Check(int number, long dollars, bool isCashed){
    number = number;
    amt = Money(dollars);
    isCashed = isCashed;
}

Check::Check(int number, long dollars, int cents, bool isCashed){
    number = number;
    amt = Money(dollars, cents);
    isCashed = isCashed; 
}

//Check Class - Public Member Functions 
int Check::getNumber() const {
    return number;
}

Money Check::getAmt() const {
    return amt;
}

bool Check::getIsCashed() const {
    return isCashed;
}

bool operator <(const Check& lhs, const Check& rhs){
    return lhs.number < rhs.number;
}

istream& operator >>(istream& ins, Check& check){
    string isCashed;

    ins >> check.number >> check.amt >> isCashed;

    if (isCashed == "y"){
        check.isCashed = true;
    }
    else if (isCashed == "n"){
        check.isCashed = false;
    }
    else {
        cout << "Error: Illigal symbol used for cashed or non-cashed check" << endl;
        cout << "Please use y or n to represent a cashed or non-cashed check, respectively.";
        exit(1);
    }

    return ins;
}

ostream& operator <<(ostream& outs,const Check& check){
    outs << check.number << ' ' << check.amt  << ' ';

    if(check.isCashed){
        outs << "Cashed";
    }
    else{
        outs << "Non-Cashed";
    }

    return outs;
}