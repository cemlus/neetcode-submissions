class Solution {
   public:
    void generate(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr,
                  vector<int>& visited) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // only allow unmarked elements
            if (visited[i] == 0) {
                curr.push_back(nums[i]);
                visited[i] = 1;        // mark the element
                generate(ans, nums, curr, visited);
                curr.pop_back();    // unmark and pop it from the place it took
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> visited(nums.size(), 0);
        generate(ans, nums, curr, visited);
        return ans;
    }
};
