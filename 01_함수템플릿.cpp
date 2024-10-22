#include <iostream>
using namespace std;

// 일반화
// 특수한 개념으로부터 공통된 개념을 찾아 묶는 것을 말합니다.
// ex) 포유류 기본 클래스
//     강아지, 인간, 고양이 파생 클래스
//     포유류가 공통적으로 갖는 데이터 및 기능을 찾아, 베이스에
//     작성하는 행위

// 일반화 프로그래밍
// 데이터 타입을 일반화하여, 프로그래밍 하는 방식
// c++에서는 템플릿을 이용한 프로그래밍을 의미

// 템플릿
// 변수의 타입을 정하지 않고, 필요한 타입을 컴파일 타임에
// 정의하여 사용하는 개념을 의미
// 이러한 템플릿을 함수 템플릿과 클래스 템플릿으로 나뉩니다.
// 템플릿을 프로젝트 전반에 걸쳐, 적용하여 사용하는
// 프로그래밍 패러다임도 존재 -> 템플릿 메타 프로그래밍

// 함수 템플릿
// 데이터 타입이 정해지지 않았으므로, 호출 시에 사용할 타입을 지정
// 함수 템플릿을 이용하면, 완전히 같은 기능을 하는 함수를
// 다른 타입에 대하여, 별도로 오버로딩하지 않아도 됩니다.

// T 라는 이름으로 데이터타입을 일반화하여 사용하겠다라고 선언
// T 라는 이름 대신, 다른 이름을 사용하여도 상관없음
// -> 관습적으로 T를 주로 사용  T, U
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

template<typename T, typename U>
T GetValue(U value)
{
	// 임의의 타입 u타입을 파라미터로 받아
	// t 타입으로 캐스팅한 후, 반환하는 함수
	return (T)value;
}

void main()
{
	cout << "Add int 결과 : " << Add<int>(1, 2) << endl;

	// 함수 호출에 <T타입>을 지정할 수 있지만
	// 지정하지 않아도, 전달되는 인자의 타입에 따라
	// 자동적으로 호출될 함수의 유형을 컴파일러가 추론하므로 생략 가능
	cout << "Add double 결과 : " << Add(3.5, 6.4) << endl;

	// 아래와 같이 매개변수에 사용되지 않는 타입이 존재할 경우
	// 함수 호출 시, 임의의 타입을 명시적으로 지정해야 한다.
	cout << "GetValue 3.14 -> int 변환 : " << GetValue<int, double>(3.14) << endl;
}
