class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        map<int, int> freq, mp;
        for (int& i : nums) {
            freq[i - k]++;
            freq[i + k + 1]--;
            freq[i] += 0;
            mp[i]++;
        }

        int mx = 0, sum = 0;
        for (auto& a : freq) {
            sum += a.second;
            int already = sum - mp[a.first];
            int canMax = min(numOperations, already);
            mx = max(mx, canMax + mp[a.first]);
        }
        return mx;
    }
};