/*************************************************************************
	> File Name: analysisTasklist.cpp
	> Author: 刘傲天
	> Mail: 1151172004@qq.com
	> Created Time: Tue 21 Aug 2018 09:16:34 PM CST
    > 8.21号先不写了，去玩游戏了
    > 8.22号睡醒了，先写一会
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

/*要删除的行数*/
#define DELLINE 3

using namespace std;

class linedata{
public:
    string Name;
    unsigned int PID;
    string session_name;
    short int session;
    long long int RAM;
};

class Tasklist{
public:
    Tasklist(){
        string line; /*每一行的数据*/
        char count = 0; /*count用于计数，删除前几行,用char是因为省内存*/
        /*首先是获得tasklist,Windows则通过命令行获得，Linux则通过读取相同目录下的文件夹*/   
        #ifdef __WINDOWS__
            system("tasklist /FI 'IMAGENAME ne PID' >> tasklist.txt");
        #endif
        /*如果是Linux，应该本身存在这个文件(自己挪过来)*/
        fstream file("tasklist.txt");
        while (getline(file, line))
        {
            count += 1;
            if (count < DELLINE+1)
            {
                //当没有删光要删除的行时，跳过循环
                continue;
            }
            lines.push_back(line);
        }
        file.close();
    };
    
    void analysis(){
        /*创建一行数据的结构体*/
        linedata linedata;
        /*代表的是每一行的每一个数据*/
        string data;
        string data1;
        bool kg = true;
        for (string i : lines){
            /*清空data1*/
            data1 = "";
            kg = true;
            i = delspace(i);
            istringstream line(i);
            while (line >> data){
                /*判断映像名称是否有空格，也就是第一次碰到数字之前的都是名称*/
                if (!(47 < data[0] && data[0] < 58)){
                    data1 = data1 + data + " ";
                    continue;
                }
                /*遇到数字之后就退出循环，但是有一个问题，退出后当前这个数字就丢失了
                * 所以推出前先给他赋值*/
                linedata.Name = data1;
                linedata.PID = stoi(data);
                break;
            }
            line >> linedata.session_name;
            line >> data1;
            linedata.session = stoi(data1);
            line >> data1;
            linedata.RAM = stoi(data1);
            alldata.push_back(linedata);
        }
    }

    void showline(){
        for(auto i : lines){
            cout << i << endl;
        }
    };

    void showlinedata(){
        for(auto i : alldata){
            cout << i.Name << endl;
            cout << i.PID << endl;
            cout << i.session_name << endl;
            cout << i.session << endl;
            cout << i.RAM << endl;
        }
    }
private:
    /*每一行数据*/
    vector<string> lines; 
    vector<linedata> alldata;

    /*尝试后发现，他只是把有空格的地方分开了...并不是我们想要的结果,失望*/   
    /*尝试在写更高级的*/
    /*这个遗弃掉，重新写*/
    void analysis1(){
        
        for (auto i : lines){
            string data;
            /*将字符串放进C++提供的标准库类中*/
            istringstream line(i);
            while(line >> data){
                cout << data << endl;
            }
            /*输出太多不想看，只输出一个*/
            break;
        }
        
    }

    /*发现标准库里的并不是很好用,去除多余的空格，然后在用那个函数处理*/
    string delspace(string data){
        if (data.find("  ") == string::npos){
            //如果不存在就退出
            return data;
        }   
        return delspace(data.replace(data.find("  "), 2, " "));
    }

};

int main(void)
{
    Tasklist one;
    one.analysis();
    one.showlinedata();

    return 0;
}
