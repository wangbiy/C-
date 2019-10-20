#include "AVLTree.hpp"
void TestAVLTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> t;
	for (auto e : array)
		t.Insert(make_pair(e,e));
	t.Inorder();
	if (t.IsBalanceTree())
	{
		cout << "t is a AVLTree" << endl;
	}
	else
		cout << "t is not AVLTree" << endl;
}
int main()
{
	TestAVLTree();
	return 0;
}