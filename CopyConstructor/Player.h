
//#pragma once
//class Player
//{
//public:
//	Player();
	//Player(const char* inName);
//
	// 복사 생성자
	//Player(const Player& other);

	//Getter (값을 반환하는 함수)
	//inline const char* GetName() const { return name; }


//private:
	// 동적 할당을 사용하는 문자열.
	//char* name = nullptr

//};*/

#pragma once

class Player
{
public:
	Player();
	Player(const char* inName);

	// 복사 생성자.
	Player(const Player& other);

	~Player();
	// private: 이걸 하면 삭제하는 방식이 됨, 
	// 대입(+) 연산자 오버로딩
	// 연산자라함은? 연산자를 이름으로 갖는 함수.
	Player& operator=(const Player& other);

	// 대입 연산자는 위가 맞는데, 이항연산자는 암묵적으로 좌측이 '나'로 받아짐.

	// Getter (값을 반환하는 함수).
	inline const char* GetName() const { return name; }

private:
	// 동적 할당을 사용하는 문자열.
	char* name = nullptr;
};