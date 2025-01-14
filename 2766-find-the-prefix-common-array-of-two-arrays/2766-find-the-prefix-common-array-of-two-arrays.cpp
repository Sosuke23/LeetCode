class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = (int)A.size();
        vector<int> res(n);
        std::array<int, 51> a {0}, b{0};
        for (int i = 0; i < n; i++) {
            a[A[i]] = 1;
            b[B[i]] = 1;
            int cnt = 0;
            for (int i = 1; i <= 50; i++) {
                if (a[i] and b[i]) {
                    cnt += 1;
                }
            }
            res[i] = cnt;
        }
        return res;
    }
};