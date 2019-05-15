#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;
//沙雕版备忘录
//1.创建一个文件来存储备忘录信息
//2.输入信息到文件
//3.删除文件的某些信息
//4.输出信息到屏幕

void menu()
{

	cout << "			欢迎使用沙雕备忘录              " << endl;
	cout << "			                              " << endl;
	cout << "			    1.我要写点啥              " << endl;
	cout << "			    2.让我删点啥              " << endl;
	cout << "			    0.哦我知道了              " << endl;
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
			ifs.get(); // 读取最后的回车符
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
	cout << "敬请期待" << endl;
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
			cout << "你个沙雕，这个都输错" << endl;
			cout << "你个沙雕，这个都输错" << endl;
			cout << "你个沙雕，这个都输错" << endl;
			Sleep(1000);
			system("cls");
			break;
		}

	} while (ret);
	return 0;
}