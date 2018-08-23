/*************************************************************************
    > File Name: vim clock.h
    > Author: 刘傲天
    > Mail: 1151172004@qq.com 
    > Created Time: 2018-06-04
 ************************************************************************/

#ifndef __CLO_C_K_ 
#define __CLO_C_K_  

class NumberDisplay 
{
    public:
        NumberDisplay(int number1, int number2):MaxNumber(number1), number(number2){} //maxnumber 为数字上限
        ~NumberDisplay();
        bool AddOneNumber();
        virtual void Display();
    private:
        const unsigned int MaxNumber; //超过上限返回True的上限
        const unsigned int number; //每次加的数字
        unsigned int count;//要显示的数字



};



#endif  
