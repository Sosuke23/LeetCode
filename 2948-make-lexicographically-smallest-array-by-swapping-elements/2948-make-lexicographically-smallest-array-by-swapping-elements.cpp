class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = (int)nums.size();
        vector<int> idx(n, 0);
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&] (int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> A;
            A.push_back(idx[i]);
            int j = i;
            while (j + 1 < n and nums[idx[j + 1]] - nums[idx[j]] <= limit) {
                A.push_back(idx[j + 1]);
                j += 1;
            }
            sort(begin(A), end(A));
            int now = i;
            for (auto x : A) {
                res[x] = nums[idx[now]];
                now += 1;
            }
            i = j;
        }
        return res;
    }
};