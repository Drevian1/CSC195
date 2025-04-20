#pragma once
#include "Animal.h"

class Dog : public  Animal
{
public:
	Dog() 
	{
		m_limbs = 4;
		has_fur = false;
	}
	void Travel() override;
	void Speak() override;
protected:
	bool has_fur;
};