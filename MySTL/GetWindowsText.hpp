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
	/*回调函数*/
	static BOOL CALLBACK callbackprocecss(
		HWND hwnd,
		LPARAM LParam)
	{
		char caption[100] = { 0 };
		GetWindowText(hwnd, caption, 100);

		if (strcmp(caption, "")) {
			/*如果不与""相等，也就是不为空的话*/
			((Getwindows *)LParam)->windowstext.push_back(caption);
			//std::cout << caption << std::endl;
		}

		return TRUE;
	}
};

int hidewindow(HWND hwnd)
{
	SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_HIDEWINDOW | SWP_NOSIZE | SWP_NOMOVE);
	return UpdateWindow(hwnd);
}

int showwindow(HWND hwnd)
{
	SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOMOVE);
	return UpdateWindow(hwnd);
}

int setwindowup(HWND hwnd)
{
	SetWindowPos(hwnd, HWND_TOPMOST, 1, 1, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOMOVE);
	return UpdateWindow(hwnd);
}

int unsetwindowup(HWND hwnd)
{
	SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOMOVE);
	return UpdateWindow(hwnd);
}
