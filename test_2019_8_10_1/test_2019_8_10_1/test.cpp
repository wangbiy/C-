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
template<typename T>//����ģ��
T Add(T left,T right)
{
	cout << typeid(right).name() << endl;
	return left + right;
}
int main()
{
	//��ʽʵ����
	cout << Add(1, 2) << endl;//�ڱ����ڼ䣬��������ʵ�ε�������ȷ��ģ������б��е�T������ȷ����T�Ľ�������ɴ���
	cout << Add(12.3, 4.56) <<endl;
	//cout << Add((double)1, 2.3) << endl;
	//����
	cout << Add<double>(1, 2.3) << endl;//��ʽʵ����,��ȷָ��T������Ϊdouble
	//���Խ�����ʽ����ת��
	//Add<double>("hello", 1.0);//����ת��ʧ��
	return 0;
}