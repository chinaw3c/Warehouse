/*************************************************************************
    > File Name: main.cpp
    > Author: 刘傲天
    > Mail: 1151172004@qq.com 
    > Created Time: 2018-06-03
 ************************************************************************/

#include<iostream>
#include "TicketMachine.h" 

using namespace std;

int main(void)
{
    TicketMachine tm;
    tm.insertMoney(100);
    tm.showBalance();
 
    return 0;
}
