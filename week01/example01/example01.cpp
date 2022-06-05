#include <iostream>
// 상수 선언
// const float PI = 3.14; 
// P : 3.14는 double
// S1 : 타입을 double로 변환
const double PI = 3.14;
// S2 : 숫자f -> float형으로 만들기
// const float PI = 3.14f;

// 함수 원형 정의
double area(int r);

int main(void) {
	int r = 3;
	std::cout << "면적은 " << area(r) << "입니다.\n";
	// std::cout << "면적은 " << area(r) << "입니다." << std::endl;
	//endl은 \n과 다르게 버퍼를 비우는 역할포함
	return 0;
}

double area(int r) {
	return PI * r * r;
}