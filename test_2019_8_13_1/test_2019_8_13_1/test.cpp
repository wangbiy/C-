#include "SList.h"
int main()
{
	SList s1;
	SList s2;
	s1.SListPushBack(1);
	s1.SListPushBack(2);
	s1.SListPushBack(3);
	s1.SListPushBack(4);
	s1.PrintSList();
	s1.SListPushFront(0);
	s1.PrintSList();
	s1.SListPopFront();
	s1.PrintSList();
	s1.SListInsertAfter(s1.SListFind(3), 11);
	s1.PrintSList();
	s1.SListErase(s1.SListFind(4));
	s1.PrintSList();
	int size = s1.SListSize();
	cout << size << endl;
	Node* ret=s1.SListFront();
	ret = s1.SListBack();
	s1.ReverseSList();
	s1.PrintSList();
	system("pause");
	return 0;
}