#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#if 0
namespace N1
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}
namespace N2
{
	int a = 30;
	int b = 40;
	int Sub(int left, int right)
	{
		return left - right;
	}
	namespace N3
	{
		int a = 50;
		int b = 60;
		int Mul(int left, int right)
		{
			return left*right;
		}
	}
}
namespace N1
{
	int c = 1;
	int d = 2;
}
int main()
{
	printf("%d ", ::a);//针对全局变量
	printf("%d\n", N1::a);//针对作用域
	printf("%d\n", N2::N3::a);
	using namespace N1;
	printf("%d\n", Add(a, b));
	printf("%d\n", N1::c);//存在相同的命名空间N1，会合并成一份
	system("pause");
	return 0;
}
#endif
#if 0
//缺省参数
void test(int a = 1,int b=2,int c=3)//全缺省参数
{
	cout << a << " " << b << " " << c << endl;
}
int main()
{
	//test();//没有传实参，运用缺省参数
	test(10);//只传了一个参数，从左往右匹配，结果为10 2 3
	system("pause");
	return 0;
}
#endif
#if 0
void test(int a, int b = 2, int c = 3)//半缺省参数
{
	cout << a << " " << b << " " << c << endl;
}
int main()
{
	//test();//不接受0个参数，因为函数中只有b和c有缺省参数
	test(10);
	system("pause");
	return 0;
}
#endif
#if 0
void func(int a = 10);
void func(int a = 10)
{
	cout << a << endl;
}
int main()
{
	//test();//缺省参数不能在函数的声明和定义同时给出，只能在一个位置给出，一般在声明的位置给出比较好，在编写代码时，可能会用到第三方库，只有给了函数声明才能用
	system("pause");
	return 0;
}
#endif
#if 0
//函数重载
//void func()
//{}
//void func(int a){}//参数个数不同
//void test(double a, int b){}
//void test(int a, double b){}//参数类型次序不同
//void test(char a){}
//void test(int a){}//参数类型不同，根据参数类型不同来调用
void test(char a){}
char test(char a){
	return a;
}//错误，仅仅因为返回值类型不同，不能形成重载，因为在调用时，没有接收函数，不知道调用哪个
int main()
{
	system("pause");
	return 0;
}
#endif
void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a)
{
	cout << "void TestFunc(int)" << endl;
}
int main()
{
	return 0;
}
