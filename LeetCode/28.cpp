/*
T:O(m+n)
S:O(m)
8ms
KMP
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if("" == needle) return 0;
        else if("" == haystack) return -1;
        
        int i = 0;  
        int j = 0;  
        int sLen = haystack.length();  
        int pLen = needle.length();
        vector<int> next;
        GetNext(needle, next);
        cout << endl << sLen << ' ' << pLen << endl;
        while (i < sLen && j < pLen)  
        {  
            if (j == -1 || haystack[i] == needle[j])  
            {
                i++;  
                j++;  
            }  
            else j = next[j];  
        } 
        if (j == pLen) return (i - j);  
        else return -1;  
    }

private:
    void GetNext(string & pattern, vector<int> & next)
	{
		const int n = pattern.length();
		if(0 == n)
		{
			next.resize(0);
			return;
		}

		next.resize(n);
		next[0] = -1;
		int j = 0;
		int k = -1;
		while (j < n-1)
		{
			if(-1 == k || pattern[j] == pattern[k])
			{
				++j;
				++k;
				next[j] = (pattern[j] != pattern[k]) ? k : next[k];
			}
			else k = next[k];
		}
	}
};
