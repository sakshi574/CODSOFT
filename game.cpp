//number guessing game in an amazing manner
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); //  here we will use seed random number generator to generate a random number 
    int number_to_guess = rand() % 100 + 1; //now here we generate random number between 1 and 100

    int user_guess;//here we create a variable for the input of a number 
    while (true) { //here we create a loop for this game
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> user_guess;//now here let take a input from the user

        if (user_guess < number_to_guess) {
            std::cout << "Your guess is too low! Try again.\n";//if vaue is less then it shows this
        } else if (user_guess > number_to_guess) {
            std::cout << "Your guess is too high! Try again.\n";//if value iss high it shows this
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
            break;
        }
        return 0;
    }
}
