// Programmer: AJ Cassell (@BrotatoBoi).
// Program Name: Rock Paper Scissors.
// Date: November/03/2021.
// Description: This program is a rock paper scissors game.


// Import the libraries.
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Check userChoice agains compChoice.
void check_choices(char uChoice, int cChoice) {
    // Check who won.
    if(uChoice == 'R' && cChoice == 1 || uChoice == 'P' && cChoice == 2 || uChoice == 'S' && cChoice == 3) {
        std::cout << "Tie!" << std::endl;
    } else if (uChoice == 'R' && cChoice == 2 || uChoice == 'P' && cChoice == 3 || uChoice == 'S' && cChoice == 1) {
        std::cout << "Sorry, you lose!" << std::endl;
    } else {
        std::cout << "You win!" << std::endl;
    }
}


// Ask if player wants to play again.
bool play_again() {
    char again;
    
    // Ask if player wants to play again.
    while(true) {
        std::cout << "Would you like to play again?" << std::endl;
        std::cin >> again;
        again = toupper(again);

        if (again == 'Y' || again == 'N') {
            break;
        }
    }

    // If player wants to play again, return true.
    if(again == 'Y') {
        return true;
    } else {
        return false;
    }
}


// Main function.
int main() {
    // Define variables.
    char userChoice;
    int computerChoice;
    bool playAgain = true;

    // Seed the random number generator.
    srand(time(NULL));

    // Loop the game.
    while(playAgain) {
        // Ask the user for their choice.
        std::cout << "Please choose one of the following: R for Rock, P for Paper, or S for Scissors." << std::endl;
        std::cin >> userChoice;
        userChoice = toupper(userChoice);

        // Generate the computer's choice.
        computerChoice = rand() % 3 + 1;

        // Print the users choice.
        if(userChoice == 'R') {
            std::cout << "You chose Rock." << std::endl;
        } else if(userChoice == 'P') {
            std::cout << "You chose Paper." << std::endl;
        } else if(userChoice == 'S') {
            std::cout << "You chose Scissors." << std::endl;
        } else if(userChoice == 'Q') {
            std::cout << "You chose to quit." << std::endl;
            playAgain = false;
            break;        
        } else {
            std::cout << "Invalid choice." << std::endl;
        }

        // Print computers choice.
        if(computerChoice == 1) {
            std::cout << "The computer chose: Rock" << std::endl;
        } else if(computerChoice == 2) {
            std::cout << "The computer chose: Paper" << std::endl;
        } else {
            std::cout << "The computer chose: Scissors" << std::endl;
        }

        // Check the choices.
        check_choices(userChoice, computerChoice);

        // Ask if the player wants to play again.
        playAgain = play_again();
    }

    return 0;
}
