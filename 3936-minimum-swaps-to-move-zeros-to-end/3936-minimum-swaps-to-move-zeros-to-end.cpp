class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = (int)nums.size();
        int res = 0;
        int i = 0, j = n - 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                while (j > i) {
                    if (nums[j] != 0) {
                        j--;
                        res++;
                        break;
                    }
                    j--;
                }
            }
        }
        return res;
    }
};