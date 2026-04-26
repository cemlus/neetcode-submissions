class Solution {
   public:
    // i am bound to find the minimum element in the unsorted half
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int mini = INT_MAX;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < mini) {
                mini = min(mini, nums[mid]);
                cout << "minimum: " << mini << endl;
            }
            if (nums[mid] <= nums[hi] && nums[lo] <= nums[mid]) {
                cout << "triggered at " << "lo = " << lo << " and hi = " << hi << endl;
                // the entire array is sorted
                mini = min(nums[0], mini);
                // return mini;
            } 
            if (nums[mid] <= nums[hi]) {
                // right sorted -> therefore our answer must be in the left unsorted
                hi = mid - 1;
            } else {
                // left sorted  -> therefore our answer must be in the right unsorted
                lo = mid + 1;
            }
        }
        return mini;
    }
};
