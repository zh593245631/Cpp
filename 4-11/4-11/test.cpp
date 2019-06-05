////模板分离编译
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
//#include"a.h"
using namespace std;
//
//int main()
//{
//	Add(1, 2);
//	Add(1.0, 2.0);
//	return 0;
//}
//int main()
//{
//	//int d;
//	////无论什么类型，都要指定类型，c语言不支持重载
//	//scanf("%d", &d);
//	//char c;
//	//scanf("%c", &c);
//	////cin 类型： istream
//	////istream 重载>>运算
//	////对于不同的内置类型，cin 调用的是不同的>>运算符重载函数，不需要指定类型
//	//cin >> d;
//	//cin >> c;
//
//	cout << "cout";
//	//cerr << "cerr";
//	//clog << "clog";
//
//	return 0;
//}
struct Info
{
	char ip[20];
	int port;
};


class Config
{
public:
	Config(string filename)
		:_filename(filename)
	{}
	//字节流读写
	void ReadBin(Info& info)
	{
		ifstream fin(_filename.c_str());
		//设置文件指针的位置
		fin.seekg(0, ifstream::end);
		//文件指针相对于文件起始位置（0）的偏移量；间接获取文件的大小
		fin.tellg();
		size_t num = fin.tellg();
		cout << num << endl;
		fin.read((char*)&info, sizeof(info));
		fin.close();
		cout << info.ip << endl;
		cout << info.port << endl;

	}

	void WriteBin(Info& info)
	{
		ofstream fout(_filename.c_str());
		fout.write((char*)&info, sizeof(info));
		fout.close();
	}


	//字符流读写
	void WriteText(Info& info)
	{
		ofstream fout(_filename.c_str());
		fout << info.ip << endl;
		fout << info.port << endl;
	}
	void ReadText(Info& info)
	{
		ifstream fin(_filename.c_str());
		fin >> info.ip;
		fin >> info.port;
	}
private:
	string _filename;
};

int main()
{
	Info info;
	strcpy(info.ip, "www.baidu.com");
	info.port = 80;

	Config cfg("Config.txt");
	cfg.WriteBin(info);
	cfg.ReadBin(info);

	//cfg.WriteText(info); 
	//cfg.ReadText(info);
	return 0;
}