#pragma once
#include <iostream>

class Animal
{
public:
	//Animal(){} //default constructor
	Animal() {
		m_limbs = 0;
		m_ptr = new int(25);
	}

	Animal(int limb) {
		m_limbs = limb;
	}

	~Animal(){
		delete m_ptr;
	}

	virtual void Travel(); //pure virtual / abstract function
	virtual void Speak() = 0;
	int GetLimbs() { return m_limbs; }
	void SetLimbs(int limbs) { m_limbs = limbs;  }
protected:
	int m_limbs;

	int* m_ptr = nullptr;
};