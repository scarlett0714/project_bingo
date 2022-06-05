#pragma once
#include "ArrayData.h"
class ArrayDataSmart :
    public ArrayData
{
private:
    //�θ� �ִ� data�� ������� ����
    unique_ptr<double[]> backdata;
    int usedB; //������� �����Ͱ���
public:
    ArrayDataSmart();
    ArrayDataSmart(ArrayDataSmart& arr);
    ArrayDataSmart(ArrayDataSmart&& arr) noexcept;
    ArrayDataSmart(const int& capacity, const int& used = 0);
    ~ArrayDataSmart();
    void backup();
    void restore(); //����޾Ҵ��� ���� ���·� ������
    ArrayDataSmart& operator=(const ArrayDataSmart& rhs);
    ArrayDataSmart& operator=(ArrayDataSmart&& rhs) noexcept;
};

