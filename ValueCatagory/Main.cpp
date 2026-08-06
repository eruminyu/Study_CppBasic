#include <iostream>
#include <string>

class Actor
{
public:
	Actor(const char* newName)
		
	{
		// 이름 값 설정
		// 1. 공간 할당
		// 2. 값 복사
		size_t length = strlen(newName) + 1;
		name = new char[length]; // = {};
		memset(name, 0, length);

		strcpy_s(name, length, newName);

	}
	~Actor()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	// 복사 생성자 - Copy constructor
	Actor(const Actor& other)
	{
		// 기존 공간 해제
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
		// 1. 공간 할당
		// 2. 값 복사
		size_t length = strlen(other.name) + 1;
		name = new char[length]; // = {};
		memset(name, 0, length);

		// strcpy_s -> 성능이 나쁨
		strcpy_s(name, length, other.name);
	}

	// 이동 생성자 - Move Constructor
	Actor(Actor&& other) noexcept // noexcept는 필수는 아님.
		//:name(other.name)
	{
		// 기존 메모리 해제
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
		// 주소 값 이전
		name = other.name;
		// 주소값을 이전시킨 후에 원본 주소를 null 대입
		other.name = nullptr;
	}


private:
	char* name = nullptr;
};


int main()
{
	//std::string actor2Name = "TestActor";
	////Actor actor1 = "Test"; -> 한번 적어봤는데 이건 안되네
	//Actor actor1("Test");	// -> 이 구문이 동작하려면 
	//						// Actor(std::string& newName) ->
	//						// 	Actor(const std::string& newName)로 수정
	//Actor actor2(actor2Name);
	// count 는 L-Value
	//L-Value : 
	// - 메모리를 차지하고,
	// - 이름이 있어 식별이 가능하며,
	// - 변경이 가능.
	// 10은 정수 리터럴로서 R-Value
	// R-Value : 
	// - 임시 값
	int count = 10;

	// L-Value Reference(L-Value 참조)
	// 여기서 count=L-Value
	int& lRef = count;
	//int& lRef2 = 10; -> 오류

	// R-Value Reference(R-Value 참조)
	//int&& rRef = count; -> 오류
	int&& rRef = 10;

}