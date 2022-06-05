#include "Concert.h"
#include <iostream>
using namespace std;

Concert::Concert(const string& name, const int& capacity)
    :name(name), capacity(capacity), rList(make_unique<string[]>(capacity))//unique_ptr일 경우 초기화
    //, rList(new string[capacity])
    //shared_ptr은 배열생성시 직접생성 : new사용
{
    cout << "생성자" << endl;
}

//깊은 복사
Concert::Concert(const Concert& concert)
    :Concert(concert.name, concert.capacity) //위임 생성자
    //위임생성자를 이용해서 초기화할 경우 주의사항
    //: Concert(concert.name, concert.capacity), num(concert.num)
    //위임생성자 이외에 따로 초기화 시킬 수 없음 (이니셜라이즈에서)
{
    cout << "복사 생성자" << endl;
    num = concert.num;
    for (size_t i = 0; i < num; i++) {
        rList[i] = concert.rList[i];
    }
}

//얕은 복사
//곧 삭제될 객체인데 굳이 방대방으로 깊은 복사할 필요 없을 경우
//stack에 있는 내용만 얕은 복사
Concert::Concert(Concert&& concert) noexcept
    :name(concert.name), capacity(concert.capacity), num(concert.num), rList(move(concert.rList))//, rList(concert.rList)
    //unique_ptr은 직접 대입x : move시키기
{
    cout << "이동 생성자" << endl;
    //1. 이니셜라이즈에서 모든 멤버들을 초기화시켜주기
    //2. 이동생성자로 만들어진 것과 원래 concert는 같은 주소를 가리킴
    //3. P : 공간을 지웠는데도 그 공간을 가리키는 게 남아있기 때문에 error
    //4, S : 
    concert.num = 0; //소멸후 예약자리스트 출력 시 , 정상작동
    //concert.rList = nullptr; //unique_ptr은 이미 move시키면서 concert.rList가 nullptr로 변경되었기 때문에 필요x구문
}

Concert::~Concert()
{
    cout << name << "소멸자" << endl;
    /*if (rList != nullptr) {
        delete[] rList;
    }
    rList = nullptr;*/
}

void Concert::reservation()
{
    if (!full() && rList != nullptr) {
        cout << "예약자 이름을 입력하세요 : ";
        cin >> rList[num++];
        cout << "예약이 완료되었습니다." << endl;
    }
}

bool Concert::full() const
{
    return capacity == num;
    //수용가능인원 = 예약자 수 : true반환
    //수용가능인원 != 예약자 수 : false반환
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
    cout << "콘서트 명 : " << name << endl;
    cout << "예약 수 : " << num << endl;
    cout << "예약자 리스트" << endl;
    cout << "=================" << endl;
    for (size_t i = 0; i < num; i++) {
        cout << rList[i] << endl;
    }
    cout << "=================" << endl;
}
