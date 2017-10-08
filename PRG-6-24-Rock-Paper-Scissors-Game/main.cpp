//
//  main.cpp
//  PRG-6-24-Rock-Paper-Scissors-Game
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that lets the user play the game of Rock, Paper, Scissors against the
//  computer. The program should work as follows:
//
//  1. When the program begins, a random number in the range of 1 through 3 is generated.
//     If the number is 1, the computer has chosen rock. If the number is 2, then
//     the computer has chosen paper. If the number is 3, then the computer has chosen
//     scissors (don't display the computer's choice yet)
//  2. The user enters his or her choice of "rock", "paper", or "scissors" at the keyboard.
//     (You can use a menu if you prefer)
//  3. The computer's choice is displayed.
//  4. A winnder is selected according the the following rules:
//     * If one player chooses rock and the other player chooses scissors, then rock wins.
//       (The rock smashes the scissors.)
//     * If one player chooses scissors and the other player chooses paper, then scissors wins.
//       (Scissors cuts paper.)
//     * If one player chooses paper and the other player chooses rock, then paper wins.
//       (Paper wraps rock.)
//     * If both players make the same choice, the game must be played again to determine
//       the winner.
//
//Be sure to divide the program into functions that preform each major task.


#include <iostream>
#include <cmath>

using namespace std;

void randomNumberSelection(int &);
void determineCase(int, string &);
void getUserChoice(string &);
void determinePlayerCase(string, int &);
void determineWinner(int, int, string, string, bool &);

int main()
{
    int intChoiceComputer;
    int intChoicePlayer;
    
    string strChoiceComputer;
    string strChoicePlayer;
    
    bool booIsTie = false;
    
    // Wrap entire sequence of game in a do/while loop
    // that tests whether there has been a tie or not
    // when tested TRUE the loop starts again
    // until it tests FALSE
    do
    {
    randomNumberSelection(intChoiceComputer);
    
    determineCase(intChoiceComputer, strChoiceComputer);
    
    getUserChoice(strChoicePlayer);
    
    determinePlayerCase(strChoicePlayer, intChoicePlayer);
    
    determineWinner(intChoiceComputer, intChoicePlayer, strChoiceComputer, strChoicePlayer, booIsTie);
    } while(booIsTie);
    
    return 0;
}

void randomNumberSelection(int &refChoiceComputer)
{
    const int INT_MAX_VALUE = 3;
    
    unsigned seed = time(0);
    
    srand(seed);
    
    refChoiceComputer = rand() % (INT_MAX_VALUE) + 1;
}

void determineCase(int intChoiceComputer, string &refChoice)
{
    switch(intChoiceComputer)
    {
        case 1:
            refChoice = "rock";
            break;
        case 2:
            refChoice = "paper";
            break;
        case 3:
            refChoice = "scissors";
            break;
    }
}

void getUserChoice(string &refStrChoice)
{
    cout << "Please enter your choice (rock, paper, or scissors):\n";
    cin >> refStrChoice;
    
    while(refStrChoice != "rock" && refStrChoice != "Rock" && refStrChoice != "ROCK" &&
          refStrChoice != "paper" && refStrChoice != "Paper" && refStrChoice != "PAPER" &&
          refStrChoice != "scissors" && refStrChoice != "Scissors" && refStrChoice != "SCISSORS")
    {
        cout << "Please enter a valid choice (rock, paper, or scissors):\n";
        cin >> refStrChoice;
    }
}

void determinePlayerCase(string strChoicePlayer, int &refChoiceInt)
{
    if(strChoicePlayer == "rock" || strChoicePlayer == "Rock" || strChoicePlayer == "ROCK")
    {
        refChoiceInt = 1;
    }
    else if(strChoicePlayer == "paper" || strChoicePlayer == "Paper" || strChoicePlayer == "PAPER")
    {
        refChoiceInt = 2;
    }
    else if(strChoicePlayer == "scissors" || strChoicePlayer == "Scissors" || strChoicePlayer == "SCISSORS")
    {
        refChoiceInt = 3;
    }
    else
    {
        cout << "ERROR ASSIGNING PLAYER CHOICE TO CASE\n";
        return;
    }
}

void determineWinner(int intChoiceComputer, int intChoicePlayer, string strChoiceComputer, string strChoicePlayer, bool &refTieCheck)
{
    // rock beats scissors 1 = 3
    // scissors beats paper 3 = 2
    // paper beats rock 2 = 1
    
    cout << "Computer chooses " << strChoiceComputer << endl;
    cout << "Player chooses " << strChoicePlayer << endl;
    
    if(intChoiceComputer == 1 && intChoicePlayer == 3)
    {
        cout << "Rock beats scisors.\n";
        cout << "Computer wins.\n";
        refTieCheck = false;
    }
    else if(intChoiceComputer == 3 && intChoicePlayer == 2)
    {
        cout << "Scissors beats paper.\n";
        cout << "Computer wins.\n";
        refTieCheck = false;
    }
    else if(intChoiceComputer == 2 && intChoicePlayer == 1)
    {
        cout << "Paper beats rock.\n";
        cout << "Computer wins.\n";
        refTieCheck = false;
    }
    else if(intChoiceComputer == 3 && intChoicePlayer == 1)
    {
        cout << "Rock beats scisors.\n";
        cout << "Player wins.\n";
        refTieCheck = false;
    }
    else if(intChoiceComputer == 2 && intChoicePlayer == 3)
    {
        cout << "Scissors beats paper.\n";
        cout << "Player wins.\n";
        refTieCheck = false;
    }
    else if(intChoiceComputer == 1 && intChoicePlayer == 2)
    {
        cout << "Paper beats rock.\n";
        cout << "Player wins.\n";
        refTieCheck = false;
    }
    else if((intChoiceComputer == 1 && intChoicePlayer == 1) ||
            (intChoiceComputer == 2 && intChoicePlayer == 2) ||
            (intChoiceComputer == 3 && intChoicePlayer == 3))
    {
        cout << "Computer and player chose same.\n";
        cout << "There was a tie. No winner determined.\n";
        refTieCheck = true;
    }
    else
    {
        cout << "ERROR DETERMINING WINNER" << endl;
    }
}

