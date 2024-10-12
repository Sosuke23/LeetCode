class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        a.insert(a.end(), b.begin(), b.end());
        sort(a.begin(), a.end());
        if ((int)a.size() % 2 == 1) {
            double p = a[(int)a.size() / 2];
            return p;
        }
        else {
            double p = a[(int)a.size() / 2];
            double q = a[(int)a.size() / 2 - 1];
            double l = (p + q) / 2;
            return l;
        }
    }
};