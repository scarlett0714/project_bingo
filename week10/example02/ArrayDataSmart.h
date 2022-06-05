#pragma once
#include "ArrayData.h"
class ArrayDataSmart :
    public ArrayData
{
private:
    //부모에 있는 data를 백업받을 공간
    unique_ptr<double[]> backdata;
    int usedB; //백업받은 데이터개수
public:
    ArrayDataSmart();
    ArrayDataSmart(ArrayDataSmart& arr);
    ArrayDataSmart(ArrayDataSmart&& arr) noexcept;
    ArrayDataSmart(const int& capacity, const int& used = 0);
    ~ArrayDataSmart();
    void backup();
    void restore(); //백업받았던거 원래 상태로 돌리기
    ArrayDataSmart& operator=(const ArrayDataSmart& rhs);
    ArrayDataSmart& operator=(ArrayDataSmart&& rhs) noexcept;
};

