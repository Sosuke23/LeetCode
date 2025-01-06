class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = (int)boxes.size();
        vector<int> res(n);
        vector<int> left(n, 0), right(n, 0);

        int c = (boxes[0] == '1');
        for (int i = 1; i < n; i++) {
            left[i] += left[i - 1] + c;
            c += (boxes[i] == '1');
        }
        
        c = (boxes[n - 1] == '1');
        for (int i = n - 2; i >= 0; i--) {
            right[i] += right[i + 1] + c;
            c += (boxes[i] == '1');
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                res[i] = right[0];
            } else if (i == n - 1) {
                res[i] = left[n - 1];
            } else {
                res[i] = left[i] + right[i];
            }
        }
        return res;
    }
};