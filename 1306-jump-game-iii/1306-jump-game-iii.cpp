class Solution {
public:

    bool fn(vector<int> &arr, vector<int> &vis, int idx) {
        if (idx < 0 or idx >= (int)arr.size() or vis[idx]) {
            return false;
        }
        if (arr[idx] == 0) {
            return true;
        }
        vis[idx] = 1;
        return  fn(arr, vis, idx + arr[idx]) || fn(arr, vis, idx - arr[idx]);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = (int)arr.size();
        vector<int> vis(n, 0);
        return fn(arr, vis, start);
    }
};