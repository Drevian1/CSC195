// [A] Memory Review.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Person
{
	char name[32];
	int id;
};

void Square(int& i)
{
	i = i * i;
}

void Double(int* i)
{
	*i = *i * 2;
}

int main()
{
	// ** REFERENCE **
	// 
	// declare an int variable and set the value to some number (less than 10)
	// declare a int reference and set it to the int variable above
	// output the int variable
	int num = 5;
	int& Rnum = num;
	cout << Rnum << endl;

	// set the int reference to some number
	// output the int variable
	// what happened to the int variable when the reference was changed? It allowed the variable to store numbers.
	Rnum = 2;
	cout << Rnum << endl;
	// output the address of the int variable
	// output the address of the int reference
	// are the addresses the same or different? The addresses are the same.
	cout << &num << endl;
	cout << &Rnum << endl;

	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	Square(num);
	// output the int variable to the console
	cout << num << endl;

	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""


	// ** POINTER VARIABLE **
	// 
	// declare an int pointer, set it to nullptr (it points to nothing)
	// set the int pointer to the address of the int variable created in the REFERENCE section
	int* ptr = nullptr;
	ptr = &Rnum;
	// output the value of the pointer
	// what is this address that the pointer is pointing to? The address of Rnum which is 00000017A16FF614.
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << ptr << endl;

	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(ptr);
	cout << ptr << endl;

	// output the dereference pointer
	// output the int variable created in the REFERENCE section
	// did the int variable's value change when using the pointer? Yes the int variable was multipled by 2 when passed into the double function.
	Double(&num);
	cout << num << endl;
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
