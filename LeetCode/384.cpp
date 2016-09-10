/*
* 352ms
* T: O(n)
* S: O(1)
* Fisher–Yates Shuffle
*/
class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int> nums) {
        srand(time(0));
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(origin);
        for(int i=res.size(); i>0; i--)
        {
            int r = rand()%i;
            swap(res[i-1], res[r]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
