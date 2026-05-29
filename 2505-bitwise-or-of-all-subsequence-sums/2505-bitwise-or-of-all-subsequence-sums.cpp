class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long res = 0, pref = 0;
        for (int x : nums) {
            pref += x;
            res |= (x | pref);
        } 
        return res;
    }
};