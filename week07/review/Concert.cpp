#include "Concert.h"
#include <iostream>
using namespace std;

Concert::Concert(const string& name, const int& capacity)
    :name(name), capacity(capacity), rList(make_unique<string[]>(capacity))//unique_ptr�� ��� �ʱ�ȭ
    //, rList(new string[capacity])
    //shared_ptr�� �迭������ �������� : new���
{
    cout << "������" << endl;
}

//���� ����
Concert::Concert(const Concert& concert)
    :Concert(concert.name, concert.capacity) //���� ������
    //���ӻ����ڸ� �̿��ؼ� �ʱ�ȭ�� ��� ���ǻ���
    //: Concert(concert.name, concert.capacity), num(concert.num)
    //���ӻ����� �̿ܿ� ���� �ʱ�ȭ ��ų �� ���� (�̴ϼȶ������)
{
    cout << "���� ������" << endl;
    num = concert.num;
    for (size_t i = 0; i < num; i++) {
        rList[i] = concert.rList[i];
    }
}

//���� ����
//�� ������ ��ü�ε� ���� �������� ���� ������ �ʿ� ���� ���
//stack�� �ִ� ���븸 ���� ����
Concert::Concert(Concert&& concert) noexcept
    :name(concert.name), capacity(concert.capacity), num(concert.num), rList(move(concert.rList))//, rList(concert.rList)
    //unique_ptr�� ���� ����x : move��Ű��
{
    cout << "�̵� ������" << endl;
    //1. �̴ϼȶ������ ��� ������� �ʱ�ȭ�����ֱ�
    //2. �̵������ڷ� ������� �Ͱ� ���� concert�� ���� �ּҸ� ����Ŵ
    //3. P : ������ �����µ��� �� ������ ����Ű�� �� �����ֱ� ������ error
    //4, S : 
    concert.num = 0; //�Ҹ��� �����ڸ���Ʈ ��� �� , �����۵�
    //concert.rList = nullptr; //unique_ptr�� �̹� move��Ű�鼭 concert.rList�� nullptr�� ����Ǿ��� ������ �ʿ�x����
}

Concert::~Concert()
{
    cout << name << "�Ҹ���" << endl;
    /*if (rList != nullptr) {
        delete[] rList;
    }
    rList = nullptr;*/
}

void Concert::reservation()
{
    if (!full() && rList != nullptr) {
        cout << "������ �̸��� �Է��ϼ��� : ";
        cin >> rList[num++];
        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
    }
}

bool Concert::full() const
{
    return capacity == num;
    //���밡���ο� = ������ �� : true��ȯ
    //���밡���ο� != ������ �� : false��ȯ
}

int Concert::getCapacity() const
{
    return capacity;
}

int Concert::getNum()
{
    return num;
}

void Concert::show() const
{
    cout << "�ܼ�Ʈ �� : " << name << endl;
    cout << "���� �� : " << num << endl;
    cout << "������ ����Ʈ" << endl;
    cout << "=================" << endl;
    for (size_t i = 0; i < num; i++) {
        cout << rList[i] << endl;
    }
    cout << "=================" << endl;
}
