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
	ra = b;//��ֵ����������
	cout << &ra << " " << &b << endl;//����һ����ַ
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	double d = 12.34;
	const int&rd = d;//��������ʱ��������12�Ž�����ʱ�����ռ��У�rd��������ʱ������
	                 //rd��֪����ʱ���������ֺ͵�ַ����������ռ��ǲ����޸ģ����Լ�const
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
	Add(100, 200);//��ʱretValue����300����ΪretValueʵ�������õ��Ǻ������еĿռ䣬�����ռ�ı�����
	//Add�����ڷ��غ󣬲���ϵͳ����պ������еĿռ䣬��û�����٣��������������ݣ�����retValue������������30��֮���ٴε�������������ֻ�����������������ռ䣬����ΪretValue���õ�����ռ䣬��������retValue����300
	printf("%d", retValue);//��Ȼ��ӡ����300������ʵֻҪ����һ��retValue��ı䣬����ȫ,������������ã���ô�����ڷ��غ󣬻��տռ䣬�ڶ��ε����������ʱ������ռ��Ѿ�����һ�ε����ݴ������
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
	cout << typeid(pa2).name() << endl;//���������Ͷ���int*,˵���Ӳ���*��һ����
	cout << "*************************" << endl;
	cout << typeid(pa3).name() << endl;//����Ϊint,�������&���ͻ��Ϊint*����
	system("pause");
	return 0;
}
