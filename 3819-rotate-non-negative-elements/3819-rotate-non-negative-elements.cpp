class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = (int)nums.size();
        std::vector<int> temp_nums = nums;
        
        std::vector<int> pos, orig_idx;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                pos.push_back(pos.empty() ? 0 : pos.back() + 1);
                orig_idx.push_back(i);
            }
        }
       
        int pos_n = (int)pos.size();
        if (pos_n > 0) {
            k %= pos_n;
        }
        for (int i = 0; i < pos_n; i++) {
            pos[i] = std::abs((pos[i] - k + pos_n)) % pos_n;
            temp_nums[orig_idx[pos[i]]] = nums[orig_idx[i]];
        }

        return temp_nums;

    }
};