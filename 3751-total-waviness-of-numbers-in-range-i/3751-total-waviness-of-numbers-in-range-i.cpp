class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int peak = 0, valley = 0;
        for (int i = num1; i <= num2; i++) {
            if (i < 100) {
                continue;
            }

            std::string a = to_string(i);
         
            for (int j = 1; j < (int)a.size() - 1; j++) {
                if (a[j] > a[j - 1] and a[j] > a[j + 1]) {
                    peak++;
                } else if (a[j] < a[j - 1] and a[j] < a[j + 1]) {
                    valley++;
                }
            }
        }

        return peak + valley;
    }
};