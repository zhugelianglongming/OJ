/*
* 12 ms
* O(nlogn)
*/
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ordered(nums);
		sort(ordered.begin(), ordered.end());
		int s = 0;
		int e = ordered.size() - 1;

		while (ordered[s] + ordered[e] != target)
		{
			while (ordered[s] + ordered[e] < target)s++;
			while (ordered[s] + ordered[e] > target)e--;
		}

		vector<int> ret;
		ret.push_back(find(nums.begin(), nums.end(), ordered[s]) - nums.begin());
		ret.push_back(nums.rend() - find(nums.rbegin(), nums.rend(), ordered[e]) - 1);
		if (ret[0] > ret[1])swap(ret[0], ret[1]);

		return ret;
	}
};