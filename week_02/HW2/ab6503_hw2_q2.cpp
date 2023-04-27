#include <iostream> 
using namespace std;

const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKEL_VALUE = 5;
const int PENNY_VALUE = 1;

void GetCoinBreakdown(int totalDollarAmt,int remainder, int tot[]) {

        int values[] = {QUARTER_VALUE, DIME_VALUE, NICKEL_VALUE, PENNY_VALUE};
        
        for (int i=0; i < end(values) - begin(values);i++ ){
            tot[i] = totalDollarAmt / values[i];
            remainder = totalDollarAmt % values[i];
            totalDollarAmt = remainder;
        }


}

void DeclareCoinValues(int totals[], int &quarters, int &dimes, int &nickels, int &pennies){
    quarters = totals[0];
    dimes = totals[1];
    nickels = totals[2];
    pennies = totals[3];
}

int main () {

    int dollars, cents, total, remainder, quarters, dimes, nickels, pennies; 

    // int values[] = {QUARTER_VALUE, DIME_VALUE, NICKEL_VALUE, PENNY_VALUE};
    int totals[4] = {};
    cout << "Please enter your amount in the format ";
    cout <<	"of dollars and cents separated by a space: " << endl;
    cin >> dollars >> cents; 

    total = (dollars * 100) + cents;

    GetCoinBreakdown(total, remainder, totals);
    DeclareCoinValues(totals, quarters, dimes, nickels, pennies);


    // quarters = totals[0];
    // dimes = totals[1];
    // nickels = totals[2];
    // pennies = totals[3];


    cout << dollars << " dollars and " << cents << " cents are:" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies";
    


    return 0;
}