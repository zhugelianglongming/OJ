/*
* 16 ms
* T:O(n)
* S:O(n)
*/
#include <bits/stdc++.h>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); ++i)
#define  FOR(i, n)  for (int i=1; i<=int(n); ++i)
#define  pii        pair<int, int>
#define  piL        pair<int, long long>
#define  mp         make_pair
#define  pb         push_back
#define  whatis(x)  cout << #x << ": " << x << endl;
#define  N   1234
#define  eps 1e-13
#define  pi  acos(-1.0)
#define  inf 0XFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> index;
		int n = nums.size();
		REP(i, n)
		{
			int another = target - nums[i];
			if (index.find(another) != index.end())
			{
				return vector<int>({ index[another], i });
			}
			index[nums[i]] = i;
		}
	}
};