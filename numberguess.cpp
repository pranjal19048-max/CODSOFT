#include <iostream>
using namespace std;

int main() {
    int secretNumber = 50;   // fixed number
    int guess;
    int attempts = 0;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        attempts = 0;

        cout << "\nNumber Guessing Game Started!" << endl;
        cout << "Guess the number between 1 and 100" << endl;

        while (true) {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess == secretNumber) {
                cout << "Correct! You guessed the number." << endl;
                cout << "Total attempts: " << attempts << endl;
                break;
            }
            else if (guess > secretNumber) {
                cout << "Too high. Try again." << endl;
            }
            else {
                cout << "Too low. Try again." << endl;
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThank you for playing!" << endl;
    return 0;
}
