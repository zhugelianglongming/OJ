/*
* 32ms
* T: O(n)
* S: O(n)
*/
class Solution {
public:
    NestedInteger deserialize(string s) {
        istringstream sin(s);
        return deserialize(sin);
    }
private:
    NestedInteger deserialize(istringstream & ss)
    {
        int k;
        if(ss >> k) return NestedInteger(k);
        ss.clear();
        
        // eat '['
        ss.get();
        NestedInteger res;
        while(ss.peek() != ']')
        {
            res.add(deserialize(ss));
            // eat',' if exist
            if(',' == ss.peek()) ss.get();
        }
        // eat ']'
        ss.get();
        return res;
    }
};
