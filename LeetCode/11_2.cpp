/*
* 24 ms
* T:O(n)
* S:O(1)
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int s = 0;
		int e = height.size() - 1;
		int ret = 0;
		while (s < e)
		{
			int waterHeight = min(height[s], height[e]);
			ret = max(ret, (e - s)*waterHeight);
			if (height[s] < height[e])
				// add s<e
				while (height[++s] <= waterHeight && s < e);
			else while (height[--e] <= waterHeight && s < e);
		}
		return ret;
	}
};