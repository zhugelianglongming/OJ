/*
* 36 ms
* O(n)
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		bool carry = 0;
		int digit;
		ListNode *ret = NULL, *tail = NULL;
		while (l1 && l2)
		{
			digit = carry + l1->val + l2->val;
			l1 = l1->next;
			l2 = l2->next;
			carry = digit > 9;
			if (!ret)
			{
				ret = new ListNode(digit % 10);
				tail = ret;
			}
			else
			{
				tail->next = new ListNode(digit % 10);
				tail = tail->next;
			}
		}
		if (l1 || l2)
		{
			ListNode *l = l1 ? l1 : l2;
			while (l)
			{
				digit = carry + l->val;
				l = l->next;
				carry = digit > 9;
				tail->next = new ListNode(digit % 10);
				tail = tail->next;
			}
		}
		if (carry) tail->next = new ListNode(1);
		return ret;
	}
};