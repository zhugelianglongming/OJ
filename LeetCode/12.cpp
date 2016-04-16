/*
* 28 ms
* T:O(1)
* S:O(1)
*/
class Solution {
public:
	string intToRoman(int num) {
		// declare as static, run once in all test case
		const static string roman[4][10] = {
			{ "","I","II","III","IV","V","VI","VII","VIII","IX" },
			{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
			{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
			{ "","M","MM","MMM" }
		};
		return roman[3][num / 1000] + roman[2][num % 1000 / 100] + roman[1][num % 100 / 10] + roman[0][num % 10];
	}
};