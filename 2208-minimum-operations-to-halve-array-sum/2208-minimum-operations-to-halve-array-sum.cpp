class Solution {
public:
    int halveArray(vector<int>& nums) {
        std::priority_queue<double> pq;
        double total = 0;
        for (int x : nums) {
            total += x;
            pq.push(x);
        }

        double half = (double)total / 2;
        // std::cout << half << " \n";
        int res = 0;
        while (total > half) {
            double d = pq.top();
            pq.pop();
            double dh = (double)d / 2;
            total -= dh;
            pq.push(dh);
            // std::cout << d << " " << dh << " \n";
            res++;
        }
        return res;
    }
};