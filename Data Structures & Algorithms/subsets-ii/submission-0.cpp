class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& curr, vector<int>&nums, int idx){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        generate(ans, curr, nums, idx + 1);
        curr.pop_back();

        int next = idx + 1;
        while(next < nums.size() && nums[next] == nums[idx]){
            next++;
        }
        generate(ans, curr, nums, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        generate(ans, curr, nums, 0);
        return ans;
    }
};
