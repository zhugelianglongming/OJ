/*
* Dynamic Programming 
* 8 ms
* T:O(n*m)
* S:O(n)
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		vector<bool> match(s.length() + 1, 0);
		match[0] = 1;
		int i = 0;
		// In i-th Loop, match[j] , in other word, dp[i][j]
		// means whether s[0..j-1] (first->"", and last->s) match p[0..i-th piece]
		while (i < p.length())
		{
			if ('*' == p[i+1])
			{
				if ('.' == p[i])
				{
					// case .*:
					// dp[i][j] = dp[i][j-1] || dp[i-1][j];
					// that means
					// dp[i][0]..dp[i][k-1] = 0 && dp[i][k]..dp[i][s.length()] = 1
					// where k is the first j make dp[i-1][j] = 1;
					int j = 0;
					while (j<match.size() && !match[j]) j++;
					while (j<match.size()) match[j++] = 1;
				}
				else
				{
					// case c*:
					// dp[i][j] = dp[i][j-1] || (dp[i-1][j] && s[j-1] == c);
					int j = 1;
					while (j<match.size())
					{
						match[j] = match[j] || (match[j - 1] && s[j - 1] == p[i]);
						j++;
					}
				}
				i += 2;
			}
			else
			{
				// case .:
				// dp[i][j] = dp[i-1][j-1];
				// case c: 
				// dp[i][j] = dp[i-1][j-1] && (s[j-1] == c);
				for (int j = match.size() - 1; j>0; j--) match[j] = match[j - 1] && ('.' == p[i] || s[j - 1] == p[i]);
				match[0] = 0;
				i++;
			}
		}
		return *(--match.end());
	}
};