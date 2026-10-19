class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::vector<int> res;
        int f[101];

        for (int x : nums) {
            f[x]++;
        }
        
        bool ok = true;
        while (ok) {
            ok = false;
            for (int i = 1; i <= 100; i++) {
                if (f[i] > 0) {
                    f[i]--;
                    res.push_back(i);
                    ok = true;
                }
            }
        }

        return res;

        
    }
};