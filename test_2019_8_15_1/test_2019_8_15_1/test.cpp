#include "Stack.h"
void TestFunc()
{
	Stack s1;
	Stack s2(s1);
	s1.StackPush(1);
	s1.StackPush(2);
	s1.StackPush(3);
	s1.StackPrint();
	s1.StackPop();
	s1.StackPrint();
	DataType top = s1.StackTop();
	cout << top << endl;
	DataType size = s1.StackSize();
	cout << size << endl;
	s1.StackEmpty();
}
int main()
{
	TestFunc();
	system("pause");
	return 0;
}