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
#if 0
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
	B* pb = &d;
	B& rb = d;
	//�����������Ը�ֵ�������ָ������ã��������

	//D* pd = &b;
	//D& rd = b;
	//���󣬻�����󲻿��Ը�ֵ���������ָ�������
	D* pd = (D*)&b;//����ǿ������ת���������ǲ���ȫ��
	return 0;
}
#endif
#if 0
class B
{
public:
	void TestFunc(int b)
	{
		_b = b;
	}
protected:
	int _b;
};
class D:public B
{
public:
	void TestFunc()
	{
		_b = 10;
	}
	char _b;
};
int main()
{
	D d;
	d._b = 10;//��ֵ�������Լ���_b
	d.TestFunc();
	//d.TestFunc(10);//���������õ��������������ͬ���ĳ�Ա���������ǵ��õĻ���ĳ�Ա����
	d.B::TestFunc(10);//�����Ϳ�����
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{}
	int _b;
};
class Derived : public Base
{
public:
	/*
	������Ĭ�����ɵĹ��캯��һ����
	Derived()
	  :Base()//ֻ�ܵ����޲εĻ��๹�캯��
	{}������
	*/
	Derived(int b, int d)//�û���ʽ�����������Ĺ��캯��
		:Base(b)
		, _d(d)
	{}
	int _d;
};
int main()
{
	//Derived d;//����û�к��ʵ�Ĭ�Ϲ��캯��
	Derived d(10, 20);//û������
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b=10)
		:_b(b)
	{}
	int _b;
};
class Derived : public Base
{
public:

	int _d;
};
int main()
{
	Derived d;
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{}
	Base(Base& b)//�������캯��
		:_b(b._b)
	{
		cout << "Base(Base&)" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
	Derived(Derived& d)//��ʽ�����������캯��,�ڳ�ʼ���б����������Ŀ������캯��
		:Base(d._b)
	{}
	Derived& operator=(const Derived& d)
	{
		Base::operator=(d);
		cout << "Derived::operator=(Derived&)" << endl;
		return *this;
	}
	int _d;
};
int main()
{
	Derived d1(10, 20);
	Derived d2(d1);//���������û����ʽ���忽�����캯�����������Զ�����
	d2 = d1;
	//������û����ʽ���帳ֵ��������أ��������Զ����ɣ�
	//Ҫ���û���ĸ�ֵ���������
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base::Base()" << endl;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
	int _b;
};
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{
		cout << "Derived::Derived()" << endl;
	}
	~Derived()
	{
		cout << "Derived::~Derived()" << endl;
	}
	int _d;
};
void Testfunc()
{
	Derived d1(10, 20);
	Derived d2(d1);
}
int main()
{
	Testfunc();
	return 0;
}
#endif
#if 0
//��ֹ�౻�̳У�C++98��,�������ַ���Ч�ʲ����ߣ���C++11�п���ʹ��final�ؼ�������ֹ�౻�̳�
class Base
{
public:
	static Base GetInstance(int b)
		//����������ͨ�ĳ�Ա�����������ͨ�����������ã�
		//������ʱ�޷��ù��캯������������˿��Խ�����Ϊ��̬��Ա����
	{
		return Base(b);
	}
private:
	Base(int b)//������Ĺ��캯������˽�е�,������Ȼ���ܱ��̳��ˣ����������Ҫ�����ⴴ���������޷������ˣ���˿���
		:_b(b)
	{}
	int _b;

};
class Derived :public Base
{
public:
	//Derived(int b, int d)
	//	:Base(b)//���ܷ��ʣ���Ϊ�����еĹ��캯��Ϊprivate�ģ����ܱ��̳�
	//	, _d(d)
	//{}
	int _d;
};
int main()
{
	Base b = Base::GetInstance(10);
	return 0;
}
#endif
#if 0
class Base final
{
public:
	Base(int b)
		:_b(b)
	{}
	int _b;

};
class Derived :public Base//���ܼ̳�
{
public:
	int _d;
};
int main()
{
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		++count;
	}
protected:
	int _b;
public:
	static int count;
};
int Base::count = 0;
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
protected:
	int _d;
};
int main()
{
	Derived d(10,20);
	cout << &Base::count << endl;
	cout<<&Derived::count<< endl;
	return 0;
}
#endif
#if 0
class Base
{
	friend void TestFunc();
public:
	Base(int b)
		:_b(b)
	{}
	~Base()
	{}
protected:
	int _b;

};
class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
	~Derived()
	{}
protected:
	int _d;
};
void TestFunc()
{
	Base b(10);
	cout << b._b << endl;//�޷�ֱ�ӷ��ʣ���Ϊ�����е�_b��protected��,����ʹ����Ԫ
	Derived d(10, 20);
	//cout << d._d << endl;//�޷���ӡ�������Ԫ��ϵû�м̳�
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
//��̳�
class B1
{
public:
	int _b1;
};
class B2
{
public:
	int _b2;
};
class D :public B1, public B2
{
public:
	int _d;
};
void TestFunc()
{
	cout << sizeof(D) << endl;//12
}
int main()
{
	TestFunc();
	return 0;
}
#endif
#if 0
//���μ̳�
class B
{
public:
	int _b;
};
class C1 :public B
{
public:
	int _c1;
};
class C2 :public B
{
public:
	int _c2;
};
class D :public C1, public C2
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;//20
	D d;
	d.C1::_b = 10;
	d.C2::_b = 20;//����ͨ�����෽��������ķ���C1����C2�м̳е�_b���÷��ʱ����ȷ
	return 0;
}
#endif
#if 0
class B
{
public:
	int _b;
};
class D :virtual public B
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;//12
	return 0;
}
#endif
#if 0
//��������̳�
class B
{
public:
	void TestFunc()
	{}
	int _b;
};
class C1 :virtual public B
{
public:
	int _c1;
};
class C2 :virtual public B
{
public:
	int _c2;
};
class D :public C1, public C2
{
public:
	int _d;
};
int main()
{
	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	return 0;
}
#endif
class Base1
{
public:
	int _b1;
};
class Base2 
{
public:
	int _b2;
};
class Derive : public Base1, public Base2 
{
public:
	int _d;
};
int main()
{
	// A. p1 == p2 == p3
	// B. p1 < p2 < p3
	// C. p1 == p3 != p2
	// D. p1 != p2 != p3
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}


