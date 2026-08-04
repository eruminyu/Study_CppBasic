#pragma once

#include <memory>

// 커스텀 RTTI를 위한 CraftObject 클래스 정의, 최상위, 기반
class CraftObject
{
public:
	// 현재 객체의 타입 아이디 반환 함수
	// 순수 가상 함수(Pure Virtual Function)
	// 로 정의되어, 파생 클래스에서 반드시 구현해야 함
	virtual size_t GetType() const = 0;

	// 타입 비교 함수
	// CraftObject의 함수를 호출했다는 건 
	// 타입이 다르다는 의미이므로 false 반환
	virtual bool Is(size_t typeId) const
	{
		return false;
	}

	// 타입 질의 함수
	template<typename T>
		bool IsTypeOf() const
	{
		return Is(T::TypeId());
	};

};

// 스마트 포인트 형변환 유틸 함수
template<typename T, typename U> // 이럴 때 SFINAE를 적용할 수 있음. 
//(SFINAE: Substitution Failure Is Not An Error)
std::shared_ptr<T> Cast(const std::shared_ptr<U> object)
{
	// null 확인
	if (!object)
	{
		return nullptr;
	}

	// object의 실제 타입이 T(또는 T의 하위) 타입인지 확인 후 형변환.
	// 재귀적으로 처리할 것.
	if (object->Is(T::TypeId()))
	{
		return std::static_pointer_cast<T>(object);
	}
	// 형변환 실패
	return nullptr;

}

// 타입 시스템에 제공할 함수를 매크로로 구현
#define TYPE_DECLARATIONS(Type, ParentType)							\
	using super = ParentType;										\
protected:															\
	static size_t TypeIdClass()										\
{																	\
	static int runTimeTypeId = 0;									\
	return reinterpret_cast<size_t>(&runTimeTypeId);				\
}																	\
public:																\
	static size_t TypeId()											\
	{																\
		return Type::TypeIdClass();									\
	}																\
	virtual size_t GetType() const override							\
	{																\
		return Type::TypeIdClass();									\
	}																\
	virtual bool Is(size_t id) const override						\
	{																\
		return (id == TypeIdClass()) ? true : ParentType::Is(id);	\
	}																\

