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

//�޸�ͼ��
BOOL SetExeIcon(LPWSTR szCurrentExePath, LPWSTR szObjectExePath)
{
	return TRUE;
}
//�޸��ƶ���ִ���ļ�ͼ��
void WormExe(TCHAR* szObjectExePath)
{
	TCHAR szCurrentExePath[MAX_PATH];
	GetModuleFileName(NULL, szCurrentExePath, MAX_PATH);

	//�滻ͼ��
	//SetExeIcon(szCurrentExePath, szObjectExePath);
	//MessageBox(NULL, szCurrentExePath, NULL, MB_OK);
}
//�̴߳�����
DWORD WINAPI PandaProc(LPVOID lpParam)
{
	//�����ļ�
	//��ȡ�̷�
	//GetLogicalDriveStrings()
	//ͨ��� *.exe

	TCHAR szFindPath[] = TEXT("D:\\hehetest");
	//�����ļ�
	WIN32_FIND_DATA fd;
	HANDLE hFinder = FindFirstFile(TEXT("D:\\hehetest\\*.exe"), &fd);

	if (hFinder == INVALID_HANDLE_VALUE)
		return 0;
	while (TRUE)
	{
		//�ļ�
		if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			//ƴ���ļ�·��
			TCHAR szExePath[MAX_PATH];
			wsprintf(szExePath, TEXT("%s\\%s"), szFindPath, fd.cFileName);
			//MessageBox(NULL, szExePath, NULL, MB_OK);
			//MessageBox(NULL, fd.cFileName, NULL, MB_OK);

			//�޸�ͼ��
			WormExe(szExePath);
		}
		if (!FindNextFile(hFinder, &fd))
			break;
	}
	return 0;
}
//���ڴ�����
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE://���ڴ�����Ϣ
		//����һ���߳� //���߳� ���Ч��
		CreateThread(NULL, 0, PandaProc, NULL, 0, NULL);
		break;
	case WM_CLOSE://���ڹر���Ϣ������ʾ
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY://����������Ϣ�������Ѿ�������
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
	//��һ������
	//1.��ƴ�����
	WNDCLASS wc;
	wc.cbClsExtra = 0;											//���������չ�ռ�
	wc.cbWndExtra = 0;											//���ڵĶ����ڴ�ռ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//���ذ�ɫ��ˢ
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);					//���ع����
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));	//����ͼƬ
	wc.hInstance = hInstance;									//Ӧ�ó���ʵ�����
	wc.lpfnWndProc = WindowProc;								//���ڴ�����
	wc.lpszClassName = szAppClassName;							//����������
	wc.lpszMenuName = NULL;										//�˵���
	wc.style = CS_HREDRAW | CS_VREDRAW;							//��������

	//2.ע�ᴰ����
	RegisterClass(&wc);
	//3.��������
	HWND hwnd = CreateWindow(
		szAppClassName,				//����������
		TEXT("��è���㲡��"),		//���ڵı���
		WS_OVERLAPPEDWINDOW,		//���ڵķ��
		200, 100,					//���ڵ����ϽǺ�����
		400, 300,					//���ڵĿ�͸�
		NULL,						//�����ھ��
		NULL,						//�˵����
		hInstance,					//Ӧ�ó���ʵ�����
		NULL						//���Ӳ���
	);

	//4.��ʾ����
	ShowWindow(hwnd, SW_SHOW);//SW_HIDE
	//5.���´���
	UpdateWindow(hwnd);
	//while(1)
	//MessageBox(NULL, L"Hello,world", L"��ʾ", MB_OK);
	//6.��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//���������Ϣת��Ϊ�ַ���Ϣ
		TranslateMessage(&msg);
		//����Ϣ�ַ������ڴ�����
		DispatchMessage(&msg);
	}
	return 0;
}
