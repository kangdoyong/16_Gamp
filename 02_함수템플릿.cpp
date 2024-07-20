#include <iostream>
using namespace std;

// 함수템플릿의 특수화
// 특정 타입에 대해 다른 처리를 하는 것을 의미

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 위의 Add 함수의 T타입에는 
// 어떤 타입이든 올 수 있음
// 현재 함수의 동작은 두 파라미터의 + 연산임
// 이 때, T타입에 수치형 데이터가 올 경우에는 문제가 없음
// 하지만 T 타입에 문자열 데이터를 전달한다면?
// 의도치 않은 동작으로 이어질 수 있음
// 이렇게 사용 의도에 벗어나는 특정 타입이 있을 경우
// 특수화를 이용해서 별도로 처리를 할 수 있음

// 특수화 방법
// 특수화 시킬 함수템플릿을 동일하게 작성
// typename을 작성하지 않고, 임의의 타입 대신
// 특수화 시킬 타입을 명시적으로 작성
template<>
const char* Add(const char* a, const char* b)
{
	const char* str = "문자열은 더 할 수 없습니다.";
	return str;
}

void main()
{
	cout << "Add(int, int) = " << Add(10, 20) << endl;
	cout << "Add(char*, char*) = " << Add("ABC", "DEF") << endl;
}
