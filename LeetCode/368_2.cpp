/*
* 52 ms
* T:O(n^2)
* S:O(n)
*/
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty()) return vector<int>();
		sort(nums.begin(), nums.end());
		vector<pair<int, int>> dp(nums.size(), make_pair(1, -1));
		int globalLargest = 1, globalLargestIdx = 0;
		for (int i = 1; i < nums.size(); i++) {
			int largest = 1, parentIdx = -1;
			for (int j = i - 1; j > -1; j--) {
				if (nums[i] % nums[j] == 0 && dp[j].first + 1 > largest) {
					parentIdx = j;
					largest = dp[j].first + 1;
				}
			}
			dp[i] = make_pair(largest, parentIdx);
			if (largest > globalLargest) {
				globalLargestIdx = i;
				globalLargest = largest;
			}
		}
		vector<int> ret;
		for (int idx = globalLargestIdx; idx != -1; idx = dp[idx].second) {
			ret.push_back(nums[idx]);
		}
		return ret;
	}
};