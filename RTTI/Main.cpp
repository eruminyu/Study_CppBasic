#include <iostream>

class Actor
{
public:
	virtual ~Actor() = default;
};

class Camera : public Actor
{
		
};
class Player : public Actor
{
};


int main()
{
	// 업캐스팅은 안전하다.
	Actor* actor1 = new Player();
	Actor* actor2 = new Camera();

	// 다운캐스팅은 안전하지 않다.
	// RTTI를 사용하여 안전하게 다운캐스팅을 수행할 수 있다.
	auto player = dynamic_cast<Player*>(actor1);
	if (player)
	{
		std::cout << "Player로 캐스팅 성공!\n";
		
	}

	const type_info& typeInfo1 = typeid(*actor1);
	const type_info& typeInfoPlayer = typeid(Player);
	const type_info& typeInfo2 = typeid(*actor2);

	if (typeInfo1 == typeInfoPlayer)
	{
		std::cout << "actor1은 Player 타입입니다.\n";
		//std::cout << typeInfo1.name() << "\n";
		std::cout << typeInfo2.name() << "\n";
	}
	

	std::cin.get();

}
