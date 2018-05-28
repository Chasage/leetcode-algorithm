#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k) {
	if (k == 0)
		return head;
	if (head == NULL)
		return head;
	vector<ListNode*> Al;
	ListNode* ptr = head;
	Al.push_back(ptr);
	while (ptr->next != NULL)
	{
		Al.push_back(ptr->next);
		ptr = ptr->next;
	}
	int len = Al.size();
	int pos = len - k%len;
	if (pos == len)
		return head;
	else
	{
		ptr = Al[pos];
		Al[pos - 1]->next = NULL;
		Al[len - 1]->next = head;
	}
	return ptr;
}
void main()
{
	int len = 5;
	ListNode P(1);
	ListNode* Head = &P;
	ListNode* str = Head;
	for (int i = 1; i < len; i++)
	{
		str->next =new ListNode(i+1);
		str = str->next;
	}
	str->next = NULL;
	str = Head;
	while (str != NULL)
	{
		cout << str->val << "->";
		str = str->next;
	}
	cout <<"NULL"<< endl;
	int k = 3;
	str = rotateRight(Head, 3);
	while (str != NULL)
	{
		cout << str->val << "->";
		str = str->next;
	}
	cout << "NULL" << endl;
	system("pause");
}