/*
* 228ms
* T: O(n)
* S: O(1)
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        
        int i = 1;
        int j = 0;
        while(j < n)
        {
            res[j] = i;
            ++j;
            // search children
            if(i*10 <= n) i *= 10;
            // search sibling
            else if(i%10 != 9 && i<n) ++i;
            // search successor in other branch
            else
            {
                do i /= 10;
                while(9 == i%10);
                ++i;
            }
        }
        return res;
    }
};
