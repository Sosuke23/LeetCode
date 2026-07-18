class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int sec = 1;
        int end_time = 0;
        int start_time = 0;
        while (!endTime.empty()) {
            int a = endTime.back() - '0';
            endTime.pop_back();
            int t = endTime.back() - '0';
            endTime.pop_back();
            end_time += (t * 10 + a) * sec;
            sec *= 60;
            if (!endTime.empty()) {
                endTime.pop_back();
            }
        }
        sec = 1;
        while (!startTime.empty()) {
            int a = startTime.back() - '0';
            startTime.pop_back();
            int t = startTime.back() - '0';
            startTime.pop_back();
            start_time += (t * 10 + a) * sec;
            sec *= 60;
            if (!startTime.empty()) {
                startTime.pop_back();
            }
        }

        return (end_time - start_time);

    }
};