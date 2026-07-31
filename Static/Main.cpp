#include "File1.h"
#include "File2.h"
#include "Person.h"
#include <iostream>
//int count = 0;
// 출력값이 1, 2, 3

void Incerment()
{
//	int count = 0;
// 출력값이 1, 1, 1	
	static int count = 0; // 이렇게 하면 출력값이 1, 2, 3
	// 함수가 끝나도 살아남게 됨.처음 함수 1회만 선언됨. 함수 밖에 선언하는 것과 동일함.
	// 함수 내부에서만 사용 가능하지만 수명은 함수 밖의 전역 선언과 같아짐.
	++count;
		std::cout << "Count " << count << "\n";
}

// 현재 존재하는 Person 객체의 수
//int personCount = 0;

class Person
{

public:
	Person()
	{
		++personCount;
		std::cout << personCount << "번째 Person 객체 생성\n";
	}

	~Person()
	{
		--personCount;
	}

private:
	//int personCount = 0; // 이러면 출력이 1, 1, 1 (객체 초기화 구문이라고 함)
	static int personCount;
//C++ 17 부터 사용할 수 있는 간단하게 static 멤버 변수를 클래스 안에서 정의, 초기화 하는 방식.	inline static int personCount = 0;
	

};
// static 변수는 별도로 초기화를 해야함. (클래스 초기화) -> 이게 정석이라고 보면 됨.
int Person::personCount = 0;

int main()
{
	//FileOneFunction();
	//FileTwoFunction();

	//Incerment();
	//Incerment();
	//Incerment();

	{
		// 괄호를 치면 객체의 생명주기가 괄호 안으로 설정됨.
	Person p1;
	Person p2;
	}
	// 따라서 Person p3의 출력값은 새롭게 초기화 된 후 다시 함수가 돌아가게 되는 느낌.
	Person p3;
}