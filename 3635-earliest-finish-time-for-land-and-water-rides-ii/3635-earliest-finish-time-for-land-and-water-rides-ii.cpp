class Solution {
public:
    int earliestFinishTime(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2) {
        int res = INT_MAX, mn = INT_MAX;
        for(int i = 0; i < (int)start1.size(); i++) {
            mn = min(mn, start1[i] + duration1[i]);
        }
        for(int i = 0; i < (int)start2.size(); i++) {
            res = min(res, duration2[i] + max(mn, start2[i]));
        }
        mn = INT_MAX;
        for(int i = 0; i < (int)start2.size(); i++) {
            mn = min(mn, start2[i] + duration2[i]);
        }
        for(int i = 0; i < (int)start1.size(); i++) {
            res = min(res, duration1[i] + max(mn, start1[i]));
        }
        return res;
    }
};