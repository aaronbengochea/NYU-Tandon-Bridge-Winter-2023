#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void readFile(ifstream& inFile);
void vectPass(vector<string>& vect, ifstream& inFile);
int elipsisCount(vector<string>& vect);

int main () {
    ifstream inFile;
    vector<string> vect;

    readFile(inFile);
    vectPass(vect, inFile);


    for(string s: vect){
        cout << s << endl;
    }

    cout << "Total Elipse Count: " << elipsisCount(vect) << endl;


}

void readFile(ifstream& inFile){
    string filename;

    cout << "enter the file name: ";
    cin >> filename;
    inFile.open(filename);

    while(inFile.fail()){
        cout << "filename error" << endl;
        cout << "Enter a new file name: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

void vectPass(vector<string>& vect, ifstream& inFile){
    string phrase;

    while(inFile >> phrase){
        vect.push_back(phrase);
    }
}

int elipsisCount(vector<string>& vect){
    int currPhraseSize = 0;
    int totalCount = 0;
    int interimCount = 0;

    for(string s: vect){
        currPhraseSize = s.size();
        for(int i = 0; i < currPhraseSize; i++){
            if (s[i] == '.'){
                interimCount++;
            }

            if (interimCount == 3){
                totalCount++;
                interimCount = 0;
            }

        }
    }

    return totalCount;
}