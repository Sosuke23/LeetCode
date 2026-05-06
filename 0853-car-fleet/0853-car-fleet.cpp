class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        std::priority_queue<std::pair<int, double>> pq;
        for (int i = 0; i < (int)speed.size(); i++) {
            pq.push({position[i], (double)(target - position[i]) / speed[i]});
        }

        int res = 0;
        double curr = 0;
        while (!pq.empty()) {
            if (pq.top().second > curr) {
                curr = pq.top().second;
                res++;
            }
            pq.pop();
        }
        return res;
    }
};