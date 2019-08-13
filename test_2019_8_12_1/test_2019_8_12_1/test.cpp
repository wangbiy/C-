#include "SeqList.h"
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 10, 9, 89 };
	SeqList s1(arr, sizeof(arr) / sizeof(int));//构造函数
	SeqList s2(s1);//拷贝构造函数
	SeqList s3 = s2;//赋值运算符重载
	s1.show();
	s2.show();
	s3.show();
	s1.PushBack(11);
	s1.show();
	s1.PopBack();
	s1.show();
	s1.PushFront(88);
	s1.show();
	s1.PopFront();
	s1.show();
	s1.InsertSeqList(4, 12);//在4后插入12
	s1.show();
	s1.EraseSeqList(4);//删除4后的数
	s1.show();
	s1.SeqListRemove(7);
	s1.show();
	s1.RemoveAll(8);
	s1.show();
	int val=s1.SeqListFront();
	cout << val << endl;
	val = s1.SeqListBack();
	cout << val << endl;
	s1.SeqListSort();
	s1.show();
	val=s2.SeqListCapacity();
	cout << val << endl;
	val = s2.SeqListSize();
	cout << val << endl;
	s1.SeqlistEmpty();
	system("pause");
	return 0;
}