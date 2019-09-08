#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
namespace bite
{
	class string
	{
	public:
		string();
		string(const char* str = "")
		{
			/*
			if (nullptr == str)
			{
				_str = new char[1];
				*_str = '\0';	
			}
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
			*/
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}

	private:
		char* _str;//动态空间
	};
}
int main()
{
	bite::string s1("hello");
	bite::string s2(nullptr);
	//bite::string s3(s1);
	//拷贝构造函数没有显式定义，编译器自动生成一个，
	//但是s3和s1共用一块空间，最后释放时先释放s3，
	//然后s1又释放了一次，一块空间被释放了两次，这就是浅拷贝
	//s2 = s1;//编译器生成了默认的赋值运算符重载，也会发生浅拷贝
	return 0;
}
#endif
#if 0
#include <string.h>
//深拷贝---传统方式
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
		//深拷贝，即给每个对象分配资源
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				//delete[]_str;//将原来的空间释放
				//_str = new char[strlen(s._str) + 1];
				//strcpy(_str, s._str);
				char* ptr = new char[strlen(s._str) + 1];
				strcpy(ptr, s._str);
				delete[]_str;
				_str = ptr;//这种方式比较好，因为上一种方法实现释放空间，后来再申请空间，可是万一后面申请空间失败，就会出错
			}
			return *this;
		}
	private:
		char* _str;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(nullptr);
	bit::string s3(s1);
	s3 = s1;
	return 0;
}
#endif
#if 0
//深拷贝---现代方式
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
		//深拷贝，即给每个对象分配资源
		string(const string& s)//拷贝构造函数
			: _str(nullptr)
			//例如：string s3(s1),因为pTemp创建了一个和s1相同的空间，相同的内容
			//pTemp与s3交换后，s3指向了pTemp指向的内容，而pTemp指向的原本s3指向的内容
			//也就是随机值，出了该作用域后，析构函数进行清理工作，pTemp的_str进行释放，
		{	//此时是对随机值进行释放（也就是释放野指针，会崩溃），因此在这里给s3的_str初始化为nullptr
			string pTemp(s._str);//构造一个临时对象
			swap(_str, pTemp._str);
		}
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string pTemp(s);//拷贝构造
		//		swap(_str, pTemp._str);
		//	}
		//	return *this;
		//}
		string& operator=(const string& s)
		
		{
			string pTemp(s);//拷贝构造
			swap(_str, pTemp._str);
			return *this;
		}
		//string& operator=(string s)
		//{
		//	swap(_str, s._str);
		//	return *this;
		//}
	private:
		char* _str;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(nullptr);
	bit::string s3(s1);
	s2 = s1;
	return 0;
}
#endif
#if 0
//使用计数的方式来解决浅拷贝,但是这样使用普通的成员变量，是每个对象有一份计数，并不是共有的，
//因此在销毁s2时，s2中的计数-1，但s1中的计数并没有改变
namespace bit
{
	class string
	{
	public:
		string(const char* str="")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str)+1];
			strcpy(_str, str);
			_count = 1;
		}
		string(string& s)
			:_str(s._str)
			, _count(++s._count)
		{}
		~string()
		{
			if (0==--_count)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		int _count;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	return 0;
}
#endif
#if 0
//如果使用static修饰的成员变量作为计数，但是一旦重新调用构造函数，_count又会发生问题,直接变为1,它是公有的，使得三个对象计数都为1，无法解决
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
				_count = 1;
			}	
		}
		string(string& s)
			:_str(s._str)
		{
			++_count;
		}
		~string()
		{
			if (0 == --_count)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		static int _count;
	};
}
int bit::string::_count = 0;
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	bit::string s3("world");
	return 0;
}
#endif
#if 0
//可以使用指针来解决
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
				_pCount=new int(1);
			}
		}
		string(string& s)
			:_str(s._str)
			, _pCount(s._pCount)
		{
			++(*_pCount);
			
		}
		~string()
		{
			Release();
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				Release();
				_str = s._str;
				_pCount = s._pCount;
				++(*_pCount);
			}
			return *this;
		}
		char& operator[](size_t index)
		{
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			return _str[index];
		}
	private:
		void Release()
		{
			if (_str && 0 == --(*_pCount))
			{
				delete[]_str;
				delete _pCount;
				_str = nullptr;
				_pCount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pCount;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	//共用一份空间
	bit::string s3("world");
	bit::string s4(s3);
	//共用一份空间
	s1 = s3;
	s2 = s4;
	s1[0] = 'w';//想要改变s1中的内容，但是不能改其他3个对象的内容，所以要分离s1的内容,
	//所以就有了写时拷贝
	return 0;
}
#endif
//写时拷贝:浅拷贝+引用计数+在修改对象时分离对象
#if 1
namespace bit
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			else
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
				_pCount = new int(1);
			}
		}
		string(string& s)
			:_str(s._str)
			, _pCount(s._pCount)
		{
			++(*_pCount);

		}
		~string()
		{
			Release();
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				Release();
				_str = s._str;
				_pCount = s._pCount;
				++(*_pCount);
			}
			return *this;
		}
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_pCount, s._pCount);
		}
		char& operator[](size_t index)
		{
			if (*_pCount > 1)//有对象共享一个空间
			{
				//分离
				string strTemp(_str);
				Swap(strTemp);
			}
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			return _str[index];
		}
	private:
		void Release()
		{
			if (_str && 0 == --(*_pCount))
			{
				delete[]_str;
				delete _pCount;
				_str = nullptr;
				_pCount = nullptr;
			}
		}
	private:
		char* _str;
		int* _pCount;
	};
}
int main()
{
	bit::string s1("hello");
	bit::string s2(s1);
	//共用一份空间
	bit::string s3("world");
	bit::string s4(s3);
	//共用一份空间
	/*s1 = s3;
	s2 = s4;*/
	s1[0] = 'w';
	return 0;
}
#endif

