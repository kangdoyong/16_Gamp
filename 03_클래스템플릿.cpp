#include <iostream>
using namespace std;

// 클래스 템플릿
// 제공되는 기능과 내부의 행동이 모두 동일하지만
// "사용하는 타입이 서로 다른 클래스 객체"를 찍어낼 수 있는 틀을 의미

// 배열과 비슷한 동작을 하는 클래스
template<typename T>
class MyArray
{
private:
	// T타입 배열의 시작주소를 들고 있을 필드
	T* arr;
	// 배열의 길이
	int length;

	// 만약 템플릿을 사용하는 클래스라면
	// 선언부에 내용을 모두 정의해야 합니다.
	// 컴파일 시, 템플릿 소스 코드를 만들어 내는데
	// 템플릿의 선언과 정의가 나누어져 있다면,
	// 제대로 템플릿 소스코드가 생성되지 않음 -> 링크 오류 발생
public:
	MyArray()
	{
		arr = nullptr;
		length = 0;
	}

	virtual ~MyArray()
	{
		if (arr)
		{
			delete[] arr;
			arr = nullptr;
		}
	}

	// 특정 인덱스의 원소 값을 반환하는 기능
	T GetElement(int index)
	{
		// 파라미터로 받은 인덱스가 배열 범위를 벗어나는지 확인
		if (index < 0 || index >= length)
		{
			cout << "배열의 범위를 벗어났습니다." << endl;
			return -1;
		}

		return arr[index];
	}

	// 현재 배열 길이를 반환하는 기능
	int GetLength()
	{
		return length;
	}

	// 배열에 원소를 추가하는 기능
	void Add(T value)
	{
		// 원소를 추가하므로, 길이를 증가시킴
		++length;

		// 기존 배열이 할당되었는지 여부에 따라, 처리를 다르게 함
		if (arr)
		{
			// 배열이 존재한다면

			// 재할당을 위해, 기존의 배열을 임시로 담아둠
			// 기존에 할당된 공간의 시작주소를 담아둠
			T* tempArr = arr;

			// tempArr가 기존 할당된 공간의 주소를 들고 있으므로
			// 새로운 공간을 할당하고 arr가 해당 주소를 가지게 끔 
			arr = new T[length];

			// 기존에 가지고 있던 값을 새로운 공간으로 옮김
			for (int i = 0; i < length - 1; ++i)
			{
				arr[i] = tempArr[i];
			}

			// 값을 다 옮겼으므로, 기존 공간 할당 해제
			delete tempArr;
			tempArr = nullptr;
		}
		else
		{
			// 존재하지 않는다면, 초기 할당
			arr = new T[length];
		}

		// 결과적으로 arr에는 새로운 값을 담을 공간이 생김
		// 마지막 원소에 접근하여 값 할당
		arr[length - 1] = value;
	}
};

void main()
{
	MyArray<int>* myArray = new MyArray<int>();
	
	myArray->Add(10);
	myArray->Add(20);
	myArray->Add(30);
	myArray->Add(40);
	myArray->Add(50);

	cout << "배열 길이 : " << myArray->GetLength() << endl;

	cout << "배열 원소 : ";
	for (int i = 0; i < myArray->GetLength(); ++i)
	{
		cout << myArray->GetElement(i) << " ";
	}
	cout << endl;

	delete myArray;
	myArray = nullptr;
}
