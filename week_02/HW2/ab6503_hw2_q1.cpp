#include <iostream> 
using namespace std;

const int QUARTER_VALUE = 25;
const int DIME_VALUE = 10;
const int NICKEL_VALUE = 5;
const int PENNY_VALUE = 1;

int main () {

    int quarters, dimes, nickels, pennies, total, total_dollars, total_cents;
    
    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    total = ((quarters * QUARTER_VALUE) + (nickels * NICKEL_VALUE) + (dimes * DIME_VALUE) + (pennies * PENNY_VALUE));


    total_dollars = total / 100;
    total_cents = total % 100;


    if ((total_dollars == 1) && (total_cents == 1)){
        cout << "The total is " << total_dollars << " dollar and " << total_cents << " cent"; 
    }
    else if (total_dollars == 1) {
        cout << "The total is " << total_dollars << " dollar and " << total_cents << " cents";  
    }
    else if (total_cents == 1) {
        cout << "The total is " << total_dollars << " dollars and " << total_cents << " cent";  
    }
    else {
    cout << "The total is " << total_dollars << " dollars and " << total_cents << " cents";
    }


    return 0;
}