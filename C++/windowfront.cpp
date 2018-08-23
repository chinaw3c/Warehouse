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
	cout << "�������˭?";
	cin >> count;
	cout << "(ǰ��:1,����:2)";
	cin >> number;
	system("cls");
	cout << "OK,���������" << count << "��" << number << endl;
	m_Hwnd = GetHandle(count);
	GetWindowText(m_Hwnd, WindowName, sizeof(WindowName));
	cout << "��ѡ����" << WindowName << endl;
	if (number == 1)
	{
		int value = SetWindowPos(m_Hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		if (value)
		{
			cout << "����ǰ�ó���" << endl;
		}
		else
		{
			cout << WindowName << "�Ѿ�ǰ��" << endl;
		}	
	}
	else if (number == 2)
	{
		//SetWindowPos(m_Hwnd, HWND_TOP, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		SetWindowPos(m_Hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		//SetWindowPos(m_Hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW | SWP_FRAMECHANGED);
		cout << WindowName << "�Ѿ�����" << endl;
	}
	else
	{
		cout << "�����ʲô���⣬�ҿ�����" << endl;
	}
	system("pause");
}

void Get_Window_Name()
{
	vector<string> Handle_name;
	string app_name;
	char data[1000] = {0};
	cout << "��ʼ�������" << endl;
	system("tasklist /V >> Liuaotian.txt");
	fstream file("Liuaotian.txt", ios::in); 
	if (!file)
	{
		cout << "������" << endl;
	}
	//��ȡ�����ļ�
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	file.getline(data, sizeof(data));
	//������������
	cout << "���ڼ������н���" << endl;
	while(file.getline(data, sizeof(data)))
	{
		string b(data);
		if (!strcmp(b.c_str(), "��ȱ"))
		{
			continue;
		}
		trim(b);
		Handle_name.push_back(b);
	}
	auto it = Handle_name.begin();
	for (; it != Handle_name.end(); it++)
	{
		if (!strcmp((*it).c_str(), "��ȱ"))
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
	cout << "��..��ֻ�ҵ��������ڴ��ڵĶ���,����ɸѡ" << endl;
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
	cout << "���ҳ���" << endl;
	return NULL;
}