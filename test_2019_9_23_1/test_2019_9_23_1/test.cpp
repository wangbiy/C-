#include <iostream>
using namespace std;
#if 0
#include <string>
class Person//����
{
public:
	Person(const string& name, int age)
		:_name(name)
		, _age(age)
	{}
	void PrintPerson()
	{
		cout << _name << endl;
		cout << _age << endl;
	}
private:
	string _name;
	int _age;
};
class Student :Person//������
{};
int main()
{
	cout << sizeof(Student) << endl;//string����ֽڴ�С��28��
	//��СΪ32���������еĳ�Ա�����̳е���������
	Student s;
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void print()
	{
		cout << _pub << endl;
		cout << _pro << endl; 
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :public Base//����public�̳з�ʽ�̳�
{
public:
	void SetDerived(int pub, int pro, int pri)
	{
		//�ӻ����м̳еĳ�Ա�����ĸ�ֵ

		_pub = pub;//�����з���Ȩ����public��pub���̳��ˣ����ҿ��Է���
		_pro = pro;//�����з���Ȩ����protected��pro���̳��ˣ����ҿ��Է��ʣ����������ⲻ�ܷ���
		//_pri = pri;//�����ԣ������еķ���Ȩ����private�ĳ�Ա�������̳��ˣ����ǲ��ܷ���(���ɼ��ģ�
		/*
		������ļ̳з�ʽ��publicʱ��������private�ĳ�Ա���������в���ֱ�ӱ�����
		���ó�Ա�Ѿ����̳���
		*/

		//�����Լ��ĳ�Ա������ֵ
		_pubD = pub;
		_proD = pro;
		_priD = pri;	
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D :public Derived
{
public:
	void TestFunc()
	{
		_pro = 10;//����ʹ�ã�˵��Derive�����м̳е�_pro����Ȩ�޲���private�ģ�����protected�ģ�˵��û�иı�
	}
};
int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	d._pub = 10;//����ֱ�ӱ����ʣ�������public�ĳ�Ա������������Ҳ��public��
	//d._pro = 10;//����ֱ�ӷ��ʣ��������������,˽�е�Ҳһ��
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void print()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :protected Base//����protected�̳з�ʽ�̳�
{
public:
	void SetDerived(int pub, int pro, int pri)
	{
		//�ӻ����м̳еĳ�Ա�����ĸ�ֵ

		_pub = pub;//���Է���
		_pro = pro;//���Է���
		//_pri = pri;//�Ѿ����̳У����ܷ��ʣ����ɼ���

		//�����Լ��ĳ�Ա������ֵ
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D :public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;//�����Ա����ʣ����ǲ�����������ʣ���˷���Ȩ����protected
		_pro = 20;//���Ա����ʣ���˷���Ȩ�޻���protected	
	}
};
int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 10;//�������������,˵��_pub�ķ���Ȩ��public�����protected����private
	//d._pro = 20;//������������ʣ����ķ���Ȩ���п�����protected����private
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void print()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
class Derived :private Base//����private�̳з�ʽ�̳�
{
public:
	void SetDerived(int pub, int pro, int pri)
	{
		//�ӻ����м̳еĳ�Ա�����ĸ�ֵ

		_pub = pub;//���Է���
		_pro = pro;//���Է���
		//_pri = pri;//���ܷ���

		//�����Լ��ĳ�Ա������ֵ
		_pubD = pub;
		_proD = pro;
		_priD = pri;
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};
class D :public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;
		_pro = 10;
		//��������Derived�������ж�����ʹ�ã�����������Ҳ����ʹ�ã�˵��
		//����Ȩ�޶��ǡ�private
	}
};
int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 10;//������������ʣ�˵�����ķ���Ȩ����protected����private
	//d._pro = 20;//������������ʣ�˵�����ķ���Ȩ����protected����private
	return 0;
}
#endif
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}
protected:
	int _b;
};
class D :public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
		_d = d;
	}
protected:
	int _d;

};
int main()
{
	B b;//����
	b.SetB(10);
	D d;//������
	d.SetD(20, 30);
	b = d;//���Ը�ֵ
	//d = b;//������������ܶ��������ֵ
	return 0;
}


