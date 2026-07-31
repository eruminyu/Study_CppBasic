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

	void Play()
	{

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

	void Attack()
	{

	}

};


int main()
{
	Base* b = new Derived();
	// 자손 객체를 생성하면서 부모의 타입으로 생성, 당연히 됨.
	b->Play();
	//b->Attack();

	delete b;
	b = nullptr;

}

// 객체의 생성과정 소멸과정. 순서확인용
// 생성은 부모 -> 자손
// 소멸은 자손 -> 부모