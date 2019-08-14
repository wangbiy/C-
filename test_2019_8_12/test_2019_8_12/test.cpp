#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#if 0
int main()
{
	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 }, *q[4], k;
	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n", a);
	return 0;
}
#endif
#if 0
int main()
{
	char a;
	int b;
	float c;
	double d;
	cout << typeid(a*b + d - c).name() << endl;//隐式类型转换
	system("pause");
	return 0;
}
#endif
#if 0
#define INT_PTR int*
typedef int* int_ptr;
int f;
int main()
{
	int i = 0;
	INT_PTR a, b;
	int_ptr c, d;
	//b = &i;//b只是int类型，typedef与宏的区别
	return 0;
}
#endif
#if 0
#define row 4
#define col 4
int Search(int arr[row][col], int key)//杨氏矩阵从右上角找
{
	int i = 0;
	int j = col - 1;
	int temp = arr[row][col];
	while (1)
	{
		if (key == arr[row][col])
			return 1;
		if (key > arr[row][col] && i < row - 1)
			temp = arr[++i][j];
		if (key<arr[row][col] && j>0)
			temp = arr[i][--j];
		else
			return 0;
	}
}
int main()
{
	int arr[4][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	int key = 0;
	printf("请输入要查找的数字:\n");
	scanf("%d", &key);
	if (Search(arr, key) == 1)
		printf("找到啦!\n");
	else
		printf("没找到!\n");
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;
	a += a *= a -= a / 3;
	printf("%d\n", a);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i = 0;
	while (i < 10)
	{
		if (i < 1)
			continue;
		if (i == 5)
			break;
		i++;

	}
	system("pause");
	return 0;
}
#endif
#if 0
//空格替换成%20
void show(char* string, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << string[i];
	}
	cout << endl;
}
void ReplaceBlack(char* string)
{
	if (NULL == string)
		return;
	int len = 0;
	int lenNull = 0;
	int i = 0;
	for (i = 0; string[i] != '\0';++i)
	{
		len++;
		if (string[i] == ' ')
		{
			lenNull++;
		}
	}
	show(string, len);
	int len2 = len + lenNull * 2;//空格后面的向后移两位
	int newpointer = len2;//指向新的末尾
	int oldpointer = len;//指向旧的末尾
	while (oldpointer > 0 && newpointer > oldpointer)
	{
		if (string[oldpointer] == ' ')
		{
			string[newpointer--] = '0';
			string[newpointer--] = '2';
			string[newpointer--] = '%';
		}
		else
		{
			string[newpointer--] = string[oldpointer];
		}
		oldpointer--;
	}
	show(string, len2);
}
int main()
{
	char string[] = { "abc defgx yz" };
	ReplaceBlack(string);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int a = 5;
	if (a = 0)
	{
		printf("%d", a - 10);
	}
	else
	{
		printf("%d", a++);
	}
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char a[] = "hello\0world";
	char b[15] = { 0 };
	strcpy(b, a);
	cout << strlen(b) << endl;
	cout << sizeof(a) << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char a[20];
	char* p1 = (char*)a;
	char* p2 = (char*)(a + 5);
	int n = p2 - p1;
	cout << n;
	system("pause");
	return 0;
}
#endif
#if 0
#define F(X,Y) ((X)+(Y))
int main()
{
	int a = 3;
	int b = 4;
	cout << F(a++, b++) << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i = 1, sum = 0;
	while (i < 10)
	{
		sum = sum + 1;
		i++;
	}
	cout << i << sum << endl;
	system("pause");
	return 0;
}
#endif
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d,",k);
	k = fun(j, m);
	printf("%d\n", k);
	system("pause");
	return 0;
}

