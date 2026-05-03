class Solution {
public:
    int minSensors(int n, int m, int k) {
        int covers = 2 * k + 1;
        int a = (n + covers - 1) / covers;
        int b = (m + covers - 1) / covers;
        return (a * b);
    }
};