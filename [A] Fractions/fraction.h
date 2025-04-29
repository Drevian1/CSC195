#pragma once
#include <iostream>
using namespace std;

namespace mathlibs {

	template <typename T> 
	
	class Fraction {
	private:
		int numerator;
		int denominator;
	public:


		Fraction()
		{

		};

		Fraction(int numerator, int denominator)
		{

		};

		void Addition()
		{
			
		};

		void Substraction()
		{
			
		};

		void Multiply()
		{
			
		};

		void Division()
		{
			
		};

		void Simplify()
		{

		};

		void toDouble()
		{

		};

		friend ostream& operator << (ostream& ostream, Fraction& fraction);
		
		friend istream& operator >> (istream& istream, Fraction& fraction);
		

		
	};
}