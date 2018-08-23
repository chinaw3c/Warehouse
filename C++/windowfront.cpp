#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

void Get_Window_Name();
void trim(string &a);
void GetWindowHandle();
void GetWindowName();
HWND GetHandle(int number);

static vector<string> Name;
static vector<HWND> HandList;

int main(void)
{
	int count = 0;
	int number = 0;
	HWND m_Hwnd;
	char WindowName[1000] = { 0 };
	//SetWindowPos(m_Hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
	Get_Window_Name();
	GetWindowHandle();
	GetWindowName();
	cout << "你想操作谁?";
	cin >> count;
	cout << "(前置:1,后置:2)";
	cin >> number;
	system("cls");
	cout << "OK,你输入的是" << count << "和" << number << endl;
	m_Hwnd = GetHandle(count);
	GetWindowText(m_Hwnd, WindowName, sizeof(WindowName));
	cout << "你选择了" << WindowName << endl;
	if (number == 1)
	{
		int value = SetWindowPos(m_Hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		if (value)
		{
			cout << "设置前置出错" << endl;
		}
		else
		{
			cout << WindowName << "已经前置" << endl;
		}	
	}
	else if (number == 2)
	{
		//SetWindowPos(m_Hwnd, HWND_TOP, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		SetWindowPos(m_Hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		//SetWindowPos(m_Hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		cout << WindowName << "已经后置" << endl;
	}
	else
	{
		cout << "你输的什么玩意，我看不懂" << endl;
	}
	system("pause");
}

void Get_Window_Name()
{
	vector<string> Handle_name;
	string app_name;
	char data[1000] = {0};
	cout << "开始处理进程" << endl;
	system("tasklist /V >> Liuaotian.txt");
	fstream file("Liuaotian.txt", ios::in); 
	if (!file)
	{
		cout << "出错了" << endl;
	}
	//读取进程文件
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	//先扔五行数据
	cout << "正在检索所有进程" << endl;
	while(file.getline(data, sizeof(data)))
	{
		string b(data);
		if (!strcmp(b.c_str(), "暂缺"))
		{
			continue;
		}
		trim(b);
		Handle_name.push_back(b);
	}
	auto it = Handle_name.begin();
	for (; it != Handle_name.end(); it++)
	{
		if (!strcmp((*it).c_str(), "暂缺"))
		{
			//Handle_name.erase(it);
			continue;
		}
		Name.push_back(*it);
	}

	Handle_name.clear();
	file.close();
	remove("Liuaotian.txt");
}

void trim(string &a)
{
	a.erase(a.find_last_not_of(" ") + 1);
	a.erase(0, a.find_last_of(" ") + 1);
}

void GetWindowHandle()
{
	for (auto name : Name)
	{
		HWND m_Hwnd = FindWindow(NULL, name.c_str());
		if (!m_Hwnd)
			continue;
		HandList.push_back(m_Hwnd);
	}
}

void GetWindowName()
{
	cout << "额..我只找到了类似于窗口的冬冬,自行筛选" << endl;
	char WindowName[1000] = { 0 };
	int count = 1;
	for (auto name : HandList)
	{
		GetWindowText(name, WindowName, sizeof(WindowName));
		cout << count << WindowName << endl;
		count++;
	}
}

HWND GetHandle(int number)
{
	int count = 1;
	char WindowName[1000] = { 0 };
	for (auto name : HandList)
	{
		GetWindowText(name, WindowName, sizeof(WindowName));
		if (count == number)
		{
			return name;
		}
		count++;
	}
	cout << "查找出错" << endl;
	return NULL;
}