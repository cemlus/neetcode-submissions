class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int idx, int k){
        if(idx == nums.size()){
            if(curr.size() == k){
                ans.push_back(curr);
            }
            return;
        }
        if(curr.size() == k && idx < nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        generate(ans, nums, curr, idx + 1, k);
        curr.pop_back();
        generate(ans, nums, curr, idx + 1, k);

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i = 1 ; i < n + 1 ; i++){
            nums.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> curr;
        generate(ans, nums, curr, 0, k);
        return ans;
    }
};