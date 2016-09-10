/*
* 64ms
* T: O(n)
* S: O(1)
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int c[128] = {0};
        for(char ch : s) ++c[ch];
        for(int i=0; i<s.length(); ++i)
            if(1 == c[s[i]]) return i;
        return -1;
    }
};
