/*
 *TicketMachine.h
 *
 *  Created on:2018-06-03 19:33:00
 *		Author:刘傲天
 */
#ifndef _TICKETMACHINE_H__
#define _TICKETMACHINE_H__ 

class TicketMachine
{
	public:
		TicketMachine(); //构造函数
		virtual ~TicketMachine(); //析构函数
		void showPrompt();
		void insertMoney(int money);
		void showBalance();
		void printTicket();
		void showTotal();
	private:
		const int PRICE = 200;
		int balance;
		int total;
};

#endif
