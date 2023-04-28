#include <iostream>
#include <array>
using namespace std;


int printMonthCalender(int numOfDays, int startingDay){

    int startDate = startingDay;
    int dayTotal = numOfDays;
    int dateMod = startingDay;
    int dayPosition = 1;
    int dateCounter = 1;
    int i;

    cout << "Mon" << "\t" <<"Tue" << "\t" <<"Wed" << "\t" <<"Thr" << "\t" <<"Fri" << "\t" <<"Sat" << "\t" <<"Sun" << endl;

    while (dateCounter <= dayTotal){
        for (i = 1; i <= 7; i++){
            if (i < dateMod && startDate <=7){
                cout << " " << "\t";
            }
            else if (dateCounter <= dayTotal){
                cout << dateCounter << "\t";
                dateCounter++;
                dayPosition++;
            }

            if (i == 7){
                cout << endl;
            }         
        }
        if (dateCounter < dayTotal){
            i = 1;
        }

        if (dateCounter <= dayTotal){
            dayPosition = 1;
        }

        dateMod = 0;
    }


    return dayPosition;

}


bool leapYear(int year){
    bool value;

    if (year % 4 == 0){
        if (year % 400 == 0 || year % 100 != 0){
            value = true;
        }
    }
    else{
        value = false;
    }

    return value;
}

void printYearCalender(int year, int startingDay){

    //string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    bool leapValue = leapYear(year);
    int daysPerMonth = 31;
    int dayCarryover;


    for (int i = 0; i < 12; i++){
        //cout << months[i] << " " << 2016 << endl;
        if (i == 0){
            cout << "January " << year << endl;
        }
        else if (i == 1){
            cout << "February " << year << endl;
        }
        else if (i == 2){
            cout << "March " << year << endl;
        }
        else if (i == 3){
            cout << "April " << year << endl;
        }
        else if (i == 4){
            cout << "May " << year << endl;
        }
        else if (i == 5){
            cout << "June " << year << endl;
        }
        else if (i == 6){
            cout << "July " << year << endl;
        }
        else if (i == 7){
            cout << "August " << year << endl;
        }
        else if (i == 8){
            cout << "September " << year << endl;
        }
        else if (i == 9){
            cout << "October " << year << endl;
        }
        else if (i == 10){
            cout << "November " << year << endl;
        }
        else if (i == 11){
            cout << "December " << year << endl;
        }


        if (i == 0){
            dayCarryover = printMonthCalender(daysPerMonth,startingDay);
        }

        if (i == 1 && leapValue == 1){
            daysPerMonth = 29;
            dayCarryover = printMonthCalender(daysPerMonth, dayCarryover);
            daysPerMonth = 31;
        }
        else if (i == 1 && leapValue == 0){
            daysPerMonth = 28;
            dayCarryover = printMonthCalender(daysPerMonth, dayCarryover);
            daysPerMonth = 31;
        }

        if (i > 1){
            dayCarryover = printMonthCalender(daysPerMonth,dayCarryover);
        }

        if (i == 2){
            daysPerMonth--;
        }
        else if (i == 3){
            daysPerMonth++;
        }
        else if (i == 4){
            daysPerMonth--;
        }
        else if (i == 5){
            daysPerMonth++;
        }
        else if (i == 7){
            daysPerMonth--;
        }
        else if (i == 8){
            daysPerMonth++;
        }
        else if (i == 9){
            daysPerMonth--;
        }
        else if (i == 10){
            daysPerMonth++;
        }

        cout << endl;

    }
}


int main () {

    int date, year;


    cout << "Please enter a starting day (1-7): ";
    cin >> date;
    cout << "Please enter a year: ";
    cin >> year;
    cout << endl;

    printYearCalender(year, date);




    return 0;
}