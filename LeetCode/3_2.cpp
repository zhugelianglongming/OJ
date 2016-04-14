/*
* 16 ms
* T:O(n)
* S:O(1)
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> preIndex(256, -1);
		int start = -1;
		int maxL = 0;
		for (int i = 0; i < s.length(); i++)
		{
			char ch = s[i];
			if (preIndex[ch] > start)
			{
				start = preIndex[ch];
			}
			preIndex[ch] = i;
			maxL = max(maxL, i - start);
		}
		return maxL;
	}
};