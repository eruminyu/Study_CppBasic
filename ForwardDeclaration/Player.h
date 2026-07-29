#pragma once

//#include "Weapon.h" // Weapon 클래스의 정의를 포함, 일반적

class Weapon;
// 이게 전방선언
// 1. 컴파일 시간을 단축
// 2. 헤더 순환 참조를 방지.

// 전방 선언은 포인터 타입에서만 가능함, 일반 변수는 불가능.
// 레퍼런스도 가능함.


class Player
{
public:

	Player();
	~Player();

private:
	// Weapon 변수
	Weapon* weapon = nullptr; // Weapon 클래스의 포인터 변수, Forward Declaration을 사용하여 선언
};

