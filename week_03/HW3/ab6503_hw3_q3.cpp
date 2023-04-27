#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main () {

    float a, b, c, resultOne, resultTwo, innerEquation;
    string status;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    innerEquation = (b * b) - 4.0 * a * c;
    
    resultOne = ((b * -1.0) - sqrt(innerEquation)) / (2.0 * a);
    resultTwo = ((b * -1.0) + sqrt(innerEquation)) / (2.0 * a);

    if (innerEquation == 0){
        status = "one real solution";
    }
    else if (innerEquation > 0){
        status = "two real solutions";
    }
    else if (innerEquation < 0){
        status = "two complex solutions";
    }


    if (a == 0 && b == 0 && c == 0){
        status = "a infinite number of solutions";
    }
    else if (a == 0 && b == 0){
        status = "no solution";
    }
    else if (b == 0){
        status = "no real solution";
    }



    cout << "This equation has " << status;

    if (innerEquation == 0 && a != 0 && b !=0){
        cout << " x = " << (float)resultOne;
    }
    else if ((innerEquation > 0) && a != 0 && b != 0){
        cout << " x = " << (float)resultOne << ", " << (float)resultTwo;
    }
    else if ((innerEquation < 0) && a != 0 && b != 0){
        cout << " x = Solution 1, Solution 2";
    }




    return 0;
}