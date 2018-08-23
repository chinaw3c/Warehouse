#include <iostream>
#include "TicketMachine.h"

using namespace std;

TicketMachine::TicketMachine()
{
	//构造函数
}

TicketMachine::~TicketMachine()
{
	//析构函数
}

void TicketMachine::showPrompt()
{
    cout << "something";
}

void TicketMachine::insertMoney(int money)
{
    balance += money;

}

void TicketMachine::showBalance()
{
    cout << balance;
}

