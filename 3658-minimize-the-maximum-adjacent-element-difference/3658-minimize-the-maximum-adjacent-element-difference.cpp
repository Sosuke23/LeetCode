class Solution {
public:
    int minDifference(vector<int>& nums) {
        vector<int> vec;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                continue;
            }
            if (i - 1 >= 0 && nums[i - 1] != -1) {
                vec.push_back(nums[i - 1]);
            }
            if (i + 1 < n && nums[i + 1] != -1) {
                vec.push_back(nums[i + 1]);
            }
        }

        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        int lb = -1, ub = (int)1e9 + 1;

        auto trial = [&](int tar) {
            vector<int> a = nums;
            if (!vec.empty()) {
                int x = min(vec[0] + tar, vec.back());
                int y = max(vec[0], vec.back() - tar);
                if (y < x) {
                    y = x;
                }

                for (int i = 0; i < n; i++) {
                    if (a[i] != -1) {
                        continue;
                    }
                    int j = i;

                    while (j < n && a[j] == -1) {
                        j++;
                    }

                    int l = i - 1;
                    int r = j;

                    // try x
                    {
                        bool bad = false;
                        if (l >= 0 && abs(x - a[l]) > tar) {
                            bad = true;
                        }
                        if (r < n && abs(x - a[r]) > tar) {
                            bad = true;
                        }

                        if (!bad) {
                            for (int k = i; k < j; k++) {
                                a[k] = x;
                            }
                        }
                    }

                    // try y
                    if (a[i] == -1) {
                        bool bad = false;
                        if (l >= 0 && abs(y - a[l]) > tar) {
                            bad = true;
                        }
                        if (r < n && abs(y - a[r]) > tar) {
                            bad = true;
                        }

                        if (!bad) {
                            for (int k = i; k < j; k++) {
                                a[k] = y;
                            }
                        }
                    }

                    // try x y
                    if (a[i] == -1) {
                        if (abs(x - y) > tar) {
                            return false;
                        }
                        if (l >= 0) {
                            if (abs(x - a[l]) <= tar) {
                                a[i] = x;
                            }
                            else if (abs(y - a[l]) <= tar) {
                                a[i] = y;
                            }
                            else {
                                return false;
                            }
                        } else {
                            a[i] = x;
                        }

                        if (r < n) {
                            if (abs(x - a[r]) <= tar) {
                                a[r - 1] = x;
                            }
                            else if (abs(y - a[r]) <= tar) {
                                a[r - 1] = y;
                            }
                            else {
                                return false;
                            }
                        } else {
                            a[r - 1] = x;
                        }

                        for (int k = i + 1; k < j - 1; k++) {
                            a[k] = a[k - 1];
                        }
                    }

                    i = j - 1;
                }
            }
            for (int i = 0; i < n; i++) {
                int l = i - 1;
                int r = i + 1;
                if (l >= 0 && abs(a[i] - a[l]) > tar) {
                    return false;
                }
                if (r < n && abs(a[i] - a[r]) > tar) {
                    return false;
                }
            }

            return true;
        };

        while (ub - lb > 1) {
            int mid = (ub + lb) >> 1;
            if (trial(mid)) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }

        return ub;
    }
};