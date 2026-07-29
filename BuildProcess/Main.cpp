#include <iostream>

//인클루드는 왜? 헤더를 포함시키는가? 헤더파일에 선언된 함수, 클래스, 변수 등을 사용할 수 있도록 하기 위해서입니다. 인클루드를 통해 헤더파일을 포함시키면, 해당 파일에 정의된 내용들을 현재 소스 파일에서 사용할 수 있게 됩니다. 이는 코드의 재사용성과 모듈화를 높이는 데 도움을 줍니다.


//void Log(const char*);
#include "Log.h"

int main()
{
	//std::cout << "Hello\n";
	//#include "EndBrace.h"

	auto number = 42;
	auto name = "Alice";


	Log("Hello");
}
