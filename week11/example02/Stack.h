#pragma once
//const int MAX = 10;

//템플릿 클래스
template<typename T = int, int MAX = 10>
class Stack {
private:
	T items[MAX];
	int top;

public:
	Stack();
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const T& item);
	bool pop(T& item);
};

//한 파일안에 정의와 선언 같이
template<typename T, int MAX>
Stack<T, MAX>::Stack() : top(0)
{
}

template<typename T, int MAX>
Stack<T, MAX>::~Stack()
{
}

template<typename T, int MAX>
bool Stack<T, MAX>::isEmpty() const
{
	return top == 0;
}

template<typename T, int MAX>
bool Stack<T, MAX>::isFull() const
{
	return top == MAX;
}

template<typename T, int MAX>
bool Stack<T, MAX>::push(const T& item)
{
	if (!isFull()) { //공간 있어
		items[top++] = item;
		return true;
	}
	else { //공간 없어
		return false;
	}
}

template<typename T, int MAX>
bool Stack<T, MAX>::pop(T& item)
{
	if (!isEmpty()) { //데이터 있어
		item = items[--top];
		return true;
	}
	else { //데이터 없어
		return false;
	}
}
