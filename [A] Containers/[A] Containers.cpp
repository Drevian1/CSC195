// [A] Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
int main()
{
    string days[7] = { "Monday ", "Tuesday ", "Wedsday ", "Thursday ", "Friday ", "Saturday ", "Sunday ", };
    
    for (string days : days)
    {
        cout << days << endl;
    }

    vector<int> nums = {1,2,3,4,5};

    nums.push_back(6);
    nums.push_back(7);
    
    nums.pop_back();

    for (int i = 0; nums.size(); i++)
    {
        cout << nums[i] << endl;
    }

    

    list<int> myList = { 1, 2, 3};
    myList.push_front(2);

    myList.remove(1);

    

    for (int i = 0; myList.size(); i++)
    {
        cout << &myList << endl;
    }


    map<int, string> mappy;
    mappy[1] = "Top";
    mappy[2] = "Bop";
    mappy[3] = "Cop";

    for(int i = 0; mappy.size(); i++)
    {
        cout << &mappy << endl;
    }


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
