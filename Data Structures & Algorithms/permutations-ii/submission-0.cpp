class Solution {
   public:
    void generate(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr,
                  vector<int>& visited) {
        if (nums.size() == curr.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if(visited[i] == 0){
                // checking whether the branch should be skipped or not before modifying the state
                // make sure the index > 0 and the next number should be a duplicate and also the previous element should be unvisited
                // this means that the next element which is the duplicate will going to produce the same subtree
                if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)  continue;
                curr.push_back(nums[i]);
                visited[i] = 1;
                generate(ans, nums, curr, visited);
                curr.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        // make visited counting array wrt visited index
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        generate(ans, nums, curr, visited);
        return ans;
    }
};