class Solution {
public:
    int numberOfDays(int year, int month) {
        
        if (month != 2) {
            return 31 - (month & 1) ^ (month <= 7);
        }

        return 28 + ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0);
    }
};