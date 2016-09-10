/*
* 68ms
* T: O(n)
* S: O(1)
*/
class Solution {
public:
    int firstUniqChar(string s) {
        /* pos[ch]	= s.length()  ; if not appear
                    = index of ch ; if appear once
                    = s.length()+1; if repeat
		    */
        vector<int> c(128, s.length());
        int duplicated = s.length()+1;
        for(int i=s.length()-1; i>=0; --i)
        {
            if(c[s[i]] == s.length()) c[s[i]] = i;
            else c[s[i]] = duplicated;
        }
        int min = *min_element(c.begin()+'a', c.begin()+'z'+1);
        return min<s.length() ? min : -1;
    }
};
