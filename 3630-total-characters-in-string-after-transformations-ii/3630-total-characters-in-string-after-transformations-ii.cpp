#define MOD ((int)1e9 + 7)

struct Matrix {
    int n, m;
    long long A[26][26];

    Matrix(int n, int m) : n(n), m(m) { memset(A, 0, sizeof(A)); }

    Matrix operator*(const Matrix& o) const {
        Matrix r(n, o.m);
        for (int k = 0; k < m; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < o.m; j++) {
                    r.A[i][j] = (r.A[i][j] + A[i][k] * o.A[k][j]) % MOD;
                }
            }
        }
        return r;
    }
};

Matrix power(Matrix a, long long b) {
    Matrix y(a.n, a.m);
    for (int i = 0; i < y.n; i++) {
        y.A[i][i] = 1;
    }
    for (; b; b >>= 1) {
        if (b & 1) {
            y = y * a;
        }
        a = a * a;
    }
    return y;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix k(26, 26);
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                k.A[i][(i + j) % 26] = 1;
            }
        }

        k = power(k, t);
        Matrix v(1, 26);
        for (char c : s) {
            v.A[0][c - 'a']++;
        }
        v = v * k;
        long long res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + v.A[0][i]) % MOD;
        }
        return res;
    }
};