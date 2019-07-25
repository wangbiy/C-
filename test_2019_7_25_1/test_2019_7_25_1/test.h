#include<string.h>
#include <iostream>
using namespace std;
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
#endif