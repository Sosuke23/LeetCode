class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(1 + (n - 1) * 2, -1);     
        unordered_set<int> nums; 
        for (int i = 1; i <= n; i++) nums.insert(i); 
        dfs(0, n, res, nums);
        return res;
    }
    bool dfs(int i, int n, vector<int>& res, unordered_set<int>& nums) {
        if (nums.size() == 0) return true; 
        if (res[i] != -1) return dfs(i + 1, n, res, nums); 
        for (int j = n; j >= 1; j--) {
            int dist = j == 1 ? 0 : j;
            if (nums.count(j) && (i + dist < res.size() && res[i + dist] == -1)) {
                res[i] = res[i + dist] = j; 
                nums.erase(j); 
                if (dfs(i + 1, n, res, nums)) return true; 
                res[i] = res[i + dist] = -1;
                nums.insert(j);
            }
        }
        return false;
    }
};

