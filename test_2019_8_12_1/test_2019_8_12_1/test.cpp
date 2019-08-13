#include "SeqList.h"
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 10, 9, 89 };
	SeqList s1(arr, sizeof(arr) / sizeof(int));//���캯��
	SeqList s2(s1);//�������캯��
	SeqList s3 = s2;//��ֵ���������
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
	s1.InsertSeqList(4, 12);//��4�����12
	s1.show();
	s1.EraseSeqList(4);//ɾ��4�����
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