#include <iostream>
using namespace std;
bool check_double_palindrome(int *x,int pos,int n)
{
    // check for odd string
    if(n%2==1)
    {
        return(0);
    }
    // now check for each even position
    if(pos<n/2)
    {
        if(x[pos]==x[pos+1] && x[pos]==x[n-1-pos] && x[pos]==x[n-1-pos-1])
        {
            return(check_double_palindrome(x,pos+2,n));
        }
        else
        {
            return(0);
        }
    }
    else
    {
        return(1);
    }
    return(1);
}

int main() {
    int x[]={1,1,1,1};
    int y[]={1,1};
    int z[]={4,5,5,4};
    int a[]={3,3,2,2,9,9,3,3};
    int b[]={3,3,2,2,1,1,2,2,3,3};
    int c[]={3,3,1,1,3,3};


    cout<<"x"<<(check_double_palindrome(x,0,4))<<"\n";
    cout<<"y"<<(check_double_palindrome(y,0,2))<<"\n";
    cout<<"z"<<(check_double_palindrome(z,0,4))<<"\n";
    cout<<"a"<<(check_double_palindrome(a,0,8))<<"\n";
    cout<<"b"<<(check_double_palindrome(b,0,10))<<"\n";
    cout<<"c"<<(check_double_palindrome(c,0,6))<<"\n";
}