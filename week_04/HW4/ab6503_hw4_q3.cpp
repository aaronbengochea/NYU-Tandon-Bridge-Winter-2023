#include <iostream>
using namespace std;

int main() {
   double n,a;
   int result = 0;
   int position = 1;

   cin >> n;
   
   for (int i=n; n>0; --i) {
     a = (int) n % 2;
     n = (int) n / 2;
     
     result += position * a;
     position *= 10;
   }
   
   cout << result << endl;    
   return 0;
}