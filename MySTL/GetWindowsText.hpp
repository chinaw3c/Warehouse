#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

class Getwindows {
public:
	Getwindows() {
		EnumWindows(callbackprocecss, (LPARAM)this);
	}
	void showwindowtext() {
		for (auto i : windowstext) {
			std::cout << i << std::endl;
		}
	}
	std::vector<std::string> getwindowtext() {
		return windowstext;
	}
	
private:
	std::vector<std::string> windowstext;
	/*�ص�����*/
	static BOOL CALLBACK callbackprocecss(
		HWND hwnd,
		LPARAM LParam)
	{
		char caption[100] = { 0 };
		GetWindowText(hwnd, caption, 100);

		if (strcmp(caption, "")) {
			/*�������""��ȣ�Ҳ���ǲ�Ϊ�յĻ�*/
			((Getwindows *)LParam)->windowstext.push_back(caption);
			//std::cout << caption << std::endl;
		}

		return TRUE;
	}
};