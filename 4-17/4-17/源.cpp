#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
//1.请设计一个类，该类只能在堆上创建对象
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
////2.请设计一个类，该类只能在栈上创建对象
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

//单例模式
//饿汉模式
//优点：简单
//缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定
//在多线程高并发环境下使用，性能要求较高，
class Singleton1
{
public:
	static Singleton1* GetInstance()
	{
		return &m_instance;
	}
private:
	Singleton1(){}
	//c++98 防拷贝
	Singleton1(Singleton1 const&);
	Singleton1& operator=(Singleton1 const&);
	////c++11
	//Singleton1(Singleton1 const&) = delete;
	//Singleton1& operator=(Singleton1 const&) = delete;

	static Singleton1 m_instance;
};
Singleton1 Singleton1::m_instance;
//l懒汉模式
//如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊，初始化网络连接啊
//读取文件啊等等，而且有可能对象程序运行时不会用到，那么也要在程序一开始就初始化
//就会导致程序启动时非常的缓慢，所以这种情况使用懒汉模式（延迟加载）更好
//优点：第一次使用实例对象时，创建对象，进程启动无负载，多个单例实例启动顺序自由控制。
//缺点：复杂
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
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
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
	//实现一个内嵌垃圾回收类
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
	//c++98 防拷贝
	Singleton2(Singleton2 const&);
	Singleton2& operator=(Singleton2 const&);
	////c++11
	//Singleton2(Singleton2 const&) = delete;
	//Singleton2& operator=(Singleton2 const&) = delete;

	static Singleton2* m_pInstance;  //单例对象指针
	static mutex m_mtx;   //互斥锁

};
Singleton2* Singleton2::m_pInstance = nullptr;
// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
Singleton2::CGarbo garbo;
mutex Singleton2::m_mtx;