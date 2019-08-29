#include <iostream>
using namespace std;
//c语言复习2
#if 0
int main()
{
	//整形提升
	char a = 127;//01111111提升为0000 0000 0000 0000 0000 0000 0111 1111
	char b = 3;//00000011提升为0000 0000 0000 0000 0000 0000 0000 0011
	char c = a + b;//相加为0000 0000 0000 0000 0000 0000 1000 0010
	//c为10000010
	//提升后是（因为char为有符号位，高位补符号位),a+b为130,但是char的
	//范围是127到-128，则高位补位1，即是1111 1111 1111 1111 1111 1111 1000 0010（补码形式）
	//原码是1000 0000 0000 0000 0000 0000 0111 1110即-126
	printf("%d\n", c);//-126
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	char c = 1;
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));
	printf("%u\n", sizeof(-c));
	system("pause");
	return 0;
}
#endif
#if 0
//结构体起始位置偏移量
#define my_offsetof(structName,memberName)\
	(size_t)&(((structName*)0)->memberName)
#endif
//位段
#if 0
struct  A
{
	int a : 2;//:后面的表示bit位,需要2个bit位剩30个bit位
	int b : 5;//用掉5个，剩25个
	int c : 10;//用掉10个，剩15个
	int d : 30;//不够，重新开辟int类型的空间
	//共8个字节
};
int main()
{
	struct A a;
	cout << sizeof(a) << endl;//8
	
	system("pause");
	return 0;
}
#endif
#if 0
#pragma pack(1)
struct tag
{
	unsigned char a : 1;//开辟一个字节，用掉一个bit位，剩7个bit位
	unsigned char b : 2;//用掉2个bit位，剩5个
	unsigned char c : 6;//不够，重新开辟一个字节，用掉6个bit位，剩2个
	unsigned char d : 4;//不够，开辟一个字节，用掉4个bit位，剩4个
	unsigned char e;//开辟一个字节
	unsigned char f : 4;//开辟一个字节，用掉4个bit位，剩4个
	unsigned char g;//开辟一个字节
	//共6个字节

};
int main()
{
	struct tag a;
	cout << sizeof(a) << endl;//6,存在对齐
	system("pause");
	return 0;
}
#endif
#if 1
//联合体
//大小端
int check_sys()
{
	union un
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
		cout << "小端!" << endl;
	else
		cout << "大端!" << endl;
	system("pause");
	return 0;
}
#endif
