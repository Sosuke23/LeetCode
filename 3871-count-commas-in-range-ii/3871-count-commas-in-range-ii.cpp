class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long th = 1000;
        while (th <= n) {
            res += n - th + 1;
            th *= 1000;
        }
        return res;
    }
};
/*
3 - 1
4 - 1
5 - 1
6 - 2
7 - 2 
8 - 2
9 - 3
10 - 3 
11 - 3 
12 - 4 
13 - 4 
14 - 4
15 - 5
*/