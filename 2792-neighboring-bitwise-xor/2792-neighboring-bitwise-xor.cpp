class Solution {
public:
    bool doesValidArrayExist(vector<int>& A) {
        int res = 0;
        for(int x: A) {
            res ^= x;
        }
        return !res;
    }
};