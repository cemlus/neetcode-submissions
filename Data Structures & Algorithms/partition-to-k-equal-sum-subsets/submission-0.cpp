class Solution {
   public:
    bool isEqual(vector<int>& nums, vector<int>& buckets, int target, int k, int idx) {
        if (idx == nums.size()) {
            // return buckets[0] == target .... && buckets[k - 1] == target
            // cout << "entered" << endl;
            for(int j = 0 ; j < k ; j++){
                if(buckets[j] != target){
                    // cout << "false executed" << buckets[j] << endl;
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (nums[idx] + buckets[i] > target) continue;
            buckets[i] += nums[idx];
            // cout << "bucket " << i << " -> " << buckets[i] << " with idx = " << idx << endl;
            if(isEqual(nums, buckets, target, k, idx + 1)) return true;
            
            buckets[i] -= nums[idx];

            if(buckets[i] == 0) break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;
        vector<int> buckets(k, 0);
        return isEqual(nums, buckets, target, k, 0);
    }
};