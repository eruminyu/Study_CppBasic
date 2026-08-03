#include <iostream>


// 두 수를 서로 교환하는 함수

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 클래스 템플릿을 만들어보기

template<typename T, int size = 10> // Size 라는 명확한 파라미터를 하나 지정 가능.
// 두번째 파라미터를 지정하지 않으면 기본값으로 10이 들어감. (Default Parameter)
class Data
{
public:
	Data(const T& newData )
		:data(newData)
	{	//data = newData;
	}

	T GetData() const
	{
		return data;
	}
	void SetData(const T& newData)
	{
		data = newData;
	}
	int GetSize() const
	{
		return size;
	}

private:

};

int main()
{
	int a = 10;
	int b = 30;
	Swap(a, b);

	Data<int, 100> intData(100);
	std::cout << intData.GetData() << "\n";
	std::cout << "Size: " << intData.GetSize()
		<< ", Data: " << intData.GetData() << "\n";

	Data<float> pi(3.141592f);
	std::cout << pi.GetData() << "\n";

	std::swap<int>(a, b);

	std::cin.get();
}