class Solution {
public:
    int countOddLetters(int n) {
        std::map<char, std::string> mp = {{'0', "zero"}, {'1', "one"}, {'2', "two"}, {'3', "three"},
                                            {'4', "four"}, {'5', "five"}, {'6', "six"}, {'7', "seven"},
                                            {'8', "eight"}, {'9', "nine"}};

        
        int res = 0;
        std::string w = "";
        std::set<char> st;
        for (char x : std::to_string(n)) {
            w += mp[x];
            for (char c : mp[x]) {
                st.insert(c);
            }
        }

        std::cout << w << '\n';
        for (char c : st) {
            if (std::count(begin(w), end(w), c) % 2 == 1) {
                res++;
            }
        }
        return res;
    }
};