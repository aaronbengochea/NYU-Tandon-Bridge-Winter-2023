#include <iostream> 
#include <cmath>
using namespace std;

double eApprox(int num){
    double e = 0.0;
    double n = num;
    double base;

    base = (1.0 + 1.0/n);
    e = pow(base, n);

    return e;

}

int main () {

    cout.precision(30);

    cout << "Calculating Euler's Number (constant e): " << endl;
    for (int n = 0; n <= 100; n++){
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }

    cout << endl;
    int limit = 5000000;
    cout << "Euler's Number reaching towards it limit: " << endl;
    cout << "n = " << limit << endl;
    cout << "e = " << eApprox(limit);


    return 0;
}