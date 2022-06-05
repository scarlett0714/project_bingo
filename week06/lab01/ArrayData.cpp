#include "ArrayData.h"
#include <iostream>
using namespace std;
//����Ʈ �����ڸ� �̿��ؼ� �迭�� ����� capacity : 3
ArrayData::ArrayData() :ArrayData(3)
{
}

ArrayData::ArrayData(const int& capacity, const int& used)
	: capacity(capacity), used(used)
{
	cout << "������" << endl;
	//data = new double[this->capacity];
	//data = make_unique<double[]>(this->capacity);
	data = shared_ptr<double[]>(new double[this->capacity]);

}

ArrayData::ArrayData(const ArrayData& arr)
	:ArrayData(arr.capacity, arr.used)
{
	cout << "���� ������" << endl;
	//�迭�� ���ӻ����ڷ� �Ҵ� �ް� ���� �۾� ����
	for (size_t i = 0; i < used; i++) {
		data[i] = arr.data[i]; //��:������ ����
		//���� �ٸ� �޸𸮸� ��������, ���� same
	}
}

ArrayData::~ArrayData()
{
	if (data != nullptr)
		delete[] data;
	data = nullptr;
}

void ArrayData::addElement(const double& num)
{
	if (!full())
		data[used++] = num;
	//used++ : ���� ���� ��ġ�� ����Ŵ
	else
		cout << "����� ����\n";
}

bool ArrayData::full() const
{
	return this->capacity == this->used;
}

void ArrayData::emptyArray()
{
	//�迭 �����
	//��� 1. ��� �� �ʱ�ȭ
	//��� 2. used�� 0���� �ʱ�ȭ
	this->used = 0;
}

void ArrayData::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}
