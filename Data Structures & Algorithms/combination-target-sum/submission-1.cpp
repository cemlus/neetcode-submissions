class Solution {
   public:
    void findCombination(vector<int>& nums, int target, vector<int>& curr, int idx,
                         vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            if (target == 0) {
                // valid combination
                ans.push_back(curr);
            }
            // end of array reached
            return;
        }

        // we will pick up element if the target is still greater than the pointed element
        if (nums[idx] <= target) {
            curr.push_back(nums[idx]);
            // this is for going about the same element and including it an another time
            findCombination(nums, target - nums[idx], curr, idx, ans);
            // when the current pointed element can no longer be added we move to the branch where
            // it was never added
            curr.pop_back();
        }

        // this means that we move one index forward and conisder the situation where we didn't
        // include the possibility of having nums[idx] in the combination
        findCombination(nums, target, curr, idx + 1, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        findCombination(nums, target, curr, 0, ans);
        return ans;
    }
};

/*
- Without maintaining an index, you might generate [2,3] and [3,2] as separate combinations. Always
iterate from the current index forward, never backward, to ensure each combination is generated only
once in sorted order.



*/
