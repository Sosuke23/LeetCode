class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& v) {
        for (int i = 0; i < (int)v.size() - 2; i++) {
            if (v[i] % 2 == 1 && v[i + 1] % 2 == 1 && v[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};