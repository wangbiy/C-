#include <stdio.h>
#if 0
//����ջ֡
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
	char i = (char)t;//0x22,��shortת��Ϊchar���ͣ������˸�λ�ض�
	int a = (int)t;//0x00001122���������ͣ�����С��������ת��Ϊ�����ͣ�����λ���0
	int b = (int)3.1415;//3������������ֵת��Ϊ�������ͣ���С�������������ض�
	unsigned int p = (unsigned int)&s;//��s�ṹ������ȡ��ֵַת��Ϊ�޷������Σ�32λ������64λ�ض���Ϊ��32λ����µ�ֵַΪ4���ֽڣ���64λ��Ϊ8���ֽ�
	long l = (long)s;//������Ϊ��C�����в��ܽ��Զ�������ת��Ϊ��������
	s = (struct S)l;//������C�����в��ܽ���������ת��Ϊ�Զ�������
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
	a = c;//���������Ͷ���int*
	b = d;//������b��int* ���ͣ�d��int����
	system("pause");
	return 0;
}