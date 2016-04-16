/*
* 36 ms
* T:O(n)
* S:O(1)
*/
class Solution {
public:
	int romanToInt(string s) {
		int ret = 0;
		int i = 0;
		while (i<s.length())
		{
			switch (s[i++])
			{
			case 'M': ret += 1000; break;
			case 'D': ret += 500; break;
			case 'C': ret += (i<s.length() && ('M' == s[i] || 'D' == s[i])) ? -100 : 100; break;
			case 'L': ret += 50; break;
			case 'X': ret += (i<s.length() && ('C' == s[i] || 'L' == s[i])) ? -10 : 10; break;
			case 'V': ret += 5; break;
			case 'I': ret += (i<s.length() && ('X' == s[i] || 'V' == s[i])) ? -1 : 1; break;
			default: break;
			}
		}
		return ret;
	}
};