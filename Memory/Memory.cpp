// Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void set(int& i)
{
    i = 123;
}

void swap(int* i1, int* i2) 
{
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}
int main()
{
    int i1 = 10;
    int i2 = 20;

    int& r = i1;
    r = 40;
    set(i1);

    swap(&i1, &i2);

    int* p = nullptr;
    p = &i1;

    cout << i1 << endl; // VALUE OF I1
    cout << i2 << endl; // vALUE OF I2
    cout << &i1 << endl; // ADDRESS OF I1
    cout << &r << endl; // ADDRESS OF R WHICH IS REFERENCE TO I1 MAKING IT THE SAME ADDRESS
    cout << p << endl;  // VALUE OF P WHICH IS THE ADDRESS OF I1
    cout << &p << endl; // ADDRESS OF P
    cout << *p << endl; // DEREFERENCE P WHICH GETS THE VALUE IN THE ADDRESS STORED IN THE POINTER

    cout << "----------------------------------------------" << endl;

    int number1 = 1;
    int* hnum1 = new int(4);

    int* Arrnum = new int[4];

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
