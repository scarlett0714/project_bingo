#include <iostream>
// ��� ����
// const float PI = 3.14; 
// P : 3.14�� double
// S1 : Ÿ���� double�� ��ȯ
const double PI = 3.14;
// S2 : ����f -> float������ �����
// const float PI = 3.14f;

// �Լ� ���� ����
double area(int r);

int main(void) {
	int r = 3;
	std::cout << "������ " << area(r) << "�Դϴ�.\n";
	// std::cout << "������ " << area(r) << "�Դϴ�." << std::endl;
	//endl�� \n�� �ٸ��� ���۸� ���� ��������
	return 0;
}

double area(int r) {
	return PI * r * r;
}