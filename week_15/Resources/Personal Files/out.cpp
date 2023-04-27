#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream outFile; // ofstream Outfile("outfile.txt") <-- uses the constructor of ofstream to open file directly
    outFile.open("outfile.txt");

    outFile << "Me again" << endl;

    //outFile.close();



    return 0;
}
