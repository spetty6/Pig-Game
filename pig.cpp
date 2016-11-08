/*
Program:Pig Game
Author:Samuel Petty
Lab Section:04
Date:4/21/14
Purpose: To create a dice game that lets a user compete with the CPU in a race to 100 points.
Algorithm: 1) Create a loop process for the computer to execute while their is still no winner.
2) The loop should allow the user to continuously input r/R to roll or h/H to hold until a clear winner has been determined
3) Create a random number generator that calculates a single number between 1-6 to resemble a dice roll.
4) After that the game should continue to loop until the user or computer reaches 100 points or more.
*/



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SCORE_LIMIT = 100;
int diceRoll();
int userTurn(int& userTotalScore);
int computerTurn(int& computerTotalScore);

int main()
{
    cout << "This dice game is called Pig: The goal of the game is to be the first to reach  100 points" << endl;
    cout << "On each turn you can either choose r/R to roll or h/H to hold and keep your     current score" << endl;
    cout << "However if either player rolls a 1 then their turn is lost and points for that  turn are lost too" << endl;
    cout << "Good luck and remember don't be a loser" << endl;




    bool win = 1; // this bool shows if the game is over or not. If win is 1 then game is not over.
    int userTotalScore = 0, computerTotalScore = 0;

    cout << "Your turn: To begin press r/R to roll";
    if ((userTotalScore < SCORE_LIMIT) && (computerTotalScore < SCORE_LIMIT)) // first roll of game so you should not choose hold.
    {
        win = 1;
    }
    else
    {
        win = 0;
    }
    do
    {
        cout << " The Computers Score is : " << computerTotalScore << endl;

        userTurn(userTotalScore);
        computerTurn(computerTotalScore);
    }
    while(win = 1);

    if ((win = 0) && (userTotalScore > computerTotalScore))
    {
        cout << "Congratulations your a winner!!!!";
    }
    else
    {
        cout << "Sorry you lost better luck next time";
    }


    return 0;
}

//calculates human score during their turn
int userTurn(int & userTotalScore)
{
    int currentScore = 0;
    int previousRoll;
    char userChoice;

    cout << "Your total score is: " << userTotalScore << "." << endl;
    cout << "Press r/R to roll again, or h/H to hold." << endl;
    cin >> userChoice;

    while (userChoice == 'r')
    {
        srand (time(NULL));
        previousRoll = diceRoll();
        if (previousRoll == 1)
        {
            cout << "Sorry you rolled a 1 you lose your turn and all points received for this turn" << endl;
            break;
        }
        else
        {
            currentScore += previousRoll; // calculates user's total points for game.
            cout << "You rolled a " << previousRoll << ". Your score for this turn is: " << currentScore << endl;
            cout << "Press r/R to roll again, or h/H to hold." << endl;
            cin >> userChoice;
        }
    }
    while (userChoice == 'h')
    {
        userTotalScore += currentScore; // calculates user score for turn.
        break;
    }

    return userTotalScore; // Returns the user score for game.
}
// calculates the computer's score during it's turn.
int computerTurn(int& computerTotalScore)
{
    int currentScore = 0;
    int previousRoll;

    cout << "Computer's total score is: " << computerTotalScore << "." << endl;
    while ((currentScore <= 20) && (currentScore != 1))
    {
        previousRoll = diceRoll();
        if (previousRoll == 1)
        {
            cout << "Good news the computer rolled a 1 so it loses it's turn and points received for it's turn" << endl;
            break;
        }
        else
        {
            currentScore += previousRoll; // calculates computer's total points for the game.
            cout << "The computer rolled a " << previousRoll << ". Computer's score this turn is: " << currentScore << endl;
        }
    }
    if(currentScore >= 20)
    {
        computerTotalScore += currentScore; // calculates user score for turn.
        cout << "After the computer's turn, they received this many points:  " << previousRoll << endl;
    }

    return computerTotalScore; // returns computers score for the game.
}
// random number generator for dice roll.
int diceRoll()
{
    int roll;

    roll = (int)(rand()%6)+1; // generates a single number between 1-6.

    return roll; // returns number for dice roll between 1-6.
}
