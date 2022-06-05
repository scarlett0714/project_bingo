#pragma once
#include <memory> //����Ʈ ������ ���
using namespace std;

class ArrayData
	//capacity��ŭ ���� �Ҵ����� �迭����
	//�� �ּҰ��� data�� ����Ŵ
{
private:
	//double* data = nullptr;
	//unique_ptr<double[]> data;
	shared_ptr<double[]> data;

	int capacity; //�迭�� �뷮 (���� �Ҵ�)
	int used; //������ ���� ���� ����
public:
	ArrayData();
	ArrayData(const int& capacity, const int& used=0);
	ArrayData(ArrayData& arr); //���� ������
	ArrayData(ArrayData&& arr) noexcept; //�̵� ������ : const���x
	~ArrayData();


	void addElement(const double& num); //�� �߰�
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
};

