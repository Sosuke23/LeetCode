class Solution {
public:
    int minRange(int a, int b, int c) {
        int res = std::max({a, b, c}) - std::min({a, b, c});

        std::vector<int> arr = {a, b, c};
        std::sort(begin(arr), end(arr));

        arr.back() = arr[0] + arr[1];
        res = std::min(res, std::max({arr[0], arr[1], arr[2]}) - std::min({arr[0], arr[1], arr[2]}));
        return res;
    }
};