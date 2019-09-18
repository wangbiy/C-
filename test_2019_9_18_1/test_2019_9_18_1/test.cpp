#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
#include <assert.h>
template <class T,size_t N>
class Array
{
public:
	T& operator[](size_t index)
	{
		//N = 100;//不能这样操作
		assert(index < N);
		return _arr[index];
	}
private:
	T _arr[N];
	size_t size;
};
int main()
{
	int N1 = 10;
	int N2 = 20;
	//错误，N1+N2表达式结果在编译期间无法确认结果，只有等到代码运行期间才能确认，相当于在编译期间对Array实例化失败
	//Array<int, N1 + N2> a;
	Array<int, 10 + 20> a;//这样才可以
	a[0] = 10;
	return 0;
}
#endif
#if 0
template<class T>
T& Max(T& left, T& right)
{
	if (left > right)
		return left;
	return right;
}
template<>
char*& Max<char*>(char*& left, char*& right)
{
	if (strcmp(left, right) > 0)
		return left;
	return right;
}//进行函数模板特化后，但是一般不用进行函数模板特化
int main()
{
	int a = 10;
	int b = 20;
	cout << Max(a, b) << endl;
	cout << Max(b, a) << endl;
	//正确
	/*char* p1 = "hello";
	char* p2 = "world";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;*/
	//这样结果是正确的，但是如果将p1和p2定义的顺序调换
	char* p2 = "world";
	char* p1 = "hello";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	//本应该结果是world，但是两个都是hello，错误，那我们可以进行函数模板特化
	return 0;
}
#endif
#if 0
//一般不使用函数模板特化，直接给出该类型对应的函数，因为例如
template<class T>
const T&(const T& left, const T& right)
{
	if (left > right)
		return left;
	return right;
}
//进行特化成为
template <>
const char*& Max<const char*>(const char*& left, const char*& right)
{
	if (strcmp(left, right) > 0)
		return left;
	return right;
}
int main()
{
	char* p2 = "world";
	char* p1 = "hello";
	p1[0] = 'H';//不能修改，因为hello和world都是常量串，存在于代码段
	//将它修改成
	const char* p2 = "world";
	const char* p1 = "hello";
	//但是这样在编译期间就崩溃了，这时候特化T都换成const char*,但是在有些情况下又会报错，因此一般不使用函数模板特化
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif
//类模板特化
#if 0
//全特化：将模板参数列表中所有的类型全部特化
template < class T1, class T2>
class Data//类模板
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//如果将Data类模板按照int和double的方式来进行实例化
template <>
class Data<int, double>
{
public:
	Data()
	{
		cout << "Data<int,double>" << endl;
	}
private:
	int _d1;
	double _d2;
};
int main()
{
	Data<int, int> d1;
	Data<int, double>d2;
	return 0;
}
#endif
#if 0
//偏特化
//1.部分特化
template <class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//如果Data类模板在实例化期间，只要第二个参数按照int方式进行实例化，就会执行特化的版本
template <class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1,int>" << endl;
	}
private:
	T1 _d1;
	int _d2;
};
int main()
{
	Data<double, int> d1;//部分特化
	Data<char, int> d2;//部分特化
	Data<int, short> d3;//类模板
	return 0;
}
#endif
#if 0
template <class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//偏特化另外一种方式：对类型参数限制更加严格
template<class T1,class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};
int main()
{
	Data<int*, char*> d1;//类模板特化
	Data<char*, short*> d2;//类模板特化
	Data<int, char*> d3;//类模板
	return 0;
}
#endif
//写一个通用的拷贝函数
#if 0
template <class T>
void copy(T* dst, const T* src, size_t size)
{
	//优点：不会出错
	//缺点：效率低
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
	//优点：效率高
	//缺点：在处理有资源管理的自定义类型时，可能有浅拷贝问题
	//memcpy(dst, src, size*sizeof(T));
}
#endif
#if 0
//可以使用类型萃取将这两种方法结合
struct TrueType//表示内置类型
{
	static bool Get()
	{
		return true;
	}
};
struct FalseType//表示自定义类型
{
	static bool Get()
	{
		return false;
	}
};
template<class T>
struct TypeTraits//类模板
{
	typedef FalseType PODType;
};
//类模板特化
//将所有的内置类型都给出
template<>
struct TypeTraits<char>
{
	typedef TrueType PODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType PODType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType PODType;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType PODType;
};
//.......
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::PODType::Get())
	{
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}
void Test1()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int _arr[10];
	Copy(_arr, arr, sizeof(arr) / sizeof(arr[0]));
}
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[]_str;
			_str = pstr;
		}
		return *this;
	}
private:
	char* _str;
};
void Test2()
{
	String s1[3] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);//使用的是自定义类型，因此是循环操作
}
int main()
{
	//Test1();
	Test2();
	return 0;
}
#endif 
#include "test.h"
//出现错误
template<class T> 
T Add(const T& left, const T& right)
{
	return left + right; 
}