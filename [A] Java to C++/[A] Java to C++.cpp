// [A] Java to C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;
int main() {
    
    random_device rd;
    mt19937 gen(rd());

    int sides = 0;
    int numDice = 0;
    string rollAgain = "y";

    std::cout << "Welcome to the Dice Roller!" << std::endl;

    while (!rollAgain.empty() && std::tolower(rollAgain[0]) == 'y') {

        sides = 0;
        numDice = 0;

        
        while (sides <= 0) { 
            std::cout << "Enter the number of sides for the die: ";
            std::cin >> sides;

            
            if (cin.fail()) {
                cout << "Invalid input. Please enter a whole number." << endl;
                cin.clear();
                
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                sides = 0;
            }
            else if (sides <= 0) {
                cout << "Number of sides must be positive. Please try again." << endl;
                
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        while (numDice <= 0) {
            cout << "Enter the number of dice to roll: ";
            cin >> numDice;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a whole number." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                numDice = 0; 
            }
            else if (numDice <= 0) {
                cout << "Number of dice must be positive. Please try again." << endl;
            }

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        uniform_int_distribution<> distrib(1, sides);

        cout << "\nRolling " << numDice << " d" << sides << "..." << endl;
        int total = 0;
        cout << "Results: ";
        for (int i = 0; i < numDice; ++i) {
            int roll = distrib(gen);
            cout << roll << " ";
            total += roll;
        }
        cout << "\nTotal: " << total << endl;

        
        cout << "\nRoll again? (y/n): ";
        cin >> rollAgain;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    } 

    cout << "\nThanks for rolling!" << endl;

    return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
