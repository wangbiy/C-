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
	printf("%d ", ::a);//���ȫ�ֱ���
	printf("%d\n", N1::a);//���������
	printf("%d\n", N2::N3::a);
	using namespace N1;
	printf("%d\n", Add(a, b));
	printf("%d\n", N1::c);//������ͬ�������ռ�N1����ϲ���һ��
	system("pause");
	return 0;
}
#endif
#if 0
//ȱʡ����
void test(int a = 1,int b=2,int c=3)//ȫȱʡ����
{
	cout << a << " " << b << " " << c << endl;
}
int main()
{
	//test();//û�д�ʵ�Σ�����ȱʡ����
	test(10);//ֻ����һ����������������ƥ�䣬���Ϊ10 2 3
	system("pause");
	return 0;
}
#endif
#if 0
void test(int a, int b = 2, int c = 3)//��ȱʡ����
{
	cout << a << " " << b << " " << c << endl;
}
int main()
{
	//test();//������0����������Ϊ������ֻ��b��c��ȱʡ����
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
	//test();//ȱʡ���������ں����������Ͷ���ͬʱ������ֻ����һ��λ�ø�����һ����������λ�ø����ȽϺã��ڱ�д����ʱ�����ܻ��õ��������⣬ֻ�и��˺�������������
	system("pause");
	return 0;
}
#endif
#if 0
//��������
//void func()
//{}
//void func(int a){}//����������ͬ
//void test(double a, int b){}
//void test(int a, double b){}//�������ʹ���ͬ
//void test(char a){}
//void test(int a){}//�������Ͳ�ͬ�����ݲ������Ͳ�ͬ������
void test(char a){}
char test(char a){
	return a;
}//���󣬽�����Ϊ����ֵ���Ͳ�ͬ�������γ����أ���Ϊ�ڵ���ʱ��û�н��պ�������֪�������ĸ�
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
