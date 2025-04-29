// Pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _DBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include<memory>
#include <iostream>
using namespace std;

template<typename T>
class smart_ptr

{

public:

    smart_ptr(T* ptr = nullptr) : _ptr{ptr} {}

    smart_ptr(const smart_ptr&) = delete;  //don't allow us to copu

    smart_ptr& operator = (const smart_ptr&) = delete;  //don't allow us to use the assignment operator

    ~smart_ptr() { if (_ptr) delete _ptr; }

    T& operator * () { return *_ptr; }

    T* operator & () { return  _ptr; }

    T* operator -> () { return  _ptr; }

    T* get() { return _ptr; }

private:

    T* _ptr{};

};


int main()
{
   // int arr[] = { 2,4,6,8 };

   // int* p = arr;  //&arr[0]

   ///* p++;
   // p++;
   // p--;
   // p = p + 2;*/

   // cout << *p << endl;

	int* p = new int{5};

	cout << *p  << endl;

	delete p;

    
    {
        smart_ptr<int> sp{ new int {25} };
        unique_ptr<int> up{ new int {20} };

        smart_ptr<int> upc{ sp };
    }

	_CrtDumpMemoryLeaks();
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
