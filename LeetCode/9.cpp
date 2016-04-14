/*
* 72 ms
* T:O(n)
* S:O(1)
*/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return 0;
		if (x < 10) return 1;
		if (0 == x % 10) return 0;
		if (x < 100) return (0 == x % 11);
		if (x < 1000) return (x / 100 == x % 10);
		int subReverse = 0;
		while (x > subReverse)
		{
			subReverse *= 10;
			subReverse += x % 10;
			x /= 10;
		}
		return (x == subReverse || x == subReverse / 10);
	}
};