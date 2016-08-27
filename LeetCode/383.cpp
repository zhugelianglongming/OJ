/*
* 322ms
* T: O(n+m)
* S: O(1)
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> c(128, 0);
        for(char ch : magazine) ++c[ch];
        // quick stop
        for(char ch : ransomNote) if(--c[ch] < 0) return 0;
        return 1;
    }
};
