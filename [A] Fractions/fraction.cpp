#include <iostream>
#include "fraction.h"
using namespace std;

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
			return numerator + numerator
		};

		void Substraction()
		{
			return numerator - numerator
		};

		void Multiply()
		{
			return numerator * numerator
		};

		void Division()
		{
			return numerator / numerator
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