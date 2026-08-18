class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int res = 0;
        int curr = 0;
        for (int request : requests) {
            res += std::abs(curr - request);
            curr = request;
        }
        return res;
    }
};