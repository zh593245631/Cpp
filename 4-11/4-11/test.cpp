////ģ��������
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
//	////����ʲô���ͣ���Ҫָ�����ͣ�c���Բ�֧������
//	//scanf("%d", &d);
//	//char c;
//	//scanf("%c", &c);
//	////cin ���ͣ� istream
//	////istream ����>>����
//	////���ڲ�ͬ���������ͣ�cin ���õ��ǲ�ͬ��>>��������غ���������Ҫָ������
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
	//�ֽ�����д
	void ReadBin(Info& info)
	{
		ifstream fin(_filename.c_str());
		//�����ļ�ָ���λ��
		fin.seekg(0, ifstream::end);
		//�ļ�ָ��������ļ���ʼλ�ã�0����ƫ��������ӻ�ȡ�ļ��Ĵ�С
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


	//�ַ�����д
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