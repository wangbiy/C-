#include "test.h"
#if 0
struct Student//在c++中结构体中不仅可以放成员变量，还可以放函数，但C语言不行
{
	void SetInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void printInfo()
	{
		cout << _age << endl;
		cout << _name << endl; 
		cout << _gender << endl;

	}
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	return 0;
}
#endif
#if 0
class Student
{
	void SetInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void printInfo()
	{
		cout << _age << endl;
		cout << _name << endl;
		cout << _gender << endl;

	}
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1, s2, s3;
	s1.SetInfo("zhangsan", "nan", 20);//无法访问，因为class的访问权限是私有的，struct的访问权限是公有的
	s2.SetInfo("lisi", "nan", 30);
	s3.Setinfo("wangwu", "nv", 40);
	return 0;
}
#endif
#if 0
void Student::SetInfo(char* name, char* gender, int age)//应该使用作用域访问符，访问类
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
int main()
{
	return 0;
}
#endif
#if 0
class Student
{
public:
	void SetInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void printInfo()
	{
		cout << _age << endl;
		cout << _name << endl;
		cout << _gender << endl;
	}
private:
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s1, s2;
	s1.SetInfo("zhangsan", "nan", 20);
	s1.printInfo();//因为此时成员函数设置为公有的，因此可以在外部访问
	//cout << _age << endl;//无法访问成员变量，因为此时为私有的
	return 0;
}
#endif
#if 0
class Person
{
public:
	void set(int a)
	{
		a = a;
	}
private:
	int a;
};
void set(int a)
{
	cout << a << endl;//这与类中的函数不形成函数重载，因为不在相同作用域
}
int main()
{
	return 0;
}
#endif
//this 指针先识别类名，再识别类中的成员变量，然后识别类中的成员函数并进行改写
//如何改写
//void StudentInit(Student* const this,char* _name,char* gender,int age)

class Student
{
public:
	void StudentInit(char* _name, char* gender, int age)
	{
		//strcpy(_name, _name);//这样就不知道是把_name拷贝给谁
		strcpy(this->_name, _name);//使用this指针来控制
		
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	void print()//这个改写成void print(Student* const this)
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
private:
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1, s2, s3;
	s1.StudentInit("张三", "男", 20);
	//相应的改写成Student::StudentInit(&s1,"张三", "男", 20)
	s2.StudentInit("李四", "男", 30);
	s3.StudentInit("王五", "女", 10);
	s1.print();
	//改写成Student::print(&s1)
	s2.print();
	s3.print();
	return 0;
}
