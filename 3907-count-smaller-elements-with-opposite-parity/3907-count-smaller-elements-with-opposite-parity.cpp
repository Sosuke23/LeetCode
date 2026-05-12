class Solution {

    std::vector<int> even_bit, odd_bit;
    int sz;

    void update(std::vector<int> &bit, int idx, int val) {
        for (; idx <= sz; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(std::vector<int> &bit, int idx) {
        int tot = 0;
        for (; idx > 0; idx -= idx & -idx) {
            tot += bit[idx];
        }
        return tot;
    }

public:
    vector<int> countSmallerOppositeParity(vector<int>& nums) {
        int n = (int)nums.size();

        std::vector<int> arr = nums;
        std::sort(begin(arr), end(arr));
        arr.erase(std::unique(begin(arr), end(arr)), end(arr));

        sz = (int)arr.size();
        even_bit.assign(sz + 1, 0);
        odd_bit.assign(sz + 1, 0);

        std::vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {

            int lb = std::lower_bound(begin(arr), end(arr), nums[i]) - begin(arr);

            if (nums[i] & 1) {
                res[i] = query(even_bit, lb);
                update(odd_bit, lb + 1,  1); 
            } else {
                res[i] = query(odd_bit, lb);
                update(even_bit, lb + 1,  1);
            }
        }
        return res;
    }
};