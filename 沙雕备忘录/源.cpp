#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;
//ɳ��汸��¼
//1.����һ���ļ����洢����¼��Ϣ
//2.������Ϣ���ļ�
//3.ɾ���ļ���ĳЩ��Ϣ
//4.�����Ϣ����Ļ

void menu()
{

	cout << "			��ӭʹ��ɳ����¼              " << endl;
	cout << "			                              " << endl;
	cout << "			    1.��Ҫд��ɶ              " << endl;
	cout << "			    2.����ɾ��ɶ              " << endl;
	cout << "			    0.Ŷ��֪����              " << endl;
}

class BWL
{
public:
	BWL(const string f = "my.txt")
		:_file(f)
	{}
	void write(string info)
	{
		ofstream ofs(_file, ios::app);
		ofs << info << endl;
		ofs.close();
	}
	void read()
	{
		ifstream ifs(_file);
		string info;
		int count = 0;
		while (!ifs.eof())
		{
			ifs >> info;
			cout <<count<<" "<< info << endl;
			++count;
			ifs.get(); // ��ȡ���Ļس���
			if (ifs.peek() == '/n') break;
		}
		if(count != 1)
		cout << count << " ";
		ifs.close();

	}

private:
	string _file;
	int _count;
};

void _delete()
{
	cout << "�����ڴ�" << endl;
}
void _write(BWL& bwl)
{
	system("cls");
	bwl.read();
	string write;
	cin >> write;
	bwl.write(write);
}
int main()
{
	int ret = 0;
	BWL bwl;
	do {
		menu();
		cin >> ret;

		switch (ret)
		{
		case 1:
			//_read(bwl);
			_write(bwl);
			break;
		case 2:
			_delete();
			break;
		case 0:
			break;
		default:
			cout << "���ɳ����������" << endl;
			cout << "���ɳ����������" << endl;
			cout << "���ɳ����������" << endl;
			Sleep(1000);
			system("cls");
			break;
		}

	} while (ret);
	return 0;
}