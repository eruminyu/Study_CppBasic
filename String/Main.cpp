#include <iostream>

class Player
{
public:
	// 생성자
	Player(const char* name)
	{
		size_t length = strlen(name) + 1; // 문자열 길이 계산
		this->name = new char[length]; // 문자열 길이 + 1 (null 문자 때문에)

		//값을 저장. 값 복사, 문자열 복사
		for (size_t ix = 0; ix < length - 1; ++ix)
		{
			this->name[ix] = name[ix]; // 문자열 복사
		}
		
		this->name[length - 1] = '\0'; // null 문자 추가]

	}

	// 소멸자
	~Player()
	{
		if (name)
		//if (name != nullptr)
		//if (nullptr != name)
		{
			delete[] name; // 동적 메모리 해제
			// name = nullptr; // 포인터 초기화
		}
	}

	void PrintName() const // const 멤버 함수, 객체의 상태를 변경하지 않음, 함수 자체의 상수성
	{
		std::cout << "Player name: " << name << "\n"; // 플레이어 이름 출력
	}

private: char* name = nullptr; // 플레이어 이름 저장용 변수
};

int main()
{

	Player player("Minsung"); // Player 객체 생성, 이름 전달
	player.PrintName(); // 플레이어 이름 출력

	// 문자열
	auto name = "Minsung"; // 문자열 리터럴, const char* 타입
	const char* name2 = "Minsung"; // const char* 타입, 문자열 리터럴
	// 문자열 리터럴은 컴파일 타임에 결정되므로, const char* 타입으로 선언하는 것이 일반적임
	// 문자열에 마우스를 올렸을 때 8개인 이유는 마지막에 '\0'이 들어가기 때문임, 문자열의 끝을 나타내는 null 문자

	
	/*
	char nameArray[4];
	nameArray[0] = 'M';
	nameArray[1] = '\0';
	nameArray[2] = 'n';
	nameArray[3] = '\0';
	//nameArray[4] = 'u'; // 배열의 크기를 초과하여 접근, 위험함
	*/

	// 문자열 크기(문자 개수)
	size_t length = strlen(name); // 문자열 길이, null 문자를 제외한 길이

	std::cout << "string length: " << length << "\n"; // 문자열 길이 출력

	std::cin.get(); // 프로그램이 종료되지 않도록 대기
}