class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr) {
        int res = 0;
		int n = (int)arr.size();
        for (int i = 0; i + 2 < (int)arr.size(); i++) {
            if (arr[i] == 0 and arr[i + 1] == 1 and arr[i + 2] == 0) {
                res += 1;
            } else  if (arr[i] == 1 and arr[i + 1] == 0 and arr[i + 2] == 1) {
                res += 1;
            }
        }
		res += (arr[n - 2] == 0 and arr[n - 1] == 1 and arr[0] == 0);
		res += (arr[n - 2] == 1 and arr[n - 1] == 0 and arr[0] == 1);
		res += (arr[n - 1] == 0 and arr[0] == 1 and arr[1] == 0);
		res += (arr[n - 1] == 1 and arr[0] == 0 and arr[1] == 1);
        return res;
    }
};
