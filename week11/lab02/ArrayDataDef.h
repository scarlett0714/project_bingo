#pragma once
#include "ArrayData.h"
#include <iostream>
using namespace std;

template<typename T>
//����Ʈ �����ڸ� �̿��ؼ� �迭�� ����� capacity : 3
ArrayData<T>::ArrayData() :ArrayData(3)
{
}

template<typename T>
ArrayData<T>::ArrayData(const int& capacity, const int& used)
	: capacity(capacity), used(used)
{
	cout << "������" << endl;
	//data = new double[this->capacity];
	data = make_unique<T[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}

template<typename T>
ArrayData<T>::ArrayData(const ArrayData& arr)
	:ArrayData(arr.capacity, arr.used)
{
	cout << "���� ������" << endl;
	//�迭�� ���ӻ����ڷ� �Ҵ� �ް� ���� �۾� ����
	for (size_t i = 0; i < used; i++) {
		data[i] = arr.data[i]; //��:������ ����
		//���� �ٸ� �޸𸮸� ��������, ���� same
	}
}

template<typename T>
ArrayData<T>::ArrayData(ArrayData&& arr) noexcept
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
	//unique_ptr�� ��� : data(move(arr.data))�� �ʱ�ȭ
	//����Ʈ �����Ͱ� �ƴ� ��� : data(arr.data)�� �ʱ�ȭ
{
	cout << "�̵� ������" << endl;
	arr.data = nullptr;
	//unique_ptr�� ��� : move�Լ����� �̹� nullptr�Ǳ� ������ ���� �ڵ� �ʿ�x
}

template<typename T>
ArrayData<T>::~ArrayData()
{
	//unique_ptr, shared_ptr����� ��� delete��� �ʿ�x
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
}

template<typename T>
void ArrayData<T>::addElement(const T& num)
{
	if (!full())
		data[used++] = num;
	//used++ : ���� ���� ��ġ�� ����Ŵ
	else
		cout << "����� ����\n";
}

template<typename T>
bool ArrayData<T>::full() const
{
	return this->capacity == this->used;
}

template<typename T>
void ArrayData<T>::emptyArray()
{
	//�迭 �����
	//��� 1. ��� �� �ʱ�ȭ
	//��� 2. used�� 0���� �ʱ�ȭ
	this->used = 0;
}

template<typename T>
void ArrayData<T>::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(const ArrayData<T>& rhs)
{
	//���� ����
	cout << "���Կ�����" << endl; //a = b;�ǹ� (a�� ����)
	//���� ������ �����ϴ� ���, ���� ���� �����ʿ�X
	if (this == &rhs)
		return *this;

	//���� ���� Ÿ���ε� �ٸ� ��ü�� ���
	this->capacity = rhs.capacity;
	this->used = rhs.used;


	//���1. unique_ptr, shared_ptr�� ���
	data.reset(new T[capacity]);

	//���2. shared_ptr�� ��� : resource���� -> ���� count����
	//data = static_cast<shared_ptr<double[]>>(new double[capacity]);

	//���3. ����Ʈ ������ �ƴѰ��
	//���� ������ �ִ� data�� �����ְ� ���ο� ���� ����
	/*if (data != nullptr)
		delete[] data;*/
		//data = new double[capacity];

		//��:������ �� ����
	for (size_t i = 0; i < used; i++) {
		//���1.
		data[i] = rhs.data[i];
		//���2. ���1 ������ ��� ���
		//*(data + i) = *(rhs.data + i);
	}
	return *this;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(ArrayData<T>&& rhs) noexcept
{
	//���� ���� : rhs�� �ӽð�ü : ����� ��ü
	cout << "�̵����Կ�����" << endl;
	this->capacity = rhs.capacity;
	this->used = rhs.used;

	//����Ʈ �������� ���
	//r-value data�� ����� : move
	data = move(rhs.data); //rhs.data�� �ش��ϴ� ���� �ڵ����� ����� : nullptr�� �ʱ�ȭ �ʿ�X

	//����Ʈ ������ �ƴѰ��
	//������ ����Ű�� �ִ��� ����� ����
	/*if (data != nullptr)
		delete[] data;
	data = rhs.data;*/
	//rhs.data = nullptr; : move�� ����ϸ� �ڵ����� ����

	return *this;
}

//���� ����
template<typename T>
T& ArrayData<T>::operator[](size_t num)
{
	if (num >= 0 && num < capacity) {
		return data[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

template<typename T>
const T& ArrayData<T>::operator[](size_t num) const
{
	if (num >= 0 && num < used) { //num<capacity�� ���, �����Ⱚ���� ��� ��µ�
		return data[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

//cout -> out���� ����
template<typename T1>
ostream& operator<<(ostream& out, const ArrayData<T1>& arr)
{
	for (size_t i = 0; i < arr.getUsed(); i++) {
		//operator<<�� �����Լ��� .p�� �߰��� ���
		//out << arr[i] << "\t";

		//data�� �����ϰ�ʹٸ� private�̹Ƿ� friend�Լ��� �߰�
		out << arr.data[i] << "\t";
	}
	out << endl;
	return out;
}
