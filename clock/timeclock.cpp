/*************************************************************************
    > File Name: main.cpp
    > Author: 刘傲天
    > Mail: 1151172004@qq.com 
    > Created Time: 2018-06-05
 ************************************************************************/

#include "clock.h"
#include <iostream>
#include <unistd.h>

#define UINT unsigned int 

class Clock  
{
    public:
        Clock(UINT MaxNumber1, UINT AddNumber1, UINT MaxNumber2, UINT AddNumber2):hour(MaxNumber1, AddNumber1), miniut(MaxNumber2, AddNumber2){};
        ~Clock(){};
        void Display()
        {
            hour.Display();
            std::cout << ":";
            miniut.Display();

        }

        void TimeStart()
        {
            //当miniut达到上限的时候就会返回True，并且清零当前的数目
            if (miniut.AddOneNumber())
            {
                hour.AddOneNumber();
            }
        }
    private:
        //小时
        NumberDisplay hour;
        //分钟
        NumberDisplay miniut;
};

int main(void)
{
    Clock demo(24, 1, 60, 1);
    while (true)
    {
        system("clear");
        demo.Display();
        std::cout << std::endl;
        demo.TimeStart();
        usleep(1000000);  
    }
    return 0;
}
