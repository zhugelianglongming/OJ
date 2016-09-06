class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const static string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits.length() <= 0) return vector<string>();
        int resLen = 1;
        for(int i=0; i<digits.length(); ++i)
        {
            char &ch = digits[i];
            if(ch < '2' || ch > '9')
                return vector<string>();
            ch -= '0';
            resLen *= dict[ch].length();
        }
        
        vector<string> res(resLen, string(digits.length(), '\0'));
        // copy(res.begin(), res.end(), ostream_iterator<string>(cout, "-"));
        int repeat = 1;
        for(int dth=0; dth<digits.length(); ++dth)
        {
            auto &subDict = dict[digits[dth]];
            int i=0;
            int j=0;
            int l = subDict.length();
            while(i<resLen)
            {
                int r = repeat+1;
                while(--r) res[i++][dth] = subDict[j];
                j = (j+1)%l;
            }
            repeat *= l;
        }
        
        return res;
    }
};
