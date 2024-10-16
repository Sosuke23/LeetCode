class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(rbegin(tasks), rend(tasks));
        sort(begin(processorTime), end(processorTime));

        int res = 0;
        for (int i = 0; i < (int)tasks.size(); i += 4) {
            res = std::max(res, processorTime[i / 4] + tasks[i]);
        }
        return res;
    }
};