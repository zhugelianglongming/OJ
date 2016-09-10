/*
* 56 ms
* T:O(n^2)
* S:O(1)
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end(), less<int>());
		for (int i = 0; i<nums.size(); ++i)
		{
			if (i>0 && nums[i] == nums[i - 1]) continue;
			int s = i + 1;
			int e = nums.size() - 1;
			while (s<e)
			{
				if (nums[i] + nums[s] + nums[e] == 0)
				{
					vector<int> triple = { nums[i], nums[s], nums[e] };
					ret.emplace_back(triple);
				}
				if (nums[i] + nums[s] + nums[e] <= 0)
					while ((nums[i] + nums[++s] + nums[e] < 0 || nums[s] == nums[s - 1]) && s<e);
				else
					while ((nums[i] + nums[s] + nums[--e] > 0 || nums[e] == nums[e + 1]) && s<e);
			}
		}
		return ret;
	}
};