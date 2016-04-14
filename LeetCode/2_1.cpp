/*
* 36 ms
* T:O(n)
* S:O(n)
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
		ListNode *ret=NULL, *tail=NULL;
		while (l1 || l2 || carry)
		{
			digit = carry;
			if (l1)
			{
				digit += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				digit += l2->val;
				l2 = l2->next;
			}
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
		return ret;
	}
};