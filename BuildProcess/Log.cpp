#include <iostream>


// C# 포인터 -> 온통 포인터
// * 포인터라는 의미.
// 포인터는 메모리 주소를 저장하는 변수입니다. 포인터를 사용하면 변수의 메모리 주소를 직접 다룰 수 있습니다.(타입)
void Log(const char* message)
{
	std::cout << message << "\n";
}