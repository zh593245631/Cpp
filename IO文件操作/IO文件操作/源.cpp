#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template<class T>
class ConfigManager
{
public:
	ConfigManager(const string& configfile):_configfile(configfile){}

	//二进制写
	void WriteBin(const T& msg)
	{
		ofstream ofs(_configfile, ofstream::in | ofstream::binary);
		ofs.write((const char*)&msg, sizeof(T));
		ofs.close();
	}
	//二进制读
	void ReadBin(T& msg)
	{
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
		ifs.read((char*)&msg, sizeof(T));
		ifs.close();
	}
	void WriteText(const T& msg)
	{
		ofstream ofs(_configfile);
		ofs << msg << endl;
		ofs.close();
	}
	void ReadText(T& msg)
	{
		ifstream ifs(_configfile);
		ifs >> msg;
		ifs.close();
	}
private:
	string _configfile;
};

struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};
int main()
{
	ConfigManager<ServerInfo> file("hehe.txt");
	
	ServerInfo s;
	strcpy(s._ip, "0.0.0.0");
	s._port = 1010;
	file.WriteBin(s);
	ServerInfo p;
	file.ReadBin(p);
	cout << p._ip << endl;
	cout << p._port << endl;

	//ConfigManager<string> file2("hehe.txt");
	//string s1("456");
	//file2.WriteBin(s1);
	//string p2("123456");
	//file2.ReadBin(p2);
	//cout << p2 << endl;
	ConfigManager<string> file2("hehe.txt");
	string s1("456");
	file2.WriteText(s1);
	string s11;
	file2.ReadText(s11);
	cout << s11 << endl;
	return 0;
}