class Solution {
public:
    void generate(vector<vector<int>>& ans, int idx, vector<int> nums, vector<int>& curr){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        generate(ans, idx + 1, nums, curr);
        curr.pop_back();
        generate(ans, idx + 1, nums, curr);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // ans.push_back({});
        vector<int> curr;
        generate(ans, 0, nums, curr);
        return ans;
    }
};
