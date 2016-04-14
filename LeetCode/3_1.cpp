/*
* 60 ms
* T:O(n)
* S:O(n)
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> preIndex;
		int start = 0;
		int maxL = 0;
		for (int i = 0; i < s.length(); i++)
		{
			char ch = s[i];
			if (preIndex.find(ch) != preIndex.end() && preIndex[ch] >= start)
			{
				start = preIndex[ch] + 1;
			}
			preIndex[ch] = i;
			maxL = max(maxL, i - start + 1);
		}
		return maxL;
	}
};