#include "test.h"
#if 0
struct Student//��c++�нṹ���в������Էų�Ա�����������Էź�������C���Բ���
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
	s1.SetInfo("zhangsan", "nan", 20);//�޷����ʣ���Ϊclass�ķ���Ȩ����˽�еģ�struct�ķ���Ȩ���ǹ��е�
	s2.SetInfo("lisi", "nan", 30);
	s3.Setinfo("wangwu", "nv", 40);
	return 0;
}
#endif
#if 0
void Student::SetInfo(char* name, char* gender, int age)//Ӧ��ʹ����������ʷ���������
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
	s1.printInfo();//��Ϊ��ʱ��Ա��������Ϊ���еģ���˿������ⲿ����
	//cout << _age << endl;//�޷����ʳ�Ա��������Ϊ��ʱΪ˽�е�
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
	cout << a << endl;//�������еĺ������γɺ������أ���Ϊ������ͬ������
}
int main()
{
	return 0;
}
#endif
//this ָ����ʶ����������ʶ�����еĳ�Ա������Ȼ��ʶ�����еĳ�Ա���������и�д
//��θ�д
//void StudentInit(Student* const this,char* _name,char* gender,int age)

class Student
{
public:
	void StudentInit(char* _name, char* gender, int age)
	{
		//strcpy(_name, _name);//�����Ͳ�֪���ǰ�_name������˭
		strcpy(this->_name, _name);//ʹ��thisָ��������
		
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	void print()//�����д��void print(Student* const this)
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
	s1.StudentInit("����", "��", 20);
	//��Ӧ�ĸ�д��Student::StudentInit(&s1,"����", "��", 20)
	s2.StudentInit("����", "��", 30);
	s3.StudentInit("����", "Ů", 10);
	s1.print();
	//��д��Student::print(&s1)
	s2.print();
	s3.print();
	return 0;
}
