/*
* 4 ms
* T:O(nm)
* S:O(1)
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		int i = 0;
		while (i<strs[0].length())
		{
			for (int j = 1; j<strs.size(); j++)
				if (strs[j][i] != strs[j - 1][i])
					return strs[0].substr(0, i);
			i++;
		}
		return strs[0];
	}
};