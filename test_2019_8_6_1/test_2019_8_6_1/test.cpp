//求1+2+3+...+100，要求不能使用乘除法、
//for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
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
			s._a = 10;//内部类可以访问外部类的私有成员
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
	int* p1 = new int;//new后面跟类型
	int *p2 = new int(10);//可以对申请的空间初始化
	delete p1;
	delete p2;
	int array[10];//int 是数组中所放元素的类型
	//连续空间
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4};//还可以初始化,不过编译器必须是2013版本后的，因为它是C++11加的语法
	delete[]p3;//释放连续空间
	delete[]p4;
	return 0;
}
#endif
//自定义类型的空间
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
		//new申请空间调用构造函数
		Test* t1 = new Test;
		delete t1;//delete销毁空间调用析构函数
		Test* t2 = (Test*)malloc(sizeof(Test));//malloc申请的空间没有调用构造函数，没有创造对象
		if (nullptr == t2)
			;
		free(t2);//没有调用析构函数
		Test* t3 = new Test[10];//调用了10次构造函数
		delete[]t3;//调用了10次析构函数
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
