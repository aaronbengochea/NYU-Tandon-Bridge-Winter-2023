#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {

    srand(time(0));

    int randomNumber, base, mod, guessTotal, guessTaken, guess, min, max;

    base = 100;
    mod = 1;
    min = mod;
    max = base;

    guessTotal = 5;
    guessTaken = 1;

    randomNumber = (rand() % base) + mod;

    cout << "Random Number: " << randomNumber << endl;

    cout << "I thought of a number between 1 and 100! Try to guess it."<< endl;

    while (guessTotal > 0){
        cout << "Range: [" << min << ", " << max << "], Number of guesses left: " << guessTotal << endl;
        cout << "Your guess: ";
        cin >> guess;
        if (guess > randomNumber){
            cout << "Wrong! My number is smaller." << endl;
            max = guess;
            
        }
        else if (guess < randomNumber){
            cout << "Wrong! My number is bigger." << endl;
            min = guess;
        }
        else if (guess == randomNumber){
            if (guessTaken == 1){
                cout << "Congrats! You guessed my number in " << guessTaken << " guess.";
                break;
            }
            else{
                cout << "Congrats! You guessed my number in " << guessTaken << " guesses.";
                break;
            }
            
        }

        guessTotal--;
        guessTaken++;
        cout << endl;
    }

    if (guessTotal == 0){
        cout << "Out of guesses, my number is " << randomNumber;
    }


    return 0;
}