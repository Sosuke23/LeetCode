class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        
        if (source == target) {
            return 0;
        } else if (source[0] == target[0] or source[1] == target[1]) {
            return 1;
        } else if (std::abs(source[0] - target[0]) == std::abs(source[1] - target[1])) {
            return 1;
        } 
        return 2;
    }
};