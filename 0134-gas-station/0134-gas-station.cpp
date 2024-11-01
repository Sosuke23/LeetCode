class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        int res = 0, tot = 0, now = 0;
        for (int i = 0; i < n; i++) {
            now += gas[i] - cost[i];
            if (now < 0) {
                tot += now; 
                now = 0;
                res = i + 1;
            }
        }
        return (tot + now < 0 ? -1 : res);
    }
};