/*
* 44ms
* O(log(m+n))
* concise one
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		bool odd = (nums1.size() + nums2.size()) % 2;
		int mid = (nums1.size() + nums2.size() - 1) / 2;
		if (odd)return kth(nums1, 0, nums2, 0, mid);
		else return (kth(nums1, 0, nums2, 0, mid) +
			kth(nums1, 0, nums2, 0, mid + 1)) / 2.0;
	}
	
	double kth(vector<int>& nums1, int l1,
		vector<int>& nums2, int l2, int n)
		// n: Median position (zero-based index)
	{
		if (l1 >= nums1.size())return nums2[l2 + n];
		if (l2 >= nums2.size())return nums1[l1 + n];
		if (0 == n)return nums1[l1] < nums2[l2] ? nums1[l1] : nums2[l2];
		if (1 == n)
		{
			if (nums1[l1] < nums2[l2]) l1++;
			else l2++;
			n--;
			return kth(nums1, l1, nums2, l2, n);
		}
		int anchor1 = l1 + n / 2 < nums1.size() ? l1 + n / 2 : nums1.size();
		int anchor2 = l2 + n / 2 < nums2.size() ? l2 + n / 2 : nums2.size();
		if (nums1[anchor1-1] < nums2[anchor2-1])
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
};