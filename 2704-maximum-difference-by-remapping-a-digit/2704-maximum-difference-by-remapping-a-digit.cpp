class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        vector<int> mx, mn, arr;
        for (int i = 0; i <= 9; i++) {
            string S = s;
            string T = s;
            for (int j = 0; j < (int)S.size(); j++) {
                if (S[j] - '0' == i) {
                    S[j] = '9';
                }
                if (T[j] - '0' == i) {
                    T[j] = '0';
                }
            }
            int a = atoi(S.c_str());
            int b = atoi(T.c_str());
            arr.push_back(a);
            arr.push_back(b);
        }
        
        sort(begin(arr), end(arr));
        for (auto x : arr) {
            cout << x << " ";
        }
        int res = arr.back() - arr.front();
        return res;
    }
};