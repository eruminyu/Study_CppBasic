#include <iostream>
#include <cstdio>
#include <cassert>

void CreateConfigFile(const char* filename)
{
	// 문자열 쓰기.
	float framerate = 120.0f;
	int width = 30;
	int height = 20;

	// 위의 변수를 포맷 지정해서 문자열로 만들기.
	// 포맷: 키 = 값.
	const int length = 256;
	char string[length] = {};

	sprintf_s(
		string,
		length,
		"framerate = %f\nwidth = %d\nheight = %d",
		framerate, width, height
	);

	// 메모리의 어떤 데이터를 서식을 지정해서 파일에 기록하는 기능
	// -> 직렬화(Serialization).
	// 이 동작을 거꾸로 하는 것이 역직렬화(Deserialization).
	// File -> Memory./

	FILE* configFile = nullptr;
	fopen_s(&configFile, filename, "wb");
	if (!configFile)
	{
		return;
	}

	auto stringSize = strlen(string) + 1;
	fwrite(string, sizeof(char), stringSize, configFile);

	fclose(configFile);
	configFile = nullptr;
}


int main()
{
	const char* configFileName = "Setting.txt";
	CreateConfigFile("Setting.txt");

	// 설정 파일 읽기
	// 파일 로드 -> 읽은 값을 변수로 저장
	FILE* configFile = nullptr;
	fopen_s(&configFile, configFileName, "rt");
	if (!configFile)
	{
		return 1;
	}

	// 파일에서 읽은 데이터를 저장할 공간이 필요함.
	// 동적 할당 (정확한 크기를 지정함)
	
	// 파일 끝 위치로 이동 (FP 이동)
	fseek(configFile, 0, SEEK_END);

	// FP가 가리키는 위치를 반환
	int fileSize = static_cast<int>(ftell(configFile));

	// 위치 값을 읽고 난 후에 다시 파일을 다루기 위해 첫 위치로 이동
	//fseek(configFile, 0, SEEK_SET);
	rewind(configFile);

	// 버퍼를 생성
	char* configData = new char[fileSize];
	// 생성한 저장소의 값을 초기화
	// 요소의 저장배열 * 실제 파일의 크기
	// 메모리 세팅해 (시작주소 부터, 0으로 세팅, char의 사이즈 * 파일의 실제 사이즈 만큼)
	memset(configData, 0, sizeof(char) * fileSize);

	size_t configreadSize = fread(configData, sizeof(char), fileSize, configFile);

	// 서식을 지정해서 문자열에서 값 읽기
	float framerate = 0.0f;
	int width = 0;
	int height = 0;

	sscanf_s(configData, 
		"framerate = %f\nwidth = %d\nheight = %d", 
		&framerate, &width, &height);


	// 실수를 방지하기 위해 다 사용한 버퍼를 해제
	delete[] configData;
	configData = nullptr;

	// 파일 닫기
	fclose(configFile);
	configFile = nullptr;

	


	// 파일 입출력을 위한 변수.
	FILE* file = nullptr;

	// 파일 열기.
	auto result = fopen_s(&file, "Test.txt", "rb");

	// 파일 제대로 열었는지 확인.
	if (!file)
	{
		std::cout << "파일 열기 실패.\n";
		return 1;
	}

	// 파일 열기 성공.
	//std::cout << "파일 열기 성공\n";

	// 기록할 값.
	//const char* message = "C 라이브러리로 기록한 텍스트.\n";

	//// 파일에 쓰기.
	//if (fputs(message, file) == EOF)
	//{
	//	std::cout << "파일에 쓰기 실패\n";
	//	fclose(file);
	//	return 1;
	//}

	// 파일에서 읽기.
	// 읽어온 데이터를 저장할 버퍼.
	const int size = 256;
	char buffer[size] = {};
	size_t readSize = fread(buffer, sizeof(char), size, file);

	// 복사할 파일 생성(쓰기 모드로 열기).
	FILE* copyFile = nullptr;
	errno_t errorCode = fopen_s(&copyFile, "Test2.txt", "wb");
	if (!copyFile)
	{
		return 1;
	}

	// 쓰기.
	size_t writtenSize = fwrite(buffer, sizeof(char), readSize, copyFile);

	// 결과 확인.
	assert(readSize == writtenSize);

	// 파일 닫기.
	fclose(file);
	file = nullptr;

	fclose(copyFile);
	copyFile = nullptr;
}