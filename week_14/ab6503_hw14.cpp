#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& vect);
vector<int> findMinMax(const vector<int>& vect, int low, int high);
vector<int> mergeMinMax(const vector<int>& minMaxVectOne, const vector<int>& minMaxVectTwo);

int main() {
    vector<int> dataVect = {100, 2, 6, -3, 18, 27, -5, -1000};
    vector<int> dataMinMaxVect = findMinMax(dataVect, 0, dataVect.size() - 1);

    int j = 1;

    cout << "Entire Data Vector: ";
    printVector(dataVect);

    cout << "Data's Min and Max Vector: ";
    printVector(dataMinMaxVect);

    cout << "Min: " << dataMinMaxVect[0] << endl;
    cout << "Max: " << dataMinMaxVect[1] << endl;


    return 0;
}


void printVector(const vector<int>& vect){
    for (int i: vect){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> findMinMax(const vector<int>& vect, int low, int high) {
    if (low == high) {
        vector<int> tempMinMaxVect;
        tempMinMaxVect.push_back(vect[low]);
        tempMinMaxVect.push_back(vect[low]);

        return tempMinMaxVect;
    } else {
        int mid = low + (high - low) / 2;
        vector<int> minMaxVectOne = findMinMax(vect, low, mid);
        vector<int> minMaxVectTwo = findMinMax(vect, mid + 1, high);

        return mergeMinMax(minMaxVectOne, minMaxVectTwo);
    }
}

vector<int> mergeMinMax(const vector<int>& minMaxVectOne, const vector<int>& minMaxVectTwo) {
    vector<int> tempMinMaxVect;
    int vectMin = min(minMaxVectOne[0], minMaxVectTwo[0]);
    int vectMax = max(minMaxVectOne[1], minMaxVectTwo[1]);
    tempMinMaxVect.push_back(vectMin);
    tempMinMaxVect.push_back(vectMax);

    return tempMinMaxVect;
}