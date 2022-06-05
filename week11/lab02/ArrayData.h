#pragma once
#include <memory> //����Ʈ ������ ���
using namespace std;

template <typename T>
class ArrayData
	//capacity��ŭ ���� �Ҵ����� �迭����
	//�� �ּҰ��� data�� ����Ŵ
{
protected:
	//double* data = nullptr;
	unique_ptr<T[]> data;
	//shared_ptr<double[]> data;

	int capacity; //�迭�� �뷮 (���� �Ҵ�)
	int used; //������ ���� ���� ����
public:
	ArrayData();
	ArrayData(const int& capacity, const int& used=0);
	ArrayData(const ArrayData& arr); //���� ������
	ArrayData(ArrayData&& arr) noexcept; //�̵� ������ : const���x
	~ArrayData();


	void addElement(const T& num); //�� �߰�
	bool full() const; //���� �� ���ִ°�?
	void emptyArray(); //�迭�� ���
	void showData() const; //�迭�� ���

	//��ȯ get : inline���� ����
	int getCapacity() const {
		return this->capacity;
	};
	int getUsed() const {
		return this->used;
	};
	void setUsed() {
		used++;
	}

	//���� ������ �����ε�
	ArrayData& operator=(const ArrayData& rhs);
	ArrayData& operator=(ArrayData&& rhs) noexcept;

	//�迭 ������ �����ε�
	//1.
	T& operator[](size_t num);
	//2. const�� �����ε� ���O
	const T& operator[](size_t num) const;

	template <typename T1>
	friend ostream& operator<<(ostream& out, const ArrayData<T1>& arr);
};

#include "ArrayDataDef.h"

