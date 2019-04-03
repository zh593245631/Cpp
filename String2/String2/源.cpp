#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
namespace zzh
{
	class String
	{
	public:
		typedef char* Iterator;
		
		String(const char* str)
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			:_size(s._size)
			, _capacity(s._capacity)
			, _str(new char[s._capacity+1])
		{
			strcpy(_str, s._str);
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char* pStr = new char[strlen(s._str) + 1];
				strcpy(pStr, s._str);
				delete[] _str;
				_str = pStr;
			}
			return *this;
		}

		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		//Iterator
		Iterator Begin()
		{
			return _str;
		}
		Iterator end()
		{
			return _str + _size;
		}
		void push_back(char c)
		{
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void Reserve(size_t t)
		{
			if (t > _capacity)
			{
				char* str = new char[t + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_capacity = t;

			}
		}
		void Append(size_t n, char c)
		{
			for (size_t i = 0; i < n; i++)
			{
				push_back(c);
			}
		}
		String& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		void Append(const char* str)
		{
			for (size_t i = 0; i < strlen(str); i++)
			{
				push_back(str[i]);
			}
		}
		String& operator+=(const char* str)
		{
			for (size_t i = 0; i < strlen(str); i++)
			{
				push_back(str[i]);
			}
			return *this;
		}
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char*C_Str()const
		{
			return _str;
		}
		size_t Size()const
		{
			return _size;
		}
		size_t Capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return 0 == _size;
		}
		void Resize(size_t newSize, char c = char())
		{
			if (newSize > _capacity)
			{
				Reserve(newSize);
				memset(_str + _size, c, newSize - _size);
			}

			_size = newSize;
			_str[newSize] = '\0';
		}
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		bool operator<(const String& s)
		{
			return strcmp(_str, s._str)<0;
		}
		bool operator<=(const String& s)
		{
			return strcmp(_str, s._str)<=0;
		}
		bool operator>(const String& s)
		{
			return strcmp(_str, s._str) > 0;
		}
		bool operator>=(const String& s)
		{
			return strcmp(_str, s._str) >= 0;
		}
		bool operator==(const String& s)
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator!=(const String& s)
		{
			return !strcmp(_str, s._str);
		}
		//返回c在string中第一次出现的位置
		int Find(char c, int pos = -1)const
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == c)
				{
					pos = i;
					break;
				}
			}

			return pos;
		}
		// 返回子串s在string中第一次出现的位置
		int Find(const char*c, int pos = -1) const
		{
			for (size_t i = 0; i < _size; i++)
			{
				size_t tmp = i;
				size_t j = 0;

				if (_str[i] == c[j])
				{
					for (j = 0; j < strlen(c);j++)
					{
						if (_str[i] != c[j]||i==_size)break;
						i++;
					}
					i = tmp;
					if (j == strlen(c))
					{
						pos = i;
						break;
					}
				}
			}
			return pos;
		}
		// 截取string从pos位置开始的n个字符
		String SubStr(size_t pos, size_t n);

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		void Insert(size_t pos, char c)
		{
			if (_capacity == _size)
			{
				Reserve(_capacity * 2);
			}

			for (size_t i = _size; i > pos; i--)
			{
				_str[i] = _str[i - 1];
			}
			_str[pos] = c;
			_size++;
			_str[_size] = '\0';
		}
		void Insert(size_t pos, const char* str)		{			for (size_t i = 0; i < strlen(str); i++)
			{
				Insert(pos + i, str[i]);
			}
		}


	private:
		friend ostream& operator<<(ostream& _cout, const zzh::String& s);
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
using namespace zzh;
ostream& zzh::operator<<(ostream& _cout, const zzh::String& s)
{
	cout << s._str;
	return _cout;
}

void test1()
{
	String s1("hello");
	s1.push_back(' ');
	s1 += 'w';
	s1 += "orld";
	cout << s1 << endl;
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;

	auto vit = s1.Begin();
	while (vit != s1.end())
	{
		cout << *vit;
		vit++;
	}
	cout << endl;
	String s2("zzh");
	s2.Swap(s1);

	cout << s1 << endl;
	cout << s2 << endl;

}
void test2()
{
	String s("hello");
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;

	s.Resize(10, 'a');
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;

	s.Resize(20);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;

	s.Resize(5);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;

	s.Reserve(50);
	cout << s << endl;
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;


}
void test3()
{
	String s1("aabb");
	String s2("ccbb");

	cout << (s1 < s2) << endl;

	cout << s1.Size() << endl;
	cout << s1.Find('f') << endl;
	cout << s1.Find("abc") << endl;
	s1.Insert(1,'c');
	s1.Insert(1, "qwer");


	cout << s1 << endl;

}
int main()
{
	String s1("hello world");
	String s2(s1);
	String s3 = s2;

	//test1();
	//test2();
	test3();
	return 0;
}