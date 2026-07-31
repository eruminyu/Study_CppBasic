#include "Player.h"
#include <iostream>

Player::Player()
{
	std::cout << "Player() called\n";
}

Player::Player(const char* inName)
{

	// 문자열 복사.
	size_t length = strlen(inName) + 1;
	name = new char[length] {};
	strcpy_s(name, length, inName);
	std::cout << "Player(const char* inName) called\n";
}

// 복사 생성자.
Player::Player(const Player& other)
	// : name(other.name) 얘도 얕음!
{
	// 얕은 복사라고 하는데, 뭘까?
	//포인터 주소값만 복사하는 생성자를 말함. 일반 값은 문제가 없는데, 포인터를 복사할때 문제가 생김.
	//name = other.name;

	//요즘 트랜드? 는 이동, 이동은 결국 얕안 복사같이 주소만 복사함.


	// 깊은 복사
	size_t length = strlen(other.name) + 1;
	name = new char[length] {};
	strcpy_s(name, length, other.name);

	//클래스 단위의 접근 한정자는 타입별로 접근이 가능함. ( 틀렸을 수 있으니 보충 영상확인 필요)


	std::cout << "Player(const Player& other) called\n";
}

Player::~Player()
{
	if (name)
		{
			delete[] name;
			name = nullptr;
		}
}

Player& Player::operator=(const Player& other)
{
	// 복사 처리.
	size_t length = strlen(other.name) + 1;
	name = new char[length] {};
	strcpy_s(name, length, other.name);

	std::cout << "operator=(const Player& other) called\n";

	return *this;
}
