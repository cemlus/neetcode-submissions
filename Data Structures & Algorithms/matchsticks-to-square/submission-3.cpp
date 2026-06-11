class Solution {
public:
    bool dfs(vector<int>& nums, int idx, vector<int>& sides, int target) {
        if (idx == nums.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target;
            // if 3 sides are correct, the 4th must also be correct
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + nums[idx] > target) continue;

            sides[i] += nums[idx];
            if (dfs(nums, idx + 1, sides, target)) return true;
            sides[i] -= nums[idx];

            // symmetry pruning
            if (sides[i] == 0) break;
        }

        return false;
    }

    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;

        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 4 != 0) return false;

        int target = sum / 4;

        sort(nums.rbegin(), nums.rend()); // largest first = better pruning
        if (nums[0] > target) return false;

        vector<int> sides(4, 0);
        return dfs(nums, 0, sides, target);
    }
};