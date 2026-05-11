class Solution {
public:
    bool findGameWinner(int n) {
        return (n - 1) % 6 != 0;
    }
};