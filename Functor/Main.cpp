#include <vector>
#include <iostream>
#include <algorithm>

// 정렬 조건에 사용할 함수 객체
struct Greater
{
	bool operator()(int left, int right)
	{
		return left > right;
	}
};
struct Less
{
	bool operator()(int left, int right)
	{
		return left < right;
	}
};

int main()
{
	// 정렬에 사용할 벡터(동적 배열)
	std::vector<int> data = { 3,4,2,6,7,8,5,7,99,8,9,10 };
	
	// 정렬
	// 기본이 3번째에 std::less오름차순
	//std::sort(data.begin(), data.end(), std::greater<>{});
	//Greater greater;
	//std::sort(data.begin(), data.end(), greater);
	//std::sort(data.begin(), data.end(), Less());

	// 람다를 정렬 조건으로 사용
	std::sort(
		data.begin(),
		data.end(),
		[](int left, int right) -> bool // bool은 명시적 선언, 생략 가능
		{
			return left < right;
		}
	);

	int result = 0;

	auto add = [&result](int value)
		{
			result += value;
		};
	
	add(10);
	add(20);



	for (const int item : data)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";


}