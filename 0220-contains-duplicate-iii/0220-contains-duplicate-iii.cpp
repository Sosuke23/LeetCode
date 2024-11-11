class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        std::unordered_map<int, int> buckets;

        for (int i = 0; i < (int)nums.size(); i++) {
            int bucket = nums[i] / ((long)valueDiff + 1);
            if (nums[i] < 0) {
                --bucket;
            }

            if (buckets.find(bucket) != buckets.end()) {
                return true;
            }
            buckets[bucket] = nums[i];
            if (buckets.find(bucket - 1) != buckets.end() and nums[i] - buckets[bucket - 1] <= valueDiff) {
                return true;
            }
            if (buckets.find(bucket + 1) != buckets.end() and buckets[bucket + 1] - nums[i] <= valueDiff) {
                return true;
            }

            if ((int)buckets.size() > indexDiff) {
                int key_to_remove = nums[i - indexDiff] / ((long)valueDiff + 1);
                if (nums[i - indexDiff] < 0) {
                    --key_to_remove;
                }
                buckets.erase(key_to_remove);
            }
        }
        return false;
    }
};