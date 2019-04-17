#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
//1.�����һ���࣬����ֻ���ڶ��ϴ�������
//class HeapOnly
//{
//public:
//	static HeapOnly*  CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//	HeapOnly(){}
//	//C++ 98
//	HeapOnly(const HeapOnly&);
//	//c++ 11
//	HeapOnly(const HeapOnly&) = delete;
//};
////2.�����һ���࣬����ֻ����ջ�ϴ�������
//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly(){}
//};
//class StackOnly1
//{
//public:
//	StackOnly1(){}
//private:
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};

//����ģʽ
//����ģʽ
//�ŵ㣺��
//ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ��
//�ڶ��̸߲߳���������ʹ�ã�����Ҫ��ϸߣ�
class Singleton1
{
public:
	static Singleton1* GetInstance()
	{
		return &m_instance;
	}
private:
	Singleton1(){}
	//c++98 ������
	Singleton1(Singleton1 const&);
	Singleton1& operator=(Singleton1 const&);
	////c++11
	//Singleton1(Singleton1 const&) = delete;
	//Singleton1& operator=(Singleton1 const&) = delete;

	static Singleton1 m_instance;
};
Singleton1 Singleton1::m_instance;
//l����ģʽ
//�������������ʮ�ֺ�ʱ����ռ�úܶ���Դ��������ز��������ʼ���������Ӱ�
//��ȡ�ļ����ȵȣ������п��ܶ����������ʱ�����õ�����ôҲҪ�ڳ���һ��ʼ�ͳ�ʼ��
//�ͻᵼ�³�������ʱ�ǳ��Ļ����������������ʹ������ģʽ���ӳټ��أ�����
//�ŵ㣺��һ��ʹ��ʵ������ʱ���������󣬽��������޸��أ��������ʵ������˳�����ɿ��ơ�
//ȱ�㣺����
class Singleton2
{
public:
	//static Singleton2* GetInstance()
	//{
	//	if (nullptr == m_pInstance)//
	//	{
	//			m_pInstance = new Singleton2();
	//	}
	//	return m_pInstance;
	//}
	static Singleton2* GetInstance()
	{
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance)//
		{
			m_mtx.lock();
			if (nullptr == m_pInstance)//2
			{
				m_pInstance = new Singleton2();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	//ʵ��һ����Ƕ����������
	class CGarbo{
	public:
		~CGarbo(){
			cout << "~CGarbo "<< endl;
			if (Singleton2::m_pInstance)
				delete Singleton2::m_pInstance;
		}
	};
private:
	Singleton2(){}
	//c++98 ������
	Singleton2(Singleton2 const&);
	Singleton2& operator=(Singleton2 const&);
	////c++11
	//Singleton2(Singleton2 const&) = delete;
	//Singleton2& operator=(Singleton2 const&) = delete;

	static Singleton2* m_pInstance;  //��������ָ��
	static mutex m_mtx;   //������

};
Singleton2* Singleton2::m_pInstance = nullptr;
// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
Singleton2::CGarbo garbo;
mutex Singleton2::m_mtx;