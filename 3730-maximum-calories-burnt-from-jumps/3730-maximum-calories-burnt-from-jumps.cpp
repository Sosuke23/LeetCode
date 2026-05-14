class Solution {
public:
    long long maxCaloriesBurnt(vector<int>& heights) {
        long long res = 0;
        int n = (int)heights.size();

        std::sort(begin(heights), end(heights));
        int prev = 0;
        for (int i = 0; i < n / 2; i++) {
            res += 1LL * (heights.back() - prev) * (heights.back() - prev);
            prev = heights.back();
            heights.pop_back();
            res += 1LL * (heights[i] - prev) * (heights[i] - prev);
            prev = heights[i];
        }

        if (n % 2 == 1) {
            res += 1LL * (heights[n / 2] - prev) * (heights[n / 2] - prev);
        }
        return res;
    }
};