/*
* 16 ms
* T:O(n)
* S:O(1)
*/
#define REP(i, n) for(int i=0; i<int(n); i++)
class Solution {
public:
	string convert(string s, int numRows) {
		if (1 == numRows) return s;
		string ret;
		int step[2];
		REP(i, numRows)
		{
			step[0] = 2 * (numRows - 1 - i);
			step[1] = 2 * i;
			int index = i;
			while (index < s.length())
			{
				ret += s[index];
				index += step[0];
				if (index < s.length() && step[0] && step[1]) ret += s[index];
				index += step[1];
			}
		}
		return ret;
	}
};