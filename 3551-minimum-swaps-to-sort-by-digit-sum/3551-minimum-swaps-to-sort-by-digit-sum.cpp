class Solution {
public:
    int minSwaps(vector<int>& nums) {
        std::vector<std::array<int, 2>> arr;

        std::unordered_map<int, int> idx;
        for (int i = 0; i < (int)nums.size(); i++) {
            idx[nums[i]] = i;
        }

        auto dig_sum = [&] (int d) {
            int ds = 0;
            for (char c : std::to_string(d)) {
                ds += (c - '0');
            }
            return ds;
        };

        for (int x : nums) {
            arr.push_back({dig_sum(x), x});
        }

        std::sort(begin(arr), end(arr));
        int res = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != arr[i][1]) {
                res++;
                int want = idx[arr[i][1]];
                idx[arr[i][1]] = i;
                idx[nums[i]] = want;
                std::swap(nums[i], nums[want]);
            }
        }
        
        // res = (res + 1) / 2;
        return res;
    }
};