#include <iostream>
using namespace std;

int main() {
    int n;
    int lineCounnt, starCount, spaceCount;
    int numberOfSpaces, numberOfStars;

    cout<<"Please enter a positive integer"<<endl;
    cin>>n;

    cout<<"Square"<<endl;
    for(lineCounnt = 1; lineCounnt <= n; lineCounnt += 1){
        // print a sequence of n stars
        for(starCount = 1; starCount <= n; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle  aligned to the left"<<endl;
    for(lineCounnt = 1; lineCounnt <= n; lineCounnt += 1){
        // print a sequence of lineCounnt stars
        for(starCount = 1; starCount <= lineCounnt; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the right"<<endl;
    for(lineCounnt = 1; lineCounnt <= n; lineCounnt += 1) {
        // print a sequence of n-lineCount spaces
        for(spaceCount = 1; spaceCount <= (n-lineCounnt); spaceCount += 1)
            cout<<" ";

        // print a sequence of lineCount stars
        for(starCount = 1; starCount <= lineCounnt; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the right in the incremental approach"<<endl;
    for(lineCounnt = 1, numberOfStars = 1, numberOfSpaces = n-1;
        lineCounnt <= n;
        lineCounnt += 1, numberOfStars += 1, numberOfSpaces -= 1) {
        // print numberOfSpaces spaces
        for(spaceCount = 1; spaceCount <= numberOfSpaces; spaceCount += 1)
            cout<<" ";

        // print numberOfStars stars
        for(starCount = 1; starCount <= numberOfStars; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }
    return 0;
}
