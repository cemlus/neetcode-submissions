class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0, maxi = 0;
        unordered_map<int, int> mpp;
        if(nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        int idx = 0;
        int ele = nums[0];
        while (idx < nums.size()) {
            if (mpp.find(ele) != mpp.end()) {
                // element was found
                cout << ele << " ";
                ele++;
                maxLen++;
            } else {
                // element not found
                // how do i make sure that after element wasn't found in
                // sequence, it resets the maxLen, without affecting the
                // original one
                maxLen = 0;
                idx = idx + 1;
                if (idx >= nums.size()) {
                    continue;
                } else {
                    ele = nums[idx];
                }
            }
            maxi = max(maxLen, maxi);
        }
        return maxi;
    }
};
