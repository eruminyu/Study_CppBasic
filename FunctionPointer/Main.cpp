#include <iostream>

void Test()
{
	std::cout << "Test.\n";
}

float Add(float a, float b)
{
	return a + b;
}

float Multiply(float a, float b)
{
	return a * b;
}

// 함수 포인터를 타입으로 선언
//typedef bool (*Comparer)(int, int);
using Comparer = bool (*)(int, int);

// 버블 정렬
//void BubbleSort(int* array, int length, bool (*Comparer)(int, int))
void BubbleSort(int* array, int length, Comparer comparer)
{
	// 정렬 처리
	for (int ix = 0; ix < length - 1; ++ix)
	{
		for (int jx = 0;jx < length - 1 - ix;++jx)
		{
			// 오름차순 정렬
			//if (array[jx] > array[jx + 1])
			if (comparer(array[jx], array[jx+1]))
			{
				std::swap(array[jx], array[jx + 1]);
			}
		}
	}
}

bool Ascending(int a, int b)
{
	return a > b;
}
bool Decending(int a, int b)
{
	return a < b;
}

// 멤버 함수 포인터
class Actor
{
public:
	void Tick(float deltaTime) {}

};

// 멤버 함수 포인터
void (Actor::*ActorTick)(float);

int main()
{
	ActorTick = &Actor::Tick;

	int array[] = { 5, 3, 7, 6, 4, 2, 1 };
	int length = sizeof(array) / sizeof(array[0]);
	BubbleSort(array, length, Ascending);
	BubbleSort(array, length, Decending);

	std::cin.get();

	//// 함수 포인터
	//void (*FunctionPointer)() = nullptr;
	////void (*FunctionPointer)();
	//// 함수 포인터에 함수 주소를 저장
	////FunctionPointer = Test;
	//// FunctionPointer = &Test;
	//
	//if (FunctionPointer)
	//{
	//	FunctionPointer();
	//}
	//
//	//FunctionPointer();
	////Test();
	//
	//float (*Calculator)(float, float) = Add;
	//float result = Calculator(10.0f, 25.0f);
	//std::cout << "result: " << result << '\n';
	//
	//Calculator = Multiply;
	//float result = Calculator(10.0f, 25.0f);
	//std::cout << "result: " << result << '\n';
}