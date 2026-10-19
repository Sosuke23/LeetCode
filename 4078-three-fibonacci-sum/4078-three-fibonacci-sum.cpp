class Solution {
public:
    bool threeFibonacciSum(int n) {
        long a = 0, b = 1, c = 1;
        long sum = a + b + c;
        while (sum < n) {
            a = b;
            b = c;
            c = a + b;
            sum = a + b + c;
        }

        return (sum == n);
    }
};