class Solution {
   public:
    // i am bound to find the minimum element in the unsorted half

    // this is the ideal solution without the extra and some unecessary checks that i added 
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int mini = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] > nums[hi]){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};
