//��1+2+3+...+100��Ҫ����ʹ�ó˳�����
//for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
#include <iostream>
using namespace std;
#if 0
class Solution
{
	class Sum
	{
	public:
		Sum()
		{
			++count;
			sum += count;
		}
		static int GetSum()
		{
			return sum;
		}
		static void ReSet()
		{
			count = 0;
			sum = 0;
		}
		void testfunc()
		{
			Solution s;
			s._a = 10;//�ڲ�����Է����ⲿ���˽�г�Ա
		}
	private:
		static int count;
		static int sum;
	};
public:
	int Sum_Solution()
	{
		Solution::Sum::ReSet();
		Sum s[200];
		return Solution::Sum::GetSum();
	}
private:
	int _a;
};
int Solution::Sum::count = 0;
int Solution::Sum::sum = 0;
int main()
{
	return 0;
}
#endif
#if 0
int GlobalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pchar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
}
int main()
{
	Test();
	return 0;
}
#endif
#if 0
int main()
{
	int* p1 = new int;//new���������
	int *p2 = new int(10);//���Զ�����Ŀռ��ʼ��
	delete p1;
	delete p2;
	int array[10];//int ������������Ԫ�ص�����
	//�����ռ�
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4};//�����Գ�ʼ��,����������������2013�汾��ģ���Ϊ����C++11�ӵ��﷨
	delete[]p3;//�ͷ������ռ�
	delete[]p4;
	return 0;
}
#endif
//�Զ������͵Ŀռ�
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
	void TestNewDelete()
	{
		//new����ռ���ù��캯��
		Test* t1 = new Test;
		delete t1;//delete���ٿռ������������
		Test* t2 = (Test*)malloc(sizeof(Test));//malloc����Ŀռ�û�е��ù��캯����û�д������
		if (nullptr == t2)
			;
		free(t2);//û�е�����������
		Test* t3 = new Test[10];//������10�ι��캯��
		delete[]t3;//������10����������
	}
private:
	int _t;
};
int main()
{
	Test t;
	t.TestNewDelete();
	return 0;
}
