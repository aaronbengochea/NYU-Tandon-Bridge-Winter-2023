#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num,int& outCountDivs, int& outSumDivs){
    int i;
    int n = num;
    int count = outCountDivs;
    int sum = outSumDivs;

    for (i=1;i<=sqrt(n);i++){
        if (n % i == 0){
            //cout << i << " ";
            count++;
            sum += i;
        }
    }

    i--;

    for (i;i > 1; i--){
        if (n % i == 0){
            //cout << (n/i) << " ";
            count++;
            sum += (n/i);
        }
    }

    outCountDivs = count;
    outSumDivs = sum;
}

bool isPerfect(int num){
    int n = num;
    int outCountDivs = 0, outSumDivs = 0;
    bool value; 

    analyzeDividors(n, outCountDivs, outSumDivs);


    if (num == outSumDivs){
        value = true;
    }
    else if (num != outSumDivs){
        value = false;
    }

    return value;
}

void isPerfectAmicible(int num){
    int n = num;
    bool perfect;
    int outCountDivsOne = 0;
    int outCountDivsTwo = 0;
    int outSumDivsOne = 0;
    int outSumDivsTwo = 0;
    int amicibleStorage = 0;


    cout << "Perfect Numbers: " << endl;
    for (int i = 2; i <= n; i++){
        perfect = isPerfect(i);
        if (perfect == 1){
            cout << i << " ";
        }
    }

    cout << endl << endl;

    cout << "Amicible Numbers: " << endl;
    for (int i = 2; i < n; i++){
        if (i != amicibleStorage){
            analyzeDividors(i,outCountDivsOne,outSumDivsOne);

            if (outSumDivsOne <= n){
                analyzeDividors(outSumDivsOne, outCountDivsTwo, outSumDivsTwo);
            }
        }

        if (outSumDivsTwo == i && isPerfect(i) == 0 && outSumDivsOne > outSumDivsTwo){
            cout << outSumDivsTwo << " " << outSumDivsOne << " ";
            amicibleStorage = outSumDivsOne;
        }

        outCountDivsOne = 0;
        outCountDivsTwo = 0;
        outSumDivsOne = 0;
        outSumDivsTwo = 0;

    }
}

int main () {

    int num;

    cout << "Perfect Numbers and Amicable Numbers:" << endl;
    cout << "Please enter a number greater than 2: ";
    cin >> num;

    cout << endl;

    cout << "Number selected: " << num << endl << endl;

    isPerfectAmicible(num);

    return 0;
}