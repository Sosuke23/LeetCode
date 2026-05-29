class ZigzagIterator {
public:
    int cnt = 0;
    std::vector<int> a, b;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        a = v1;
        b = v2;
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
    }

    int next() {
        int res = 0;
        if ((cnt % 2 == 0 and !a.empty()) or b.empty()) {
            res = a.back();
            a.pop_back();
        } else if ((cnt % 2 == 1 and !b.empty()) or a.empty()) {
            res = b.back();
            b.pop_back();
        } 
        cnt++;
        return res;
    }

    bool hasNext() {
        if (!a.empty() or !b.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */