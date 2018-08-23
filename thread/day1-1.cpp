/*************************************************************************
    > File Name: day1-1.cpp
    > Author: 刘傲天
    > Mail: 1151172004@qq.com 
    > Created Time: 2018-07-15
 ************************************************************************/
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Counter{
    public:
        void addCount() { m_count++; }
        int count() const {return m_count;}
        Counter() : m_count{0}{}
    private:
        int m_count;
};

int work(int a){
    // do some thing
    return a + a;
}

template <class Iter>
void realWork(Counter & c, double & totalValue, Iter b, Iter e)
{
    for (; b != e; b++)
    {
        totalValue += work(*b);
        c.addCount();
    }
}

int main(void)
{
    //标准库建议你开启的多线程数量
    unsigned int n = thread::hardware_concurrency();
    cout << n << endl;
    vector<int> vec;
    double totalValue = 0;
    for(int i = 0; i < 100000000; i++)
    {
        vec.push_back(rand() % 100);
    }
    Counter counter;
    //do work 
    //循环容器内的每一个数据
    for (auto v: vec)
    {
        totalValue += work(v);
        counter.addCount();
    }
    //realWork(counter, totalValue, vec.begin(), vec.end());
    cout << counter.count() << endl;
    cout << totalValue << endl;
    Counter counter2;
    Counter counter3;
    Counter counter4;
    totalValue = 0;
    double totalValue1 = 0;
    double totalValue2 = 0;
    auto iter = vec.begin() + (vec.size() / 3);
    auto iter2 = vec.begin() + (vec.size() / 3 * 2);
    //创建一个lambda
    //    auto realWork = [&counter2, &totalValue](auto b, auto e)
    //    {
    //        for (; b != e; b++)
    //        {
    //            totalValue += work(*b);
    //            counter2.addCount();
    //        }
    //    };
    //创建线程
    //计算iter到iter2的部分也就是第二部分
    thread b([&counter2, &totalValue, iter, iter2]{realWork(counter2, totalValue, iter, iter2);});
    auto end = vec.end();
    thread c([&counter3, &totalValue1, iter2, end]{realWork(counter3, totalValue1, iter2, end);});
    //开始线程
    //计算到iter就结束，计算三分之一
    realWork(counter4,totalValue2, vec.begin(), iter); 
    b.join();
    c.join();
    cout << totalValue + totalValue1 + totalValue2 << endl;   
    cout << "total times use multithread:" << counter2.count() + counter3.count() + counter4.count() << endl;
    /*多线程需要谨记:
                1. 如果没有必要，线程间不要共享资源

    */
}
