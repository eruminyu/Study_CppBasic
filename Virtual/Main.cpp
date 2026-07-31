#include <iostream>

class Entity
{
public:

	Entity()
	{
		std::cout << "Entity() called\n";
	}

	virtual ~Entity()
	{
		std::cout << "~Entity() called\n";
	}


	virtual const char* GetName()
	{
		return "Entity";
	}
};

class Player : public Entity
{
public:
	Player(const char* inName)
	{
		std::cout << "Player() called\n";
		size_t length = strlen(inName) + 1;
		strcpy_s(name, length, inName);
	}

	virtual const char* GetName() override { return name; }
	//const char* GetName() { return name; } 같은 식으로 작성하여도 오류는 없이 동작함.
	// 단, 최근의 코딩 표준은 virtual과 override를 권장.

	~Player()
	{
		std::cout << "~Player() called\n";
	}

private:
	// 이름 값 저장 변수
	char name[15] = {};
};

int main()
{
	// 객체 생성.
	Entity* e1 = new Entity();
	Entity* e2 = new Player("Minsung");

	// 이름 값 출력.
	//std::cout << e1->GetName() << "\n";
	//std::cout << sizeof(Entity) << "\n";
	//std::cout << e2->GetName() << "\n";
	//std::cout << sizeof(Entity) << "\n";


	delete e1;
	e1 = nullptr;

	delete e2;
	e2 = nullptr;
}