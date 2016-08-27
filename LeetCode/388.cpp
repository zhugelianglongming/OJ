/*
* 0ms
* T: O(n)
* S: O(1)
*/
class Solution {
public:
    int lengthLongestPath(string input) {
		// length absolute path for current directory
		// "" ==> 0
		// "dir/" ==> 4
		// "dir/subdir2/" ==> 12
		int l[1000] = {0};
		int i=0;
		int res = 0;
		while(i<input.length())
		{
			bool isFile = 0;
			int filenameLength = 0;
			int level = 0;
			int mark = 0;

			// count level, default = 1
			mark = i;
			while('\t' == input[i]) ++i;
			level = i-mark+1;

			// count length of file or sub-directory
			mark = i;
			while(input[i] && input[i] != '\n')
			{
				if('.' == input[i]) isFile = 1;
				++i;
			}
			filenameLength = i-mark;

			if(isFile) res = max(res, l[level-1]+filenameLength);
			else l[level] = l[level-1]+filenameLength+1;
			++i;
		}
		return res;
	}
};
