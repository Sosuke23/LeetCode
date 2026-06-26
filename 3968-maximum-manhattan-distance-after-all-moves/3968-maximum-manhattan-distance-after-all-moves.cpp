class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0;
        int n = (int)moves.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            char m = moves[i];
            if (m == 'D') {
                y -= 1;
            } else if (m == 'L') {
                x -= 1;
            } else if (m == 'U') {
                y += 1;
            } else if (m == 'R') {
                x += 1;
            } else {
                c++;
            }
        }

        // int c = std::count(begin(moves), end(moves), '_');
        int res = std::abs(x) + std::abs(y) + c;
        return res;
    }
};