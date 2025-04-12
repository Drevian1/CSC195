// Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
int main()
{
    string fruits[5] = { " Banana", "Kiwi", "Mango", "Chikoo", "Strawberry" };
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(25);

    numbers.pop_back();
    numbers.pop_back();

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << endl;
    }

    // Pointer Arithmetic

    cout << "-------------------------------------------------------" << endl;

    string chemicals[5] = { "mercury", "hydrochloric acid", "chlorine", "bromine", "table salt" };

    cout << chemicals[2] << endl;
    cout << chemicals << endl;
    cout << &chemicals[0] << endl;

    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < (*chemicals).size(); i++)
    {
        cout << &chemicals[i] << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    string* p = chemicals;
    cout << p << endl;
    cout << ++p << endl;
    cout << ++p << endl;
    cout << --p << endl;

    cout << p + 2 << endl;
    cout << p - 3 << endl;

    cout << "-------------------------------------------------------" << endl;

    //containers
    list<string> cars = { "Hyundai", "Ferrai", " Mercedes", "Volvo" };

    cout << cars.front() << endl;
    cout << cars.back() << endl;

    cars.pop_back();
    cout << cars.back() << endl;

    cars.push_front("Tesla");
    cout << cars.front() << endl;

    map<string, int> pet = { {"Dogs", 23}, {"Chameloeons",  3}, {"Turtle", 43} };

    pet["Dogs"] = 50;
    
    cout << pet["Dogs"] << endl;

    pet["Spiders"] = 2;

    cout << pet.empty() << endl;
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
