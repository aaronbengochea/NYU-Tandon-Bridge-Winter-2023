#include <iostream>
using namespace std;

const int HOURS = 24;
const int MINUTES = 60;


int main () {

    int johnDays, johnHours, johnMinutes, billDays, billHours, billMinutes, totalDays, totalHours, totalMinutes, leftoverMinutes, leftoverHours;

    cout << "Please enter the number of days John has worked: ";
    cin >> johnDays;
    cout << "Please enter the number of hours John has worked: ";
    cin >> johnHours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> johnMinutes;

    cout << endl;
    
    cout << "Please enter the number of days Bill has worked: ";
    cin >> billDays;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> billHours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> billMinutes;

    totalMinutes = (johnMinutes + billMinutes) % MINUTES;
    leftoverMinutes = (johnMinutes + billMinutes) / MINUTES;
    totalHours = (johnHours + billHours + leftoverMinutes) % HOURS;
    leftoverHours = (johnHours + billHours + leftoverMinutes) / HOURS;
    totalDays = johnDays + billDays + leftoverHours;

    cout << endl;

    cout << "The total time both of them worked together is: " << totalDays << " days, ";
    cout << totalHours << " hours and " << totalMinutes << " minutes." << endl;







    return 0;
}