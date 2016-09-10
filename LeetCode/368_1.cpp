/*
* 68 ms
* T:O(n^2)
* S:O(n)
*/
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		// special case: null input
		if (nums.empty()) return vector<int>();

		vector<int> path(nums.size(), 1);
		vector<int> ret;
		sort(nums.begin(), nums.end(), less<int>());
		for (int i = 0; i < nums.size(); i++)
		{
			int new_path = path[i] + 1;
			for (int j = i + 1; j<nums.size(); j++)
				if (0 == nums[j] % nums[i] && new_path > path[j])
					path[j] = new_path;
		}
		int step = *max_element(path.begin(), path.end());
		for (int i = nums.size() - 1; step && i >= 0; i--)
			if (path[i] == step && (ret.empty() || 0 == ret[0] % nums[i]))
			{
				ret.push_back(nums[i]);
				step--;
			}
		reverse(ret.begin(), ret.end());

		return ret;
	}
};