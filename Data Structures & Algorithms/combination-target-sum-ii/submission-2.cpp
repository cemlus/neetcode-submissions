class Solution {
public:
    void find(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, int target, int idx){
        if(idx == nums.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }
        if(nums[idx] <= target){
            curr.push_back(nums[idx]);
            find(ans, curr, nums, target - nums[idx], idx + 1);
            curr.pop_back();
        }
        int next = idx + 1;
        while(next < nums.size() && nums[next] == nums[idx]){
            next++;
        }
        find(ans, curr, nums, target, next);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        find(ans, curr, nums, target, 0);
        return ans;
    }
};
