#include <iostream>
#include <string>
#include "CraftObject.h"

//
//#define TO_NAME(x) #x
//#define CLASS_NAME(type)					\
//	public:									\
//	virtual const char* ClassName() const	\
//	{										\
//		return TO_NAME(type);				\
//	}
//
//class Actor
//{ 
////public:
////	virtual const char* ClassName() const 
////	{
////		//return "Actor"; 
////		return TO_NAME(Actor);
////	}
//
//	CLASS_NAME(Actor)
//
//public:
//	static size_t TypeId()
//	{
//		// 정적 지역 변수
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//};
//
//class Player : public Actor
//{
//private:
//	CLASS_NAME(Player)
//
//public:
//	static size_t TypeId()
//	{
//		// 정적 지역 변수
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//
//};
//

class Actor : public CraftObject
{
using super = CraftObject; protected: static size_t TypeIdClass() {
	static int runTimeTypeId = 0; return reinterpret_cast<size_t>(&runTimeTypeId);
} public: static size_t TypeId() {
	return Actor::TypeIdClass();
} virtual size_t GetType() const override {
	return Actor::TypeIdClass();
} virtual bool Is(size_t id) const override {
	return (id == TypeIdClass()) ? true : CraftObject::Is(id);
}
};

class Player : public Actor
{
	TYPE_DECLARATIONS(Player, Actor)
};

class Camera : public Actor
{
	TYPE_DECLARATIONS(Camera, Actor)
};


int main()
{
	std::shared_ptr<Actor> camera = std::make_shared<Player>();
	std::shared_ptr<Player> targerPlayer = Cast<Player>(camera);
	if (targerPlayer)
	{
		std::cout << "형변환 성공\n";
	}
	else
	{
		std::cout << "형변환 실패\n";
	}

	//Actor* actor = new Actor();
	//Actor* player = new Player();
	//
	//std::cout << actor->ClassName() << "\n";
	//std::cout << player->ClassName() << "\n";

	// 원시 문자열 비교
	
	//if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	//{
	//	std::cout << "두 타입은 같습니다." << "\n";
	//}
	//else
	//{
	//	std::cout << "두 타입은 다릅니다." << "\n";
	//}

	//// TypeId 비교
	//if (actor->TypeId() == Player::TypeId())
	//{
	//	std::cout << "두 타입은 같습니다." << "\n";
	//}
	//else
	//{
	//	std::cout << "두 타입은 다릅니다." << "\n";
	//}
	//
	//delete actor;
	//actor = nullptr;
	//delete player;
	//player = nullptr;
}