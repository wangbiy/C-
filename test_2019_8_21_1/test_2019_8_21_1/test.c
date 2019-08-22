#include <stdio.h>
#if 0
//函数栈帧
int Add(int left, int right)
{
	int z = 0;
	z = left + right;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	int ret = 0;
	ret = Add(a, b);
	printf("ret=%d\n", ret);
	return 0;
}
#endif
#if 0
struct S
{
	int a;
	int b;
};
struct S s;
int main()
{
	short t = 0x1122;
	char i = (char)t;//0x22,将short转换为char类型，发生了高位截断
	int a = (int)t;//0x00001122，将低类型（容量小）的类型转换为高类型，将高位填充0
	int b = (int)3.1415;//3，将浮点型数值转换为整数类型，将小数点后的所有数截断
	unsigned int p = (unsigned int)&s;//将s结构体类型取地址值转换为无符号整形，32位正常，64位截断因为在32位情况下地址值为4个字节，在64位下为8个字节
	long l = (long)s;//错误，因为在C语言中不能将自定义类型转换为内置类型
	s = (struct S)l;//错误，在C语言中不能将内置类型转换为自定义类型
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char c = 0;
	short s = c;
	int i = s;
	long l = i;
	printf("%d\n", s);
	printf("%d\n", i);
	printf("%d\n", l);
	system("pause");
	return 0;
}
#endif
typedef int* pINT;
#define pINT2 int*
int main()
{
	pINT a, b;
	pINT2 c, d;
	a = c;//这两个类型都是int*
	b = d;//这两个b是int* 类型，d是int类型
	system("pause");
	return 0;
}