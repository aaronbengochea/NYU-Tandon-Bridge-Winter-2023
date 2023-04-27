#include <iostream>
using namespace std;

void printArray(int arr[], int arrLen) {

    for (int i = 0; i < arrLen; i++) {
        cout << arr[i];

        if (i != arrLen - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

int lowestCostOnBoard(int arr[], int arrLen) {
    if (arrLen <= 3) {
        return arr[arrLen - 1];
    } 
    else {
        int oneMove = lowestCostOnBoard(arr, arrLen - 1);
        int twoMove = lowestCostOnBoard(arr, arrLen - 2);

        if (oneMove < twoMove) {
            return oneMove + arr[arrLen - 1];
        } 
        else {
            return twoMove + arr[arrLen - 1];
        }
    }
}

int main() {
    int game[] = { 0, 3, 80, 6, 57, 10 };
    int gameLen = sizeof(game) / sizeof(*game);

    cout << "Game Board: ";
    printArray(game, gameLen);
    cout << "Cheapest path on board: " << lowestCostOnBoard(game, gameLen) << endl;


    return 0;
}

