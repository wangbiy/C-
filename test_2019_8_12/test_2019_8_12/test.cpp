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
#if 0
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
#endif
#if 0
int x = 3;
void fun()
{
	static int x = 1;
	x *= (x + 1);
	printf("%d\n", x);
	return;
}
int main()
{
	int i;
	for (i = 0; i < x; i++)
	{
		fun();
	}
	
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int i = 0;
	int j = 0;
	if ((++i > 0) || (++j > 0))
		printf("%d %d\n", i, j);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int x = 0;
	switch (++x)
	{
	case 0:++x;
	case 1:++x;
	case 2:++x;
	}
	printf("%d", x);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char s[] = "\\123456\123456\t";
	cout << strlen(s) << endl;
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int s = 0, n;
	for (n = 0; n < 4; ++n)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
	}
	printf("%d\n", s);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char* a = "blue1";
	char a1[] = "blue1";
	cout << strlen(a) << endl;
	cout << strlen(a1) << endl;
	cout << sizeof(a) << endl;
	cout << sizeof(a1) << endl;
	system("pause");
	return 0;
}
#endif
#if 0
void func(char sr[2])
{
	int m = sizeof(sr);
	int n = strlen(sr);
	printf("%d\n", m);
	printf("%d\n", n);
}
int main()
{
	char str[] = "Hello";
	func(str);
	
	system("pause");
	return 0;
}
#endif
#if 0
int find_half(int* arr, int size)
{
	int count = 0;
	int temp;
	for (int i = 0; i < size; ++i)
	{
		if (count == 0)
		{
			temp = arr[i];
			count++;
		}
		if (arr[i] == temp)
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	return temp;
}
int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int temp = find_half(arr, sizeof(arr) / sizeof(int));
	printf("%d ", temp);
	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 0
union X{
	int x;
	char y[4];
}a;
int main()
{
	a.x = 0x11223344;
	printf("%x\n", a.y[0]);
	printf("%x\n", a.y[1]);
	printf("%x\n", a.y[2]);
	printf("%x\n", a.y[3]);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int a, x;
	for (a = 0, x = 0; a <= 1 && !x++; a++)
	{
		a++;
	}
	printf("%d %d", a, x);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* p1 = (int*)(&a + 1);
	int* p2 = (int*)((int)a + 1);
	int* p3 = (int*)(a + 1);
	printf("%d %x %d\n", p1[-1], p2[0], p3[1]);
	system("pause");
	return 0;
}
#endif
#if 0
//求子数组和
int Find(int* arr, int size, int& temp)
{
	if (arr == NULL || size == 0)
		return NULL;
	int sum = temp = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
		if (sum < 0)
			sum = 0;
		if (sum>temp)
			temp = sum;
	}
	if (temp == 0)
	{
		temp = arr[0];
		for (int i = 0; i < size; ++i)
		{
			if (arr[i]>temp)
				temp = arr[i];
		}
	}
	printf("%d\n", temp);
}
int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int num;
	Find(arr, sizeof(arr) / sizeof(int), num);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char* str[3] = { "stra", "strb", "strc" };
	char* p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s ", p++);
		i++;
	}
	system("pause");
	return 0;
}
#endif
#if 0
char* mystring()
{
	char buffer[6] = { 0 };
	char* s = "Hello World";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main()
{
	printf("%s\n", mystring());
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d", strlen(a));

	system("pause");
	return 0;
}
#endif
#if 0
//在字符串中找出第一个只出现一次的字符
#include <assert.h>
char Find(char* s)
{
	assert(s);
	const  int arrsize = 256;
	char arr[256];
	for (int i = 0; i < arrsize; i++)
	{
		arr[i] = 0;
	}
	char* key = s;
	while (*key != '\0')
	{
		arr[*(key++)]++;
	}
	key = s;
	while (*key != '\0')
	{
		if (arr[*key] == 1)
		{
			return *key;
		}
		key++;
	}
	return '\0';
}
int main()
{
	char* str = "abaccdeff";
	char ret = Find(str);
	printf("%c\n", ret);
	system("pause");
	return 0;
}
#endif
#if 0
int fun(char* s)
{
	char* p = s;
	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}
int main()
{
	printf("%d\n", fun("goodbye!"));
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);
	system("pause");
	return 0;
}
#endif 
#if 0
int main()
{
	const int i = 0;
	int* j = (int*)&i;
	*j = 1;
	printf("%d %d", i, *j);
	system("pause");
	return 0;
}
#endif
#if 0
//找到第一个重复出现的字符
char Find(char* str)
{
	char arr[256] = { 0 };
	char* key = str;
	while (*key != '\0')
	{
		arr[*(key++)]++;
	}
	key=str;
	while (*key != '\0')
	{
		if (arr[*key] >= 2)
			return *key;
		key++;
	}
	return '\0';
}
int main()
{
	char* str = "qywyer23tdd";
	char ret = Find(str);
	printf("%c\n", ret);
	system("pause");
	return 0;
}
#endif
#if 0
int f(int x, int y)
{
	int a = x&y;
	int b = x^y;
	return (a) + (b >> 1);
}
int main()
{
	int ret = f(2, 4);
	printf("%d", ret);
	system("pause");
	return 0;
}
#endif
#if 0
void sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int flag = 1;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j]>arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
int Find(int*arr, int size, int* num)
{
	int count = 0;
	for (int i = 0; i < size-1; i+=2)
	{
		if (arr[i] == arr[i + 1])
		{
			continue;
		}
		else if (count<2)
		{
				*num = arr[i];
				i = i + 1;
		}
		count++;
	}
	return *num;
}
int main()
{
	int a[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	sort(a, sizeof(a) / sizeof(int));
	int num;
	for (int i = 0; i<sizeof(a) / sizeof(int);++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	Find(a, sizeof(a)/sizeof(int), &num);
	printf("%d\n",num);
	system("pause");
	return 0;
}
#endif
#if 0
#define sum(a,b,c) a+b+c
int main()
{
	int i = 3;
	int j = 2;
	printf("%d\n", i*sum(i, (i + j), j));
	system("pause");
	return 0;

}
#endif
#if 0
int f(int n)
{
	static int i = 0;
	if (n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}
int main()
{
	printf("%d\n", f(1));
	system("pause");
	return 0;
}
#endif
#if 0
int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	printf("%d\n", func());
	system("pause");
	return 0;
}
#endif 
#if 0
#define NUMBER 256

void DeleteArr(char* str, char* del_str)
{
	bool flag[NUMBER];
	char* slow = str;
	char* fast = str;
	int del_size = strlen(del_str);
	if (NULL == str || NULL == del_str)
	{
		return;
	}
	for (int i = 0; i < NUMBER; ++i)
	{
		flag[i] = false;
	}
	for (int i = 0; i < del_size; ++i)
	{
		int pos = static_cast<int>(del_str[i]);//将要删除的字符标志为true
		flag[pos] = true;
	}
	while (*fast)
	{
		if (flag[*fast]==false)
		{
			*slow = *fast;
			slow++;
			fast++;
		}
		fast++;
	}
	*slow = '\0';
}
int main()
{
	char* str = "They are students.";
	char* del_str = "aeiou";
	DeleteArr(str, del_str);
	printf("%s\n", str);

	system("pause");
	return 0;
}
#endif
#if 0
struct student
{
	char name[10];
	int age;
	char gender;
}std[3],*p=std;
int main()
{
	scanf("%d", &(*p).age);
	scanf("%c", &std[0].gender);
	scanf("%c", &(p->gender));
	scanf("%c", &std->name);

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int a = 2, *p1, **p2;
	p2 = &p1;
	p1 = &a;
	a++;
	printf("%d %d %d\n", a, *p1, **p2);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int k, j, s;
	for (k = 2; k < 6; k++, k++)
	{
		s = 1;
		for (j = k; j < 6; j++)
		{
			s += j;
		}
		printf("%d\n", s);
	}
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int arr[] = { 6, 7, 8, 9, 10 };
	int* ptr = arr;
	int* a = ptr++;
	*(a) += 123;
	printf("%d %d", *ptr, *(++ptr));
	system("pause");
	return 0;
}
#endif
#if 0
//判断回文数
bool isPalindrome(int x){
	int temp;
	long y = 0;
	int start = x;
	if (x<0){
		return false;
	}
	else{
		while (x != 0){
			temp = x % 10;
			x = x / 10;
			y = temp + y * 10;
		}
		if (start == y){
			return true;
		}
		return false;
	}
}
int main()
{
	int n = 1211121;
	if (isPalindrome(n) == true)
		cout << "是回文数" << endl;
	else if (isPalindrome(n) == false)
		cout << "不是回文数" << endl;

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char a[] = "123456789",*p=a;
	int i = 0;
	while (*p)
	{
		if (i % 2 == 0)
			*p = '!';
		i++; p++;
	}
	puts(a);

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char str[] = "ABCDEFG";
	char* p1, *p2;
	p1 = "abcd";
	p2 = "efgh";
	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	printf("%s\n", str);
	system("pause");
	return 0;
}
#endif
#if 0
int fun(char* s1, char* s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
		i++;
	return (s1[i] == '\0'&&s2[i] == '\0');
}
int main()
{
	char* s1 = "avc";
	char* s2 = "abc";
	int ret=fun(s1, s2);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char* b = (char*)&a;
	printf("%08x,%08x\n", i, *b);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&arr + 1);
	printf("%d %d\n", *(arr + 1), *(ptr - 1));
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char ch = 'B' + '8' - '3';
	cout<<ch<<endl;
	system("pause");
	return 0;
}
#endif
#if 0
double powHelper(double x, int n, double re)
{
	if (n == 0)
		return 1 * re;
	else if (n == 1)
		return x * re;
	else
		return n % 2 == 0 ? powHelper(x * x, n / 2, re) : powHelper(x * x, n / 2, x * re);
}

double myPow(double x, int n)
{
	if (n < 0)
		x = 1 / x;
	return n % 2 == 0 ? powHelper(x * x, n / 2, 1) : powHelper(x * x, n / 2, x);
}
#endif
