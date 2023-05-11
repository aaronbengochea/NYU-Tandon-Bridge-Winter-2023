#include <iostream>
#include <vector>
using namespace std;

class Sorting {
public:
    virtual string worstCaseSorting() = 0;
    virtual void sort(vector<int>& vect) = 0;
};

class InsertionSort : public Sorting {
public:
    string worstCaseSorting();
    void sort(vector<int>& vect);
}






void InsertionSort::sort(vector<int>& vect){
    int target, prev;
    int vectSize = vect.size();

    for(int i = 1; i < vectSize; i++){
        prev = i - 1;
        target = vect[i];

        while(prev >= 0 && vect[prev] > target){
            int store = target;
            target = vect[prev];
            vect[prev] = store;

            prev--;
        }
    }
}