class Vector2D {
public:
    std::vector<int> arr;
    Vector2D(vector<vector<int>>& vec) {
        for (std::vector<int> a : vec) {
            for (int x : a) {
                arr.push_back(x);
            }
        }
        reverse(begin(arr), end(arr));
    }
    
    int next() {
        int res = arr.back();
        arr.pop_back();
        return res;
    }
    
    bool hasNext() {
        return (!arr.empty());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */