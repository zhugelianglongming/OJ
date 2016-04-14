/*
* Manacher
* 8 ms
* T:O(n)
* S:O(n)
*/
#define REP(i,n) for(int i=0; i<int(n); i++)

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() < 2) return s;

		string ss(s.length() * 2 + 3, '#');
		ss[0] = '@';
		ss[ss.length() - 1] = 0;
		REP(i, s.length()) ss[2 * i + 2] = s[i];
		vector<int> p(ss.length(), 0);

		int pedge = 0;
		int pcenter = 1;
		int maxp = 0;
		int maxpcenter = 0;
		for (int i = 1, forend = ss.length() - 1; i<forend; i++)
		{
			if (i + maxp > forend) break;
			p[i] = pedge > i ? min(p[2 * pcenter - i], pedge - i) : 1;
			int j = i - p[i];
			int k = i + p[i];
			while (ss[j--] == ss[k++]) p[i]++;
			if (i + p[i] > pedge)
			{
				pedge = i + p[i];
				pcenter = i;
			}
			if (p[i] > maxp)
			{
				maxp = p[i];
				maxpcenter = i;
			}
		}
		return s.substr((maxpcenter - maxp) / 2, maxp - 1);
	}
};