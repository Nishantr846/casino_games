#include <iostream>
#include <string>  // string function
#include <cstdlib> // random numbers
#include <ctime>

using namespace std;

void rules()
{
    cout << "\t\t ===== CASINO NUMBER GUESSING RULES!=====\n";
    cout << "\t1. Choose a number between 1 to 10" << endl;
    cout << "\t2. Winner will get 10 times of his/her bet amount" << endl;
    cout << "\t3. If your guess is wrong, you loose your entire bet amount" << endl;
}

int main()

{
    string playerName; // store player name
    int balance;       // store balance of player
    int bettingAmount;
    int guess;
    int dice; // store the random number
    char choice;
    srand(time(0)); // "seed" the random generator

    cout << "\n\t\t=====WELCOME TO CASINO=====\n\n";
    cout << "\n\n What's your name: " << endl;
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play the game" << endl;
    cin >> balance;

    do
    {
        rules();
        cout << "\n Your current balance is " << balance << endl;
        cout << "Hey, " << playerName << " Enter the bet amount: " << endl;
        cin >> bettingAmount;

        if (bettingAmount > balance)
        {
            cout << "Betting amount cannot be more than current balance\n"
                 << "\nRe-enter the balance" << endl;
        }

    } while (bettingAmount > balance);
    do
    {
        cout << "Guess any number between 1 & 10: ";
        cin >> guess;
        if (guess <= 0 || guess > 10)
        {
            cout << "Number should be between 1 & 10\n"
                 << "Re-enter the number: \n";
        }
    } while (guess <= 0 || guess > 10);
    dice = rand() % 10 + 1; // Te generate a random number between 1 to 10.
    if (dice == guess)
    {
        cout << "CONGRATULATIONS, YOU HAVE WON" << bettingAmount * 10 << endl;
        balance += bettingAmount * 10;
        cout << "Total Balance is: " << balance << endl;
    }
    else
    {
        cout << "Oops! You lost " << bettingAmount << endl;
        balance -= bettingAmount;
        cout << "Total Balance Left is: " << balance << endl;
    }
    if (balance == 0)
    {
        cout << "You have no money to play" << endl;
        // break;
    }
    // cout << "Do want to play again? (Y/N)" << endl;
    // cin >> choice;
}