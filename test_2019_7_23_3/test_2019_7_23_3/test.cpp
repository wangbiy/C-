#include <stdlib.h>
#include <iostream>
using namespace std;
//int main()
//{
//	int a = 10;
//	int&ra = a;
//	int&rra = ra;
//	cout << &ra << "=" << &a <<"="<<&rra<< endl;
//	ra = 20;
//	cout << ra << a << rra << endl;
//	system("pause");
//	return 0;
//}
#if 0
int main()
{
	int a = 10;
	int&ra = a;
	int b = 20;
	ra = b;//赋值，不是引用
	cout << &ra << " " << &b << endl;//不是一个地址
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	double d = 12.34;
	const int&rd = d;//创建了临时变量，将12放进了临时变量空间中，rd引用了临时变量，
	                 //rd不知道临时变量的名字和地址，所以这个空间是不能修改，所以加const
	cout << &rd << " " << &d << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int& Add(int left, int right)
{
	int ret = left + right;
	return ret;
}
int main()
{
	int a = 10;
	int b = 20;
	int retValue = Add(a, b);
	printf("%d", retValue);
	Add(100, 200);//这时retValue会变成300，因为retValue实际上引用的是函数运行的空间，是这块空间的别名，
	//Add函数在返回后，操作系统会回收函数运行的空间，但没有销毁，会留下垃圾数据，所以retValue会接收这个数据30，之后再次调用这个函数，又会给这个函数分配这个空间，又因为retValue引用的这个空间，所以最终retValue会变成300
	printf("%d", retValue);//虽然打印的是300，但其实只要运行一次retValue会改变，不安全,但如果不是引用，那么函数在返回后，回收空间，第二次调用这个函数时，这个空间已经将上一次的数据处理掉了
	system("pause");
	return 0;
}
#endif
#if 0
void Swap(int& ra, int& rb)
{
	int t = rb;
	rb = ra;
	ra = t;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	cout << a << " " << b << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	const int a = 10;
	int arr[10];
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	const int a = 10;
	int* pa = (int*)&a;
	*pa = 100;
	cout << a << endl;
	cout << *pa <<endl;
	system("pause");
	return 0;
}
#endif
#if 0
#define Max(a,b) (((a)>(b))? (a):(b))
int main()
{
	int a = 10;
	int b = 20;
	cout << Max(a, b)<< endl;//20
	cout << Max(++b, a)<< endl;//22
	system("pause");
	return 0;
}
#endif
#if 0
inline int Max(int left, int right)
{
	return left > right ? left:right;
}
int main()
{
	int a = 10;
	int b = 20;
	cout << Max(a, b) << endl;//20
	cout << Max(++b, a) << endl;//21
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	int e = 0;
	for (auto&e : array)
		e *= 2;
	for (auto e:array)
	cout << e << " ";
	system("pause");
	return 0;
}
#endif
int main()
{
	int a = 10;
	auto pa1 = &a;
	auto* pa2 = &a;
	auto& pa3 = a;
	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;//两个的类型都是int*,说明加不加*是一样的
	cout << "*************************" << endl;
	cout << typeid(pa3).name() << endl;//类型为int,如果不加&，就会成为int*类型
	system("pause");
	return 0;
}
