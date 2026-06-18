class Solution {
public:
    bool func(vector<int>& nums, int target, int idx, vector<vector<int>>& dp){
        if(idx == 0){
            // imagine this as if there was a single element in the array, now imagning that write the base case
            if(nums[idx] == target) return true;
            return false;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        bool notPick = func(nums, target, idx - 1, dp);
        
        bool pick = false;
        if(target >= nums[idx]){
            pick = func(nums, target - nums[idx], idx - 1, dp);
        }

        return dp[idx][target] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), (vector<int>(target + 1, -1)));
        return func(nums, target, nums.size() - 1, dp);
    }
};
