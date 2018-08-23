/*************************************************************************
    > File Name: clock.cpp
    > Author: 刘傲天
    > Mail: 1151172004@qq.com 
    > Created Time: 2018-06-04
 ************************************************************************/
#include "clock.h"
#include <iostream>

using namespace std;

bool NumberDisplay::AddOneNumber()
{
    count += number;
    return count >= MaxNumber ? count = 0,true : false;
}

void NumberDisplay::Display()
{
    count < 10 ? cout << "0" << count : cout << count;
}

NumberDisplay::~NumberDisplay()
{
    //析构函数
}



