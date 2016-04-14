/*
* 8 ms
* T:O(n)
* S:O(1)
*/
#define LL long long
class Solution {
public:
	int myAtoi(string str) {
		bool positive = 1;
		LL ret = 0;
		int index = 0;
		while (' ' == str[index]) index++;
		positive = ('-' != str[index]);
		if ('-' == str[index] || '+' == str[index]) index++;
		while (str[index] >= '0' && str[index] <= '9')
		{
			ret *= 10;
			ret += str[index] - '0';
			if (positive && ret > INT_MAX) return INT_MAX;
			if (!positive && -ret < INT_MIN) return INT_MIN;
			index++;
		}
		return positive ? ret : -ret;
	}
};