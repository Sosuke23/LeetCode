class Solution {
public:
    bool checkGoodInteger(int n) {
        
    auto f = [&] () {
        int dig_sum = 0;
        int sqr_sum = 0;
        for (char c : std::to_string(n)) {
            dig_sum += (c - '0');
            sqr_sum += (c - '0') * (c - '0');
        }
        return sqr_sum - dig_sum;
    }; 

    return (f() >= 50);

    }
};