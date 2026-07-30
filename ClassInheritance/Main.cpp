#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base() called\n";
	}

	~Base()
	{
		std::cout << "~Base() called\n";
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived() called\n";
	}
	~Derived()
	{
		std::cout << "~Derived() called\n";
	}

};


int main()
{
	Derived derived;
}