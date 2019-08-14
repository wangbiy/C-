#include "DList.h"
void TestFunc()
{ 
	DList s1;
	DList s2(s1);
	s1.DListPushBack(1);
	s1.DListPushBack(2);
	s1.DListPushBack(3);
	s1.DListPushBack(4);
	s1.DListPushBack(5);
	s1.PrintDList();
	s1.DListPopBack();
	s1.PrintDList();
	s1.DListPushFront(0);
	s1.PrintDList();
	s1.DListPopfront();
	s1.PrintDList();
	s1.DListInsertFront(s1.Find(2), 0);
	s1.PrintDList();
	s1.DListErase(s1.Find(0));
	s1.PrintDList();
	int size = s1.DListSize();
	cout << size << endl;
	DLDataType data = s1.DListFront();//取出第一个元素
	cout << data << endl;
	data = s1.DListBack();
	cout << data << endl;
}
int main()
{
	TestFunc();
	system("pause");
	return 0;
}