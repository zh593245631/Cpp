#include<iostream>
#include<vector>
using namespace std;
//int main()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	//ʹ�õ��������б�����ӡ
//	vector<int>::iterator vit = v1.begin();
//	while (vit != v1.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	//ʹ�õ����������޸�
//	vit = v1.begin();
//	while (vit != v1.end())
//	{
//		*vit *= 2;
//		++vit;
//	}
//	//ʹ�÷�����������б�����ӡ
//	vector<int>::reverse_iterator rvit = v1.rbegin();
//	while (rvit != v1.rend())
//	{
//		cout << *rvit << " ";
//		rvit++;
//	}
//	cout << endl;
//
//
//	return 0;
//}
//void printfVector(const vector<int>& v)
//{
//	for (auto& e : v)
//	{
//		cout << e<<" ";
//	}
//	cout<<endl;
//}
//int main()
//{
//	vector<int> v1(5, 1);
//	vector<int> v2(5, 2);
//	printfVector(v1);
//	printfVector(v2);
//
//	swap(v1, v2);
//	printfVector(v1);
//	printfVector(v2);
//
//	v1.swap(v2);
//	printfVector(v1);
//	printfVector(v2);
//
//
//	return 0;
//}
class String
{
public:
	String()
	{
		cout << " string" << endl;
	}
	~String()
	{
		cout << "~string" << endl;
	}
};
int main()
{
	//vector<int> v1(50, 1);
	//cout << v1.capacity() << endl;
	////�ֶ��ͷ�vector�ռ�
	////{
	////	vector<int> v2;
	////	v2.swap(v1);
	////}
	//v1.resize(0);
	//v1.shrink_to_fit();
	//cout << v1.capacity() << endl;
	//String s;

	//{
	//	String s1;
	//} //{}��������������
	//getchar();
	//return 0;
}