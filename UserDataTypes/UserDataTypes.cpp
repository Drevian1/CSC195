// UserDataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Declarations.h"
#include <iostream>
using namespace std;



int main()
{
    std::cout << "User Data Types\n";

    Sandwich pastrami;
    pastrami.meat = Pastrami;
    pastrami.heatSandwich();
    //pastrami.isHot = true;
    pastrami.weight = 1.0f;

    cout << "size of sandwich " << sizeof(Sandwich) << endl;
    cout << "size of pastrami " << sizeof(pastrami) << endl;
    cout << "size of string " << sizeof(string) << endl;
    cout << "size of float " << sizeof(float) << endl;
    cout << "size of boolean " << sizeof(bool) << endl;

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
