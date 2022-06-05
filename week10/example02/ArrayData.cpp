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
	data = make_unique<double[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
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

ArrayData::ArrayData(ArrayData&& arr) noexcept
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
	//unique_ptr�� ��� : data(move(arr.data))�� �ʱ�ȭ
	//����Ʈ �����Ͱ� �ƴ� ��� : data(arr.data)�� �ʱ�ȭ
{
	cout << "�̵� ������" << endl;
	arr.data = nullptr;
	//unique_ptr�� ��� : move�Լ����� �̹� nullptr�Ǳ� ������ ���� �ڵ� �ʿ�x
}

ArrayData::~ArrayData()
{
	//unique_ptr, shared_ptr����� ��� delete��� �ʿ�x
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
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

ArrayData& ArrayData::operator=(const ArrayData& rhs)
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
	data.reset(new double[capacity]);
	
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

ArrayData& ArrayData::operator=(ArrayData&& rhs) noexcept
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
double& ArrayData::operator[](size_t num)
{
	if (num >= 0 && num < capacity) {
		return data[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

const double& ArrayData::operator[](size_t num) const
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
ostream& operator<<(ostream& out, const ArrayData& arr)
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
