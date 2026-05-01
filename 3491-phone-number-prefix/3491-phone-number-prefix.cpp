class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        std::sort(begin(numbers), end(numbers), [&] (const auto &i, const auto &j) {
            return i.size() < j.size();
        });

        for (int i = 0; i < (int)numbers.size(); i++) {
            for (int j = i + 1; j < (int)numbers.size(); j++) {
                if (numbers[j].find(numbers[i]) == 0) {
                    return false;
                }
            }
            cout << '\n';
        }
        return true;
    }
};