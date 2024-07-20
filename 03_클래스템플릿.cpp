#include <iostream>
using namespace std;

// Ŭ���� ���ø�
// �����Ǵ� ��ɰ� ������ �ൿ�� ��� ����������
// "����ϴ� Ÿ���� ���� �ٸ� Ŭ���� ��ü"�� �� �� �ִ� Ʋ�� �ǹ�

// �迭�� ����� ������ �ϴ� Ŭ����
template<typename T>
class MyArray
{
private:
	// TŸ�� �迭�� �����ּҸ� ��� ���� �ʵ�
	T* arr;
	// �迭�� ����
	int length;

	// ���� ���ø��� ����ϴ� Ŭ�������
	// ����ο� ������ ��� �����ؾ� �մϴ�.
	// ������ ��, ���ø� �ҽ� �ڵ带 ����� ���µ�
	// ���ø��� ����� ���ǰ� �������� �ִٸ�,
	// ����� ���ø� �ҽ��ڵ尡 �������� ���� -> ��ũ ���� �߻�
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

	// Ư�� �ε����� ���� ���� ��ȯ�ϴ� ���
	T GetElement(int index)
	{
		// �Ķ���ͷ� ���� �ε����� �迭 ������ ������� Ȯ��
		if (index < 0 || index >= length)
		{
			cout << "�迭�� ������ ������ϴ�." << endl;
			return -1;
		}

		return arr[index];
	}

	// ���� �迭 ���̸� ��ȯ�ϴ� ���
	int GetLength()
	{
		return length;
	}

	// �迭�� ���Ҹ� �߰��ϴ� ���
	void Add(T value)
	{
		// ���Ҹ� �߰��ϹǷ�, ���̸� ������Ŵ
		++length;

		// ���� �迭�� �Ҵ�Ǿ����� ���ο� ����, ó���� �ٸ��� ��
		if (arr)
		{
			// �迭�� �����Ѵٸ�

			// ���Ҵ��� ����, ������ �迭�� �ӽ÷� ��Ƶ�
			// ������ �Ҵ�� ������ �����ּҸ� ��Ƶ�
			T* tempArr = arr;

			// tempArr�� ���� �Ҵ�� ������ �ּҸ� ��� �����Ƿ�
			// ���ο� ������ �Ҵ��ϰ� arr�� �ش� �ּҸ� ������ �� 
			arr = new T[length];

			// ������ ������ �ִ� ���� ���ο� �������� �ű�
			for (int i = 0; i < length - 1; ++i)
			{
				arr[i] = tempArr[i];
			}

			// ���� �� �Ű����Ƿ�, ���� ���� �Ҵ� ����
			delete tempArr;
			tempArr = nullptr;
		}
		else
		{
			// �������� �ʴ´ٸ�, �ʱ� �Ҵ�
			arr = new T[length];
		}

		// ��������� arr���� ���ο� ���� ���� ������ ����
		// ������ ���ҿ� �����Ͽ� �� �Ҵ�
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

	cout << "�迭 ���� : " << myArray->GetLength() << endl;

	cout << "�迭 ���� : ";
	for (int i = 0; i < myArray->GetLength(); ++i)
	{
		cout << myArray->GetElement(i) << " ";
	}
	cout << endl;

	delete myArray;
	myArray = nullptr;
}
