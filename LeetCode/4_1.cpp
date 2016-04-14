/*
* 40ms
* T:O(log(m+n))
* S:O(1)
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		odd = (nums1.size() + nums2.size()) % 2;
		return kth(nums1, 0, nums2, 0,
			(nums1.size() + nums2.size() - 1) / 2);
	}

	double kth(vector<int>& nums1, int l1,
		vector<int>& nums2, int l2, int n)
		// n: Median position (zero-based index)
	{
		if (l1 >= nums1.size())
		{
			if (odd)return nums2[l2 + n];
			else return (nums2[l2 + n] + nums2[l2 + n + 1]) / 2.0;
		}
		if (l2 >= nums2.size())
		{
			if (odd)return nums1[l1 + n];
			else return (nums1[l1 + n] + nums1[l1 + n + 1]) / 2.0;
		}
		if (0 == n)
		{
			if (odd)return nums1[l1] < nums2[l2] ? nums1[l1] : nums2[l2];
			else
			{
				int ret = nums1[l1] + nums2[l2];
				if (l1 + 1 < nums1.size() && ret > nums1[l1] + nums1[l1 + 1])
					ret = nums1[l1] + nums1[l1 + 1];
				if (l2 + 1 < nums2.size() && ret > nums2[l2] + nums2[l2 + 1])
					ret = nums2[l2] + nums2[l2 + 1];
				return ret / 2.0;
			}
		}
		if (1 == n)
		{
			if (nums1[l1] < nums2[l2]) l1++;
			else l2++;
			n--;
			return kth(nums1, l1, nums2, l2, n);
		}
		int anchor1 = l1 + n / 2 < nums1.size() ?
			l1 + n / 2 : nums1.size();
		int anchor2 = l2 + n / 2 < nums2.size() ?
			l2 + n / 2 : nums2.size();
		if (nums1[anchor1 - 1] < nums2[anchor2 - 1])
		{
			n -= anchor1 - l1;
			l1 = anchor1;
		}
		else
		{
			n -= anchor2 - l2;
			l2 = anchor2;
		}
		return kth(nums1, l1, nums2, l2, n);
	}
private:
	bool odd;
};