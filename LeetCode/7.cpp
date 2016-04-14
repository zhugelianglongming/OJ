/*
* 8 ms
* T:O(n)
* S:O(1)
*/
#define LL long long
class Solution {
public:
	int reverse(int x) {
		LL reverse = 0;
		while (x)
		{
			reverse *= 10;
			reverse += x % 10;
			if (reverse > INT_MAX || reverse < INT_MIN) return 0;
			x /= 10;
		}
		return reverse;
	}
};