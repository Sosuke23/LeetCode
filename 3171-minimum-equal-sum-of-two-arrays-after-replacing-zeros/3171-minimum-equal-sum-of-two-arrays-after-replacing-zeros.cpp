class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cnt_1 = 0, cnt_2 = 0;
        typedef long long i64;
        i64 sum_1 = 0, sum_2 = 0;

        for (auto x : nums1) {
            cnt_1 += (x == 0);
            sum_1 += x;
        }
        for (auto x : nums2) {
            cnt_2 += (x == 0);
            sum_2 += x;
        }
     
        if (cnt_1 == 0 and cnt_2 == 0) {
            return (sum_1 == sum_2 ? sum_1 : -1);
        }
        if (cnt_1 == 0) {
            if (sum_1 <= sum_2) {
                return -1;
            }
            else {
                int diff = sum_1 - sum_2;
                if (diff < cnt_2) {
                    return -1;
                }
                else {
                    return sum_1;
                }
            }
        }

        if (cnt_2 == 0) {
            if (sum_2 <= sum_1) {
                return -1;
            }
            else {
                int diff = sum_2 - sum_1;
                if (diff < cnt_1) {
                    return -1;
                }
                else {
                    return sum_2;
                }
            }
        }
        
        i64 res = max(sum_1 + cnt_1, sum_2 + cnt_2); 
        return res;
    }
};