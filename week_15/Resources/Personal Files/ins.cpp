#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    int id;
    double testScore;
    string name;
};

void openInputFile(ifstream& inFile){
    string filename;
    cout << "What filename? ";
    cin >> filename;

    inFile.open(filename);
    while(!inFile){
        cout << "File failed to open" << endl;
        cout << "what filename? ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }


}

void openOutputFile(ofstream& outFile){
    string filename;
    cout << "Desired filename? ";
    cin >> filename;

    outFile.open(filename);
    if (outFile.fail()){
        cout << "Output file failed to save.";
        exit(1);
    }

}

int main () {
    ifstream inFile, inFile2;
    openInputFile(inFile);
    openInputFile(inFile2);


    // vector<int> v;

    // int temp;   // does both reading and testing to see it was successful
    // while (inFile >> temp){ // reads in a piece to temp, it then will do it again
    //     v.push_back(temp);
    // }

    // double sum;
    // for (int item : v) {
    //     sum += item;
    // }

    // cout << "the avg: " << sum / v.size();


    vector<Student> vs;
    Student temp;

    while (inFile >> temp.id) {
        inFile >> temp.testScore;
        inFile.ignore(9999,' '); // you can use other forms as well, ' ' worked for me here even though i was using tab in the readin file
        getline(inFile, temp.name);
        vs.push_back(temp);

    }

    while (inFile2 >> temp.id) {
        inFile2 >> temp.testScore;
        inFile2.ignore(9999,' '); // you can use other forms as well, ' ' worked for me here even though i was using tab in the readin file
        getline(inFile2, temp.name);
        vs.push_back(temp);

    }

    inFile.close();

    cout << "Students with scores over 90: " << endl;
    for (Student s : vs){
        if (s.testScore >= 90) {
            cout << s.id << ' ' << s.name << endl;
        }

    }


    ofstream outFile; // ofstream Outfile("outfile.txt") <-- uses the constructor of ofstream to open file directly
    openOutputFile(outFile);

    outFile << "Students with scores over 90: "  << endl;
    outFile << "ID" << '\t' << "Score" << '\t' << "Name" << endl;
    for (Student s : vs) {
        if (s.id <= 12) {
            if (s.name.size() > 5){
                outFile << s.id << '\t' << s.testScore << '\t' << '\t' << s.name << endl;
            }
            else {
                outFile << s.id << '\t' << s.testScore << '\t' << s.name << endl;
            }
        }
    }

    outFile.close();

    return 0;
}