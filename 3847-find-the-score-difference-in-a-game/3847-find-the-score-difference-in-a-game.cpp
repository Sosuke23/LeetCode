class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        std::array<int, 2> score = {0, 0};
        int n = (int)nums.size();
        int curr_player = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                curr_player ^= 1;
            }

            if ((i + 1) % 6 == 0) {
                curr_player ^= 1;
            }
            score[curr_player] += nums[i]; 
        }
        return score[0] - score[1];
    }
};