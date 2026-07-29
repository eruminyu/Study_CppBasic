#include <iostream>
//#include <array>
//#include <windows.h>

#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// 제어 가능한 환경에서 수정, 아니면 하기 원본 그대로 사용 권장
/*
#ifdef _DEBUG
	#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
	// allocations to be of _CLIENT_BLOCK type
#else
	#define DBG_NEW new
#endif
*/

// 배열을 전달받아서 원소를 출력하는 함수
void PrintArray(int* arr, int count)
{
	for (int ix = 0; ix < count; ++ix)
	{
		std::cout << arr[ix] << " ";
	}
}
// 원시 배열에서는 배열의 크기를 알 수 없기 때문에, 배열의 크기를 별도로 전달해야 함.

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//std::array<int, 5> arr2 = { 1, 2, 3, 4, 5 }; // std::array 사용
	//std::cout << "std::array 크기: " << arr2.size() << std::endl; // 배열의 크기 확인
	// 배열
	const int length = 5;
	int arr[length] = {0};
	//memset(&arr, 0, sizeof(int) * length);

	// 동적 배열.
	int* dArr = new int[length]; // 동적 배열 생성
	
	// dArr[0] = 20; 사용법은 같음.

	// 지역변수기 때문에, 스택이 잡힘, 그래서 힙이라는 공간에 동적 배열을 생성해야 함, 스택은 지역변수, 힙은 동적할당
	// 사용하는 공간이 클 경우, 스택은 제한이 있으므로, 힙을 사용해야 함.
	delete[] dArr; // 동적 배열 해제, delete[]를 사용하여 배열을 해제해야 함


	// 배열을 포인터로 다루기.
	int* ptr = arr; // 배열의 첫 번째 요소를 가리키는 포인터
	*(ptr + 2) = 33; // 배열의 세 번째 요소에 값 33을 저장 포인터의 덧셈은 메모리 점프.

	// 배열 순회.
	//for (int ix = 0; ix < length; ix++)
	// 차이점 확인, 요즘은 의미 없음, 컴파일러가 알아서 함
	// 직접 구현할 떄 메모리를 하나 더 씀, 리턴의 순서 차이
	for (int ix = 0; ix < length; ++ix)
	{
		arr[ix] = ix + 1; // 배열의 각 요소에 값 저장]
	}

	// Range-based for loop (범위 기반 루프, C#의 foreach와 비슷함.)
	for (const int value : arr)
	{
		std::cout << value << " "; // 배열의 각 요소 출력
	}

	PrintArray(arr, length); // 배열과 크기를 전달하여 원소 출력

	
	



	std::cin.get(); // 프로그램이 종료되지 않도록 대기
}