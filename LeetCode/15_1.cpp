/*
* Map implementation
* 68 ms
* T:O(n^2logn)
* S:O(n)
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		map<int, int> countings;
		for (int num : nums) countings[num]++;
		for (auto it = countings.begin(); it != countings.end(); it++)
		{
			it->second--;
			for (auto itt = it; itt != countings.end(); itt++)
			{
				if (itt->second <= 0) continue;
				int another = -it->first - itt->first;
				if (another < itt->first) break;
				if ((another == itt->first && itt->second >= 2)
					|| (another > itt->first && countings[another]))
				{
					vector<int> triple = { it->first, itt->first, another };
					ret.emplace_back(triple);
				}
			}
			it->second++;
		}
		return ret;
	}
};