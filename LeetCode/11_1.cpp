/*
* 120 ms
* T:O(nlogn)
* S:O(n)
*/
#define REP(i, n) for(int i=0; i<int(n); i++)
class Solution {
public:
	int maxArea(vector<int>& height) {
		auto comp = [&height](int a, int b) -> bool {return height[a] < height[b]; };
		priority_queue<int, vector<int>, decltype(comp)> xs(comp);
		REP(i, height.size()) xs.push(i);
		int minx = xs.top();
		int maxx = xs.top();
		int ret = 0;
		xs.pop();
		while (!xs.empty())
		{
			minx = min(minx, xs.top());
			maxx = max(maxx, xs.top());
			ret = max(ret, (maxx - minx)*height[xs.top()]);
			// cout << xs.top() << ' ' << ret << endl;
			xs.pop();
		}
		return ret;
	}
};