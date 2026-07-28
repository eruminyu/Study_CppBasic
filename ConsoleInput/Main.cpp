#include <iostream>


int main() 
{

	int value = 0;

	// 무한루프를 돌면서 0이 아닌 숫자를 입력받을 때까지 반복
	// 종료하는 조건을 확인해서 조건을 만족하면 break를 통해 루프를 종료
	while (true)
	{
		//검증용 문자 버퍼
	//char은 1바이트 크기이므로, 50개의 문자를 담을 수 있는 배열을 선언 (사실은 문자선언이 아니라 숫자선언이지만, char배열을 이용하여 숫자를 입력받을 수 있음)
		char buffer[50] = {};
		std::cout << "0이 아닌 숫자를 입력하세요(첫 번째): ";
		std::cin >> buffer;

		if ((value = atoi(buffer)) == 0)
		{
			std::cout << "잘못된 입력입니다. 0이 아닌 숫자를 입력해주세요.\n";
		} // atoi: 문자열을 정수로 변환하는 함수

		//숫자 입력이 정상일 때
		else
		{
			break;
		}

	}

	

	int value2 = 0;
	std::cout << "숫자를 입력하세요: ";
	std::cin >> value2;

	std::cout
		<< " 입력한 두 수의 합은? "
		<< (value + value2)
		<< "입니다.\n";


}