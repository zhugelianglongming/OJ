/*
* 12ms
* T: O(n^2)
* S: O(1)
*/

class Solution {
public:

	void updateClosetSum(int newSum, int &oldSum, int target)
	{
		if(abs(newSum-target) < abs(oldSum-target)) oldSum = newSum;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];
		for (int i=0; i<nums.size(); i++)
		{
			int x = nums[i];
			int j = i+1;
			int k = nums.size()-1;
			// check the closet two sum from both side
			while(j<k)
			{
				while(j<k && (x+nums[j]+nums[k])>=target) k--;
				if(j<k+1 && k+1<nums.size()) updateClosetSum(x+nums[j]+nums[k+1], res, target);
				while(j<k && (x+nums[j]+nums[k])<=target) j++;
				if(j-1<k && j-1>i) updateClosetSum(x+nums[j-1]+nums[k], res, target);
				if(res == target) return res;
			}
		}
		return res;
	}

};
