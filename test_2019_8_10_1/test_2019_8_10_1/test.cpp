#include <iostream>
using namespace std;
#if 0
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
short Add(short left, short right)
{
	return left + right;
}
int main()
{
	Add(12, 32);
	Add(12.3, 34.5);
	return 0;
}
#endif
template<typename T>//函数模板
T Add(T left,T right)
{
	cout << typeid(right).name() << endl;
	return left + right;
}
int main()
{
	//隐式实例化
	cout << Add(1, 2) << endl;//在编译期间，必须推演实参的类型来确定模板参数列表中的T，根据确定的T的结果来生成代码
	cout << Add(12.3, 4.56) <<endl;
	//cout << Add((double)1, 2.3) << endl;
	//或者
	cout << Add<double>(1, 2.3) << endl;//显式实例化,明确指定T的类型为double
	//尝试进行隐式类型转换
	//Add<double>("hello", 1.0);//错误，转换失败
	return 0;
}