#include <iostream>



// 포인터를 사용하여 동적 메모리 해제 및 초기화
// 참조를 한다는 것은 주소를 복사 또는 사용한다는 의미.
// int*& t: int형 포인터를 참조하는 참조자, 즉 포인터의 주소를 참조하는 참조자
void Release(int*& t) {
	if (t != nullptr)
	{
		delete t;
		t = nullptr;
	}
}
/*
void Release(int** t) {
	if (t != nullptr)
	{
		delete *t;
		*t = nullptr;
	}
}
*/

// 두 변수의 값을 서로 교환하는 함수

void SwapRef(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//자동완성된건데 아래는 따라한거
//위가 레퍼런스, 아래가 포인터를 사용한거임

void Swap(int* const a, int* const b) //const
{
	int temp = *a;
	// a++; // 실수한거임, a++는 포인터를 증가시키는 것이므로 잘못된 코드임
	*a = *b;
	*b = temp;
};
// 포인터를 사용하여 두 변수의 값을 서로 교환하는 함수
// 무엇이 다른가? 체크


int main() {
	

	// 두 수를 교환

	int numberA = 10;
	int numberB = 20;
	SwapRef(numberA, numberB); // SwapRef 함수 호출, numberA와 numberB의 참조를 전달
	Swap(&numberA, &numberB); // Swap 함수 호출, numberA와 numberB의 주소를 전달

	int var = 8;
	int* ptr = &var; // 포인터 변수 ptr에 var의 주소를 저장

	int* testPtr = new int;
	//delete testPtr; // 동적 메모리 해제
	//testPtr = nullptr; // 포인터를 nullptr로 초기화하여 dangling pointer 방지

	Release(testPtr); // 동적 메모리 해제 및 포인터 초기화
	//Release(&testPtr); // 동적 메모리 해제 및 포인터 초기화

	const int length = 100;
	int* buffer = new int[length]; // 동적 메모리 할당, length개의 int를 저장할 수 있는 배열 생성
	int** bufferPtr = &buffer; // buffer의 주소를 저장하는 포인터 변수 bufferPtr 생성 (int**: int형 포인터를 가리키는 포인터, 더블포인터)
	int*** bufferPtrPtr = &bufferPtr; // int***: int형 포인터를 가리키는 포인터를 가리키는 포인터, 트리플포인터

	//*buffer = 0;
	memset(buffer, 0, sizeof(int) * length);
	// memset: 메모리 초기화 함수, buffer의 시작 주소부터 length * sizeof(int) 바이트를 0으로 초기화
	//length 가 없으면 0번째만 초기화됨, length를 곱해주어야 전체 초기화됨



	delete[] buffer; // 동적 메모리 해제
	//delete buffer; // 단일 객체를 해제할 때 사용, 배열을 해제할 때는 delete[]를 사용해야 함


	std::cin.get(); // 프로그램이 종료되지 않도록 대기


	
}
