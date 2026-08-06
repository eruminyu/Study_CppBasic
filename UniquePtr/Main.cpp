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

};

int main()
{
	Player* player = new Player();
	delete player;
	player = nullptr;

}