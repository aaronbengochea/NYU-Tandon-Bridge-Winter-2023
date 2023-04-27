#include <iostream>
#include <string>
using namespace std;

const float PRIMARY_PER_MINUTE = .40;
const float SECONDARY_PER_MINUTE = .25;
const float WEEKEND_PER_MINUTE = .15;
const float MINUTES_PER_HOUR = 60.0;

int main() {

    string day;
    int callLength;
    float hour, minute, callCost, minuteTrans, aggTime;
    char temp;

    cout << "Day of the week (Ex: Mo, Tu): ";
    cin >> day;
    cout << "Time that the call started (24-hour Notation): ";
    cin >> hour >> temp >> minute;
    cout << "Length of the call (in minutes): ";
    cin >> callLength;


    minuteTrans = minute / MINUTES_PER_HOUR;
    aggTime = hour + minuteTrans;
    



    if (aggTime < 8 || aggTime > 18){
        if (day != "Sa" && day != "Su"){
            callCost = callLength * SECONDARY_PER_MINUTE;
        }
        else{
            callCost = callLength * WEEKEND_PER_MINUTE;
        }
    }

    else if (aggTime > 8 || aggTime < 18){
        if (day != "Sa" && day != "Su"){
            callCost = callLength * PRIMARY_PER_MINUTE;
        }
        else {
            callCost = callLength * WEEKEND_PER_MINUTE;
        }
    }

    cout << hour << minute;
    cout << "Total cost of collect call: $" << callCost;



    return 0;
}