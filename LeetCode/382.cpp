/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
* 64ms
* T: O(n)
* S: O(1)
* Reservoir Sampling
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h = head;
        srand(0);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode * head = h;
        int count = 1;
        int res = head->val;
        while(head->next != NULL)
        {
            ++count;
            head = head->next;
            int r = rand();
            // cout << count << ':' << r%count << endl;
            if(0 == r%count) res = head->val;
        }
        return res;
    }
    
private:
    ListNode * h;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
