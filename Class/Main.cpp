#include <iostream>

// 클래스 선언
class Player
{

	// Manager 클래스가 Player 클래스의 private 멤버에 접근할 수 있도록 friend 선언
	friend class Manager; // Manager 클래스가 Player 클래스의 private 멤버에 접근할 수 있도록 friend 선언

public:
	Player() = default; // 기본 생성자
	~Player() = default; // 기본 소멸자

	// x, y 좌표를 설정하는 멤버 함수, 정석적인 방법
public:
	void SetXY(int newX, int newY) // x, y 좌표 설정
	{
		x = newX;
		y = newY;
	}

	// frind 선언을 사용하여 전역 함수가 private 멤버에 접근할 수 있도록 함
	friend void SetPosition(Player& player, int newX, int newY); // 전역 함수 선언
	
	

private:
	int x = 0; // x 좌표
	int y = 0; // y 좌표

};

class Manager
{
public:
	Manager(Player* const newPlayer)
		: player(newPlayer)
	{
	}

	void Test()
	{
		player->x = 30;
		player->y = 60;
	}

private:
	Player* player = nullptr;
};


// Player의 x, y 위치를 설정한느 전역 함수
void SetPosition(Player& player, int newX, int newY)
{
	//player.SetXY(newX, newY); // Player 객체의 SetXY 멤버 함수를 호출하여 x, y 좌표를 설정 이게 정석, 정답.
	player.x = newX;
	player.y = newY;
}

int main()
{
	// 객체 포인터 배열
	// Player 객체를 가리키는 포인터 배열을 생성하고, 각 포인터에 동적으로 생성된 Player 객체를 할당
	const int length = 5; // 배열 크기
	Player* players[length] = {}; // Player 객체를 가리키는 포인터 배열

	// 객체 생성
	for (int ix = 0; ix < length; ++ix)
	{
		players[ix] = new Player(); // Player 객체 동적 생성
	}

	// 사용
	SetPosition(*players[0], 10, 20); // 첫 번째 Player 객체의 위치 설정)

	Manager manager(players[1]); // Manager 객체 생성, 첫 번째 Player 객체를 전달)
	manager.Test(); // Manager 객체의 Test 멤버 함수 호출, 두 번째 Player 객체의 위치 설정

	// 객체 소멸 및 null
	for (Player*& player : players)
		// Player*& player: Player 객체를 가리키는 포인터의 참조, 배열의 각 요소를 순회
		// Player* 또한 일종의 포인터이므로, Player*& player는 Player 객체를 가리키는 포인터의 참조를 의미함
		// 더블 포인터를 사용하지 않고, 포인터의 참조를 사용하여 배열의 각 요소를 직접 수정할 수 있음
		// 포인터의 레퍼런스를 사용하면, 포인터를 직접 수정할 수 있으므로, 더블 포인터를 사용하는 것보다 코드가 간결해짐
		// 레퍼런스를 사용 하지 않았을 떄 지워졌지만 원본의 주소는 그대로 남아있음, 그래서 nullptr로 초기화 해야함
		// 해당 주소를 댕글러 포인터라 함, 댕글링 포인터는 이미 해제된 메모리를 가리키는 포인터를 의미함
		// 스마트 포인터로 해결 되지 않을 때가 있음.
	{
		delete player; // Player 객체 소멸
		player = nullptr; // 포인터 초기화
	}

	std::cin.get(); // 프로그램이 종료되지 않도록 대기
}