#include<Windows.h>
#include"resource.h"
#include <tchar.h>
#include<atlconv.h>
#include <cstring>
struct ICONDIRENTRY
{
	BYTE bWidth;
	BYTE bHeight;
	BYTE bColorCount;
	BYTE bReserved;
	WORD wPlanes;
	WORD wBitCount;
	DWORD dwBytesInRes;
	DWORD dwImageOffset;
};

struct ICONDIR
{
	WORD idReserved;
	WORD idType;
	WORD idCount;
	//ICONDIRENTRY idEntries;
};

struct GRPICONDIRENTRY
{
	BYTE bWidth;
	BYTE bHeight;
	BYTE bColorCount;
	BYTE bReserved;
	WORD wPlanes;
	WORD wBitCount;
	DWORD dwBytesInRes;
	WORD nID;
};
struct GRPICONDIR
{
	WORD idReserved;
	WORD idType;
	WORD idCount;
	GRPICONDIRENTRY idEntries;
};

//修改图标
BOOL SetExeIcon(LPWSTR szCurrentExePath, LPWSTR szObjectExePath)
{
	return TRUE;
}
//修改制定可执行文件图标
void WormExe(TCHAR* szObjectExePath)
{
	TCHAR szCurrentExePath[MAX_PATH];
	GetModuleFileName(NULL, szCurrentExePath, MAX_PATH);

	//替换图标
	//SetExeIcon(szCurrentExePath, szObjectExePath);
	//MessageBox(NULL, szCurrentExePath, NULL, MB_OK);
}
//线程处理函数
DWORD WINAPI PandaProc(LPVOID lpParam)
{
	//查找文件
	//获取盘符
	//GetLogicalDriveStrings()
	//通配符 *.exe

	TCHAR szFindPath[] = TEXT("D:\\hehetest");
	//查找文件
	WIN32_FIND_DATA fd;
	HANDLE hFinder = FindFirstFile(TEXT("D:\\hehetest\\*.exe"), &fd);

	if (hFinder == INVALID_HANDLE_VALUE)
		return 0;
	while (TRUE)
	{
		//文件
		if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			//拼出文件路径
			TCHAR szExePath[MAX_PATH];
			wsprintf(szExePath, TEXT("%s\\%s"), szFindPath, fd.cFileName);
			//MessageBox(NULL, szExePath, NULL, MB_OK);
			//MessageBox(NULL, fd.cFileName, NULL, MB_OK);

			//修改图标
			WormExe(szExePath);
		}
		if (!FindNextFile(hFinder, &fd))
			break;
	}
	return 0;
}
//窗口处理函数
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE://窗口创建消息
		//创建一个线程 //多线程 提高效率
		CreateThread(NULL, 0, PandaProc, NULL, 0, NULL);
		break;
	case WM_CLOSE://窗口关闭消息，不显示
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY://窗口销毁消息，窗口已经被销毁
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance,LPSTR lpCmdLine,int nCmdShow)
{
	//TCHAR tstr[] = _T("pandas.exe");
	//TCHAR tstr2[] = _T("2.exe");

	//OnBTNUpdateResource();
	//ChangeExeIcon(tstr, tstr2);
	TCHAR szAppClassName[] = TEXT("DunKai-Liqi");
	//做一个窗口
	//1.设计窗口类
	WNDCLASS wc;
	wc.cbClsExtra = 0;											//窗口类的扩展空间
	wc.cbWndExtra = 0;											//窗口的额外内存空间
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//加载白色画刷
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					//加载光标句柄
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));	//加载图片
	wc.hInstance = hInstance;									//应用程序实例句柄
	wc.lpfnWndProc = WindowProc;								//窗口处理函数
	wc.lpszClassName = szAppClassName;							//窗口类型名
	wc.lpszMenuName = NULL;										//菜单名
	wc.style = CS_HREDRAW | CS_VREDRAW;							//窗口类风格

	//2.注册窗口类
	RegisterClass(&wc);
	//3.创建窗口
	HWND hwnd = CreateWindow(
		szAppClassName,				//窗口类型名
		TEXT("熊猫烧香病毒"),		//窗口的标题
		WS_OVERLAPPEDWINDOW,		//窗口的风格
		200, 100,					//窗口的左上角横坐标
		400, 300,					//窗口的宽和高
		NULL,						//父窗口句柄
		NULL,						//菜单句柄
		hInstance,					//应用程序实例句柄
		NULL						//附加参数
	);

	//4.显示窗口
	ShowWindow(hwnd, SW_SHOW);//SW_HIDE
	//5.更新窗口
	UpdateWindow(hwnd);
	//while(1)
	//MessageBox(NULL, L"Hello,world", L"提示", MB_OK);
	//6.消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//将虚拟键消息转化为字符消息
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}
	return 0;
}
