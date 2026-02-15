class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        std::string res = "";
        for (std::string word: words) {
            int sum = 0;
            for (char w : word) {
                sum += weights[w - 'a'];
            }
            sum %= 26;
            res += ('a' + (25 - sum));
        }
        return res;
    }
};