#pragma once
#include "Animal.h"
#include <iostream>
using namespace std;

class Snake : public Animal 
{
public:
	Snake(bool venom, int limbs) : Animal(0) {
		//m_limbs = 0;
		has_venom = false;
		std::cout << "snake constructor\n";
	}
	~Snake()
	{
		std::cout << "snake constructor\n";
	}
	void Travel() override;
	void Speak() override;
protected:
	bool has_venom;
};
