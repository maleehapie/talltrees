//NUMBER GUESSING GAME 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;
int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    bool guessedCorrectly = false;
    while (!guessedCorrectly) {
        cout << "Guess the number between 1 and 100: ";
        cin >> userGuess;
        if (userGuess == randomNumber) {
            guessedCorrectly = true;
            cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
        } else if (userGuess > randomNumber) {
            cout << "Oops! Your guess is too high. Try again." << endl;
        } else {
            cout << "Oops! Your guess is too low. Try again." << endl;
        }
    }
    return 0;
}