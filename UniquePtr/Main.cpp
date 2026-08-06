#include <iostream>
#include <memory>

class Actor
{
public:
	virtual ~Actor() = default;
};

class Player : public Actor
{
public:
	Player()
	{
		std::cout << " Player constructed.\n";
	}
	~Player()
	{
		std::cout << " Player destroyed.\n";
	}

	void Attack() const
	{
		std::cout << "Player attacks.\n";
	}

};

//template<template T>
//class Data
//{
//public:
//	T* operator->()
//	{
//		return data;
//	}
//private:
//	T* data = nullptr;
//};

void AttackPlayer(
	//std::unique_ptr<Player> player 이렇게는 불가능
	 Player* player)
{
	player->Attack();
}
void AttackPlayer2(const Player& player)
{
	player.Attack();
}

// 스마트 포인터 자체의 레퍼런스를 받아서 사용하면 문제 없음
void AttackPlayer3(const std::unique_ptr<Player>& player)
{
	
	player->Attack();
}

int main()
{
	//Player* player = new Player();
	//delete player;
	//player = nullptr;

	// 스마트 포인터
	// STL - Standard Template Library.
	std::unique_ptr<Player> player = std::make_unique<Player>();

	//Player* rawPtr = player.get(); 사용 가능하나 주의.

	

	// 스마트 포인터 객체의 사용은 일반 포인터의 사용방법과 같다
	// -> 연산자로 참조 가능함.
	player->Attack();

	// 레퍼런스(역참조) 방법도 기존 포인터랑 동일함.
	Player& playerRef = *player;

	// 다른 스마트 포인터
	// unique_ptr은 소유권의 공유가 불가능함
	//std::unique_ptr<Player> player2 = player;

	// 주소를 빌려서 사용하는 방법
	// 1. RawPointer (원시 포인터) 로 받아서 사용 가능
	// 위험함, 실수로 delete를 해버릴 수 있음.
	//Player* player2 = player.get();
	//delete player2;
	AttackPlayer(player.get());

	// 2. 레퍼런스로 전달받기
	// 원시 포인터보다 조금 더 안전함 -> 가장 추천
	AttackPlayer2(*player);

	// 3. 스마트 포인터의 레퍼런스를 사용
	// 3번 방법도 가능하지만, unique_ptr의 정의/사용 방식에 위배됨.
	AttackPlayer3(player);

	// unique_ptr의 소유권을 다른 곳으로 넘기는 방법.
	// ValueCategory와 연관
	// 이전을 다른 곳으로 한 이후엔 기존에 사용하던 player를 사용하면 안됨.
	std::unique_ptr<Player> otherPlayer = std::move(player);
	// 이전을 한 뒤로는 기존 포인터를 리셋(초기화) 해주는 게 좋음
	player.reset();
	if (player)
	{

	};

	std::cout << "End,\n";

}