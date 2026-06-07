class Solution {
   public:
    void findCombination2(vector<vector<int>>& ans, vector<int>& curr, int target, int idx,
                          vector<int>& nums) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (idx == nums.size() || nums[idx] > target) {
            return;
        }

        // pick nums[idx]
        curr.push_back(nums[idx]);
        findCombination2(ans, curr, target - nums[idx], idx + 1, nums);
        curr.pop_back();

        // not pick nums[idx]
        // skip all duplicates of the current value
        int next = idx + 1;
        while (next < nums.size() && nums[idx] == nums[next]) {
            next++;
        }
        findCombination2(ans, curr, target, next, nums);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        findCombination2(ans, curr, target, 0, candidates);
        return ans;
    }
};