#include <iostream>
using namespace std;
//c���Ը�ϰ2
#if 0
int main()
{
	//��������
	char a = 127;//01111111����Ϊ0000 0000 0000 0000 0000 0000 0111 1111
	char b = 3;//00000011����Ϊ0000 0000 0000 0000 0000 0000 0000 0011
	char c = a + b;//���Ϊ0000 0000 0000 0000 0000 0000 1000 0010
	//cΪ10000010
	//�������ǣ���ΪcharΪ�з���λ����λ������λ),a+bΪ130,����char��
	//��Χ��127��-128�����λ��λ1������1111 1111 1111 1111 1111 1111 1000 0010��������ʽ��
	//ԭ����1000 0000 0000 0000 0000 0000 0111 1110��-126
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
//�ṹ����ʼλ��ƫ����
#define my_offsetof(structName,memberName)\
	(size_t)&(((structName*)0)->memberName)
#endif
//λ��
#if 0
struct  A
{
	int a : 2;//:����ı�ʾbitλ,��Ҫ2��bitλʣ30��bitλ
	int b : 5;//�õ�5����ʣ25��
	int c : 10;//�õ�10����ʣ15��
	int d : 30;//���������¿���int���͵Ŀռ�
	//��8���ֽ�
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
	unsigned char a : 1;//����һ���ֽڣ��õ�һ��bitλ��ʣ7��bitλ
	unsigned char b : 2;//�õ�2��bitλ��ʣ5��
	unsigned char c : 6;//���������¿���һ���ֽڣ��õ�6��bitλ��ʣ2��
	unsigned char d : 4;//����������һ���ֽڣ��õ�4��bitλ��ʣ4��
	unsigned char e;//����һ���ֽ�
	unsigned char f : 4;//����һ���ֽڣ��õ�4��bitλ��ʣ4��
	unsigned char g;//����һ���ֽ�
	//��6���ֽ�

};
int main()
{
	struct tag a;
	cout << sizeof(a) << endl;//6,���ڶ���
	system("pause");
	return 0;
}
#endif
#if 1
//������
//��С��
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
		cout << "С��!" << endl;
	else
		cout << "���!" << endl;
	system("pause");
	return 0;
}
#endif
